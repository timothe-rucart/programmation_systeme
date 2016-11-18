#include <stdio.h>
#include "tp6_typedef.h"
#include "tp6_functions.h"

void affichage_entete(entete_bmp *bmp) {

	printf("Entete fichier : \n");
	printf("Signature : %d\n", bmp->fichier.signature );
	printf("Taille Fichier : %d\n", bmp->fichier.taille_fichier );
	printf("Reserve :%d\n", bmp->fichier.reserve );
	printf("offset_donnees %d\n", bmp->fichier.offset_donnees );

	printf("Entete bitmap : \n");
	printf("taille_entete %d\n", bmp->bitmap.taille_entete );
	printf("largeur %d\n", bmp->bitmap.largeur );
	printf("hauteur %d\n", bmp->bitmap.hauteur );
	printf("nombre_plans %d\n", bmp->bitmap.nombre_plans );
	printf("profondeur %d\n", bmp->bitmap.profondeur );
	printf("compression %d\n", bmp->bitmap.compression );
	printf("taille_donnees_image %d\n", bmp->bitmap.taille_donnees_image);
	printf("resolution_horizontale %d\n", bmp->bitmap.resolution_horizontale);
	printf("resolution_verticale %d\n", bmp->bitmap.resolution_verticale);
	printf("taille_palette %d\n", bmp->bitmap.taille_palette);
	printf("nombre_de_couleurs_importantes %d\n", bmp->bitmap.nombre_de_couleurs_importantes );

}