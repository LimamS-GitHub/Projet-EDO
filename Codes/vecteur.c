#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"

Vecteur_t somme_vecteur(Vecteur_t u, Vecteur_t v)
{
	Vecteur_t w;

	w.d = u.d;
	for (int i = 0 ; i < w.d ; i++)
	{
		w.x[i] = u.x[i] + v.x[i];
	}

	return w;
}

Vecteur_t produit_vecteur(double lambda, Vecteur_t u)
{
	Vecteur_t v;

	v.d = u.d;
	for (int i = 0 ; i < v.d ; i++)
	{
		v.x[i] = lambda*u.x[i];
	}

	return v;
}