//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PV2D.h"

//---------------------------------------------------------------------------

PV2D::PV2D()
{
        x = 0;
        y = 0;
};

PV2D::PV2D(GLdouble xn, GLdouble yn)
{
        x = xn;
        y = yn;
};

PV2D::PV2D(const PV2D &p)
{
        x = p.x;
        y = p.y;
};

PV2D::~PV2D()
{
        x = 0;
        y = 0;
};

PV2D* PV2D::restaVertices(PV2D *v){

        return new PV2D(x - v->x, y - v->y);
};

GLdouble PV2D::dot(PV2D* v){
        return x*v->x + y*v->y;
};
        


#pragma package(smart_init)
