//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Elipse.h"
#include "Lapiz.h"

//---------------------------------------------------------------------------

Elipse::Elipse(PV2D* cent, double alt, double anc, bool pint){
        pintable = pint;
        alto = alt;
        ancho = anc;
        centro = cent;

        circulo = new Circulo(new PV2D(0,0),1,true);


};

void Elipse::draw(){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        glTranslated(centro->x,centro->y,0);
        glScaled(ancho,alto,1);
        if (pintable == true){
               circulo->draw();
        }

        glPopMatrix();
};

#pragma package(smart_init)
