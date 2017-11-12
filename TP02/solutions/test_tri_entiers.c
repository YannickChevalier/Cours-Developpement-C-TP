#include "tests.h"
#include "tri_entiers.h"

int tableaux_egaux ( int * t1 , int * t2 , int  n)
{
  int i ;
  for ( i = 0 ; i < n ; i++ )
    if ( t1[i] != t2[i] )
      return 0 ;
  return 1 ;
}


void init_4( int * t )
{
  t[0] = 1 ; t[1] = 4 ; t[2] = 2 ; t[3] = 3 ;
}
void init_6( int * t )
{
  t[0] = 1 ; t[1] = 5 ; t[2] = 3 ;
  t[3] = 6 ; t[4] = 2 ; t[5] = 4 ;
}

int main ()
{
  int
    n = 7 ,
    m = 14 ,
    t[6] , tt[6] ,
    t4[4] = {1,2,3,4} ,
    t6[6] = {1,2,3,4,5,6} ;
  // echange
  echange ( &n , & m ) ;
  test ( n == 14 ) ;
  test ( m == 7 ) ;
  echange ( &n , & n ) ;
  test ( n == 14 ) ;

  // int_cmp
  test ( int_cmp ( &m, &n ) < 0 ) ;
  test ( int_cmp ( &n , &n ) == 0 ) ;
  test ( int_cmp ( &n, &m ) > 0 ) ;

  // indice_max
  init_4 ( t ) ;
  test ( indice_max ( t , 4 ) == 1 ) ;
  test ( indice_max ( t +2, 2 ) == 1 ) ;

  //tri_a_bulles
  init_4 ( t ) ;
  tri_a_bulles ( t , 4 ) ;
  test ( tableaux_egaux ( t , t4 , 4 ) ) ;
  init_6 ( t ) ;
  tri_a_bulles ( t , 6 ) ;
  test ( tableaux_egaux ( t , t6 , 6 ) ) ;
  
  // recopie
  recopie (  tt , t , 4 ) ;
  test ( tableaux_egaux ( tt, t6 , 4 ) ) ;

  // fusion
  init_4 ( t ) ;
  fusion ( tt , t , 2, 2 ) ;
  test ( tableaux_egaux ( tt, t4 , 4 ) ) ;

  // tri_fusion
  init_6 ( t ) ;
  tri_fusion ( t , 6 ) ;
  test ( tableaux_egaux ( t, t6 , 6 ) ) ;
  
  // indice_pivot
  init_4 ( t ) ;
  test ( indice_pivot ( t , 4 ) < 4 ) ;
  test ( indice_pivot ( t , 4 ) >= 0 ) ;

  // tri_rapide
  init_4 ( t ) ;
  tri_rapide ( t , 4 ) ;
  test ( tableaux_egaux ( t, t4 , 4 ) ) ;
  init_6 ( t ) ;
  tri_rapide ( t , 6 ) ;
  test ( tableaux_egaux ( t, t6 , 6 ) ) ;


  
  return 0 ;
}
