#include "tests.h"
#include "majorite.h"
#include <string.h>


#define  test_ligne(ligne , succes , resultat )                                                           \
  do {									                                                           \
    int longueur ;							                                                           \
    char c = 'x';							                                                           \
    longueur = strlen ( ligne ) ;					                                                   \
    ligne[--longueur] = '\0' ;						                                           \
    printf ( "ligne: |%s|\n" , ligne ) ;				                                                   \
    printf ( "\tsucces = %d, resultat = %c\n" , succes , resultat ) ;	                   \
    test ( trouve_candidat ( ligne , longueur ) == resultat ) ;		                   \
    test ( est_majoritaire ( ligne , resultat , longueur ) == succes ) ;                     \
    test ( element_majoritaire ( ligne , longueur , & c ) == succes ) ;	           \
    test (  c == resultat ) ;						                                                   \
    printf ( "resultat attendu: element %c %s\n\n\n" ,                                            \
	     c , succes ? "majoritaire" : "pas majoritaire" ) ;                                             \
  }  while ( 0 )		  
    
int main ( int argc , char * argv[] )
{
  char ligne[50] ;
  if ( freopen ( "majorite.test" , "r" , stdin ) == NULL )
    {
      fprintf ( stderr , "Impossible d'ouvrir le fichier de tests.\n" ) ;
      return 1 ;
    }
  
  fgets ( ligne , 49 , stdin ) ;
  test_ligne ( ligne , 0 , 'b' ) ;
  
  fgets ( ligne , 49 , stdin ) ;
  test_ligne ( ligne , 0 , 'a' ) ;

  fgets ( ligne , 49 , stdin ) ;
  test_ligne ( ligne , 0 , 'b' ) ;
  
  fgets ( ligne , 49 , stdin ) ;
  test_ligne ( ligne , 1 , 'a' ) ;
      
    
  return 0 ;
}
