#include "include.h"
#include "yams.h"
/**
 * Fonction : montrerScore
 * Auteur : Valentin
 * Param : yams - pointeur vers la structure Yams qui contient les informations de jeu.
 * Traitement : Affiche le score actuel de la partie en cours.
 * Retour : aucun
 */

void montrerScore()
{
    printf(" +----------------------- SCORES -----------------------+ \n");
    printf(" |                                                      | \n");
    FILE* file = fopen("../txt/sae.txt", "r");
    if (file != NULL) {
        char line[100];
        int cpt = 1;
        while (fgets(line, sizeof(line), file)) {
            char* name = strtok(line, "$");
            char* score = strtok(NULL, "$");
            char* comment = strtok(NULL, "$");
            printf("| |   %d/ %s => %s  (%s)                          | |\n", cpt, name+1, score, comment);
            cpt++;
        }
        fclose(file);
    }
    printf(" |                                                      | \n");
    printf(" +------------------------------------------------------+ \n");
    printf("  Tapez sur 'Entrée' pour quitter ... ");
    getchar();
    effacerBuffer();
}

/**
 * Fonction : afficherScoreJoueur
 * Auteur : Valentin
 * Param : yams - pointeur vers la structure Yams qui contient les informations de jeu.
 * Traitement : Affiche le score final de chaque joueur à la fin de la partie.
 * Retour : aucun
 */

void afficherScoreJoueur(Yams* yams) {
    printf(" +-------------------- SCORES FINAUX --------------------+ \n");
    printf(" |                                                      | \n");

    // Calculate final scores
    for (int i = 0; i < yams->num_players; i++) {
        int upper_score = 0;
        int lower_score = 0;
        for (int j = 0; j < 6; j++) {
            upper_score += yams->players[yams->current_player].grille[j];
        }
        for (int j = 6; j < 14; j++) {
            if (yams->players[yams->current_player].grille[j] != 0 && yams->players[yams->current_player].grille[j] != -1) {
                lower_score += yams->players[yams->current_player].grille[j];
            }
        }
        yams->players[i].score = upper_score + lower_score;
    }

    // Display final scores
    for (int i = 0; i < yams->num_players; i++) {
        printf(" | %s: %d                                                                                | \n", yams->players[i].name, yams->players[i].score);
    }

    printf(" |                                                      | \n");
    printf(" +--------------------------+ \n");

    char choice;
    printf(" Entrez 'q' pour quitter ou 'n' pour une nouvelle partie : ");
    scanf(" %c", &choice);
    effacerBuffer();

    if (choice == 'q') {
        printf(" Au revoir ...                                            \n");
        printf("+-----------------------------------------------------------+\n");
        exit(0);
    } else if (choice == 'n') {
        joueurConfiguration(yams);
        jeu(yams);
    } else {
        printf("| Choix invalide. Veuillez entrer 'q' pour quitter ou 'n' pour une nouvelle partie. |\n");
        afficherScoreJoueur(yams);
    }
}

//Fonction : Meilleur_score
//Auteur :Valentin
//Param :int score,char Nomjoueur[]
// Traitement : Cette proc�dure permet de v�rifier si le score du joueur doit �tre ajout� au fichier du top 10 des meilleurs scores.
//              Sa v�ritable fonction est de v�rifier si le fichier existe ou non. En fonction de la r�ponse � cette question,
//              elle appellera la proc�dure appropri�e. Cette proc�dure joue le r�le de contr�leur.
// Retour : Elle ne renvoie rien.

void Meilleur_score(int score,char Nomjoueur[])
    {
        FILE *f = fopen("MeilleursScores.txt", "r");
        if (f == NULL) {
                Ecrire_score_fichier_vide(score, Nomjoueur);
                        }
        else{Ecrire_score_fichier(score, Nomjoueur);
        fclose(f);
        }
    }

// Fonction : Ecrire_score_fichier_vide
// Auteur: Valentin
// Param: int score, char Nomjoueur[]
// Traitement : Dans le cas o� le contr�leur a d�tect� que le fichier n'existait pas, on entre dans cette proc�dure.
//              Elle cr�e le fichier "MeilleursScores.txt" s'il n'existe pas et y ajoute le joueur avec son score.
// Retour: Elle ne renvoie rien.

void Ecrire_score_fichier_vide(int NouveauScore,char NouveauNomJoueur[])
    {
        FILE *f = fopen("MeilleursScores.txt", "w");

         fprintf(f, "%s\n%d\n", NouveauNomJoueur, NouveauScore);
         fclose(f);
    }

