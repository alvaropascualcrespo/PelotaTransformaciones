//---------------------------------------------------------------------------

#ifndef PV2DH
#define PV2DH
//---------------------------------------------------------------------------

#include <gl/GL.h>
#include <iostream>
using namespace std;

//const double PI = 3,1415926;

class PV2D{

	public:
		GLdouble x;
		GLdouble y;

	PV2D();
	PV2D(GLdouble xn, GLdouble yn);
	PV2D(const PV2D &p);
	~PV2D();
        PV2D * restaVertices(PV2D *v1);
        GLdouble dot(PV2D* v);
        void normalizar(){      GLdouble modulo = 1 / sqrt(pow(x,2) + pow(y,2));
                                x *= modulo;
                                y *= modulo;
                        };

};


#endif
