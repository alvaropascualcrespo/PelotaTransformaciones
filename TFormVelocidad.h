//---------------------------------------------------------------------------

#ifndef TFormVelocidadH
#define TFormVelocidadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormVelocidad : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *EditVelocidad;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormVelocidad(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormVelocidad *FormVelocidad;
//---------------------------------------------------------------------------
#endif
