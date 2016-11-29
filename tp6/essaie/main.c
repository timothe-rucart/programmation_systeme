#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 
#include "tp6.h"

int main(int argc, char *argv[])
{
  entete_bmp entete;

  int fd = open("test.bmp", O_RDONLY);


  // si c'est bien un fichier bmp
  if(lire_entete(fd, &entete) == -1)
  {
    perror("Erreur lecture entete");
    return -1;
  }

  printf("Lecture entete : \n");
  // Lecture entete fichier
  printf("Signature : 0x%x \n", entete.fichier.signature);
  printf("Taille fichier : %d bytes \n", entete.fichier.taille_fichier);
  printf("Reserve : %d \n", entete.fichier.reserve);
  printf("DataOffset : %x \n", entete.fichier.offset_donnees);

  // Lecture entete bmp
  printf("Taille entete : %d \n", entete.bitmap.taille_entete);
  printf("Taille Image : %dx%d \n", entete.bitmap.largeur, entete.bitmap.hauteur);
  printf("Nombre plans : %d \n", entete.bitmap.nombre_plans);
  printf("Profondeur : %d \n", entete.bitmap.profondeur);
  printf("Compression : %d \n", entete.bitmap.compression);
  printf("Taille donnees image : %d bytes \n", entete.bitmap.taille_donnees_image);
  printf("Resolution : %dx%d ppm\n", entete.bitmap.resolution_horizontale, entete.bitmap.resolution_verticale);
  printf("Taille palette : %d \n", entete.bitmap.taille_palette);
  printf("Nombre de couleurs importantes : %d \n", entete.bitmap.nombre_de_couleurs_importantes);

  

  int input = open("test.bmp", O_RDONLY);
  int output = open("retour.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  printf("rest\n"); 

  if (input != -1 && output != -1) {
    
    unsigned char *pixels;

    lire_entete(input, &entete);
    pixels = allouer_pixels(&entete);

    lire_pixels(input, &entete, pixels);

    if (argc > 1) {

      int i;
      for (i = 1; i < argc; i++) { 

  if (argv[i][0] == '-') { 
    unsigned int j;
    for (j = 1; j < strlen(argv[i]); j++) {
      
      switch (argv[i][j]) { 
      case 'r':
        rouge(&entete, pixels);
        break;
      case 'n':
        negatif(&entete, pixels);
        break;
      case 'b':
        noir_blanc(&entete, pixels);
        break;
      case 's':
        moitie(&entete, pixels, 1);
        break;
      case 'i':
        moitie(&entete, pixels, 0);
        break;
      }
    }
  }
  else {
    return 1;
  }

      }
    }

    ecrire_entete(output, &entete);
    ecrire_pixels(output, &entete, pixels);

    free(pixels);

    close(input);
    close(output);
    return 0;
  }
}