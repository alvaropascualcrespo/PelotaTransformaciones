//---------------------------------------------------------------------------

#ifndef PelotaH
#define PelotaH

#include <gl/GL.h>
#include "PV2D.h"

const int MAX_LADOS = 500;

class Pelota{

	public:
		PV2D* centro;
                GLdouble radio;
                GLdouble radioReal;
                PV2D* vector;
                PV2D* circulo[MAX_LADOS];
                PV2D* circuloI[MAX_LADOS];
                GLdouble velocidad;
                GLdouble avanceU;
                GLdouble teta;
                GLdouble avanceG;


	Pelota();
	Pelota(PV2D* centron, GLdouble radion);
        void poner_vector(PV2D* vectorn);
        void ponerVelocidad(GLdouble vel);
        void movimiento(GLdouble avance, bool cambiaGiro);
        void rebota(PV2D* n);
        double modulo(PV2D* v);
        void draw();

	

};
//---------------------------------------------------------------------------
#endif
