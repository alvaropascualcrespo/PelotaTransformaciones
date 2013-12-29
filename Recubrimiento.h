//---------------------------------------------------------------------------

#ifndef RecubrimientoH
#define RecubrimientoH

#include "Obstaculo.h"
#include "Lapiz.h"
//---------------------------------------------------------------------------
const int MAX_RECUBRIMIENTO = 304;
const int MAX_ANGULO = 100;

class Recubrimiento : public Obstaculo{
        public:
                PV2D* vertices[MAX_RECUBRIMIENTO];
                bool interseccion(PV2D* P, PV2D* direccion, double &thit, PV2D* &normalIn);
                void draw();
                Recubrimiento(double rad, PV2D* v0, PV2D* v1, PV2D* v2);
                double modulo(PV2D* v);
                PV2D* normal[MAX_RECUBRIMIENTO];
                double velocidad;

        private:
                bool cyrusBeck(PV2D* P, PV2D* direccion, double &tIn, PV2D* &normalIn);
};


#endif
