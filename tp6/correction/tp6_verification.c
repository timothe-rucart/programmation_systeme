#include <stdio.h>
#include "tp6_typedef.h"
#include "tp6_functions.h"

int verifier_entete(entete_bmp *bmp) {
	return (bmp->bitmap.profondeur==24);
}