//Fonction : Ecrire_score_fichier
//Auteur : Valentin
//Param : int score, char Nomjoueur[]
//Traitement : Dans le cas o� le contr�leur a d�tect� que le fichier existait, on entre dans cette proc�dure. Elle va r�cup�rer toutes les valeurs
//             qui sont dans le fichier, ajouter � la liste des scores celui que l'on souhaite ajouter et
//             faire la m�me chose avec le nom.Cet ajout se fait de mani�re � ce que la liste reste tri�e.
//             Une fois cette �tape pass�e, la proc�dure va enregistrer les 10
//             premiers scores et noms, sans prendre le dernier car il s'agit d'un top 10.
//Retour : Elle ne renvoie rien, mais a mis � jour le top 10.

void Ecrire_score_fichier(int Score,char NomJoueur[])
    {
        FILE *f = fopen("MeilleursScores.txt", "r");
        if (f == NULL) {
                printf("Erreur lors de l'ouverture du fichier pour l'enregistrement du meilleur score Fonction:Ecrire_score_fichier.\n");
                        }
    char **ListeNomJoueur = NULL;
    int *ListeScore = NULL;
    int NombreJoueurs = 0;
    char RecuperationNoms[50];
   while (fgets(RecuperationNoms, sizeof(RecuperationNoms), f) != NULL)
{

    ListeNomJoueur = realloc(ListeNomJoueur, (NombreJoueurs + 1) * sizeof(char *));
    ListeNomJoueur[NombreJoueurs] = strdup(RecuperationNoms);
    ListeNomJoueur[NombreJoueurs][strlen(ListeNomJoueur[NombreJoueurs]) - 1] = '\0'; // Supprimer le saut de ligne


    fgets(RecuperationNoms, sizeof(RecuperationNoms), f);


    ListeScore = realloc(ListeScore, (NombreJoueurs + 1) * sizeof(int));
    ListeScore[NombreJoueurs] = atoi(strtok(RecuperationNoms, "\n"));

    NombreJoueurs++;
}
    fclose(f);

    ListeNomJoueur = realloc(ListeNomJoueur, (NombreJoueurs + 1) * sizeof(char *));
    ListeScore = realloc(ListeScore, (NombreJoueurs + 1) * sizeof(int));

    int i=0;
    printf("Liste des joueurs et scores :\n");
    for (int i = 0; i < NombreJoueurs; i++) {
        printf("Nom: %s, Score: %d\n", ListeNomJoueur[i], ListeScore[i]);
    }
     NombreJoueurs++;
    printf("\n");
    while(i<NombreJoueurs)
        { int test = ListeScore[i];

        if (Score >= ListeScore[i] && i == 0){

        for (int j = NombreJoueurs - 1; j > i; j--)
        {
            ListeNomJoueur[j] = ListeNomJoueur[j - 1];
            ListeScore[j] = ListeScore[j - 1];
        }


        ListeScore[i] = Score;
        ListeNomJoueur[i] = strdup(NomJoueur);


        i = NombreJoueurs;
                        }


        else if (Score <= ListeScore[i] && i == NombreJoueurs - 1)
        {
             ListeScore[i] = Score;
        ListeNomJoueur[i] = strdup(NomJoueur);


        i = NombreJoueurs;
        }
        else if (Score <= ListeScore[i] && Score >= ListeScore[i + 1])
    {

        for (int j = NombreJoueurs - 1; j > i; j--)
        {
            ListeNomJoueur[j] = ListeNomJoueur[j - 1];
            ListeScore[j] = ListeScore[j - 1];
        }


        ListeScore[i + 1] = Score;
        ListeNomJoueur[i + 1] = strdup(NomJoueur);

        i = NombreJoueurs;
    }
        i++;

        }

    f = fopen("MeilleursScores.txt", "w");
    if (f == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier pour l'enregistrement du meilleur score Fonction:Ecrire_score_fichier");
        for (int i = 0; i < NombreJoueurs; i++)
        {
            free(ListeNomJoueur[i]);
        }
        free(ListeNomJoueur);
        free(ListeScore);
        return;
    }

    if(NombreJoueurs>10){NombreJoueurs=10;}
    for (int i = 0; i < NombreJoueurs; i++)
    {
        fprintf(f, "%s\n%d\n", ListeNomJoueur[i], ListeScore[i]);
        free(ListeNomJoueur[i]);
    }

    fclose(f);
    free(ListeNomJoueur);
    free(ListeScore);




    }


/**
 * Fonction : SauvegarderCombo
 * Auteur : Valentin
 * Param : yams - pointeur vers la structure Yams contenant les données de jeu.
 * Traitement : Permet à l'utilisateur de choisir une combinaison pour enregistrer le score actuel.
 * Retour : aucun
 */

