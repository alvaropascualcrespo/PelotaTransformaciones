//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("AnimacionPelota.res");
USEFORM("main.cpp", MainForm);
USEUNIT("Obstaculo.cpp");
USEUNIT("Triangulo.cpp");
USEUNIT("Circulo.cpp");
USEUNIT("Obstaculo.cpp");
USEUNIT("Triangulo.cpp");
USEUNIT("Circulo.cpp");
USEUNIT("Lapiz.cpp");
USEUNIT("Pelota.cpp");
USEUNIT("PV2D.cpp");
USEFORM("TFormRadio.cpp", FormRadio);
USEFORM("TFormVelocidad.cpp", FormVelocidad);
USEUNIT("Escena.cpp");
USEUNIT("Recubrimiento.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TFormRadio), &FormRadio);
                 Application->CreateForm(__classid(TFormVelocidad), &FormVelocidad);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
