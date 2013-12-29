//---------------------------------------------------------------------------

#ifndef LapizH
#define LapizH
//---------------------------------------------------------------------------

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "PV2D.h"

//#include <GL/glut.h>

#include <iostream>
using namespace std;
const double PI = 3.1415926536;

class Lapiz{

public:
	PV2D* pos;
	GLdouble dir;

	Lapiz();
	Lapiz(PV2D * p, GLdouble d);
	~Lapiz();
	void moveTo(PV2D* p, bool draw);
	void turnTo(GLdouble a);
	void turn(GLdouble a);
	void forward(GLdouble dist, bool draw);
        void lookAt(PV2D* p);


};


#endif
