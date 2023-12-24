#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"
#include "f.h"
#include "runge_kutta_4.h"
#include "calcul_solution.h"

double l;

int main()
{
	double T;
	int N;
	double theta0;

	FILE* fichier_entre = NULL;
	fichier_entre = fopen("donnees_entrees.txt", "r");
	if (NULL == fichier_entre)
	{
		printf("Erreur lors de l'ouverture du fichier donnees_entrees.txt\n");
		exit(EXIT_FAILURE);
	}

	FILE* fichier_sortie = NULL;
	fichier_sortie = fopen("donnees_sorties.txt", "w");
	if (NULL == fichier_sortie)
	{
		printf("Erreur lors de l'ouverture du fichier donnees_sorties.txt\n");
		exit(EXIT_FAILURE);
	}


	lire_donnees(&T, &theta0, &N, fichier_entre);


	Vecteur_t y0;
	y0.d = 2;
	y0.x[0] = theta0;
	y0.x[1] = 0;


	Vecteur_t* y = approximation_solution(T, N, y0);


	ecrire_solution(T, N, y, fichier_sortie);

	free(y);
	fclose(fichier_sortie);
	fclose(fichier_entre);

	printf("FIN\n");

	return EXIT_SUCCESS;
}

Vecteur_t* approximation_solution(double T, int N, Vecteur_t y0)
{
	return runge_kutta_4(T, N, y0, f);
}

void ecrire_solution(double T, int N, Vecteur_t* y, FILE* fichier)
{
	double h = T/N;
	double t = 0;
	for (int n = 0 ; n <= N ; n++)
	{
		fprintf(fichier, "%lf %lf\n", t, y[n].x[0]);
		t += h;
	}
}

void lire_donnees(double* T, double* theta0, int* N, FILE* fichier)
{
	fscanf(fichier, "%lf %lf %lf %d", T, &l, theta0, N);
}