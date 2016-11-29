#include "funct.h"
#include <stdio.h>

/*retourne 1 si c'est  un fichier bmp de profondeur 24*/
int verifier_entete(entete_bmp *entete){
  if (entete->bitmap.profondeur == 24)
    return 1;
  perror("ERROR: Profondeur fausse");
  return 0;
}