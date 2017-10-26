#include <malloc.h>


void echange ( int * a , int * b )
{
  // echange le contenu des deux variables aux adresses
  // a et b 
}

int int_cmp ( int * a , int * b )
{
  // compare les deux variables aux adresses
  // a et b. Renvoie un entier  strictement inferieur,
  // egal, ou strictement superieur a zero si la premiere
  // variable est plus petite, egale, ou plus grande quela seconde
  return 0 ;
}


int indice_max ( int * t , int n )
{
  // rend l'indice du maximum du tableau t de n entiers
  return 0 ;
}


void tri_a_bulles ( int * t , int n )
{
  // Écrire une fonctions prenant en entrée un tableau d'entier,
  // et triant les éléments de ce tableau en utilisant le tri a bulles
  // Le tri à bulles consiste à échanger le maximum des éléments de
  // 0 à i avec le contenu de la case i, pour i de n-1 à 2 (inclus) 
}

void recopie ( int * res , int * t , int n )
{
  /*
    Écrire une procédure qui copie les n premiers éléments du tableau
    t dans le tableau res
   */
}

void fusion ( int * res , int * t , int l1 , int l2 )
{
  /*
    Écrire une procédure fusion qui prend en entrée:
    - deux tableaux de même taille res et t
    - deux entiers l1 et l2 tels que:
    * t[0],...,t[l1-1] est trié
    * t[l1],...,t[l1+l2 -1] est trié
    et qui met dans res[0],...,res[l1+l2-1] les éléments
    t[0],...,t[l1+l2-1] dans l'ordre croissant
    Il faut pour cela deux indices i1 et i2 qui permettent de 
    parcourir les deux tableaux triés en partant du plus petit
    élément. On met dans le résultat le plus petit des 2, et 
    on incrémente l'indice pour la tableau choisi.

    On termine en copiant les éléments restant une fois qu'on a
    terminé un des  tableaux triés.
   */
}


void tri_fusion ( int * t , int n )
{
  // Ecrire une procedure implementant le tri fusion 
  // fusion d'un tableau t de n entiers:
  // - Si a tableau a zéro ou un élément, il est trié
  // - Sinon, on coupe le tableau en deux partie qu'on trie
  // avec 2 appels à la procédure tri_fusion, et on fusionne les
  // 2 sous-tableaux triés.
}


int indice_pivot ( int * t ,  int n )
{
  // Retourner l'indice d'un element pivot dans le tableau
  // t de n elements entiers. Il est inutile d'implémenter cette fonction,
  // elle existe pour permettre des optimisations à l'algorithme de tri. 
  return 0 ;
}


void partition ( int * t , int n , int * fin_premiere_partie , int * debut_deuxieme_partie )
{
  int bleu , blanc, rouge ;
  // Partitionner le tableau t de n entiers en suivant
  // l'algorithme de drapeau hollandais. 
  // - on commence à choisir un élément quelconque dans
  //   le tableau en utilisant la fonction indice_pivot
  // - puis on met sur la gauche (zone bleu) du tableau
  //   tous les éléments < au pivot
  // - et en même temps, on met à droite du tableau (zone rouge)
  //   tous les éléments > au pivot



  // on se souvient des indices des parties bleus et rouges
  // pour la fonction tri_rapide
  * fin_premiere_partie= bleu ;
  * debut_deuxieme_partie = rouge + 1 ;
}

void tri_rapide ( int * t , int n )
{
  // Ecrire une fonction implementant le tri rapide de deux tableaux
  // d'entiers:
  // - si un tableau a moins de un élément, il est trié
  // - sinon, on partitionne le tableau avec la fonction partition
  //   et on appelle récursivement la fonction tri_rapide sur les zones
  //   bleu et rouge (la blanche est correctement placée)

}


