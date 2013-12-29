//---------------------------------------------------------------------------

#ifndef TFormRadioH
#define TFormRadioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormRadio : public TForm
{
__published:	// IDE-managed Components
        TEdit *EditRadio;
        TButton *btnAceptarRadio;
        TLabel *Label1;
        void __fastcall btnAceptarRadioClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormRadio(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRadio *FormRadio;
//---------------------------------------------------------------------------
#endif
