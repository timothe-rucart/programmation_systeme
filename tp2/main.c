#include <stdio.h>
#include "tp2_2.h"

int main(void){
	/*struct rat r1 = {3,2};
	struct rat r2 = {2,1};
	struct rat r3 = {5,2};*/
	struct rat list[3];

	int i;

	for(i=0 ; i<2 ; i++){
		list[i].den = i+4;
		list[i].num = i+5;		
	}
	
	list[2].den =0; 
	list[2].num=1;


	struct rat r4 = rat_plus_petit(list);
	afficher(r4);	
	
	return 0;



	/*
	*** tp_1

	int tab1[5] = {1,2,3,4,5};
	int dest[10];	

	afficher(tab1,sizeof(tab1)/sizeof(tab1[0]));
	ajoute_apres(dest,5,tab1,5);
	afficher(dest,sizeof(dest)/sizeof(dest[0]));
	
	return 0;
	*/
}