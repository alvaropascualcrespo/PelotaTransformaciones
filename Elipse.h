//---------------------------------------------------------------------------
#include "Obstaculo.h"
#include "Circulo.h"

#ifndef ElipseH
#define ElipseH
//---------------------------------------------------------------------------
class Elipse : public Obstaculo{

        public:
                PV2D* centro;
                double ancho;
                double alto;
                Circulo* circulo;
                bool interseccion(PV2D* P, PV2D* direccion, double &thit, PV2D* &normalIn);
                void draw();
        private:

};

#endif
