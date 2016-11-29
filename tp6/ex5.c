#include "funct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int lire_pixels(int de, entete_bmp *entete, unsigned char *pixels){
  int res;
  lseek(de,entete->fichier.offset_donnees,SEEK_SET);
  res = read(de,pixels,entete->bitmap.taille_donnees_image);
  return res;
}



int ecrire_pixels(int vers, entete_bmp *entete, unsigned char *pixels){
  int res;
  lseek(vers,entete->fichier.offset_donnees,SEEK_SET);  
  res = write(vers,pixels,entete->bitmap.taille_donnees_image);
  return res;
}

int copier_bmp(int de, int vers){
  entete_bmp entete;
  unsigned char *pixels;
  /* lecture du fichier source */
  lire_entete(de, &entete);
  pixels = allouer_pixels(&entete);
  lire_pixels(de, &entete, pixels);
  /* écriture du fichier destination */
  ecrire_entete(vers, &entete);
  ecrire_pixels(vers, &entete, pixels);
  /* on libère les pixels */
  free(pixels);
  return 1; /* on a réussi */
}
