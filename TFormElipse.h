//---------------------------------------------------------------------------

#ifndef TFormElipseH
#define TFormElipseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormElipse : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *EditAlto;
        TButton *btnAceptarElipse;
        TLabel *Label2;
        TEdit *EditAncho;
        TLabel *Label3;
        void __fastcall btnAceptarElipseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormElipse(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormElipse *FormElipse;
//---------------------------------------------------------------------------
#endif
