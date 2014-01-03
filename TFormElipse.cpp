//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TFormElipse.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormElipse *FormElipse;
//---------------------------------------------------------------------------
__fastcall TFormElipse::TFormElipse(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormElipse::btnAceptarElipseClick(TObject *Sender)
{
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------

