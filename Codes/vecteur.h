#ifndef VECTEUR_H
#define VECTEUR_H

#define TAILLE_MAX 10

typedef struct Vecteur_s
{
	int d;
	double x[TAILLE_MAX];
}Vecteur_t;

Vecteur_t somme_vecteur(Vecteur_t u, Vecteur_t v); /* u et v doivent avoir la même taille */
Vecteur_t produit_vecteur(double lambda, Vecteur_t u);

#endif