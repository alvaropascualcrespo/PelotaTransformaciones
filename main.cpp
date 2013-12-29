//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    hdc = GetDC(Handle);
    SetPixelFormatDescriptor();
    hrc = wglCreateContext(hdc);
    if(hrc == NULL)
    	ShowMessage(":-)~ hrc == NULL");
    if(wglMakeCurrent(hdc, hrc) == false)
    	ShowMessage("Could not MakeCurrent");
    //Cor de fondo de la ventana
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //inicialización del volumen de vista
    xRight=400.0; xLeft=-xRight;
    yTop=xRight; yBot=-yTop;
    //Radio del volumen de vista == 1

    //inicialización del puerto de vista
    //ClientWidth=400;
    //ClientHeight=400;
    RatioViewPort=1.0;

    // inicialización de las variables del programa
    GLdouble xCentro = 0;
    GLdouble yCentro = 0;
    GLdouble radio = 0;
    Timer->Enabled = false;
    circulos = false;


    

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetPixelFormatDescriptor()
{
    PIXELFORMATDESCRIPTOR pfd = {
    	sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0
    };
    int PixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, PixelFormat, &pfd);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormResize(TObject *Sender)
{

 //se actualiza puerto de vista y su radio
  if ((ClientWidth<=1)||(ClientHeight<=1)){
     ClientWidth=400;
     ClientHeight=400;
     RatioViewPort=1.0;
     }
  else RatioViewPort= (float)ClientWidth/(float)ClientHeight;

  glViewport(0,0,ClientWidth,ClientHeight);

  // se actualiza el volumen de vista
  // para que su radio coincida con ratioViewPort
  GLfloat WidthVolVista = xRight-xLeft;
  GLfloat HeightVolVista = yTop-yBot;
  GLfloat RatioVolVista = (xRight-xLeft)/(yTop-yBot);

  if (RatioVolVista>=RatioViewPort){
     //Aumentamos yTop-yBot
     GLfloat newHeight = WidthVolVista/RatioViewPort;
     GLfloat yMiddle = (yTop+yBot)/2.0;
     yTop= yMiddle+newHeight/2.0;
     yBot= yMiddle-newHeight/2.0;
     }
  else{
     //Aumentamos xRight-xLeft
     GLfloat newWidth = HeightVolVista*RatioViewPort;
     GLfloat xMiddle = (xLeft+xRight)/2.0;
     xRight= xMiddle+newWidth/2.0;
     xLeft= xMiddle-newWidth/2.0;
     }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft,xRight, yBot,yTop);


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  GLScene();

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GLScene()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0,0.0,0.0);
        //drawScene();
        if (escena != NULL){
               escena -> draw();
        }
        glFlush();
        SwapBuffers(hdc);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormPaint(TObject *Sender)
{
  GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
    ReleaseDC(Handle,hdc);
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);
    delete escena;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NuevaPelota1Click(TObject *Sender)
{
       TFormRadio* FormRadio;
       FormRadio = new TFormRadio(NULL);
       FormRadio->ShowModal();
       AnsiString rad = FormRadio->EditRadio->Text;
       radio = atof(rad.c_str());
       ShowMessage("Presione un punto para colocar la pelota");
       inicio = true;
       nCirculos = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Salir1Click(TObject *Sender)
{
        exit(-1);        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AvanzarMenuClick(TObject *Sender)
{
        escena->step();
        GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if (inicio == true)
          {
                GLfloat escalaAncho = ClientWidth / (xRight - xLeft);
                GLfloat escalaAlto = ClientHeight / (yTop - yBot);
                xCentro = (X + xLeft * escalaAncho) / escalaAncho;
                yCentro = (ClientHeight/2 - Y) / escalaAlto;
                escena =  new Escena (new Pelota(new PV2D(xCentro,yCentro),radio));
                inicio = false;

                GLScene();
                ShowMessage("Presione un punto para la direccion de la pelota");
                direccion = true;

                PV2D *v1 = new PV2D(ClientWidth + 100,0);
                PV2D *v2 = new PV2D(ClientWidth - 50 ,ClientHeight + 100);
                PV2D *v3 = new PV2D(ClientWidth -50 ,- ClientHeight - 100);

                Obstaculo* r = new Recubrimiento(escena->pelota->radio,v1,v2,v3);
                Obstaculo *triangulo = new Triangulo(v1,v2,v3);
                escena->aniadirObstaculo(triangulo);
                escena->aniadirObstaculo(r);

                v1 = new PV2D(- ClientWidth - 100 ,0);
                v2 = new PV2D(- ClientWidth + 50,-ClientHeight - 100);
                v3 = new PV2D(- ClientWidth + 50,ClientHeight + 100);

                r = new Recubrimiento(escena->pelota->radio,v1,v2,v3);
                triangulo = new Triangulo(v1,v2,v3);
                escena->aniadirObstaculo(triangulo);
                escena->aniadirObstaculo(r);


                v1 = new PV2D(0,ClientHeight + 100);
                v2 = new PV2D(-ClientWidth - 100 ,ClientHeight - 50 );
                v3 = new PV2D( ClientWidth + 100, ClientHeight - 50);
                r = new Recubrimiento(escena->pelota->radio,v1,v2,v3);
                triangulo = new Triangulo(v1,v2,v3);
                escena->aniadirObstaculo(triangulo);
                escena->aniadirObstaculo(r);

                v1 = new PV2D(0,-ClientHeight - 100 );
                v2 = new PV2D(ClientWidth + 100,-ClientHeight + 50);
                v3 = new PV2D(- ClientWidth - 100,- ClientHeight + 50 );
                r = new Recubrimiento(escena->pelota->radio,v1,v2,v3);
                triangulo = new Triangulo(v1,v2,v3);
                escena->aniadirObstaculo(triangulo);
                escena->aniadirObstaculo(r);



          } else{
                if (direccion == true){
                        GLScene();
                        direccion = false;
                        GLfloat escalaAncho = ClientWidth / (xRight - xLeft);
                        GLfloat escalaAlto = ClientHeight / (yTop - yBot);
                        xCentro = (X + xLeft * escalaAncho) / escalaAncho;
                        yCentro = (ClientHeight/2 - Y) / escalaAlto;
                        escena->pelota->poner_vector(new PV2D(xCentro - escena->pelota->centro->x, yCentro - escena->pelota->centro->y));
                        GLScene();
                        TFormVelocidad* FormVelocidad;
                        FormVelocidad = new TFormVelocidad(NULL);
                        FormVelocidad->ShowModal();
                        AnsiString vel = FormVelocidad->EditVelocidad->Text;
                        escena->pelota->ponerVelocidad(atof(vel.c_str()));
                        for(int k=0; k<escena->nObstaculos && k < 8; k++){
                                if ((k%2) == 1){
                                        ((Recubrimiento*)(escena->obstaculos[k]))->velocidad = atof(vel.c_str());
                                }
                        }
                        GLScene();
                }
                else{
                        if (triangulo == true)
                        {
                                GLfloat escalaAncho = ClientWidth / (xRight - xLeft);
                                GLfloat escalaAlto = ClientHeight / (yTop - yBot);
                                xCentro = (X + xLeft * escalaAncho) / escalaAncho;
                                yCentro = (ClientHeight/2 - Y) / escalaAlto;
                                if (vertice == 0){
                                        vt1 = new PV2D(xCentro,yCentro);
                                        vertice++;
                                } else if (vertice == 1){
                                        vt2 = new PV2D(xCentro,yCentro);
                                        vertice++;
                                } else if (vertice == 2){
                                        vt3 = new PV2D(xCentro,yCentro);
                                        vertice = 0;
                                        triangulo = false;
                                        Obstaculo* r = new Recubrimiento(escena->pelota->radio,vt1,vt2,vt3);
                                        Obstaculo *triangulo = new Triangulo(vt1,vt2,vt3);
                                        escena->aniadirObstaculo(triangulo);
                                        ((Recubrimiento*)(r))->velocidad = escena->pelota->velocidad;
                                        escena->aniadirObstaculo(r);
                                }

                        }
                        else {
                                if (circulos == true){
                                GLfloat escalaAncho = ClientWidth / (xRight - xLeft);
                                GLfloat escalaAlto = ClientHeight / (yTop - yBot);
                                xCentro = (X + xLeft * escalaAncho) / escalaAncho;
                                yCentro = (ClientHeight/2 - Y) / escalaAlto;
                                double rad = random(75);
                                Circulo* c = new Circulo(new PV2D(xCentro,yCentro),rad,true);
                                escena->aniadirObstaculo(c);
                                Circulo* c1 = new Circulo(new PV2D(xCentro,yCentro),rad+escena->pelota->radio,false);
                                escena->aniadirObstaculo(c1);
                                circulos = false;
                                GLScene();
                        }
                        }

                }
        }
       GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerTimer(TObject *Sender)
{
        Timer->Enabled = false;
        Timer->Interval = 20;
        escena->step();
        GLScene();
        Timer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ActivaTimerClick(TObject *Sender)
{
        Timer->Enabled = !Timer->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Triangulo1Click(TObject *Sender)
{
        ShowMessage("Indica los 3 vertices en sentido contrahorario");
        triangulo = true;
        vertice = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Circulo1Click(TObject *Sender)
{
        circulos = true;
        ShowMessage("Seleccione un punto para que sea el centro del circulo");        
}
//---------------------------------------------------------------------------

