#include <stdio.h>
#include <stdlib.h>  /* pour pouvoir utiliser malloc */
#include <string.h>   // pour pouvoir utiliser strlen
#include <ctype.h>
#include "tp4.h"

char * miroir (const char *s){

	char* res;
	int i = strlen(s);
	int j;
	res = malloc(i*sizeof(char)+1);
	for(j=i ; j>0 ;j--){
		res[i-j]=s[j-1];
	}
	res[i]='\0';
	return res;
}

char * saisie (){

	char clavier ='a';
	int n = 128;
	char * res  = malloc(n);
	int i = 0;

	while( !isspace(clavier)){
		clavier = getchar();
		res[i] = clavier;
		i++;		
		if(i==n){
			n *= 2;
			res= realloc(res,n);
		}

	}
	res = realloc(res,i+1);
	res[i] = '\0';
	return res;
}