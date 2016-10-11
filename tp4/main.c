#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // pour pouvoir utiliser strlen
#include "tp4.h"
#include <unistd.h>


int main(int argc, char ** argv){

	int i=0;
	int m=0;
	int s=0;
	int arg=0;
	char * mir ;
	char * sai ;

	char chaines1 [] = "-m";
	char chaines2 [] = "-s";
	char chaines3 [] = "-ms";
	char chaines4 [] = "-sm";


			for (i=1; i<argc; i++) {
				/*if (strchr(argv[i], '-')!=NULL && strchr(argv[i], 'm')!=NULL) {
					m=1;
				}
				if (strchr(argv[i], '-')!=NULL && strchr(argv[i], 's')!=NULL) {
					s=1;
				}
				if (strchr(argv[i], '-')==NULL && arg==0) {
					arg=i;
				} */
				if (strcmp(argv[i],chaines1) ==0){
					m++;
				}
				if (strcmp(argv[i],chaines2) ==0){
					s++;
				}
				 if (strcmp(argv[i],chaines3) ==0  || (strcmp(argv[i], chaines4)==0)){
					s++;
					m++;					
				}
				if (strchr(argv[i],'-')==NULL && arg == 0){
					arg = i;
				}

			}


			if (m && !s) { //Si just m est prÃ©sent	
			if(arg != 0){
				mir = miroir(argv[arg]);
				printf("%s\n", mir);
				free(mir);
			}
			else
				printf("pas de mot a retourner en parametre\n");

			} else if (s && !m) {
				printf("%s\n", saisie());

			} else if (s && m){ 				
				sai = saisie();
				mir = miroir(sai);
				printf("%s\n", mir);
				free(sai);
				free(mir);
			} else {
				printf ("mauvaise utilisation \n");
			}
		

	
	return 0;
}
