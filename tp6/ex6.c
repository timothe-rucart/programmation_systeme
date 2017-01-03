#include "funct.h"
#include <string.h>

int taille_ligne(const entete_bmp *entete){
  int taille = (entete->bitmap.largeur) * 3;
  int bourrage = 0;
  if (taille % 4 != 0){
    bourrage = 4 - (taille % 4);
  }
  return taille + bourrage;
}

int taille_image(const entete_bmp *entete){
  return entete->bitmap.hauteur * taille_ligne(entete);
}

void rouge(entete_bmp *entete, unsigned char *pixels){
  
  int y;
  int x;
  int hauteur = entete->bitmap.hauteur;
  int largeur = entete->bitmap.largeur;
  int taille_ligne = largeur*3;
  while(taille_ligne%4 !=0) taille_ligne++;	

  for(y=0; y<hauteur;y++){
    for(x=0;x<largeur;x++){
      int ind = y*taille_ligne + x*3;
      pixels[ind]=0;
      pixels[ind+1]=0;
    }
  }
}

void negatif(entete_bmp *entete, unsigned char *pixels){
 unsigned int i = 0;

  for (i = 0; i < (entete->bitmap.taille_donnees_image) ;i++)
    pixels[i] = ~pixels[i];
}


void noir_et_blanc(entete_bmp *entete, unsigned char *pixels){
  unsigned int i=0;
  for (i = 0; i < (entete->bitmap.taille_donnees_image)-3 ;i+=3){
    int m = (pixels[i]+pixels[i+1]+pixels[i+2])/3;
    pixels[i] = m;
    pixels[i+1] = m;
    pixels[i+2] = m;
  }
}

void moitie(entete_bmp *entete, unsigned char *pixels, int sup){


  int h = entete->bitmap.hauteur/2;
  int hauteur = entete->bitmap.hauteur;
  int dataSize = taille_ligne(entete) * h;
  entete->bitmap.hauteur = h;
  entete->bitmap.taille_donnees_image = dataSize;
  entete->fichier.taille_fichier = dataSize + entete->fichier.offset_donnees;
  if (sup != 1){
    return;
  }
  unsigned char *psup = pixels + (hauteur - h)*taille_ligne(entete);
  memmove(pixels, psup, h*taille_ligne(entete));}