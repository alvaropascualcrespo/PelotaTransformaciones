//---------------------------------------------------------------------------

#ifndef EscenaH
#define EscenaH
//---------------------------------------------------------------------------

#include "Obstaculo.h"
#include "Pelota.h"

const int MAX_OBSTACULOS = 35;
class Escena{

        public:

        Obstaculo *obstaculos[MAX_OBSTACULOS];
        int nObstaculos;
        Pelota *pelota;

        Escena(Pelota *p){pelota = p; nObstaculos = 0;};
        ~Escena(){ delete pelota; for(int i =0; i<nObstaculos; i++) delete obstaculos[i];};
        void step();
        void draw();
        void aniadirObstaculo(Obstaculo *o);


};


#endif
