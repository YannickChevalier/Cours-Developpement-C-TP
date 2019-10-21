#pragma once
#include "matrice.h"

/* 
   NEURONES
*/

typedef float ( * fonction_d_activation_t ) ( float ) ;



/*
  On va regarder des réseaux de neurones qui sont organisés en
  couches.  Chaque couche est un tableau de neurones. On a choisi ici
  une version non optimisée qui est plus simple, où chaque neurone est
  représenté par son adresse de type neurone_t, mais il serait plus
  efficace de représenter chaque neurone par une structure de type
  struct neurone_s. Un tableau de neurones aurait ainsi le type 
  struct neurone_s * 
  = neurone_t
*/

typedef struct couche_s * couche_t ;

struct couche_s {
  couche_t suivante ;
  matrice_t poids ;
  int nb_neurones ;
  float * entree ;
  fonction_d_activation_t * f ;
  float * sortie ;
} ;

