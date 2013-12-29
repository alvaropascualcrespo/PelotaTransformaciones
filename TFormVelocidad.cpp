//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TFormVelocidad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormVelocidad *FormVelocidad;
//---------------------------------------------------------------------------
__fastcall TFormVelocidad::TFormVelocidad(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormVelocidad::Button1Click(TObject *Sender)
{
        AnsiString vel = EditVelocidad->Text;
        int velocidad = atoi(vel.c_str());
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------
