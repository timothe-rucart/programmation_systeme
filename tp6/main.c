#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "funct.h"

int main(int argc, char * argv[]){
	
  int j;
  int fd;
  int vers;
  entete_bmp entete;
  unsigned char *pixels;

  if(argc < 3){
    printf("Wrong number of parameters\n");
    printf("Usage: %s <bmp file> <bmp file>\n", argv[0]);
    return -1;
  }

  fd = open(argv[argc-2], O_RDONLY);

  if (fd == -1){
    perror(argv[1]);
    return -1;
  }

  lire_entete(fd,&entete);
  if(verifier_entete(&entete) == 0 ){
    perror(argv[1]);
    return -1;
  }

  pixels = allouer_pixels(&entete);
  lire_pixels(fd, &entete, pixels);

  if ((vers = open(argv[argc-1], O_WRONLY | O_CREAT | O_RDONLY, 0666 )) == -1){
    perror(argv[1]);
    return -1;
  }

  
  
  

  if (fd == -1){
    perror(argv[2]);
    return -1;
  }
	
  for ( j = 1; j < argc-2; j++) {
		
    if (argv[j][0] == '-' && argv[j][1] == 'r'){
      rouge(&entete, pixels);
    } else if (argv[j][0] == '-' && argv[j][1] == 'n'){
      negatif(&entete, pixels);
    } else if (argv[j][0] == '-' && argv[j][1] == 'b'){
      noir_et_blanc(&entete, pixels);
    } else if (argv[j][0] == '-' && argv[j][1] == 's'){
      moitie(&entete, pixels, 1);
    } else if (argv[j][0] == '-' && argv[j][1] == 'i'){
      moitie(&entete, pixels, 8);
    }
  }

 

  //affichage(&entete);
  ecrire_entete(vers,&entete);
  ecrire_pixels(vers,&entete,pixels);

  free(pixels);

  return 0;
}
