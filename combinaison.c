#include "include.h"
#include "yams.h"

/**
 * Fonction : trouverCombinaison
 * Auteur : Clement
 * Param yams : pointeur vers la structure du jeu Yams contenant l'état actuel du jeu.
 * Param validCombinations : pointeur vers un tableau de pointeurs de chaînes de caractères où les combinaisons valides seront stockées.
 * Param validCombinationCount : pointeur vers un entier où le nombre de combinaisons valides trouvées sera stocké.
 * Traitement : Parcourt les combinaisons possibles du jeu Yams et remplit le tableau validCombinations avec les combinaisons que le joueur actuel peut encore utiliser. Met à jour validCombinationCount avec le nombre de combinaisons valides trouvées.
 * Retour : Ne retourne rien directement, mais le tableau validCombinations et la valeur pointée par validCombinationCount seront modifiés pour refléter les combinaisons valides trouvées.
 */

void trouverCombinaison(Yams* yams, char **validCombinations, int* validCombinationCount) {
    const char* allCombinations[] = {"1", "2", "3", "4", "5", "6", "Brelan", "Carré", "Full", "Petite suite", "Grande suite", "Yam's", "Chance"};
    int count = 0;

    for (int i = 0; i < 13; i++) {
        if (yams->players[yams->current_player].grille[i] == 0) {  // Vérifie si la combinaison n'a pas encore été choisie
            if (strcmp(allCombinations[i], "Brelan") == 0 && Brelan(yams->listeDe)) {
                validCombinations[count++] = "Brelan";
            } else if (strcmp(allCombinations[i], "Carré") == 0 && Carre(yams->listeDe)) {
                validCombinations[count++] = "Carré";
            } else if (strcmp(allCombinations[i], "Full") == 0 && Full(yams->listeDe)) {
                validCombinations[count++] = "Full";
            } else if (strcmp(allCombinations[i], "Petite suite") == 0 && PetiteSuite(yams->listeDe)) {
                validCombinations[count++] = "Petite suite";
            } else if (strcmp(allCombinations[i], "Grande suite") == 0 && GrandeSuite(yams->listeDe)) {
                validCombinations[count++] = "Grande suite";
            } else if (strcmp(allCombinations[i], "Yam's") == 0 && YamsCombi(yams->listeDe)) {
                validCombinations[count++] = "Yam's";
            } else if (strcmp(allCombinations[i], "Chance") == 0) {
                validCombinations[count++] = "Chance";
            } else {
                int number = atoi(allCombinations[i]);
                if (number >= 1 && number <= 6 && contientNombre(yams->listeDe, number)) {
                    validCombinations[count++] = allCombinations[i];
                }
            }
        }
    }

    *validCombinationCount = count;
}

/**
 * Fonction : contientNombre
 * Auteur : Clement
 * Param : listeDe - tableau d'entiers des dés lancés, number - entier à rechercher dans le tableau.
 * Traitement : Vérifie si le tableau de dés contient un nombre spécifique.
 * Retour : bool - vrai si le nombre est trouvé, faux sinon.
 */

bool contientNombre(int *listeDe, int number) {
    for (int i = 0; i < 5; i++) {
        if (listeDe[i] == number) {
            return true;
        }
    }
    return false;
}

/**
 * Fonction : GrandeSuite
 * Auteur : Clement
 * Param : list - tableau d'entiers représentant les dés lancés.
 * Traitement : Vérifie si les dés forment une grande suite.
 * Retour : bool - vrai si les dés forment une grande suite, faux sinon.
 */

bool GrandeSuite(int* list) {
    // Vérifie si la liste représente une grande suite (2-3-4-5-6)
    return (list[0] == 2 && list[1] == 3 && list[2] == 4 && list[3] == 5 && list[4] == 6);
}

/**
 * Fonction : PetiteSuite
 * Auteur : Clement
 * Param : list - tableau d'entiers représentant les dés lancés.
 * Traitement : Vérifie si les dés forment une petite suite.
 * Retour : bool - vrai si les dés forment une petite suite, faux sinon.
 */

bool PetiteSuite(int* list) {
    return (list[0] == 1 && list[1] == 2 && list[2] == 3 && list[3] == 4 && list[4] == 5);
}

/**
 * Fonction : Full
 * Auteur : Clement
 * Param : list - tableau d'entiers représentant les dés lancés.
 * Traitement : Vérifie si les dés forment un full (un brelan et une paire).
 * Retour : bool - vrai si les dés forment un full, faux sinon.
 */

bool Full(int* sortedList) {
    // Pour un "Full", soit les trois premiers dés sont identiques et les deux derniers forment une paire, soit l'inverse.
    bool firstCase = (sortedList[0] == sortedList[1]) && (sortedList[1] == sortedList[2]) && (sortedList[3] == sortedList[4]) && (sortedList[2] != sortedList[3]);
    bool secondCase = (sortedList[0] == sortedList[1]) && (sortedList[2] == sortedList[3]) && (sortedList[3] == sortedList[4]) && (sortedList[1] != sortedList[2]);

    return firstCase || secondCase;
}

/**
 * Fonction : max
 * Auteur : Clement
 * Param : a - premier entier, b - second entier.
 * Traitement : Détermine le maximum entre deux entiers.
 * Retour : int - le plus grand des deux entiers.
 */

int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Fonction : Carre
 * Auteur : Clement
 * Param : list - tableau d'entiers représentant les dés lancés.
 * Traitement : Vérifie si les dés forment un carré (quatre dés identiques).
 * Retour : bool - vrai si les dés forment un carré, faux sinon.
 */

bool Carre(int *listeDe) {
    for (int i = 0; i < 2; i++) { // Seulement besoin de commencer à vérifier à partir des deux premiers dés
        int count = 1;
        for (int j = i + 1; j < 5; j++) {
            if (listeDe[i] == listeDe[j]) {
                count++;
            }
        }
        if (count >= 4) {
            return true;
        }
    }
    return false;
}

/**
 * Fonction : YamsCombi
 * Auteur : Clement
 * Param : list - tableau d'entiers représentant les dés lancés.
 * Traitement : Vérifie si les dés forment un Yams (cinq dés identiques).
 * Retour : bool - vrai si les dés forment un Yams, faux sinon.
 */

bool YamsCombi(int *listeDe) {
    for (int i = 1; i < 5; i++) {
        if (listeDe[0] != listeDe[i]) {
            return false;
        }
    }
    return true;
}

/**
 * Fonction : Brelan
 * Auteur : Clement
 * Param : list - tableau d'entiers représentant les dés lancés.
 * Traitement : Vérifie si les dés forment un brelan (trois dés identiques).
 * Retour : bool - vrai si les dés forment un brelan, faux sinon.
 */

bool Brelan(int *listeDe) {
    for (int i = 0; i < 3; i++) { // Seulement besoin de commencer à vérifier à partir des trois premiers dés
        int count = 1;
        for (int j = i + 1; j < 5; j++) {
            if (listeDe[i] == listeDe[j]) {
                count++;
            }
        }
        if (count >= 3) {
            return true;
        }
    }
    return false;
}
