//Lecture
int lire_deux_octets(int fd, uint16 *val);
int lire_quatre_octets(int fd, uint32 *val);
int lire_entete(int de, entete_bmp *entete);
void affichage_entete(entete_bmp *bmp);
//Ecriture
int ecrire_deux_octets(int fd, uint16 val);
int ecrire_quatre_octets(int fd, uint32 val);
int ecrire_entete(int fd, entete_bmp *bmp);
//Verification
int verifier_entete(entete_bmp *bmp);
//Pixels
unsigned char* allouer_pixels(entete_bmp *entete);
int lire_pixels(int fd, entete_bmp *entete, unsigned char *pixels);
int ecrire_pixels(int fd, entete_bmp *entete, unsigned char *pixels);