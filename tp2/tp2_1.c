#include <stdio.h>

void afficher(int liste[], int taille){
	int i=0;
	for(i=0 ; i<taille ; i++){
		printf("%d\n ",liste[i] );
	}	
	printf("\n " );
}

int somme (int liste[], int taille){
	int somme =0;
	int i=0;
	for(i=0; i<taille;i++){
		somme +=liste[i];
	}
	return somme;

}


void copie_dans(int dest[], int src[], int taille){
	int i=0;
	for(i=0 ; i<taille ; i++){
		dest[i]=src[i];
	}
}

void ajoute_apres(int dest[], int taille_dest, int src[], int taille_src){
	int i = taille_dest;
	for (i = taille_dest ; i<taille_dest + taille_src ; i++){
		dest[i] = src[i - taille_dest];		
	}
}


int main(void){
	int tab1 [5] = {1,2,3,4,5};
	int dest[10];		
	afficher(tab1,sizeof(tab1)/sizeof(tab1[0]));
	ajoute_apres(dest,5,tab1,5);
	afficher(dest,sizeof(dest)/sizeof(dest[0]));
	return 0;
}