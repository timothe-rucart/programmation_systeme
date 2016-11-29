#include "funct.h"
#include <stdlib.h>

unsigned char* allouer_pixels(entete_bmp *entete){
  long taille = entete->bitmap.taille_donnees_image;
  unsigned char* res = malloc(sizeof(char)*taille);
  return res;
}