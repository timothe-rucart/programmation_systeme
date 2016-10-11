#include <stdio.h>
#include "tp5.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void){

	int n;
	int m;


	n = open("cac",O_RDONLY) ;
	m = open("salut",O_RDONLY);
	printf("%d\n", n );
	printf("%d\n", m );
	return 0;
}
