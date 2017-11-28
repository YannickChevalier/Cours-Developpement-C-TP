enum color_e {
    RED,
    GREEN,
    BLUE
};

struct matrice_s {
  int nb_lignes ;
  int nb_cols ;
  unsigned char *** raw ;
} ;

typedef struct matrice_s * matrice_t ;


matrice_t creation_matrice(int nb_lignes, int nb_colonnes);

void charger_img(matrice_t *m, unsigned char* img);

void filtrage_pixel_rouge(matrice_t m1, matrice_t *m2, unsigned char seuil);

void filtrage_pixel_bleu(matrice_t m1, matrice_t *m2, unsigned char seuil);

void permutation_couleur(matrice_t m1, matrice_t *m2);

int fusion_matrice(matrice_t m1, matrice_t m2, matrice_t *m3);

void copie_masque(matrice_t *m1, matrice_t m2);

void change_couleur(matrice_t m1, matrice_t *m2, unsigned char rouge, unsigned char vert, unsigned char bleu);
