#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"



matrice_t creation_matrice(int nb_lignes, int nb_colonnes) {
    /* Initialisation de la structure matrice qui va stocker les dimensions ainsi que
    l'image brute à 3 dimensions dont chaque composante RGB sera initialisé à 0
    */
    matrice_t res;
    return res;
}


void charger_img(matrice_t *m, unsigned char* img) {
    /* Fonction permettant de transformer la chaine de caractère img 
    dans un format compatible avec notre type matrice_t
    La variable img est structurée de la manière suivante :
        img = RED_0 GREEN_0 BLUE_0 RED_1 GREEN_1 BLUE_1 RED_2 ...
    Cette fonction doit pouvoir formatter la chaine de caractère contenant tous
    les pixels alignés les uns après les autres dans la matrice 3D définit dans la variable m
    */
}


void filtrage_pixel_rouge(matrice_t m1, matrice_t *m2, unsigned char seuil) {
    /* Construire une image filtrée où ne sont retenus que les pixels
    dont l'intensité en rouge est inférieur à un seuil donné
    Les valeurs supérieures au seuil donné seront mis à 0 sinon on garde la valeur de base.

    La nouvelle image sera stockée dans m2 intialisée avec creation_matrice
    */
}


void filtrage_pixel_bleu(matrice_t m1, matrice_t *m2, unsigned char seuil) {
    /* Construire une image filtrée où ne sont retenus que les pixels
    dont l'intensité en bleu est supérieure à un seuil donné
    Les valeurs innférieurs au seuil donné seront mis à 0 sinon on garde la valeur de base

    La nouvelle image sera stockée dans m2 intialisée avec creation_matrice
    */
}


void permutation_couleur(matrice_t m1, matrice_t *m2) {
    /* Permute la composante rouge avec la composante bleue.

    La nouvelle image sera stockée dans m2 intialisée avec creation_matrice
    */
}


int fusion_matrice(matrice_t m1, matrice_t m2, matrice_t *m3) {
    /* Fonction permettant de fusionner les valeurs de la matrice m1 et m2 par la méthode de votre choix
    À vous de réfléchir un peu :)

    La nouvelle matrice sera stockée dans m3
    */

    return 0;
}


void copie_masque(matrice_t *m1, matrice_t m2) {
    /* Copie le masque m2 d'une image sur l'image originale m1, pour cela, pour chaque pixel du masque m2 dont une 
    composante R, G ou B est différente de 0, on recopie la valeur simplement dans l'image définit par m1

    On ne crée pas de nouvelle matrice, ici on modifie directement m1.
    */
}

