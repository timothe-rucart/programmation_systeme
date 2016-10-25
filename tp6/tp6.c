#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tp6.h"

/*  fd descripteur du fichier     val est le buffer qui contient les donnes que tu lies  */
int lire_deux_octets(int fd, uint16 *val){
	return (read(fd,val,2))==2;
}

int lire_quatre_octets(int fd, uint32 *val){
	return (read(fd,val,4)==4;
}

int lire_entete(int de, entete_bmp *entete){

	/* entete fichier */	
	if((lire_deux_octets(de, &entete->fichier.signature))==-1){return -1; }
	if((lire_quatre_octets(de,&entete->fichier.taille_fichier))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->fichier.reserve))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->fichier.offset_donnees))==-1){return -1;}

	/* entete bmp */
	if(lire_quatre_octets(de,&entete->bitmap.taille_entete))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->bitmap.largeur))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->bitmap.hauteur))==-1){return -1;}
	if(lire_deux_octets(de,&entete->bitmap.nomber_plans))==-1){return -1;}
	if(lire_deux_octets(de,&entete->bitmap.profondeur))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->bitmap.compression))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->bitmap.taille_donnees_image))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->bitmap.resolution_horizontale))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->bitmap.resolution_verticale))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->bitmap.taille_palette))==-1){return -1;}
	if(lire_quatre_octets(de,&entete->bitmap.nombre_de_couleurs_importantes))==-1){return -1;}

	return 0;
}

int lire_deux_octets(int fd, uint16 *val){}

int lire_quatre_octets(int fd, uint32 *val){}

