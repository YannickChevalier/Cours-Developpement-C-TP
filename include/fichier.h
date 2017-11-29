#ifndef _FICHIER_H
#define _FICHIER_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "image.h"


void* xmalloc(size_t size){
	void* ptr=malloc(size);
	if(ptr==NULL)
		exit(0);
	return(ptr);
}

int fic_lire(const char* nom_fichier, char** p_fic) {
	int i_fic_taille, i_nb_octets_lus;
	int f_disk=open(nom_fichier, O_RDONLY);
	
	//teste si le fichier a bien été ouvert
	if(f_disk == -1)
		return(-1);
	
	//récupère la taille du fichier
	i_fic_taille = lseek(f_disk, 0, SEEK_END);
	lseek(f_disk, 0, SEEK_SET);
	
	//une zone mémoire de la taille du fichier est réservée
 	(*p_fic) = xmalloc(i_fic_taille);
 	
 	//lis le fichier
 	i_nb_octets_lus = read(f_disk, *p_fic, i_fic_taille);
 	if(i_nb_octets_lus != i_fic_taille){
 		free(*p_fic);
 		close(f_disk);
 		return(-4);
 	}
	
	//ferme le fichier après lecture
	close(f_disk);
	return(i_nb_octets_lus);
}


int fic_lire_ppm(const char* nom_fichier, unsigned char** img, int* nb_lignes, int* nb_cols) {
	char *ptr_buffeur;
	int ret = fic_lire(nom_fichier, &ptr_buffeur);

	// Vérification du format du fichier
    if (ptr_buffeur[0] != 'P' || ptr_buffeur[1] != '6') {
        fprintf(stderr, "Format invalide! (Doit être un PPM P6)\n");
        exit(1);
    }

    // Récupération taille matrice
    *nb_lignes = strtol(ptr_buffeur+2, &ptr_buffeur, 10);
    *nb_cols = strtol(ptr_buffeur, &ptr_buffeur, 10);

	*img = (unsigned char*) ptr_buffeur+5;

	return(ret);
}


int fic_lire_bmp(const char* nom_fichier, unsigned char** img, int* nb_lignes, int* nb_cols) {
	char *ptr_buffeur;
	int ptr_img;
	int i;
	int size_img;
	unsigned char tmp_pixel;
	int ret = fic_lire(nom_fichier, &ptr_buffeur);

	// Vérification du format du fichier
    if (ptr_buffeur[0] != 0x42 || ptr_buffeur[1] != 0x4D) {
        fprintf(stderr, "Format invalide! (Doit être un BMP)\n");
        exit(1);
    }

    // Récupération taille matrice
	*nb_lignes = abs(*(int *)(ptr_buffeur + 18));
    *nb_cols = abs(*(int *)(ptr_buffeur + 22));

	// Début de l'image en format raw
	ptr_img = *(int *)(ptr_buffeur+10);

	// Taille total de l'image raw
	size_img = (*nb_lignes) * (*nb_cols * 3);

	// Permute la valeur de R et de B pour obtenir RGB au lieu de BGR pour le bitmap
	for (i = 0; i < size_img ; i+=3) {
		tmp_pixel = *(ptr_buffeur + ptr_img + i);
		*(ptr_buffeur + ptr_img + i) = *(ptr_buffeur + ptr_img + i + 2);
		*(ptr_buffeur + ptr_img + i + 2) = tmp_pixel;
	}

	*img = (unsigned char*) ptr_buffeur + ptr_img;

	return(ret);
}



