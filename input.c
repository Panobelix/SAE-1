#include "include.h"
#include "yams.h"

bool readUserChoice(int* choix, int dicoSize) {
    char input[10];
    printf("| --> Entrez votre choix : ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Erreur lors de la lecture de l'entrée.\n");
        return false; // Indique une erreur de lecture
    }
    input[strcspn(input, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne

    if (strcmp(input, "s") == 0) {
        *choix = -1; // Code spécial pour 'sauvegarder'
        return true;
    }

    long val = strtol(input, NULL, 10);
    if (val < 1 || val > dicoSize) {
        printf("| Choix invalide. Veuillez entrer un nombre entre 1 et %d ou 's' pour sauver.\n", dicoSize);
        return false; // Indique un choix invalide
    }

    *choix = (int)val;
    return true; // Indique un choix valide
}

/**
 * Fonction : recevoirDate
 * Auteur : Paul
 * Param : aucun
 * Traitement : Récupère la date actuelle du système.
 * Retour : char* - une chaîne de caractères représentant la date actuelle au format "JJ-MM-AAAA".
 */

char* recevoirDate() {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    char* date = malloc(11 * sizeof(char));
    strftime(date, 11, "%d-%m-%Y", timeinfo);
    return date;
}
