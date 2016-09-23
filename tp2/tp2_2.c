#include <stdio.h>

struct rat
{
	int den;
	int num;

}r1,r2,r3;

 struct rat rat_produit(struct rat n1, struct rat n2){
	struct rat res ;
	res.den = n1.den * n2.den;
	res.num = n1.num * n2.num;
	return res;
}









int main(void){
	struct rat r1 = {2,3};
	struct rat r2 = {2,2};
	rat_produit(r1,r2);
	int n = rat_produit(r1,r2).den;
	//struct rat r3 = {rat_produit(r1,r2).den,rat_produit(r1,r2).num};
	
	//printf()
	return 0;
}