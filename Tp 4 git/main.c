#include <stdio.h>
#define taillemax 9

int taille;
int colonne = 0;
int ligne = 0;
int valeur = 0;
int grille[taillemax][taillemax] = { 0 };

void InitGrille(int grille[taillemax][taillemax], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grille[i][j] = 0;
        }
    }
}

void AfficherGrille(int grille[taillemax][taillemax], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < n; j++) {
            printf("| %d ", grille[i][j]);
        }
        printf("|");
    }
    printf("\n");
}

int VerifierContraintes(int grille[taillemax][taillemax], int n) {
    // Vérifier que tous les nombres sont entre 1 et n
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grille[i][j] < 1 || grille[i][j] > n) {
                printf("La valeur %d à la position (%d, %d) n'est pas valide.\n", grille[i][j], i, j);
                return 0;
            }
        }
    }

    // Vérifier qu'un nombre n'est présent qu'une seule fois par ligne
    for (int i = 0; i < n; i++) {
        int ligneCheck[taillemax] = { 0 };
        for (int j = 0; j < n; j++) {
            if (grille[i][j] != 0) {
                if (ligneCheck[grille[i][j] - 1] == 1) {
                    printf("Le nombre %d est en double dans la ligne %d.\n", grille[i][j], i);
                    return 0;
                }
                ligneCheck[grille[i][j] - 1] = 1;
            }
        }
    }

    // Vérifier qu'un nombre n'est présent qu'une seule fois par colonne
    for (int j = 0; j < n; j++) {
        int colonneCheck[taillemax] = { 0 };
        for (int i = 0; i < n; i++) {
            if (grille[i][j] != 0) {
                if (colonneCheck[grille[i][j] - 1] == 1) {
                    printf("Le nombre %d est en double dans la colonne %d.\n", grille[i][j], j);
                    return 0;
                }
                colonneCheck[grille[i][j] - 1] = 1;
            }
        }
    }

    printf("La grille respecte toutes les contraintes.\n");
    return 1;
}

void taillegrille() {
    printf("Entrer la taille de votre grille (max 9) : ");
    if (scanf_s("%d", &taille) != 1 || taille < 1 || taille > taillemax) {
        printf("La taille de la grille est invalide (doit être entre 1 et 9).\n");
        return;
    }

    InitGrille(grille, taille);

    printf("Quelle valeur voulez-vous entrer dans votre tableau : ");
    if (scanf_s("%d", &valeur) != 1) {
        printf("Erreur de saisie de la valeur.\n");
        return;
    }
    printf("À quelle ligne voulez-vous assigner votre valeur (0 à %d) : ", taille - 1);
    if (scanf_s("%d", &ligne) != 1 || ligne < 0 || ligne >= taille) {
        printf("Indice de ligne invalide.\n");
        return;
    }
    printf("À quelle colonne voulez-vous assigner votre valeur (0 à %d) : ", taille - 1);
    if (scanf_s("%d", &colonne) != 1 || colonne < 0 || colonne >= taille) {
        printf("Indice de colonne invalide.\n");
        return;
    }

    grille[ligne][colonne] = valeur;

    AfficherGrille(grille, taille);

    // Vérifier les contraintes
    VerifierContraintes(grille, taille);
}

int main() {
    taillegrille();
    return 0;
}
