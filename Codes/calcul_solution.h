#ifndef CALCUL_SOLUTION_H
#define CALCUL_SOLUTION_H

#include "vecteur.h"

Vecteur_t* approximation_solution(double T, int N, Vecteur_t y0);
void ecrire_solution(double T, int N, Vecteur_t* y, FILE* fichier);
void lire_donnees(double* T, double* theta0, int* N, FILE* fichier);

#endif