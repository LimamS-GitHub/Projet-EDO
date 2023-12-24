#include <stdio.h>
#include <stdlib.h>
#include "recuperation_donnees.h"

int main()
{
	double T;
	int N;
	double theta0;
	double l;

	FILE* fichier_entre = NULL;
	fichier_entre = fopen("donnees_entrees.txt", "w");
	if (NULL == fichier_entre)
	{
		printf("Erreur lors de l'ouverture du fichier donnees_entrees.txt\n");
		exit(EXIT_FAILURE);
	}

	printf("Veuillez saisir la valeur de T : ");
	scanf("%lf", &T);
	printf("Veuillez saisir la valeur de N : ");
	scanf("%d", &N);
	printf("Veuillez saisir la valeur de l'angle initial : ");
	scanf("%lf", &theta0);
	printf("Veuillez saisir la valeur de l : ");
	scanf("%lf", &l);

	fprintf(fichier_entre, "%lf %lf %lf %d", T, l, theta0, N);

	fclose(fichier_entre);

	return EXIT_SUCCESS;
}