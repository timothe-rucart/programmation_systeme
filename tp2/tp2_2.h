
struct rat
{
	int den;
	int num;

};
struct rat rat_produit(struct rat n1, struct rat n2);
struct rat rat_somme(struct rat n1, struct rat n2);
struct rat rat_plus_petit(struct rat list[]);
void afficher(struct rat r3);