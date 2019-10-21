#include "tests.h"
#include "matrices.h"



int main ( int argc , char * argv[] )
{
  int i , j ;
  matrice_t m ;
  if ( argc != 2 )
    {
      fprintf ( stderr , "Utilisation: %s <fichier à lire>\n" , argv[0] ) ;
      return 1 ;
    }
  if ( ! ( freopen ( argv[1] , "r" , stdin ) ) )
    {
      fprintf ( stderr , "Erreur, %s n'est pas un fichier lisible.\n" , argv[1] ) ;
      return 2 ;
    }
  /* test nouvelle matrice */
  m = creation_matrice ( 2 , 3 ) ;
  test ( m != NULL ) ;
  test ( m->nb_lignes == 2 ) ;
  test ( m->nb_cols == 3 ) ;
  test ( m->matrice != NULL ) ;
  test ( m->matrice[0] != NULL ) ;
  test ( m->matrice[1] != NULL ) ;
  for ( i = 0 ; i < 2 ; i++ )
    for ( j = 0 ; j < 3 ; j++ )
      test ( m->matrice[i][j] == 0 ) ;
  m = lire_matrice ( ) ;
  test ( m != NULL ) ;
  test ( m->nb_lignes == 2 ) ;
  test ( m->nb_cols == 3 ) ;
  test ( m->matrice != NULL ) ;
  test ( m->matrice[0] != NULL ) ;
  test ( m->matrice[1] != NULL ) ;
  for ( i = 0 ; i < 2 ; i++ )
    for ( j = 0 ; j < 3 ; j++ )
      test ( m->matrice[i][j] == ( 3 * i + j ) ) ;
  affiche_matrice ( m ) ; 
  
  return 0 ;
}
