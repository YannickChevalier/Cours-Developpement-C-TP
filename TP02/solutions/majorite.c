
int est_majoritaire ( char * t , char c , int n )
{
  /*
   * Cette fonction prend en entree un tableau t de caracteres
   * de taille n, ainsi qu'un caractere c, et renvoie 1 si la moitie ou plus
   * des elements du tableau t sont egaux a c.
   */
  int nb_occurrences, i ;
  for ( i = nb_occurrences = 0 ; i < n ; i++ )
    nb_occurrences += ( t[i] == c ) ;
  printf ( "%d occurrences sur %d\n" , nb_occurrences , n ) ;
  return ( nb_occurrences >  n / 2 ) ;
}

char trouve_candidat ( char * t , int n )
{
  /*
   * Cette fonction prend en entree un tableau t de n > 0 caracteres, et
   * renvoie, s'il existe, le caractere majoritaire. S'il n'y a pas de caractere
   * majoritaire, un element quelconque est renvoye.
   * On suppose que le tableau ne contient pas le caractere '\0'.
   */
  int i , candidat_nombre ;
  char candidat ;
  for ( i = candidat_nombre = 0 ; i < n ; i++ )
  {
    if ( candidat_nombre == 0 )
    {
      candidat = t[i] ;
      candidat_nombre = 1 ;
      continue ;
    }
    if ( t[i] == candidat )
      candidat_nombre += 1 ;
    else 
      candidat_nombre -= 1 ;
  }
  return candidat ;
}

int element_majoritaire ( char * t , int  n , char * c )
{
  /*
   * Cette procedure cherche s'il existe un element apparaissant
   * plus de (n+1)/2 fois dans le tableau t de n caracteres.
   * S'il en existe un, elle le stocke a l'adresse c et renvoie 1
   * Sinon, elle renvoie 0
   */
  *c = trouve_candidat ( t , n ) ;
  return est_majoritaire ( t , *c , n ) ;
}
