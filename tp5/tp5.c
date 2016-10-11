#include <stdio.h>
#include <stdlib.h>  /* pour pouvoir utiliser malloc */
#include <string.h>   // pour pouvoir utiliser strlen
#include <ctype.h>	  // permet d'utiliser issuper, islower, isspace etc
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tp5.h"

int traiter (int f, int *car, int *mot, int *lig){
	int BUFFER_SIZE = 80;
	char buf[BUFFER_SIZE];
	int i = 0;
	int mot = 0;
	int n;


	while((n=read(f,buf,80*sizeof(char)))>0) {
		while(i<n)
	}



}