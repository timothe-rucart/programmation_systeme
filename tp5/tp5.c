#include <stdio.h>
#include <stdlib.h>  /* pour pouvoir utiliser malloc */
#include <string.h>   // pour pouvoir utiliser strlen
#include <ctype.h>	  // permet d'utiliser issuper, islower, isspace etc
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tp5.h"

#define BUFFER_SIZE 80

int traiter (int f, int *car, int *mots, int *lig){
	char buf[BUFFER_SIZE];	
	int i = 0;
	int mot = 0; 	// boolean si on est dans un mot
	int n;
	*car = 0;
  	*lig = 0;
  	*mots = 0;

	while((n=read(f,buf,80*sizeof(char)))>0) {		// n reçois le nombre d'octets lu
		while(i<n){
			(*car)++;

			if(! mot && !isspace(buf[i])){         //si il n'y a tj pas de mot et non-espace
				(*mots)++;
			}
			
			if (isspace(buf[i])) {				   //si il  espace c'est que c'est la fin d'un mot
				mot=0;
												  //augmentation du nombre de caractere
      		}
      		
      		else {								  // sinon c'est que c'est le debut d'un mot
				mot=1;
												  //augmentation du nombre de caractere
      		}

      		
      		if(buf[i] == '\n') {			 	  //si c'est un retour a la ligne alors nouvelle ligne
	
				(*lig)++;
	     		}

     		i++;
    	}
    	i=0;
 	}
    return 0;		
}