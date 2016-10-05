#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // pour pouvoir utiliser strlen
#include "tp4.h"

int main(void){

	char *s = "coucou";
	printf("%s\n",miroir(s) );
	printf("%s \n",saisie());
	return 0;
}