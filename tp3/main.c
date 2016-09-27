#include <stdio.h>
#include "tp3.h"

int main(void){

	char s1[] = "salut";
	char s2[] = "salot";
	//printf("%d \n" ,mon_strlen(s1));

	
	const char * c1 = s1;
	const char * c2 = s2;
	//printf("%d\n", *s1 ); 	// donne le numero ascii
	//printf("%d \n",mon_strlen2(c1));

	//printf("%d\n",mon_strcmp(c1,c2) );
	printf("%d\n",mon_strncmp(c1,c2,4) );

	return 0;
}