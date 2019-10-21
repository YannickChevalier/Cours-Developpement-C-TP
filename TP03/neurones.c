#include "neurones.h"
#include "matrice.h"
#include "matrices.h"
#include <malloc.h>

/*
  Une couche contient:
  - un tableau de n entrées, chaque entrée étant l'entrée d'un neurone
  - un tableau de n fonctions d'activation, chaque 
  Un neurone est défini par une valeur d'entrée (un float), une fonction d'activation 
  f, et une valeur de sortie output telle que output = f(input)
  - l'adresse de la couche suivante dans le réseau de neurones

  La fonction suivante prend en entrée le nombre de neurones et la fonction
  d'activation, la couche suivante (NULL s'il n'y en a pas), et rend une couche.
*/

#define UNPRECISE_BITS N


couche_t creation_couche ( int n , fonction_d_activation_t f , couche_t couche_suivante )
{
  int i ;
  couche_t res = malloc ( sizeof ( struct couche_s ) ) ;
  couche_suivante = couche_suivante ;
  res->nb_neurones = n ;
  res->entree = malloc ( n * sizeof ( float ) ) ;
  res->f = malloc ( n * sizeof ( fonction_d_activation_t ) ) ;
  res->sortie = malloc ( n * sizeof ( float ) ) ;
  for ( i = 0 ; i < n ; i++ )
    res->f[i] = f ;
  return res ;
}

couche_t creation_couche_aleatoire ( int n , couche_t couche_suivante )
{
  int nb_suivant ;
  couche_t res ;
  if ( n <= 0 )
    return couche_suivante ;
  res = malloc ( sizeof ( struct couche_s ) ) ;
  
  if ( couche_suivante == NULL )
      nb_suivant = 0 ;
  else
    nb_suivant = couche_suivante->nb_neurones ;
  res->suivante = couche_suivante ;

  if ( nb_suivant == 0 )
    res->poids = NULL ;
  else 
    res->poids = creation_matrice_aleatoire ( n , nb_suivant ) ;

  res->nb_neurones = n ;
  res->entree = malloc ( n * sizeof ( float ) ) ;
  res->sortie = malloc ( n * sizeof ( float ) ) ;
  res->f = malloc ( n * sizeof ( fonction_d_activation_t ) ) ;

  return res ;
}

couche_t creation_reseau_aleatoire ( int nb_couches , int * taille_couches )
{
  if ( n <= 0 ) return NULL ;
  return creation_couche_aleatoire (
				    t[0] ,
				    creation_reseau_aleatoire (
							       nb_couches - 1 ,
							       tailles_couches + 1 ) ) ;
}


int nb_couches ( couche_t couche )
{
  if ( couche == NULL ) return 0 ;
  return 1 + nb_couches ( couche->suivante ) ;
}


int adresse_des_entrees ( couche_t couche , int * taille_entrees , float ** adresse_entrees )
{
  if ( couche == NULL ) return 1 ;
  *taille_entrees = couche->nb_neurones ;
  *adresse_entrees = couche->entree ;
  return 0 ;
}

int adresse_des_sorties ( couche_t couche , int * taille_sorties , float ** adresse_sorties )
{
  if ( couche == NULL ) return 1 ;
  if ( couche->suivante == NULL )
    {
      *taille_sorties = couche->nb_neurones ;
      *adresse_sorties = couche->entree ;
      return 0 ;
    }
  return adresse_des_sorties ( couche->suivante , taille_sorties , adresse_sorties ) ;
}


/*
  Fonction de mise à jour de a sortie d'une couche de neurones: la
  sortie est calculée en fonction de l'entrée et de la fonction
  d'activation.
 */


int calcule_entrees_couche_suivante ( couche_t couche )
{
  int i , j ;
  couche_t suivante ;
  if ( couche->suivante == NULL )  return 1 ;
  suivante = couche->suivante ;
  if ( matrice_vecteur_multiplication (
				       couche->sortie ,
				       couche->poids ,
				       suivante->entree ) )
    {
      return -1 ; // erreur lors de la multiplication
    }
  return 0 ;
}


int mise_a_jour_sortie_couche ( couche_t couche )
{
  int i ;
  for ( i = 0 ; i < couche->nb_neurones ; i++ )
    couche->sortie[i] = ( * ( couche->f[i] ) ) ( c->entree[i] ) ;
  return 0 ;
}

/*
  Calcule d'une valeur par un réseau de neurones. Il faut définir l'entrée
*/
int propagation ( couche_t couche )
{
  // on suppose que l'entrée est définie
  if ( mise_a_jour_sortie_couche ( couche ) )
    return 1 ; // erreur, impossible a priori
  switch ( calcule_entrees_couche_suivante ( couche ) )
    {
    case -1: // erreur lors de la multiplication vecteur-matrice
      return 1 ;
    case 0: // si la couche suivante existe
      return propagation ( couche->suivante ) ;
    case 1: // si la couche suivante n'existe pas, on copie sur la sortie
      
      return 0 ;
    }
}

