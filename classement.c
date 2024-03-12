#include "include.h"
#include "yams.h"

//Fonction : classement
//Auteur : Valentin paul
//Param : aucun
//Traitement : Cette proc�dure nous permet d'afficher le top 10 des meilleurs scores.
//Retour : Elle ne retourne rien, mais utilise printf pour afficher les joueurs et les scores.

void classement(Yams *yams)
{
    char touch;
 FILE *f = fopen("MeilleursScores.txt", "r");
        if (f == NULL) {
                printf("Il n'y a pas encore de score enregistrer soyez les premier :) \n");
                        }
        char caractere;
     char Nom[50];
     int Score;
      while(fscanf(f,"%s %d",Nom,&Score) == 2)
      {
          printf("Joueur : %-20s Score : %d\n",Nom,Score);
      }
    fclose(f);
    printf("||||||||||||||||||||  - E S C -  Q U I T T E R   ||||||||||||||||||||\n");
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




