#include "include.h"
#include "yams.h"
/**
 * Fonction : freeYams
 * Auteur : Clement
 * Param : yams - pointeur vers la structure Yams à libérer de la mémoire.
 * Traitement : Libère toutes les allocations mémoire associées à la structure Yams, y compris les joueurs, les combinaisons et la grille.
 * Retour : aucun
 */

void freeYams(Yams* yams) {
    // Libération de la mémoire allouée pour les combinaisons
    if (yams->combinaisons != NULL) {
        for (int i = 0; i < 14; i++) {
            if (yams->combinaisons[i] != NULL) {
                free(yams->combinaisons[i]);
            }
        }
        free(yams->combinaisons);
    }

    // Libération de la mémoire allouée pour la grille
    if (yams->players[yams->current_player].grille != NULL) {
        free(yams->players[yams->current_player].grille);
    }

    // Libération de la mémoire allouée pour les joueurs
    if (yams->players != NULL) {
        free(yams->players);
    }

    // Finalement, libérer la mémoire allouée pour la structure Yams elle-même
    free(yams);
}
