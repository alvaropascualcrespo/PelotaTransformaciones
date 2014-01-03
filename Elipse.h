//---------------------------------------------------------------------------

#ifndef ElipseH
#define ElipseH
//---------------------------------------------------------------------------
#include "Obstaculo.h"
#include "Circulo.h"

const int MAX_LADOS_ELIPSE = 500;

class Elipse : public Obstaculo{

        public:
                PV2D* centro;
                GLdouble ancho;
                GLdouble alto;
                Circulo* circulo;
                bool interseccion(PV2D* P, PV2D* direccion, double &thit, PV2D* &normalIn){};
                void draw();
                bool pintable;
                Elipse(){};
                Elipse(PV2D* cent, double alt, double anc, bool pint);
        private:

};

#endif
