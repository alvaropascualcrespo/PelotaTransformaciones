//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Circulo.h"

#include "Circulo.h"
#include "Lapiz.h"

//---------------------------------------------------------------------------

Circulo::Circulo(PV2D* centron, GLdouble radion, bool pint){
        pintable = pint;
        centro = new PV2D(*centron);
        radio = radion;
        radio2 = pow(radio,2);
        delete centron;

        GLdouble alfa = (2.0*PI) / MAX_LADOS_CIRCULO;
        GLdouble beta = (PI - alfa) / 2.0;
        GLdouble lado = 2.0 * cos(beta) * radio;

        Lapiz* lapiz = new Lapiz(centro,0);
        lapiz->forward(radio,false);
        contorno[0] = new PV2D(*lapiz->pos);
        lapiz->turn(PI - beta);
        for (int i = 1; i < MAX_LADOS_CIRCULO; i++)
        {
           lapiz->forward(lado,false);
           contorno[i] = new PV2D(*lapiz->pos);
           lapiz->turn(alfa);
        }
};

void Circulo::draw(){
        if (pintable == true){
                glBegin(GL_POLYGON);
                        for (int i = 0; i < MAX_LADOS_CIRCULO; i++){
                                glVertex2d(contorno[i]->x,contorno[i]->y);
                        }
                glEnd();
        }
};

bool Circulo::interseccion(PV2D* P, PV2D* vGrande, double &thit, PV2D* &normalIn){
        PV2D* v = new PV2D(vGrande->x / modulo(vGrande), vGrande->y / modulo(vGrande));
        double a = v->dot(v);
        double b = 2*((P->restaVertices(centro))->dot(v));
        double c = ((P->restaVertices(centro))->dot(P->restaVertices(centro))) - radio2;

        double discriminante = pow(b,2) - 4*a*c;
        if (discriminante < 0) return false;
        if (discriminante > -1 && discriminante < 1){
                thit = -b / 2*a;
                PV2D* puntoCorte = new PV2D(P->x + thit * v->x, P->y + thit * v->y);
                normalIn = new PV2D((puntoCorte->x - centro->x), (puntoCorte->y - centro->y));
                return true;
        }
        if (discriminante > 0){
                double t1 = (-b - sqrt(discriminante)) / 2*a;
                double t2 = (-b + sqrt(discriminante)) / 2*a;
                thit = min(t1,t2);
                PV2D* puntoCorte = new PV2D(P->x + thit * v->x, P->y + thit * v->y);
                normalIn = new PV2D((puntoCorte->x - centro->x), (puntoCorte->y - centro->y));
                return true;
        }
        return false;
};

double Circulo::modulo(PV2D * v){
        return sqrt(pow(v->x,2) + pow(v->y,2));
};

#pragma package(smart_init)
