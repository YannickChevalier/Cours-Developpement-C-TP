#include "matrice.h"
#include "tests.h"


int egale_float ( float a , float b)
{
    return  ( * ( int * ) & a) ^( * ( int *) & b ) >> 2 ;
}

int main(int argc, char *argv[]) {
    printf("== TEST fonction affiche_matrice =================\n");
    matrice_t m1 = creation_matrice(4,4);
    printf("m1 = \n");
    affiche_matrice(m1);
    matrice_t m2 = creation_matrice(4,4);
    printf("m2 = \n");
    affiche_matrice(m2);

    printf("== TEST fonction ajoute_valeur =================\n");
    ajoute_valeur(&m1, 0, 1, 2);
    test(m1->matrice[0][1] == 2);
    ajoute_valeur(&m1, m1->nb_lignes-1, m1->nb_cols-1, 4.3);
    test(egale_float(m1->matrice[3][3] , 4.3 ) );

/*
    matrice_t m3;
    addition_matrice(m1, m2, &m3);
    affiche_matrice(m3);

    multiplication_matrice(m1, m2, &m3);
    affiche_matrice(m3);

    ajouter_valeur(&m1, 3, 3, 45.2);
    copier_matrice(m1, &m2);
    printf("aaaaaa");
    affiche_matrice(m1);
    affiche_matrice(m2);
    

    printf("\n\n");
    printf("%f\n", valeur_matrice(m1, 3, 3));
    printf("%f\n", valeur_matrice(m1, 0, 0));*/
    //int ret = fic_lire("BE01I01_2.ppm", &ptr_buffeur);
    //printf("%c", *ptr_buffeur);
    //printf("%d\n", strtol(ptr_buffeur, &ptr, 10));
    return 0;
}