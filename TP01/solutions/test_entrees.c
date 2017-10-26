#include "entrees.h"
#include "tests.h"


int main ( int argc , char * argv[] )
{
  float f ;
  int n ;
  if ( freopen ( "entrees.test", "r" , stdin ) == NULL )
    {
      fprintf ( stderr , "Erreur d'ouverture du fichier de test.\n" ) ;
      return 1 ;
    }
  
  // tests lire_fin_ligne
  test ( lire_fin_ligne ( ) == 0 ) ;
  test ( lire_fin_ligne ( ) > 0 ) ;
  test ( lire_fin_ligne ( ) == 0 ) ;

  // tests demande_decimal
  test ( ! demande_decimal ( & f ) && ( f == 3.5 ) ) ;
  test ( ! demande_decimal ( & f ) && ( f == 2.5 ) ) ;
  test ( ! demande_decimal ( & f ) && ( f == 0.5 ) ) ;
  
  // tests demande_entier
  test ( ! demande_entier ( & n ) && ( n == 3 ) ) ;
  test ( ! demande_entier ( & n ) && ( n == 2 ) ) ;
  test ( ! demande_entier ( & n ) && ( n == 0 ) ) ;

  // tests demande_entier_positifi
  test ( ! demande_entier_positif ( & n ) && ( n == 3 ) ) ;
  return 0 ;
}
