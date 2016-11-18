#include <stdio.h>
#include "tp6_typedef.h"
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

int lire_deux_octets(int fd, uint16 *val) {
	return read(fd, val, 2);
}

int lire_quatre_octets(int fd, uint32 *val) {
	return read(fd, val, 4);
}