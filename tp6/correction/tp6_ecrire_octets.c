#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tp6_typedef.h"
#include "tp6_functions.h"

int ecrire_deux_octets(int fd, uint16 val) {
	return write(fd, &val, 2);
}

int ecrire_quatre_octets(int fd, uint32 val) {
	return write(fd, &val, 2);
}

int ecrire_entete(int fd, entete_bmp *bmp) {
	//écriture entete_fichier
	if (ecrire_deux_octets(fd, (bmp->fichier.signature)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->fichier.taille_fichier)) == -1) {return -1;} 
	if (ecrire_quatre_octets(fd, (bmp->fichier.reserve)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->fichier.offset_donnees)) == -1) {return -1;}

	//écriture entete_bitmap
	if (ecrire_quatre_octets(fd, (bmp->bitmap.taille_entete)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->bitmap.largeur)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->bitmap.hauteur)) == -1) {return -1;}
	if (ecrire_deux_octets(fd, (bmp->bitmap.nombre_plans)) == -1) {return -1;}
	if (ecrire_deux_octets(fd, (bmp->bitmap.profondeur)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->bitmap.compression)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->bitmap.taille_donnees_image)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->bitmap.resolution_horizontale)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->bitmap.resolution_verticale)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->bitmap.taille_palette)) == -1) {return -1;}
	if (ecrire_quatre_octets(fd, (bmp->bitmap.nombre_de_couleurs_importantes)) == -1) {return -1;}
	return 1;
}