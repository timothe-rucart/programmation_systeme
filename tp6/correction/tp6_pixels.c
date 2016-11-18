#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "tp6_typedef.h"
#include "tp6_functions.h"

unsigned char* allouer_pixels(entete_bmp *entete) {
	int pixelsSize = entete->bitmap.taille_donnees_image;
	printf("%d\n", pixelsSize);
	unsigned char * pixels= malloc(pixelsSize);
	return pixels; 
}

int lire_pixels(int fd, entete_bmp *entete, unsigned char *pixels) {
	return read(fd, pixels, entete->bitmap.taille_donnees_image);
}

int ecrire_pixels(int fd, entete_bmp *entete, unsigned char *pixels) {
	return write(fd, pixels, entete->bitmap.taille_donnees_image);
}