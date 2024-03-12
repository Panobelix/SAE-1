#include "include.h"
#include "yams.h"
/**
 * Fonction : totalCalcul
 * Auteur : Paul
 * Param : yams - pointeur vers la structure Yams contenant les informations de jeu.
 * Traitement : Calcule le score total du joueur courant en additionnant les scores des différentes combinaisons et en appliquant le bonus si nécessaire.
 * Retour : aucun
 */

void totalCalcul(Yams* yams) {
    int totalSuperieur = 0;
    int totalInferieur = 0;

    for (int i = 0; i < 6; i++) {
        totalSuperieur += yams->players[yams->current_player].grille[i];
    }

    for (int i = 6; i < 14; i++) {
        totalInferieur += yams->players[yams->current_player].grille[i];
    }

    yams->players[yams->current_player].total[0] = totalSuperieur;
    yams->players[yams->current_player].total[1] = totalInferieur;

    if (totalSuperieur >= 63) {
        yams->players[yams->current_player].total[0] += 35;
    }

    yams->players[yams->current_player].total[2] = totalSuperieur + totalInferieur;
}

/**
 * Fonction : remplacerCombinaison
 * Auteur : Paul
 * Param : yams - pointeur vers la structure Yams contenant les données de jeu.
 * Traitement : Permet au joueur de supprimer une combinaison de sa grille.
 * Retour : aucun
 */

void remplacerCombinaison(Yams* yams) {
    int choix = 0;
    int dicoSize = 0;
    char dico[14][51];

    // Afficher les combinaisons déjà remplies
    printf("| Combinaisons déjà choisies :\n");
    for (int i = 0; i < 14; i++) {
        if (yams->players[yams->current_player].grille[i] != 0) {
            printf("| %d/ %s\n", i + 1, yams->combinaisons[i]);
        }
    }

    // Demander quelle combinaison supprimer
    printf("| Entrez le numéro de la combinaison que vous voulez supprimer : ");
    scanf("%d", &choix);
    effacerBuffer();

    if (choix < 1 || choix > 14 || yams->players[yams->current_player].grille[choix - 1] == 0) {
        printf("| Choix invalide ou combinaison déjà vide.\n");
        return;
    }

    // Supprimer la combinaison choisie
    yams->players[yams->current_player].grille[choix - 1] = 0;

    // Afficher les combinaisons valides pour le remplacement
    printf("| Choisissez une nouvelle combinaison pour remplacer :\n");
    trouverCombinaison(yams, dico, &dicoSize);
    for (int i = 0; i < dicoSize; i++) {
        printf("| %d/ %s\n", i + 1, dico[i]);
    }

    // Sélectionner la nouvelle combinaison
    printf("| Entrez votre choix : ");
    scanf("%d", &choix);
    effacerBuffer();

    if (choix < 1 || choix > dicoSize) {
        printf("| Choix invalide.\n");
        return;
    }

    // Insérer la nouvelle combinaison
    strcpy(yams->players[yams->current_player].grille[choix - 1], dico[choix - 1]);
}
