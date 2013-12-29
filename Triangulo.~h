//---------------------------------------------------------------------------

#ifndef TrianguloH
#define TrianguloH

#include "Obstaculo.h"

#include <iostream>
using namespace std;

class Triangulo : public Obstaculo{

        public:
                PV2D* vertices[3];
                PV2D* normal[3];
                PV2D* normalV[3];
                PV2D* baricentro;
                Triangulo(PV2D* p0,PV2D* p1,PV2D* p2);
                bool interseccion(PV2D* P, PV2D* direccion, double &thit, PV2D* &normalIn);
                void draw();
        private:
                double modulo(PV2D *v);
                PV2D* lados[3];
};

//---------------------------------------------------------------------------
#endif
