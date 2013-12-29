//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lapiz.h"

//---------------------------------------------------------------------------

Lapiz::Lapiz()
{
        pos = new PV2D();
        dir = 0;
};

Lapiz::Lapiz(PV2D * p, GLdouble d)
{
        pos = new PV2D(*p);
        dir = d;
};

Lapiz::~Lapiz()
{
        delete pos;
};

void Lapiz::moveTo(PV2D* p, bool draw)
{
        if (draw)
        {
                glBegin (GL_LINES);
                glVertex2d(pos->x,pos->y);
                glVertex2d(p->x,p->y);
                glEnd();
        }
        delete pos;
        pos  = new PV2D(*p);
        // borrar p si no se borra en otro sitio
};

void Lapiz::turnTo(GLdouble a)
{
        dir = a;
};

void Lapiz::turn(GLdouble a)
{
	dir += a;
};

void Lapiz::forward(GLdouble dist, bool draw)
{
        PV2D *p = new PV2D(pos->x + dist*cos(dir),pos->y + dist*sin(dir));
        if (draw)
        {
                glBegin (GL_LINES);
                glVertex2d(pos->x,pos->y);
                glVertex2d(p->x,p->y);
                glEnd();
        }
        delete pos;
        pos  = new PV2D(*p);
        delete p;
};

void Lapiz::lookAt(PV2D* p)
{
        dir = atan2(p->y-pos->y,p->x-pos->x);
};

#pragma package(smart_init)
