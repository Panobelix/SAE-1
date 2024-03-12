#include "include.h"
#include "yams.h"

int main() {
    srand(time(NULL));
    Yams* yams = calloc(1, sizeof(Yams));
    if (yams == NULL) {
        printf("Erreur lors de l'allocation de la mémoire\n");
        return 1;
    }
    initYams(yams);
    menu(yams);
    jeu(yams);
    printf("| Merci d'avoir joué\n");
    grille(yams);
    printf("| Au revoir ...\n");
    freeYams(yams);
    return 0;
}