/*
  On calcule la dérivée au point x de la fonction f par la formule approchée:
  f'(x) = ( f( x + epsilon ) - f( x - epsilon ) ) / 2 epsilon

  Le type fonction_d_activation_t représente l'adresse d'une fonction
  f qui prend en entrée un float et renvoie un float. On le construit ainsi:
  - ( *f ) est une fonction qui prend en entrée un float et renvoie un float
  - donc ( *f ) ( float ) est un float
  - donc la déclaration de f est:  float ( * f ) ( float )
  - pour obtenir un type à partir d'une déclaration, on ajoute typedef:
  typedef float ( * fonction_d_activation_t ) ( float ) ;
 */
#define EPSILON 0.001f

float derive ( float x , fonction_d_activation_t f )
{
  float res ;
  static float * memoization = NULL ;
  int i_x = ( * ( int * ) & x ) & ( -1 << UNPRECISE_BITS ) ;
  if ( UNPRECISE_BITS )
    {
      if ( memoization == NULL )
	memoization = calloc ( 1 << ( 32 - UNPRECISE_BITS ) , sizeof ( float ) ) ;
      if ( memoization[i_x >> UNPRECISE_BITS] == 0 )
	memoization[i_x >> UNPRECISE_BITS] =  ( (*f) ( x + EPSILON ) - (*f) ( x - EPSILON ) ) / ( 2 * EPSILON ) ;
      res = memoization[i_x >> UNPRECISE_BITS] ;
    }
  else
    res = ( (*f) ( x + EPSILON ) - (*f) ( x - EPSILON ) ) / ( 2 * EPSILON ) ;
  return res ;
}
#if UNPRECISE_BITS > 0
#define make_function(f)							\
  float f ## _diff ( float x )						\
  {									\
    int i_x = ( * ( int * ) & x ) & ( -1 << UNPRECISE_BITS ) ;		\
    static float * memoization = NULL ;					\
    if ( memoization == NULL )  memoization = calloc ( 1 << ( 32 - UNPRECISE_BITS ) , sizeof ( float ) ) ; \
    if ( memoization[i_x >> UNPRECISE_BITS] == 0 ) memoization[i_x >> UNPRECISE_BITS] =  ( f( x + EPSILON ) - f ( x - EPSILON ) ) / ( 2 * EPSILON ) ; \
    return memoization[i_x >> UNPRECISE_BITS] ;				\
  }									\
  float f ## _orig ( float x )						\
  {									\
    int i_x = ( * ( int * ) & x ) & ( -1 << UNPRECISE_BITS ) ;		\
    static float * memoization = NULL ;					\
    if ( memoization == NULL )  memoization = calloc ( 1 << ( 32 - UNPRECISE_BITS ) , sizeof ( float ) ) ; \
    if ( memoization[i_x >> UNPRECISE_BITS] == 0 ) memoization[i_x >> UNPRECISE_BITS] =  f ( x ) ; \
    return memoization[i_x >> UNPRECISE_BITS] ;				\
  }									\

#else
#define make_function(f)						\
  inline float f ## _diff ( float x )					\
  {									\ \
      return ( f( x + EPSILON ) - f ( x - EPSILON ) ) / ( 2 * EPSILON ) ; \
  }
inline float f ## _orig ( float x )					\
{									\
  return f( x ) ;							\
}

#endif


int retro_propagration ( couche_t couche , float * attendu , float vitesse )
{
  int i ;
  float
    sortie  ;
  // in suppose que l'entrée est définie
  if ( mise_a_jour_sortie_couche ( couche ) )
    return 1 ; // erreur, impossible a priori

  switch ( calcule_entrees_couche_suivante ( couche ) )
    {
    case -1:
      return 1 ; // cas d'erreur
    case 1:
      // dernière couche, les entrees servent maintenant à stocker les erreurs
      for ( i = 0 ; i < couche->nb_neurones ; i++ )
	{
	  sortie = couche->sortie[i] ;
	  couche->entree[i] = ( sortie - attendu[i] ) * derive ( sortie , couche->f[i] ) ;
	}
      return 0 ;
    case 0:
      if ( retro_propagration ( couche->suivante , attendu ) )
	return 1 ; // cas d'erreur ;
      // Les entrées de la couche suivante sont maintenant les erreurs
      // de la couche suivante. On commence par calculer les erreurs
      // sur les entres, puis on mettra à jour la matrice des poids.

      // 1- Erreur sur les entrees: on utilise les poids utilisés pour
      // le calcul
      for ( i = 0 ; i < couche->nb_neurones ; i++ )
	{
	  sortie = couche->sortie[i] ;
	  couche->entree[i] =  0 ;
	  for ( j = 0 ; j < couche->suivante->nb_neurones ; j++ )
	      couche->entree[i] += couche->suivante->entree[j] * couche->poids[i][j] ;
	  couche->entree[i] *= derive ( sortie , couche->f[i] ) ;
	}
      // 2- Erreur sur les poids: on corrige en fonction de la valeur de sortie
      // et de l'erreur à la couche suivante
      for ( i = 0 ; i < couche->nb_neurones ; i++ )
	  for ( j = 0 ; j < couche->suivante->nb_neurones ; j++ )
	      couche->poids[i][j] -= couche->suivante->entree[j] * couche->sortie[i] ;
      return 0 ;
    }
  return 0 ;  
}

