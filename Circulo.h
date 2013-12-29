//---------------------------------------------------------------------------

#ifndef CirculoH
#define CirculoH
//---------------------------------------------------------------------------

#include "Obstaculo.h"
#include "Math.h"

const int MAX_LADOS_CIRCULO = 500;

class Circulo : public Obstaculo{

        public:
		PV2D* centro;
                GLdouble radio;
                GLdouble radio2;
                PV2D* contorno[MAX_LADOS_CIRCULO];
                bool interseccion(PV2D* P, PV2D* v, double &thit, PV2D* &normalIn);
                void draw();
                bool pintable;


	        Circulo();
	        Circulo(PV2D* centron, GLdouble radion, bool pint);

        private:
                double modulo(PV2D*);
                
};

#endif
