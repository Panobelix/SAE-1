#include "include.h"
#include "yams.h"
/**
 * Fonction : afficherDes
 * Auteur : Valentin
 * Param : yams - pointeur vers la structure Yams contenant les dés à afficher.
 * Traitement : Affiche graphiquement les valeurs des dés du joueur courant.
 * Retour : aucun
 */

void afficherDes(Yams* yams) {
    printf("+---+---+---+---+---+\n");
    printf("|");
    for (int i = 0; i < 5; i++) {
        printf(" %d |", yams->listeDe[i]);
    }
    printf("\n+---+---+---+---+---+\n");
}


/**
 * Fonction : effacerBuffer
 * Auteur : Clement
 * Param : aucun
 * Traitement : Nettoie le buffer d'entrée pour éviter les saisies utilisateur indésirables lors de la lecture suivante.
 * Retour : aucun
 */

void effacerBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Fonction : ancerDes
 * Auteur : Valentin
 * Param : yams - pointeur vers la structure Yams où les dés seront lancés.
 * Traitement : Effectue un lancer de dés pour le joueur courant et propose de relancer certains dés ou de sauvegarder le score.
 * Retour : aucun
 */

void lancerDes(Yams* yams) {
    printf("| Voici votre lance de des :                  |\n");
    for (int i = 0; i < 5; i++) {
        yams->listeDe[i] = rand() % 6 + 1;
    }

    afficherDes(yams);

    for (int i = 0; i < 1; i++) {
        printf("| Entrez les des que vous voulez relancer (1-5) ou 'a' pour tous les relancer, 's' pour sauver: ");
        char rep[10];
        scanf("%s", rep);
        effacerBuffer();
        if (strcmp(rep, "s") == 0) {
            SauvegarderCombo(yams);
        } else if (strcmp(rep, "a") == 0) {
            for (int j = 0; j < 5; j++) {
                yams->listeDe[j] = rand() % 6 + 1;
            }
        } else {
            for (int j = 0; j < strlen(rep); j++) {
                int index = rep[j] - '0' - 1;
                if (index >= 0 && index < 5) {
                    yams->listeDe[index] = rand() % 6 + 1;
                }
            }
        }
        printf("| Voici votre nouveau lance de des :                        |\n");
        afficherDes(yams);
    }
}
