#include <stdio.h>
#define taillemax 9

int taille;
#include <stdio.h>
#define taillemax 9

int taille;
int colonne = 0;
int ligne = 0;
int valeur = 0;
int grille[taillemax][taillemax] = { 0 };
int i;
int j;

void taillegrille() {
    printf("Entrer la taille de votre grille : ");
    scanf_s("%d", &taille);

    if (taille > taillemax) {
        printf("La taille de la grille est trop grande (max 9)\n");
    }
    else {

        printf("Quelle valeure voulez vous entrer dans votre tableau: ");
        scanf_s("%d", &valeur);
        printf("A quelle ligne voulez vous assigner votre valeur : ");
        scanf_s("%d", &ligne);
        printf("A quelle colonne voulez vous assigner votre valeur : ");
        scanf_s("%d", &colonne);

        grille[i][j] = valeur;

        for (int i = 0; i < taille; i++) {

            printf("\n");

            for (int j = 0; j < taille; j++) {
                printf("| %d ", grille[i][j]);
            }

            printf("|");
        }

    }
}

int main() {

    taillegrille();
    return 0;
}