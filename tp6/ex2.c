#include "funct.h"
#include <stdio.h>
#include <unistd.h>

int ecrire_deux_octets(int fd, uint16 *val){
  if(fd == -1) 
    return -1;
  return(write(fd, val, 2));

}

int ecrire_quatre_octets(int fd, uint32 *val){
  if(fd == -1)
    return -1;
    return(write(fd, val, 4)); 
}

int ecrire_entete(int vers, entete_bmp *entete){
  if(ecrire_deux_octets(vers,&(entete->fichier.signature)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->fichier.taille_fichier)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->fichier.reserve)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->fichier.offset_donnees)) ==-1) return -1;
  // entete bitmap
  if(ecrire_quatre_octets(vers,&(entete->bitmap.taille_entete)) ==-1) return -1;  
  if(ecrire_quatre_octets(vers,&(entete->bitmap.largeur)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->bitmap.hauteur)) ==-1) return -1;
  if(ecrire_deux_octets(vers,&(entete->bitmap.nombre_plans)) ==-1) return -1;
  if(ecrire_deux_octets(vers,&(entete->bitmap.profondeur)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->bitmap.compression)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->bitmap.taille_donnees_image)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->bitmap.resolution_horizontale)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->bitmap.resolution_verticale)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->bitmap.taille_palette)) ==-1) return -1;
  if(ecrire_quatre_octets(vers,&(entete->bitmap.nombre_de_couleurs_importantes)) ==-1) return -1;
  
  return 0;
}

