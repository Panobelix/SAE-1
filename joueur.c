#include "include.h"
#include "yams.h"

/**
 * Fonction : setupPlayers
 * Auteur : Paul
 * Param : yams - pointeur vers la structure Yams où les informations des joueurs seront enregistrées.
 * Traitement : Permet à l'utilisateur d'entrer le nombre de joueurs et leurs noms, puis initialise leurs données dans la structure Yams.
 * Retour : aucun
 */

void joueurConfiguration(Yams* yams) {
    int nbr = 1;  // Nombre de joueurs par défaut
    int key;

    // Affichage initial du menu de configuration
    afficherMenuConfiguration(nbr);

    while (1) {
        key = _getch(); // Attend une entrée clavier

        // Vérifier si la touche est une flèche directionnelle ou autre
        if (key == 0 || key == 0xE0) {
            int key2 = _getch(); // Obtient la touche spécifique pour les flèches directionnelles
            switch (key2) {
                case 72: // Flèche vers le haut
                    if (nbr < 4) {
                        nbr++;
                    }
                    break;
                case 80: // Flèche vers le bas
                    if (nbr > 1) {
                        nbr--;
                    }
                    break;
            }
        } else if (key == 27) { // ESC
            return; // Retour au menu précédent
        } else if (key == 13) { // ENTER
            // Procéder à la configuration des joueurs
            configurerJoueurs(yams, nbr);
            return; // Retour au menu principal ou à l'étape suivante
        }

        // Rafraîchir l'affichage après chaque action
        system("cls");
        afficherMenuConfiguration(nbr);
    }
}

void afficherMenuConfiguration(int nbrJoueurs) {
    system("cls"); // Efface l'écran pour éviter le clignotement
    printf(" ___________________\n");
    printf("|                   |\n");
    printf("| NOMBRE DE JOUEURS |\n");
    printf("|    -    %d    +    |\n", nbrJoueurs);
    printf("|___________________|\n");
    printf("\nESC - Retour\n");
    printf("ENTER - Valider\n");
}

void configurerJoueurs(Yams* yams, int nbr) {
    // Initialisation des joueurs ici
    yams->num_players = nbr;
    yams->players = (Player*)malloc(yams->num_players * sizeof(Player));
    for (int i = 0; i < yams->num_players; i++) {
        printf("Entrez le nom du Joueur %d : ", i + 1);
        char player_name[100];
        scanf("%s", player_name);
        effacerBuffer();
        strcpy(yams->players[i].name, player_name);
        yams->players[i].score = 0;
        for (int j = 0; j < 14; j++) {
            yams->players[i].grille[j] = 0;
        }
        memset(yams->players[i].total, 0, sizeof(yams->players[i].total));
    }
    system("cls");
}
