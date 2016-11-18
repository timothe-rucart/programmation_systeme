typedef unsigned short uint16;
typedef unsigned short uint32;

typedef struct 
{
	uint16 signature; 
	uint32 taille_fichier;
	uint32 reserve;
	uint32 offset_donnees;
} entete_fichier;

typedef struct
{
	uint32 taille_entete;
	uint32 largeur;
	uint32 hauteur;
	uint16 nombre_plans;
	uint16 profondeur;
	uint32 compression;
	uint32 taille_donnees_image;
	uint32 resolution_horizontale;
	uint32 resolution_verticale;
	uint32 taille_palette; /* en nombre de couleurs */
	uint32 nombre_de_couleurs_importantes; /* 0 */
} entete_bitmap;

typedef struct
{
	entete_fichier fichier;
	entete_bitmap bitmap;
} entete_bmp;