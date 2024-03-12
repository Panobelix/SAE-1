#ifndef YAMS_H
#define YAMS_H

#include <stdbool.h>

typedef struct {
    char name[20];
    int score;
    int total[4];
    int grille[14];
} Player;

typedef struct {
    int num_players;
    Player* players;
    int current_player;
    int* grille;
    int total[4];
    int listeDe[5];
    char** combinaisons;
} Yams;

// Fonctions pour le Yams
void initYams(Yams* yams);
void effacerBuffer();
void classement(Yams *yams);
void joueurConfiguration(Yams* yams);
void montrerScore();
void jeu(Yams* yams);
void trouverCombinaison(Yams* yams, char **validCombinations, int* validCombinationCount);
void menu(Yams* yams);
void afficherScoreJoueur(Yams* yams);
void regle();
void remplacer(Yams* yams, const char* choix);
void sauvegarderScore(char* name, int score);
bool GrandeSuite(int* list);
int max(int a, int b);
bool PetiteSuite(int* list);
bool Full(int* list);
bool Carre(int* list);
bool contientNombre(int *listeDe, int number) ;
bool YamsCombi(int* list);
bool Brelan(int* list);
char* recevoirDate();
void SauvegarderCombo(Yams* yams);
int compareScores(const void* a, const void* b);
void plusHautScore(Yams* yams);
void questionChoix(Yams* yams);
void remplacerCombinaison(Yams* yams);
int choixPossibles(Yams* yams, char **dico, int* dicoSize);
void totalCalcul(Yams* yams);
void freeYams(Yams* yams);
void afficherDes(Yams* yams);
void lancerDes(Yams* yams);
void grille(Yams* yams);
void sauvegardeJeu(Yams* yams, const char* filename);
void chargerPartie(Yams* yams, const char* filename);

#endif // YAMS_H
