#include <stdio.h>
#include <ctype.h>


void  somme ( int a , int b , int * res  )
{
  * res = a + b ;
}

void produit ( int a , int b , int * res  )
{
  *res = a * b ;
}

void soustraction ( int a , int b , int * res  )
{
  *res = a - b ;
}

int division ( int a , int b , int * res  )
{
  if ( b == 0 )
    return 1 ;
  *res = a / b ;
  return 0 ;
}
 
