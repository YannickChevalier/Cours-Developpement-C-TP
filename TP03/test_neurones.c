#include "neurones.h"
#include "tests.h"
#include <math.h>


/*
  Fonction courament utilisée même si on ne tiendra pas compte de ses
  propriétés utiles pour le calcul (sa dérivée s'exprime simplement en
  fonction de f ).
 */
float f ( float x )
{
  return 2 / ( 1 + expf ( - x ) ) ;
}

float neurone_mort ( float x )
{
  return 0 ;
}

float neurone_tetu ( float x )
{
  return 1 ;
}


int main ( int argc , char * argv[] )
{
  int i , j ;
  couche_t c ;
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
  test ( ( c = creation_couche ( 2 , neurone_tetu ) ) != NULL ) ;
  test ( c->nb_neurones == 2 ) ;
  for ( i = 0 ; i < 2 ; i++ )
    test ( c->f[i] == neurone_tetu ) ;
  return 0 ;
}
