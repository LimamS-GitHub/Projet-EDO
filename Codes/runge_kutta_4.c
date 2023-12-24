#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"
#include "runge_kutta_4.h"

Vecteur_t* runge_kutta_4(double T, int N, Vecteur_t y0, Vecteur_t (*f)(double t, Vecteur_t y))
{
	Vecteur_t* y = NULL;
	y = (Vecteur_t*)malloc((N + 1)*sizeof(Vecteur_t));
	if (NULL == y)
	{
		printf("Erreur lors de l'allocation memoire\n");
		exit(EXIT_FAILURE);
	}

	double h = T/N;
	double t = 0;

	y[0] = y0;
	for (int n = 0 ; n < N ; n++)
	{
		Vecteur_t k1 = (*f)(t, y[n]);
		Vecteur_t k2 = (*f)(t + h/2, somme_vecteur(y[n], produit_vecteur(h/2, k1)));
		Vecteur_t k3 = (*f)(t + h/2, somme_vecteur(y[n], produit_vecteur(h/2, k2)));
		Vecteur_t k4 = (*f)(t + h, somme_vecteur(y[n], produit_vecteur(h, k3)));
		y[n + 1] = somme_vecteur(y[n], produit_vecteur(h/6, somme_vecteur(k1, somme_vecteur(produit_vecteur(2, k2), somme_vecteur(produit_vecteur(2, k3), k4)))));
		t += h;
	}

	return y;
}