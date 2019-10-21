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
    if ( m1 != NULL )
      {
	test(m1->matrice[0][1] == 2);
      }
    else
      {
	debug ( "matrice is NULL, implement first the function.\n" COULEUR_NORMALE ) ;
      }
    if ( m1 != NULL )
      {
	ajoute_valeur(&m1, m1->nb_lignes-1, m1->nb_cols-1, 4.3);
	test(egale_float(m1->matrice[3][3] , 4.3 ) );
      }
    else
      {
	debug ( "matrice is NULL, implement first the function.\n" COULEUR_NORMALE ) ;
      }
    printf("== TEST fonction recupere_valeur ==============\n");
    test(egale_float(recupere_valeur(m1, 3, 3), 1.0f));

    printf("== TEST fonction copie_matrice ==============\n");
    if ( m1 != NULL )
      {
	copie_matrice(m1, &m2);
	test(egale_float(m1->matrice[3][3], m2->matrice[3][3]));
      }
    else
      {
	debug ( "matrice is NULL, implement first the function.\n" COULEUR_NORMALE ) ;
      }
    printf("== TEST fonction addition_matrice =============\n");
    matrice_t m3;
    if ( ( m1 != NULL ) && ( m2 != NULL ) && ( m3 != NULL ) )
      {
	addition_matrice(m1, m2, &m3);
	test(egale_float(m1->matrice[3][3] + m2->matrice[3][3], m3->matrice[3][3]));
      }
    else
      {
	debug ( "matrice is NULL, implement first the function.\n" COULEUR_NORMALE) ;
      }
    printf("== TEST fonction multiplication_matrice ===============\n");
    matrice_t m4;
    if ( ( m1 != NULL ) && ( m3 != NULL ) )
      {
	test(egale_float(multiplication_matrice(m1, m3, &m4), 36.98));
      }
    else
      {
	debug ( "matrice is NULL, implement first the function.\n" COULEUR_NORMALE ) ;
      }
    return 0;
}