int fic_ecrire(const char* nom_fichier, char* fic, int i_taille) {
	int i_nb_elts_ecrits;
	int f_disk = open(nom_fichier, O_WRONLY|O_TRUNC|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

	//teste si le fichier a bien été ouvert
	if(f_disk == -1)
		return(-1);
 	
 	//ecrit le fichier
 	i_nb_elts_ecrits = write(f_disk, fic, i_taille);
 	if(i_nb_elts_ecrits != i_taille){
 		close(f_disk);
 		return(-4);
 	}
	
	//ferme le fichier après ecriture
	close(f_disk);
	return(i_taille);
}


void fic_ecrire_ppm(const char* nom_fichier, matrice_t img) {
	unsigned int i, j, k;
	char *str, *str_img;
	unsigned int taille = 3
		+ (unsigned int)floor(log10(abs(img->nb_cols))) + 2
		+ (unsigned int)floor(log10(abs(img->nb_lignes))) + 2
		+ (unsigned int)floor(log10(abs(255))) + 2
		+ img->nb_lignes * (3 * img->nb_cols);
	/*
	Le fichier est de la forme:
		P6\n
		nb_cols nb_lignes\n
		255\n
		matrice\0
	*/
	str = malloc(taille);
	snprintf(str, taille, "P6\n%d %d\n255\n", img->nb_cols, img->nb_lignes);

	// Convertir matrice de l'image en string
	k = 0;
	str_img = malloc(img->nb_lignes * (3 * img->nb_cols) + 1);
	for (i = 0; i < img->nb_lignes; i++) {
		for (j = 0; j < img->nb_cols; j++) {
			*(str_img+k) = img->raw[i][j][RED];
			*(str_img+k+1) = img->raw[i][j][GREEN];
			*(str_img+k+2) = img->raw[i][j][BLUE];
			k += 3;
		}
	}

	memcpy(str+15, str_img, img->nb_lignes * (3 * img->nb_cols) + 1);

	fic_ecrire(nom_fichier, str, taille);
}


void fic_ecrire_bmp(const char* nom_fichier, matrice_t img) {
	unsigned int i, j, k;
	unsigned int taille_img = img->nb_lignes * (3 * img->nb_cols);
	unsigned int taille_totale = 54 + taille_img;

	// Déclaration du Header
	char str_header[] = {0x42, 0x4D, // ID
						taille_totale & 0xFF,
						(taille_totale >> 8) & 0xFF,
						(taille_totale >> 16) & 0xFF,
						(taille_totale >> 24) & 0xFF, // Taille IMG
						0x00, 0x00, // réservé
						0x00, 0x00, // réservé
						0x36, 0x00, 0x00, 0x00, // offset du début du tableau (54)
						0x28, 0x00, 0x00, 0x00, // taille du header (40)
						(img->nb_cols) & 0xFF, (img->nb_cols >> 8) & 0xFF, (img->nb_cols >> 16) & 0xFF, (img->nb_cols >> 24) & 0xFF, // nb_cols
						(-img->nb_lignes) & 0xFF, (-img->nb_lignes >> 8) & 0xFF, (-img->nb_lignes >> 16) & 0xFF, (-img->nb_lignes >> 24) & 0xFF,// nb_lignes
						0x01, 0x00,
						0x18, 0x00, // Codage du pixel sur 24 bits
						0x00, 0x00, 0x00, 0x00, // Pas de compression
						0x00, 0x00, 0x00, 0x00, // Taille de l'image raw non obligatoire vu qu'il n'y a pas de compression
						0x13, 0x0B, 0x00, 0x00, // 72 DPI
						0x13, 0x0B, 0x00, 0x00, // 72 DPI
						0x00, 0x00, 0x00, 0x00, // Pas de palette
						0x00, 0x00, 0x00, 0x00 // Toutes les couleurs sont importantes
						};

	char *str;
	
	
	str = xmalloc(taille_totale);
	memcpy(str, str_header, 54);

	// Convertir matrice de l'image en string
	k = 54;
	for (i = 0; i < img->nb_lignes; i++) {
		for (j = 0; j < img->nb_cols; j++) {
			// /!\ dans le format bitmap, ordre = BGR et non RGB
			*(str + k) = img->raw[i][j][BLUE];
			*(str + k + 1) = img->raw[i][j][GREEN];
			*(str + k + 2) = img->raw[i][j][RED];
			k += 3;
		}
	}

	fic_ecrire(nom_fichier, str, taille_totale);
}

#endif