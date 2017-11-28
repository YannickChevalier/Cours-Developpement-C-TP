#include "image.h"

int main(int argc, char *argv[]) {
    unsigned char *ptr_buffeur;
    int nb_lignes;
    int nb_cols;
    int ret = fic_lire_bmp("img_2cv.bmp", &ptr_buffeur, &nb_cols, &nb_lignes);

    matrice_t img;

    //fic_ecrire_bmp("test.bmp", img);

    return 0;
}