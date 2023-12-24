#ifndef RUNGE_KUTTA_4_H
#define RUNGE_KUTTA_4_H

#include "vecteur.h"

Vecteur_t* runge_kutta_4(double T, int N, Vecteur_t y0, Vecteur_t (*f)(double t, Vecteur_t y));

#endif