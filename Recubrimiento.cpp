//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recubrimiento.h"

//---------------------------------------------------------------------------

Recubrimiento::Recubrimiento(double rad, PV2D* v0, PV2D* v1, PV2D* v2){

        velocidad = 1;
        //Segmento de v0 a v1
        int actual = 0;
        Lapiz* lapiz = new Lapiz(v0,0);
        lapiz->lookAt(v1);
        lapiz->turn(-0.5*PI);
        lapiz->forward(rad,false);
        vertices[0] = new PV2D(*lapiz->pos);
        lapiz->turn(0.5*PI);
        lapiz->forward(modulo(v1->restaVertices(v0)),false);
        vertices[1] = new PV2D(*lapiz->pos);
        lapiz->moveTo(v1,false);
        lapiz->lookAt(vertices[1]);


        //Circulo en v1
        PV2D* ve1 = new PV2D(v1->x - v2->x, v1->y - v2->y);
        PV2D* ve2 = new PV2D(v1->x - v0->x, v1->y - v0->y);
        GLdouble angulo = PI - acos((ve1->dot(ve2))/(modulo(ve1)*modulo(ve2)));
        GLdouble alfa = (angulo) / MAX_ANGULO;
        GLdouble beta = (PI - alfa) / 2.0;
        GLdouble lado = 2.0 * cos(beta) * rad;

        lapiz->forward(rad,false);
        lapiz->turn(PI - beta);
        actual = 2;
        int i;
        for (i = actual; i < actual+MAX_ANGULO; i++)
        {
           lapiz->forward(lado,false);
           vertices[i] = new PV2D(*lapiz->pos);
           lapiz->turn(alfa);
        }
        actual = i;

        //Segmento de v1 a v2
        lapiz->moveTo(v1,false);
        lapiz->lookAt(v2);
        lapiz->moveTo(vertices[actual-1],false);
        lapiz->forward(modulo(v1->restaVertices(v2)),false);
        vertices[actual] = new PV2D(*lapiz->pos);
        actual++;

        //Circulo en v2
        ve1 = new PV2D(v2->x - v0->x, v2->y - v0->y);
        ve2 = new PV2D(v2->x - v1->x, v2->y - v1->y);
        angulo = PI - acos((ve1->dot(ve2))/(modulo(ve1)*modulo(ve2)));
        alfa = (angulo) / MAX_ANGULO;
        beta = (PI - alfa) / 2.0;
        lado = 2.0 * cos(beta) * rad;

        lapiz->moveTo(v2,false);
        lapiz->lookAt(vertices[actual-1]);
        lapiz->forward(rad,false);
        lapiz->turn(PI - beta);
        for (i = actual; i < actual+MAX_ANGULO; i++)
        {
           lapiz->forward(lado,false);
           vertices[i] = new PV2D(*lapiz->pos);
           lapiz->turn(alfa);
        }
        actual = i;

        //Segmento de v2 a v0
        lapiz->moveTo(v2,false);
        lapiz->lookAt(v0);
        lapiz->moveTo(vertices[actual-1],false);
        lapiz->forward(modulo(v2->restaVertices(v0)),false);
        vertices[actual] = new PV2D(*lapiz->pos);
        actual++;

        //Circulo en v0
        ve1 = new PV2D(v0->x - v1->x, v0->y - v1->y);
        ve2 = new PV2D(v0->x - v2->x, v0->y - v2->y);
        angulo = PI - acos((ve1->dot(ve2))/(modulo(ve1)*modulo(ve2)));
        alfa = (angulo) / MAX_ANGULO;
        beta = (PI - alfa) / 2.0;
        lado = 2.0 * cos(beta) * rad;

        lapiz->moveTo(v0,false);
        lapiz->lookAt(vertices[actual-1]);
        lapiz->forward(rad,false);
        lapiz->turn(PI - beta);
        for (i = actual; i < actual+MAX_ANGULO; i++)
        {
           lapiz->forward(lado,false);
           vertices[i] = new PV2D(*lapiz->pos);
           lapiz->turn(alfa);
        }
        actual = i;

        //Calculo las normales
        for(int k=0; k<MAX_RECUBRIMIENTO; k++){
                PV2D *aux = vertices[(k+1)%MAX_RECUBRIMIENTO]->restaVertices(vertices[k]);
                normal[k] = new PV2D (aux->y / modulo(aux)*10, - aux->x / modulo(aux)*10);
        }
}

void Recubrimiento::draw(){
        /*glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < MAX_RECUBRIMIENTO; i++){
                glVertex2d(vertices[i]->x,vertices[i]->y);
        }
        glEnd();
        glColor3f(0.0,0.0,0.0);
        
        //Dibujamos normales
        glColor3f(1.0,0.0,1.0);
        for (int i = 0; i<MAX_RECUBRIMIENTO; i++){
                GLdouble mediox = (vertices[i%MAX_RECUBRIMIENTO]->x + vertices[(i+1)%MAX_RECUBRIMIENTO]->x)/2;
                GLdouble medioy = (vertices[i%MAX_RECUBRIMIENTO]->y + vertices[(i+1)%MAX_RECUBRIMIENTO]->y)/2;

                GLdouble finx = mediox + normal[i%MAX_RECUBRIMIENTO]->x;
                GLdouble finy = medioy + normal[i%MAX_RECUBRIMIENTO]->y;

                glBegin(GL_LINES);
                        glVertex2d(mediox,medioy);
                        glVertex2d(finx,finy);
                glEnd();
        }
        glColor3f(0.0,0.0,0.0);*/
}

bool Recubrimiento::cyrusBeck(PV2D* P, PV2D* direccion, double &tIn, PV2D* &normalIn){
     GLdouble thit = 0;
     tIn = 0;
     GLdouble tOut = 1;
     int normalIntAux = -1;
     int i = 0;
     bool encontrado = false;
     PV2D* dir = new PV2D(direccion->x / modulo(direccion)*velocidad, direccion->y / modulo(direccion)*velocidad);

     while (!encontrado && i < MAX_RECUBRIMIENTO){

        //int j = (i + 1) % MAX_RECUBRIMIENTO;

        GLdouble numerador = (vertices[i]->restaVertices(P))->dot(normal[i]);
        GLdouble denominador =  dir->dot(normal[i]);

        if (denominador == 0 && ((P->restaVertices(vertices[i]) == 0) || (P->restaVertices(vertices[i]) > 0))) encontrado = true;
        else if (!(denominador == 0 && (P->restaVertices(vertices[i]) < 0))){
                thit = numerador / denominador;
                if (dir->dot(normal[i]) < 0){
                        if (thit > tIn){
                                tIn = thit;
                                normalIntAux = i;
                        }
                }else if (dir->dot(normal[i]) > 0) tOut = min(tOut,thit);
                encontrado = tIn > tOut;
        }
        i++;
     }
     //Prueba
     if(!encontrado && normalIntAux != -1){
        normalIn = new PV2D(*normal[normalIntAux]);
     }
     else return false;

     thit = tIn;
     return !encontrado;

}

bool Recubrimiento::interseccion(PV2D* P, PV2D* direccion, double &thit, PV2D* &normalIn){
        GLdouble tIn = 0;
        bool devolver = cyrusBeck(P, direccion, tIn, normalIn);
        thit = tIn;
        if (devolver && (thit < 1)) thit = thit * velocidad;
        return devolver;
}


double Recubrimiento::modulo(PV2D * v){
        return sqrt(pow(v->x,2) + pow(v->y,2));
};

#pragma package(smart_init)
