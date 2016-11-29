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
  
  int dataSize = entete->bitmap.taille_donnees_image;
  int hauteur = entete->bitmap.hauteur;
  int i = 0;
  int j = 0;
  int newSize = 0;

  if (dataSize % 2 == 0){
    newSize = (dataSize / 2);
  }else{
    newSize = (dataSize / 2);
    newSize = (dataSize - newSize);
  }
  for(i = ((sup != 1) ? (0) : (newSize)); i < ((sup != 1) ? (newSize) : (dataSize)); i++)
    {
      pixels[j] = pixels[i];
      j++;
    }
  entete->bitmap.taille_donnees_image = newSize;
  hauteur = (hauteur / 2);
  if (hauteur % 2 != 0){
    hauteur = (entete->bitmap.hauteur - hauteur);
  }
  entete->bitmap.hauteur = hauteur;
  entete->fichier.taille_fichier = newSize + entete->bitmap.taille_entete + (entete->fichier.offset_donnees - entete->bitmap.taille_entete);
}


/*void moitie(entete_bmp *entete, unsigned char *pixels, int sup){
  int hauteurNew = entete->bitmap.hauteur/2;
  int dataSize = taille_ligne(entete) * hauteurNew;
  entete->bitmap.hauteur = hauteurNew;
  entete->bitmap.taille_donnees_image = dataSize;
  entete->fichier.taille_fichier = dataSize + entete->fichier.offset_donnees;
  if (!sup)
    return;
  unsigned char *psup = pixels + (entete->bitmap.hauteur - hauteurNew)*taille_ligne(entete);
  memcpy(pixels, psup, hauteurNew*taille_ligne(entete));
}*/