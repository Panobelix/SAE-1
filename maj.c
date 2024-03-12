#include "include.h"
#include "yams.h"

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Fonction : remplacer
 * Auteur : Clement
 * Param : yams - pointeur vers la structure Yams contenant les données de jeu, choix - chaîne de caractères représentant la combinaison choisie par le joueur.
 * Traitement : Met à jour la grille de score du joueur courant avec les points obtenus pour la combinaison choisie.
 * Retour : aucun
 */

void remplacer(Yams* yams, const char* choix) {
    int score = calculerScore(yams, choix);
    mettreAJourGrille(yams, choix, score);
    mettreAJourTotaux(yams);
    totalCalcul(yams);
}

/**
 * Fonction : mettreAJourGrille
 * Auteur : Clement
 * Paramètres :
 *     - yams : pointeur vers la structure Yams.
 *     - choix : chaîne de caractères représentant la combinaison choisie.
 *     - score : entier représentant le score à attribuer à la combinaison.
 * Description :
 *     Met à jour la grille du joueur actuel en enregistrant le score pour la combinaison choisie.
 *     Parcourt la liste des combinaisons possibles et, lorsqu'elle trouve la combinaison correspondante,
 *     met à jour le score dans la grille du joueur actuel.
 *     Si la combinaison a déjà été utilisée, affiche un message d'erreur.
 * Retour :
 *     void - Aucun retour. Modifie directement la grille du joueur.
 */

void mettreAJourGrille(Yams* yams, const char* choix, int score) {
    for (int i = 0; i < 14; i++) {
        if (strcmp(choix, yams->combinaisons[i]) == 0) {
            yams->players[yams->current_player].grille[i] = score;
            return;
        }
    }
    printf("| Vous avez déjà utilisé cette combinaison.\n");
}

/**
 * Fonction : remplacer
 * Auteur : Clement
 * Param : yams - pointeur vers la structure Yams, choix - chaîne de caractères représentant la nouvelle combinaison choisie.
 * Traitement : Remplace une combinaison existante dans la grille du joueur actuel par une nouvelle, en recalculant le score.
 * Retour : void - aucun retour, la grille et les totaux du joueur sont mis à jour directement.
 */

void mettreAJourTotaux(Yams* yams) {
    yams->players[yams->current_player].total[0] = 0;
    yams->players[yams->current_player].total[1] = 0;

    for (int i = 0; i < 7; i++) {
        yams->players[yams->current_player].total[0] += yams->players[yams->current_player].grille[i];
    }

    for (int i = 7; i < 14; i++) {
        yams->players[yams->current_player].total[1] += yams->players[yams->current_player].grille[i];
    }

    if (yams->players[yams->current_player].total[0] >= 63) {
        yams->players[yams->current_player].total[0] += 35;
        yams->players[yams->current_player].total[3] = 1;
    }

    yams->players[yams->current_player].total[2] = yams->players[yams->current_player].total[0] + yams->players[yams->current_player].total[1];
}

/**
 * Fonction : calculerScore
 * Auteur : Clement
 * Param : yams - pointeur vers la structure Yams, choix - chaîne de caractères représentant la combinaison choisie.
 * Traitement : Calcule le score basé sur la combinaison choisie et les valeurs actuelles des dés.
 * Retour : int - le score calculé pour la combinaison donnée.
 */

int calculerScore(Yams* yams, const char* choix) {
    int score = 0;
    int i;

    // Calcul du score pour les nombres (1, 2, 3, 4, 5, 6)
    if (strcmp(choix, "1") == 0 || strcmp(choix, "2") == 0 || strcmp(choix, "3") == 0 ||
        strcmp(choix, "4") == 0 || strcmp(choix, "5") == 0 || strcmp(choix, "6") == 0) {
        int value = atoi(choix);
        for (i = 0; i < 5; i++) {
            if (yams->listeDe[i] == value) {
                score += value;
            }
        }
    }
    // Calcul du score pour Brelan, Carré et Chance (somme de tous les dés)
    else if (strcmp(choix, "Brelan") == 0 || strcmp(choix, "Carré") == 0 || strcmp(choix, "Chance") == 0) {
        for (i = 0; i < 5; i++) {
            score += yams->listeDe[i];
        }
    }
    // Calcul du score pour Yam's
    else if (strcmp(choix, "Yam's") == 0 && YamsCombi(yams->listeDe)) {
        score = 50; // Score fixe pour un Yam's
    }
    // Calcul du score pour Petite suite
    else if (strcmp(choix, "Petite suite") == 0 && PetiteSuite(yams->listeDe)) {
        score = 25; // Score fixe pour une Petite Suite
    }
    // Calcul du score pour Grande suite
    else if (strcmp(choix, "Grande suite") == 0 && GrandeSuite(yams->listeDe)) {
        score = 40; // Score fixe pour une Grande Suite
    }
    // Calcul du score pour Full
    else if (strcmp(choix, "Full") == 0 && Full(yams->listeDe)) {
        score = 25; // Score fixe pour un Full
    }

    return score;
}
