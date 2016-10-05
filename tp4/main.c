#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // pour pouvoir utiliser strlen
#include "tp4.h"
#include <unistd.h>


int main(int argc, char ** argv){

	/*char tab [] = "ms"; // tableau avec les options disponibles
	char * s1;
	int c=0;
	int m=0;
	int s=0;

	close(2);
	printf("%d \n",getopt(argc, argv, tab));

	while( (c == getopt(argc, argv, tab)) != EOF){
		
		if((char) c == 'm' && !m)
			m=1;
		if((char) c == 's' && !s)
			s=1;
	}
	printf("%d  %d\n",m,s );

		if(m && s)
			printf("%s\n",miroir(saisie()) );
		else if(s)
			printf("%s\n",saisie() );
		else if(m){
			s1 = argv[optind];
			if(s1 =='\0')
				printf("mauvaise utilisation");
			else
				printf("%s\n",miroir(s1) );
		}
		else 
			printf("mauvaise utilisation");
	return 0;*/



			/*char *s= "Sidious";

	printf("%s\n", miroir(s));
	printf("%s\n", saisie());
	return 0;*/

	int i=0;
	int m=0;
	int s=0;
	int arg=0;

	for (i=1; i<argc; i++) 
	{
		/*if 
		{
			printf("mauvaise utilisation\n");
			return 1;
		} else {*/

			for (i=1; i<argc; i++) {
				if (strchr(argv[i], '-')!=NULL && strchr(argv[i], 'm')!=NULL) {
					m=1;
				}
				if (strchr(argv[i], '-')!=NULL && strchr(argv[i], 's')!=NULL) {
					s=1;
				}
				if (strchr(argv[i], '-')==NULL && arg==0) {
					arg=i;
				} 
			}

			if (m && !s) { //Si just m est prÃ©sent	
			printf("%s\n", miroir(argv[arg]));
			

			} else if (s && !m) {
				printf("%s\n", saisie());

			} else if (s && m){ 				
				char *s1 = saisie();
				printf("%s\n", miroir(s1));
			} else {
				printf ("mauvaise utilisation");
			}
		}

	
	return 0;
}
