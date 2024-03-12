#include "include.h"
#include "yams.h"

/**
 * Fonction : grille
 * Auteur : Clement
 * Param : yams - pointeur vers la structure Yams contenant la grille à afficher.
 * Traitement : Affiche la grille de score actuelle pour le joueur courant, avec les différentes combinaisons et le total des points.
 * Retour : aucun
 */

void grille(Yams* yams) {
    int* grille = yams->players[yams->current_player].grille;
    int* total = yams->players[yams->current_player].total;
    const char* categories[] = {
        "1", "2", "3", "4", "5", "6",
        "Brelan", "Carre", "Full",
        "Petite Suite", "Grande Suite",
        "Yam's", "Chance"
    };

    // Affichage de l'entête
    printf("+----------------------+----------------------+\n");
    printf("|       YAM'S         |       YAM'S         |\n");
    printf("+----------------------+----------------------+\n");

    // Affichage des scores pour les dés simples
    for (int i = 0; i < 6; i++) {
        printf("| %-13s | %3d | %-13s | %3d   |\n",
            categories[i], grille[i], categories[i+6], grille[i+6]);
    }

    // Affichage de la section bonus et des autres combinaisons
    printf("| %-13s | %-4s| %-13s | %3d   |\n",
        "Bonus (>62)", (total[3] == 1) ? "35" : "    ", categories[12], grille[12]);

    // Affichage des totaux
    printf("+----------------------+----------------------+\n");
    printf("| Total superieur |%3d | Total inferieur | %3d|\n", total[0], total[1]);
    printf("+----------------------+----------------------+\n");
    printf("| TOTAL GENERAL   | %3d                       |\n", total[2]);
    printf("+---------------------------------------------+\n");
}
