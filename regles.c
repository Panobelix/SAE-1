#include "include.h"
#include "yams.h"

/**
 * Fonction : regle
 * Auteur : Paul
 * Param : aucun
 * Traitement : Affiche les règles du jeu Yams.
 * Retour : aucun
 */

void regle()
{
    Yams* yams;
    char touch;
    printf("+----------------------- REGLES -----------------------+\n");
    printf("Le Yams est un jeu qui se joue avec cinq des standard a six faces.\n");
    printf("Le but du jeu est de marquer le plus de points possible en remplissant\n");
    printf("differentes combinaisons sur une feuille de score.\n");
    printf("Voici les regles generales du Yams :\n");
    printf("Comment se deroule le jeu :\n");
    printf("Chaque joueur lance les cinq des lors de son tour.\n");
    printf("Le joueur a le droit de relancer un ou tous les des.\n");
    printf("Apres les lancers, le joueur choisit une combinaison a inscrire sur sa feuille de score.\n");
    printf("Les combinaisons comprennent des elements tels que les brelans, les carres, les suites, le Yams (cinq des identiques), etc.\n");
    printf("Le joueur marque des points en fonction de la combinaison choisie et des des obtenus.\n");
    printf("Par exemple, si le joueur obtient trois des identiques, il marque la somme de tous les des.\n");
    printf("Les combinaisons spaciales comme le Yams peuvent rapporter davantage de points.\n");
    printf("Le joueur remplit sa feuille de score en inscrivant les points dans la case appropriee.\n");
    printf("Une fois une combinaison choisie et les points marques, elle ne peut plus etre utilisee dans les tours suivants.\n");
    printf("Le jeu se compose de plusieurs tours, generalement 13, au cours desquels les joueurs remplissent leur feuille de score.\n");
    printf("Une fois que toutes les combinaisons ont ete remplies, le joueur avec le score total le plus eleve remporte la partie.\n");
    printf("Exemples de combinaisons :\n");
    printf("Brelan : Trois des identiques.\n");
    printf("Carre : Quatre des identiques.\n");
    printf("Full : Un brelan et une paire.\n");
    printf("Petite suite : 1, 2, 3, 4, 5.\n");
    printf("Grande suite : 2, 3, 4, 5, 6.\n");
    printf("Yams : Cinq des identiques.\n");
    printf("Chaque combinaison a des regles specifiques pour marquer des points.\n");
    printf("La strategie consiste a choisir judicieusement la combinaison qui maximise le score en fonction des des obtenus !\n");
    printf("+------------------------------------------------------+\n");
    printf("  Tapez sur 'Echap' pour quitter ... ");
    while (1) {
        if (_kbhit()) {  // V�rifie si une touche a �t� frapp�e
            touch = _getch();  // R�cup�re la touche frapp�e sans n�cessiter d'appuyer sur Enter
            if (touch == 27){
                system("cls");
                menu(yams);
            }
        }
    }
}
