#include "../include/matrice.h"
#include "../include/tests.h"

#ifndef NULL
#define NULL ( ( void * ) 0 )
#endif
#define not_implemented \
  do {			\
  debug ( "Function %s not implemented.\n" COULEUR_NORMALE , __func__ ) ; \
  } while ( 0 ) 

matrice_t creation_matrice ( int nb_lignes , int nb_colonnes )
{
    /*
    Crée une matrice de taille nb_lignes x nb_colonnes avec 
    chaque case initialisée à 0
    */
   not_implemented ;
    return ( matrice_t ) NULL ;
}


matrice_t lire_matrice (  )
{
    /*
    Crée une matrice dont toutes les cases sont initialisées à 0 et
    dont la taille est demandée préalablement à l'utilisateur
    */
   not_implemented ;
    return ( matrice_t ) NULL ;
}


void affiche_matrice ( matrice_t m )
{
    /*
    Affiche tous les éléments contenus dans la matrice
    */
   not_implemented ;
}


void ajoute_valeur(matrice_t *m1, int num_ligne, int num_colonne, float valeur) {
    /*
    Ajoute l'élément valeur à la matrice m1 à la ligne num_ligne et colonne num_colonne
    */
   not_implemented ;
}

float recupere_valeur(matrice_t m1, int num_ligne, int num_colonne) {
    /*
    Renvoie simplement la valeur d'un élément de la matrice m1 défini à la ligne
    num_ligne et à la colonne num_colonne
    */
   not_implemented ;
  return 1.0f ;
}

void copie_matrice(matrice_t m1, matrice_t *m2) {
    /*
    Copie tous les éléments de la matrice m1 dans m2
    */
   not_implemented ;
  m2 = NULL ;
}


int addition_matrice(matrice_t m1, matrice_t m2, matrice_t *m3) {
    /*
    Addition de 2 matrices m1 et m2, le résultat sera mis dans la matrice m3
    qu'il faudra créé.
    La fonction renvoie -1 en cas d'erreur sinon 0
    */
   not_implemented ;
  return 0 ;
}


int multiplication_matrice(matrice_t m1, matrice_t m2, matrice_t *m3) {
    /*
    Addition de 2 matrices m1 et m2, le résultat sera mis dans la matrice m3
    qu'il faudra créé.
    La fonction renvoie -1 en cas d'erreur sinon 0
    */
   not_implemented ;
  return 0 ;
}

