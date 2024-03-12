#include "include.h"
#include "yams.h"

/**
 * Fonction : initialisation
 * Auteur : Clement
 * Param : yams - pointeur vers la structure Yams à initialiser.
 * Traitement : Initialise une nouvelle structure Yams, alloue la mémoire nécessaire pour les joueurs, la grille et les combinaisons, et définit les valeurs par défaut.
 * Retour : aucun
 */

void initYams(Yams* yams) {
    if (yams == NULL) {
        printf("Erreur : Pointeur Yams non initialisé.\n");
        return;
    }

    const char* categories[13] = {"1", "2", "3", "4", "5", "6", "Brelan", "Carré", "Full", "Petite suite", "Grande suite", "Yam's", "Chance"};
    int nombreDeCategories = sizeof(categories) / sizeof(categories[0]);

    // Initialisation des valeurs de base
    yams->num_players = 1; // Nombre de joueurs par défaut
    yams->current_player = 0;
    for (int i = 0; i < 4; i++) {
        yams->total[i] = 0; // Initialise les totaux à 0
    }

    // Allocation de mémoire pour les joueurs
    yams->players = (Player*)calloc(yams->num_players, sizeof(Player));
    if (yams->players == NULL) {
        printf("Erreur d'allocation de mémoire pour yams->players.\n");
        return;
    }

    // Initialisation des grilles de chaque joueur
    for (int j = 0; j < yams->num_players; j++) {
        for (int i = 0; i < 14; i++) {
            yams->players[j].grille[i] = 0;  // Initialise chaque case de la grille à 0
        }
    }

    // Allocation de mémoire pour la grille
    yams->grille = calloc(14, sizeof(int));
    if (yams->grille == NULL) {
        printf("Erreur d'allocation de mémoire pour yams->grille.\n");
        free(yams->players); // Libère la mémoire allouée précédemment
        return;
    }

    // Allocation de mémoire pour les combinaisons
    yams->combinaisons = calloc(nombreDeCategories, sizeof(char*));
    if (yams->combinaisons == NULL) {
        printf("Erreur d'allocation de mémoire pour yams->combinaisons.\n");
        free(yams->grille); // Libère la mémoire allouée précédemment
        free(yams->players); // Libère la mémoire allouée précédemment
        return;
    }

    for (int i = 0; i < nombreDeCategories; i++) {
        yams->combinaisons[i] = calloc(strlen(categories[i]) + 1, sizeof(char));
        if (yams->combinaisons[i] == NULL) {
            printf("Erreur d'allocation de mémoire pour yams->combinaisons[%d].\n", i);
            // Libérer les ressources allouées précédemment...
            return;
        }
        strcpy(yams->combinaisons[i], categories[i]);
    }

    yams->current_player = 0;
    yams->total[0] = 0;
    yams->total[1] = 0;
    yams->total[2] = 0;
    yams->total[3] = 0;
}
