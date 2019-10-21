#include "matrices.h"
#include <malloc.h>

matrice_t creation_matrice ( int nb_lignes , int nb_colonnes )
{
  int i , j ;
  matrice_t res ;
  res = malloc ( sizeof ( struct matrice_s ) ) ;
  res->nb_lignes = nb_lignes ;
  res->nb_cols = nb_colonnes ;
  res->matrice = malloc ( nb_lignes * sizeof ( float * ) ) ;
  for ( i = 0 ; i < nb_lignes ; i++ )
    {
      res->matrice[i] = malloc ( nb_colonnes * sizeof ( float ) ) ;
      for ( j = 0 ; j < nb_colonnes ; j++ )
	res->matrice[i][j] = 0 ;
    }
  return res ;
}


matrice_t lire_matrice (  )
{
  int i , j , nb_lignes , nb_cols ;
  matrice_t res ;
  scanf ( "%d" , & nb_lignes ) ;
  scanf ( "%d" , & nb_cols ) ;
  res = creation_matrice ( nb_lignes , nb_cols ) ;
  for ( i = 0 ; i < nb_lignes ; i ++ )
    for ( j = 0 ; j < nb_cols ; j++ )
      scanf ( "%f" , res->matrice[i] + j ) ;
  return res ;
}

void affiche_matrice ( matrice_t m )
{
  int i , j ;
  for ( i = 0 ; i < m->nb_lignes ; i++ )
    {
      printf ( "( " ) ;
      for ( j = 0 ; j < m->nb_cols ; j++ )
	printf ( "%2.3f " , m->matrice[i][j] ) ;
      printf ( ")\n" ) ;
    }
}


