#include "include.h"
#include "yams.h"
/**
 * Fonction : jeu
 * Auteur : Clement
 * Param : yams - pointeur vers la structure Yams qui contient les informations de jeu.
 * Traitement : Déroule le jeu de Yams, manche par manche, pour chaque joueur jusqu'à la fin de la partie.
 * Retour : aucun
 */

void jeu(Yams* yams) {
    const int manchetotale = 3;

    for (int manche = 0; manche < manchetotale; manche++) {
        for (int joueur = 0; joueur < yams->num_players; joueur++) {
            yams->current_player = joueur;
            printf("| Tour du joueur %s - Manche %d\n", yams->players[joueur].name, manche + 1);
            grille(yams);
            lancerDes(yams);
            questionChoix(yams);  // Assurez-vous que cette fonction utilise aussi la grille individuelle
            system("cls");
        }
    }

    printf("| Partie terminée !\n");
    plusHautScore(yams);
    for (int i = 0; i < yams->num_players; i++) {
        Meilleur_score(yams->players[i].name, yams->players[i].score);
    }
    afficherScoreJoueur(yams);
}
