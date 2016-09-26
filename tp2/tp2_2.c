#include <stdio.h>
#include "tp2_2.h"



 
struct rat rat_produit(struct rat n1, struct rat n2){
	struct rat res ;
	res.den = n1.den * n2.den;
	res.num = n1.num * n2.num;
	return res;
}


struct rat rat_somme(struct rat n1, struct rat n2){
	struct rat res;
	if(n1.den == n2.den){
		res.num = n1.num + n2.num;
		res.den = n1.den;
	}else{
		res.num = n1.den * n2.num + n1.num *n2.den;
		res.den = n1.den * n2.den;
	}
	return res;

}


struct rat rat_plus_petit(struct rat list[]){
	struct rat min = list[0];
	int i = 0;

	while (list[i].den != 0 ){	
		if(min.den/min.num > list[i].den/list[i].num){
			min.den = list[i].den;
			min.num = list[i].num;
		}	
		i++;
	}	
	return min;
}


void afficher(struct rat r3){
	printf("%d / %d \n",r3.num,r3.den);

}