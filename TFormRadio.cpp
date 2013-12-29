//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TFormRadio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRadio *FormRadio;
//---------------------------------------------------------------------------
__fastcall TFormRadio::TFormRadio(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRadio::btnAceptarRadioClick(TObject *Sender)
{
        AnsiString tam = EditRadio->Text;
        int radio = atoi(tam.c_str());
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------
