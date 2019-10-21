#pragma once
struct matrice_s {
  int nb_lignes ;
  int nb_cols ;
  float ** matrice ;
} ;

typedef struct matrice_s * matrice_t ;


matrice_t creation_matrice ( int nb_lignes , int nb_colonnes ) ;

matrice_t lire_matrice (  ) ;

void affiche_matrice ( matrice_t m ) ;

void ajoute_valeur(matrice_t *m1, int x, int y, float value);

float recupere_valeur(matrice_t m1, int num_ligne, int num_colonne);

void copie_matrice(matrice_t m1, matrice_t *m2);

int addition_matrice(matrice_t m1, matrice_t m2, matrice_t *m3) ;

int multiplication_matrice(matrice_t m1, matrice_t m2, matrice_t *m3) ;
