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

        circulo = new Circulo(new PV2D(0,0),1,pint);

        //Calculo de la matriz M

        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                        matrix[i][j] = 0;
                }
        }
        matrix[0][0] = 1/ancho;
        matrix[1][1] = 1/alto;
        matrix[0][2] = - centro->x;
        matrix[1][2] = - centro->y;
        matrix[2][2] = 1;

        // **** HASTA AQUI ****
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

bool Elipse::interseccion(PV2D* P, PV2D* direccion, double &thit, PV2D* &normalIn){

        bool choque = false;
        //Aplico M sobre el centro de la pelota
        GLfloat xaux = matrix[0][0] * (P->x + matrix[0][2]);
        GLfloat yaux = matrix[1][1] * (P->y + matrix[1][2]);
        PV2D* centroBola = new PV2D(xaux,yaux);
        // AQUI FALLO *Aplicar M sobre la velocidad Lineal
        PV2D* unitario = new PV2D(direccion->x/modulo(direccion), direccion->y/modulo(direccion));
        GLfloat xaux1 = matrix[0][0] * unitario->x * 33;
        GLfloat yaux1 = matrix[1][1] * unitario->y * 33;
        PV2D* dir = new PV2D(xaux1,yaux1);
        // choque
        choque = circulo->interseccion(centroBola,dir,thit,normalIn);
        delete centroBola;
        delete dir;
        //Calculo de la normal
        matrix[2][0] = - centro->x;
        matrix[2][1] = - centro->y;
        matrix[0][2] = 0;
        matrix[1][2] = 0;
        GLfloat xaux2 = matrix[0][0] * normalIn->x;
        GLfloat yaux2 = matrix[1][1] * normalIn->y;
        normalIn->x = xaux2;
        normalIn->y = yaux2;
        return choque;

 };

double Elipse::modulo(PV2D * v){
        return sqrt(pow(v->x,2) + pow(v->y,2));
};

#pragma package(smart_init)
