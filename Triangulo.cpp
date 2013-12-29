//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Triangulo.h"

//---------------------------------------------------------------------------


Triangulo::Triangulo(PV2D* p0,PV2D* p1,PV2D* p2){

        vertices[0] = new PV2D(*p0);
        vertices[1] = new PV2D(*p1);
        vertices[2] = new PV2D(*p2);

        lados[0] = p1->restaVertices(p0);
        lados[1] = p2->restaVertices(p1);
        lados[2] = p0->restaVertices(p2);

        normal[0] = new PV2D(lados[0]->y ,-lados[0]->x);
        normal[1] = new PV2D(lados[1]->y ,-lados[1]->x);
        normal[2] = new PV2D(lados[2]->y ,-lados[2]->x);

        //Calculo del baricentro
        baricentro = new PV2D(vertices[0]->x + vertices[1]->x + vertices[2]->x /3.0 ,vertices[0]->y + vertices[1]->y + vertices[2]->y /3.0);

        normalV[0] = new PV2D (*vertices[0]->restaVertices(baricentro));
        normalV[1] = new PV2D (*vertices[1]->restaVertices(baricentro));
        normalV[2] = new PV2D (*vertices[2]->restaVertices(baricentro));

        delete p0;
        delete p1;
        delete p2;


};


bool Triangulo::interseccion(PV2D* P, PV2D* direccion, double &thit, PV2D* &normalIn){
        GLdouble dist[3];
        GLdouble proy[3];
        GLdouble sign[3];

        PV2D* v = new PV2D(direccion->x / modulo(direccion), direccion->y / modulo(direccion) );


        PV2D* normalDeV = new PV2D(-v->y, v->x);
        for (int i=0; i<3; i++){
                dist[i] = normalDeV->dot(vertices[i]->restaVertices(P));
                proy[i] = v->dot(vertices[i]->restaVertices(P));
                if (dist[i] < 0) {sign[i] = -1;}
                else if (dist[i] == 0) {sign[i] = 0;}
                else if (dist[i] > 0) {sign[i] = 1;}
        }

        int sum = sign[0] + sign[1] + sign[2];
        if (abs(sum) == 3) return false; //Fallo trivial
        int nHits = 0;
        GLdouble hit[3];
        PV2D* n[3];
        for (int i=0; i<3; i++){
                int j = (i+1)%3;
                if ((sign[i] * sign[j]) < 0){
                        GLdouble numerador = proy[i] * dist[j] - dist[i] * proy[j];
                        GLdouble denominador = dist[j] - dist[i];
                        hit[nHits] = numerador / denominador;
                        n[nHits] = new PV2D(normal[i]->x / modulo(normal[i]), normal[i]->y / modulo(normal[i]));
                        nHits++;
                }
        }

         if (nHits < 2){
                for (int i=0; i<3; i++){
                        if (sign[i] == 0){
                                hit[nHits] = proy[i];
                                n[nHits] = normalV[i];
                                nHits++;
                        }
                }
        }
        GLdouble min = 9999999999999.0;
        int m;
        for (int i=0; i<nHits; i++){
                if (hit[i] < min) {
                        m = i;
                        min = hit[i];
                }
        }
        thit = hit[m];
        normalIn = n[m];
        return true;
};

double Triangulo::modulo(PV2D * v){

        return sqrt(pow(v->x,2) + pow(v->y,2));
};


void Triangulo::draw()
{
       glBegin(GL_LINE_LOOP);
                glVertex2d(vertices[0]->x,vertices[0]->y);
                glVertex2d(vertices[1]->x,vertices[1]->y);
                glVertex2d(vertices[2]->x,vertices[2]->y);
       glEnd();
}
#pragma package(smart_init)

