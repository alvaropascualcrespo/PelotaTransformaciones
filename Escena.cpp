//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"
#include "Triangulo.h"

//---------------------------------------------------------------------------


void Escena::step()
{
        bool exitoG = false;
        GLdouble thitG = 2.0 * pelota->velocidad;
        PV2D *nG;
        bool exitoL = false;
        GLdouble thitL = 0;
        PV2D *nL;
        for (int i = 0; i < nObstaculos; i++){

                exitoL = obstaculos[i]->interseccion(pelota->centro, pelota->vector,thitL,nL);
                if ((exitoL && thitL > 0) && thitL <= (pelota->velocidad)) exitoL = true;
                else exitoL = false;

                if (exitoL && thitL < thitG){
                        thitG = thitL;
                        nG = new PV2D (*nL);
                }
                exitoG |= exitoL;
        }



        if (!exitoG) pelota->movimiento(pelota->velocidad,false);
        else {
                pelota->movimiento(thitG,true);
                pelota->rebota(nG);
        }
}

void Escena::aniadirObstaculo(Obstaculo *o)
{
        obstaculos[nObstaculos] = o;
        nObstaculos++;
}

void Escena::draw()
{
     glColor3f(1.0,0.0,0.0);
     /*glBegin(GL_LINE_LOOP);
     for (int i = 0; i < MAX_LADOS; i++)
     {
        glVertex2d(pelota->circulo[i]->x,pelota->circulo[i]->y);
     }
     glEnd();*/
     pelota->draw();
     glColor3f(0.0,0.0,0.0);
     for (int i=0; i < nObstaculos; i++)
     {
        obstaculos[i]->draw();
     }

}





#pragma package(smart_init)