void SauvegarderCombo(Yams* yams) {
    int validCombinationCount = 0;
    char* validCombinations[13]; // Puisqu'il y a 13 combinaisons possibles

    // Trouver les combinaisons valides
    trouverCombinaison(yams, validCombinations, &validCombinationCount);

    if (validCombinationCount == 0) {
        printf("| Aucune combinaison disponible pour sauvegarder.\n");
        return;
    }

    printf("| Combinaisons disponibles pour sauvegarder le score :\n");
    for (int i = 0; i < validCombinationCount; i++) {
        printf("| %d/ %s\n", i + 1, validCombinations[i]);
    }

    printf("| Choisissez une combinaison pour sauvegarder le score :  |\n| (Entrez le nom de la combinaison) : ");
    char choix[100];
    fgets(choix, sizeof(choix), stdin);
    choix[strcspn(choix, "\n")] = '\0';

    // Vérifier si le choix est valide
    bool choixValide = false;
    for (int i = 0; i < validCombinationCount; i++) {
        if (strcmp(choix, validCombinations[i]) == 0) {
            choixValide = true;
            break;
        }
    }

    if (choixValide) {
        remplacer(yams, choix);
        printf("| Score sauvegardé pour '%s'.\n", choix);
    } else {
        printf("| Choix invalide. Veuillez réessayer.\n");
    }
}

/**
 * Fonction : plusHautScore
 * Auteur : Valentin
 * Param : aucun
 * Traitement : Enregistre les dix meilleurs scores dans un fichier texte "MeilleursScores.txt".
 * Retour : aucun
 */

void plusHautScore(Yams* yams) {
    // Tri des scores des joueurs
    qsort(yams->players, yams->num_players, sizeof(Player), compareScores);

    FILE* file = fopen("../txt/MeilleursScores.txt", "w");
    if (file != NULL) {
        fprintf(file, "Top 10 Scores\n");
        // Écrire les 10 meilleurs scores ou le nombre total de joueurs si moins de 10
        int topCount = yams->num_players < 10 ? yams->num_players : 10;
        for (int i = 0; i < topCount; i++) {
            fprintf(file, "%s: %d\n", yams->players[i].name, yams->players[i].score);
        }
        fclose(file);
    } else {
        printf("Erreur d'ouverture du fichier MeilleursScores.txt\n");
    }
}

/**
 * Fonction : sauvegardeJeu
 * Auteur : Valentin
 * Param : yams - pointeur vers la structure Yams contenant l'état de jeu actuel, filename - chaîne de caractères représentant le nom du fichier où sauvegarder le jeu.
 * Traitement : Sauvegarde l'état actuel du jeu dans un fichier pour permettre la reprise de la partie plus tard.
 * Retour : aucun
 */

void sauvegardeJeu(Yams* yams, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    // Sauvegarde du nombre de joueurs et du joueur actuel
    fprintf(file, "%d\n%d\n", yams->num_players, yams->current_player);

    // Sauvegarde des informations de chaque joueur
    for (int i = 0; i < yams->num_players; i++) {
        fprintf(file, "%s\n", yams->players[i].name);
        for (int j = 0; j < 14; j++) {
            fprintf(file, "%d ", yams->players[i].grille[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

/**
 * Fonction : chargerPartie
 * Auteur : Valentin
 * Param : yams - pointeur vers la structure Yams où charger l'état de jeu, filename - chaîne de caractères représentant le nom du fichier à partir duquel charger le jeu.
 * Traitement : Charge une partie précédemment sauvegardée à partir d'un fichier, en restaurant l'état du jeu.
 * Retour : aucun
 */

void chargerPartie(Yams* yams, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier de sauvegarde.\n");
        return;
    }

    // Lecture du nombre de joueurs et du joueur actuel
    fscanf(file, "%d", &yams->num_players);
    fscanf(file, "%d", &yams->current_player);

    // Allocation de mémoire pour les joueurs
    yams->players = (Player*)calloc(yams->num_players, sizeof(Player));
    if (yams->players == NULL) {
        printf("Erreur d'allocation de mémoire pour yams->players.\n");
        fclose(file);
        return;
    }

    // Lecture des informations de chaque joueur
    for (int i = 0; i < yams->num_players; i++) {
        fscanf(file, "%s", yams->players[i].name);
        for (int j = 0; j < 14; j++) {
            fscanf(file, "%d", &yams->players[i].grille[j]);
        }
    }

    fclose(file);
}

/**
 * Fonction : compareScores
 * Auteur : Valentino
 * Param : a - pointeur vers le premier joueur, b - pointeur vers le deuxième joueur.
 * Traitement : Compare les scores de deux joueurs pour le tri.
 * Retour : int - différence des scores pour la fonction de tri qsort.
 */

int compareScores(const void* a, const void* b) {
    Player* playerA = (Player*)a;
    Player* playerB = (Player*)b;
    return playerB->score - playerA->score;
}
