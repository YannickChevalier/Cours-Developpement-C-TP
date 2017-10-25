#include "operations.h"
#include "tests.h"


int main ( int argc , char * argv[] )
{
  int n ;
  
  // test somme
  somme ( 5 , 7 , & n ) ;
  test ( n == 12 ) ;

  // test produit
  produit ( 5 , 7 , & n ) ;
  test ( n == 35 ) ;
  
  // test soustraction
  soustraction ( 5 , 7 , & n ) ;
  test ( n == -2 ) ;

  // test division
  division ( 5 , 7 , & n ) ;
  test ( n == 0 ) ;
  test ( division ( 5 , 0 , & n ) == 1 ) ;

  return 0 ;
}
