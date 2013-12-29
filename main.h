#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include "Pelota.h"
#include "TFormRadio.h"

#include "Lista.h"
#include "Obstaculo.h"
#include "Triangulo.h"
#include "Circulo.h"
#include "Recubrimiento.h"

#include "TFormVelocidad.h"
#include "Lista.h"
#include "Obstaculo.h"
#include "Triangulo.h"

#include "Escena.h"

#include "TFormVelocidad.h"
#include <ExtCtrls.hpp>
#include <gl\gl.h>
#include <gl\glu.h>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Salir1;
        TMenuItem *NuevaPelota1;
        TMenuItem *AvanzarMenu;
        TTimer *Timer;
        TMenuItem *ActivaTimer;
        TMenuItem *Obstaculos1;
        TMenuItem *Triangulo1;
        TMenuItem *Circulo1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall NuevaPelota1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall AvanzarMenuClick(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall TimerTimer(TObject *Sender);
        void __fastcall ActivaTimerClick(TObject *Sender);
        void __fastcall Triangulo1Click(TObject *Sender);
        void __fastcall Circulo1Click(TObject *Sender);
private:
        HDC hdc;
        HGLRC hrc;
 //definen el tamaño del volumen de vista
        GLfloat xLeft,xRight,yTop,yBot;
 //guarda el radio del puerto de vista
        GLfloat RatioViewPort;
        void __fastcall SetPixelFormatDescriptor();
        void __fastcall GLScene();
        bool inicio;
        bool direccion;
        
        GLdouble xCentro;
        GLdouble yCentro;
        GLdouble radio;
        Escena *escena;
        bool triangulo;
        int vertice;
        PV2D *vt1;
        PV2D *vt2;
        PV2D *vt3;
        bool circulos;
        int nCirculos;

public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
