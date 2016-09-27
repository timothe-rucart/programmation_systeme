#include <stdio.h>
#include "tp3.h"

int mon_strlen(char s[]){
	
	int cpt = 0; 
	while(s[cpt]!= '\0'){
		cpt ++;
	}
	return cpt;
}

int mon_strlen2(const char *s){

	int i = 0;

 	while (*(s+i) != '\0') {
  		i++;
  	}
  	return i;
 }


int mon_strcmp(const char * s1, const char * s2){

	int ts1 = mon_strlen2(s1);
	int ts2 = mon_strlen2(s2);
	int i=0;
	int cmp=0;
	
	while( i<ts1 && i<ts2 && cmp ==0){
		if(*(s1+i)> *(s2+i))
			cmp ++;
		else if( *(s1+i) < *(s2+i))
			cmp --;
		i++;
	}

	return cmp;
 }