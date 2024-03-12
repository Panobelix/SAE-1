#include "include.h"
#include "yams.h"
/**
 * Fonction : choixPossibles
 * Auteur : Clement
 * Param : yams - pointeur vers la structure Yams, dico - tableau de pointeurs vers les chaînes des combinaisons possibles, dicoSize - pointeur vers la taille du dico.
 * Traitement : Remplit le dico avec les combinaisons possibles pour le joueur courant.
 * Retour : int - nombre de combinaisons possibles.
 */

int choixPossibles(Yams* yams, char **dico, int* dicoSize) {
    if (yams == NULL || yams->players[yams->current_player].grille == NULL || yams->combinaisons == NULL || dicoSize == NULL) {
        printf("Erreur : Paramètres non initialisés dans possibleChoice.\n");
        return 0;
    }

    char* validCombinations[13]; // Tableau pour stocker les combinaisons valides
    int validCombinationCount = 0;

    trouverCombinaison(yams, validCombinations, &validCombinationCount);

    int cpt = 0;
    for (int i = 0; i < validCombinationCount; i++) {
        for (int j = 0; j < 14; j++) {  // 14 est le nombre de combinaisons différentes dans le jeu
            if (yams->players[yams->current_player].grille[j] == 0 && strcmp(yams->combinaisons[j], validCombinations[i]) == 0) {
                strcpy(dico[cpt], validCombinations[i]);
                cpt++;
                break;
            }
        }
    }

    *dicoSize = cpt;
    return cpt > 0;
}

/**
 * Fonction : questionChoix
 * Auteur : Clement
 * Param : yams - pointeur vers la structure Yams contenant les données de jeu.
 * Traitement : Pose une question au joueur sur la combinaison à choisir et met à jour le score.
 * Retour : aucun
 */

void questionChoix(Yams* yams) {
    int choix = 0;
    int validCombinationCount = 0;
    char* validCombinations[13]; // Puisqu'il y a 13 combinaisons possibles

    trouverCombinaison(yams, validCombinations, &validCombinationCount);

    printf("| Choisissez votre combinaison ou 's' pour sauver :       |\n");
    if (validCombinationCount == 0) {
        remplacerCombinaison(yams);
        return;
    }

    for (int i = 0; i < validCombinationCount; i++) {
        printf("| %d/ %s\n", i + 1, validCombinations[i]);
    }
    printf("| s/ Sauvegarder le score\n");

    while (!readUserChoice(&choix, validCombinationCount)) {
        // La fonction readUserChoice affiche les messages d'erreur et demande à nouveau.
    }

    if (choix == -1) { // L'utilisateur a choisi de sauvegarder
        SauvegarderCombo(yams);
    } else {
        remplacer(yams, validCombinations[choix - 1]);
    }
}
