/*  Little Game in C langage where the player has to guess a number
    Single player or multiplayer

    By Ulysse Valdenaire
    31/08/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Main Function
int main()
{
    printf("Jeu code en langage C par Ulysse Valdenaire \n");
    printf("Bienvenue dans ce jeu, le but est de deviner un nombre \n");

    //Secret Number
    int nombreMystere;
    //Game mode
    int modeJoueur;
    //Game level
    int level;
    //Random number
    int max;
    const MIN = 1;
    //Player answer
    int rep = 0;
    //Compteur
    int compteur = 0;
    //To continue the game
    int running = 1;

    //Main loop of the game
    while(running)
    {
        //Game mode (1 or 2 players)
        printf("Voulez vous jouez a 1 ou 2 joueurs ? (1)/(2)  ");
        scanf("%d", &modeJoueur);
        //According to the answer
        if(modeJoueur == 1)
        {
            //The player choose the difficulty level
            printf("Choisissez le niveau de difficulte : 1/2/3 : \n");
            scanf("%d", &level);

            switch(level){
             case 1:
                max = 100;
                break;
            case 2:
                max =1000;
                break;
            case 3 :
                max = 10000;
                break;
            }

            //Generate a random number between 0 and and max
            srand(time(NULL));
            nombreMystere = (rand() % (max - MIN + 1)) + MIN;
        }
        else
        {
            printf("Entrez le nombre a faire deviner : ");
            scanf("%d", &nombreMystere);
        }

        //Game loop
        do
        {
            //The player choose a number
            printf("Entrez un nombre entre 0 et %d  ", max);
            scanf("%d", &rep);

            //Tests on the player's answer
            if(nombreMystere > rep)
            {
                printf("C'est plus grand !");
                compteur++;
            }
            else if(nombreMystere < rep)
            {
                printf("C'est plus petit !");
                compteur++;
            }
            else
            {
                printf("Bravo, vous avez trouve le nombre mystere !!!");
                printf("Vous avez reussi en %d coups !", compteur);
            }
        }
        while (rep != nombreMystere);

        //If the player want to play again
        printf("Voulez vous refaire une partie ? yes(1)/no(0) ");
        scanf("%d", &running);
    }

    //If the player wants to stop the game
    printf("Au revoir !");
    return 0;
}