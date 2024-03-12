#include "include.h"
#include "yams.h"

/**
 * Fonction : menu
 * Auteur : Paul
 * Param : yams - pointeur vers la structure Yams qui contient les informations de jeu.
 * Traitement : Affiche le menu principal du jeu et gère la navigation entre les différentes options du menu.
 * Retour : aucun
 */

void menu(Yams* yams) {
    char touch;
    printf("||||||||||||||||||||| - - - - - - - - - - - - - |||||||||||||||||||||\n|||||||||||||||||||||          M E N U          |||||||||||||||||||||\n||||||||||||||||||||| - - - - - - - - - - - - - |||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||    - 1 -  N O U V E L L E  P A R T I E      |||||||||||\n|||||||||||    - 2 -  C H A R G E R  U N E  P A R T I E     |||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||    - 3 -  R E G L E S  D U  J E U       |||||||||||||\n|||||||||||   - 4 -  C L A S S E M E N T  D U  S C O R E    |||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n||||||||||||||||||||                             ||||||||||||||||||||\n||||||||||||||||||||  - E S C -  Q U I T T E R   ||||||||||||||||||||\n||||||||||||||||||||                             ||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    while (1) {
        if (_kbhit()) {  // TOUCHE FRAPPE ?
            touch = _getch();  // R�cup�re la touche frapp�e sans n�cessiter d'appuyer sur Enter
            if (touch == 38){ // TOUCHE NOUVELLE PARTIE
                system("cls");
                joueurConfiguration(yams);
                jeu(yams);
            }

            if (touch == 34){ // TOUCHE REGLES DU JEU
                system("cls");
                regle();
            }
            if (touch == 39){ // TOUCHE CLASSEMENT
                system("cls");
                classement(yams);
            }
            if (touch == 27){ // TOUCHE QUITTER
                system("cls");
                exit(0);
            }
            if (touch = '2'){ // TOUCHE CHARGER UNE PARTIE
                system("cls");
                chargerPartie(yams, "../txt/savegame.txt"); // Charge le jeu à partir du fichier "savegame.txt"
                printf("Partie chargée.\n");
                jeu(yams); // Continue le jeu chargé
            }
            if (touch == '7') {
                system("cls");
                montrerScore(); // Appel de la fonction montrerScore
                system("cls");
                // Pas besoin de rappeler menu(yams) ici car la boucle while dans menu le fera
            }
            if (touch == 'S') {
                system("cls");
                sauvegardeJeu(yams, "../txt/savegame.txt"); // Sauvegarde du jeu dans le fichier "savegame.txt"
                printf("Partie sauvegardée.\n");
            }
        }
    }
}
