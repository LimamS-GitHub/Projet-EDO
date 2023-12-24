#include "vecteur.h"
#include <math.h>
#include "f.h"

extern double l;

Vecteur_t f(double t, Vecteur_t y) // d = 2
{
	Vecteur_t z;
	z.d = y.d;
	z.x[0] = y.x[1];
	z.x[1] = -g/l*sin(y.x[0]);

	return z;
}