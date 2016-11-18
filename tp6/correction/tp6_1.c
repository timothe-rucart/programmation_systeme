#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tp6_typedef.h"
#include "tp6_functions.h"

int main(void) {
	char *filepath = "./flying.bmp";
	char *filepath2 = "./copie.bmp";
	unsigned char* pixels;
	
	entete_bmp bmp;
	entete_bmp bmp2;
	int f = open(filepath, O_RDONLY);
	int copy = open(filepath2, O_RDWR  | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);

	

	int error = lire_entete(f, &bmp);

	affichage_entete(&bmp);

	if (verifier_entete(&bmp)!=1) {
		printf("La profondeur n'est pas de 24 mais de %d\n", bmp.bitmap.profondeur);
		return -1;
	} 

	error = ecrire_entete(copy, &bmp);
	error = lire_entete(copy, &bmp2);
	if (error != -1) {
		pixels = allouer_pixels(&bmp);
	}
	if (error != -1) {error = lire_pixels(f, &bmp, pixels);}
	if (error != -1) {error = ecrire_pixels(copy, &bmp, pixels);}
	
	return error;
}