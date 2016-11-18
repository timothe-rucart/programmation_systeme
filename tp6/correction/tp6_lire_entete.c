#include <stdio.h>
#include "tp6_typedef.h"
#include "tp6_functions.h"

int lire_entete(int de, entete_bmp *entete) {
	
	//lecture entete_fichier
	if (lire_deux_octets(de, &(entete->fichier.signature)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->fichier.taille_fichier)) == -1) {return -1;} 
	if (lire_quatre_octets(de, &(entete->fichier.reserve)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->fichier.offset_donnees)) == -1) {return -1;}

	//lecture entete_bitmap
	if (lire_quatre_octets(de, &(entete->bitmap.taille_entete)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->bitmap.largeur)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->bitmap.hauteur)) == -1) {return -1;}
	if (lire_deux_octets(de, &(entete->bitmap.nombre_plans)) == -1) {return -1;}
	if (lire_deux_octets(de, &(entete->bitmap.profondeur)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->bitmap.compression)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->bitmap.taille_donnees_image)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->bitmap.resolution_horizontale)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->bitmap.resolution_verticale)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->bitmap.taille_palette)) == -1) {return -1;}
	if (lire_quatre_octets(de, &(entete->bitmap.nombre_de_couleurs_importantes)) == -1) {return -1;}
	
	return 0;
}