#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int nombreMystere = 0, nombreATrouve = 1,continuerPartie = 1;
    int MAX = 100, MIN = 1;

    printf("Bienvenu au game: trouve le nombre\n");

    while (continuerPartie)
    {

        int compt = 1, choixDuJoueur = 0, niveauDeDifficulte = 0, erreurMenuDifficulte = 1, erreurMenuModeDeJeux = 1;


        while( erreurMenuDifficulte)
        {
            printf("Choisis la difficulte\n");
            printf("===Menu===\n");
            printf("1. facile\n");
            printf("2. intermediaire\n");
            printf("3. Difficile\n");
            printf("Ecrivez le chiffre qui correspond au niveau\n");
            scanf("%d", &niveauDeDifficulte);

            switch(niveauDeDifficulte)
            {
            case 1:
                erreurMenuDifficulte = 0;
                printf("Tu as choisi le mode facile tu dois trouver un nombre entre 1 et 100\n");
                break;
            case 2:
                erreurMenuDifficulte = 0;
                printf("Tu as choisi le mode intermediaire tu dois trouver un nombre entre 1 et 1000\n");
                MAX = 1000;
                break;
            case 3:
                erreurMenuDifficulte = 0;
                printf("Tu as choisi le mode difficile tu dois trouver un nombre entre 1 et 10000\n");
                MAX = 10000;
            default:
                printf("Le choix n'est pas bon merci de recommencer\n");
                break;
            }
        }

        while(erreurMenuModeDeJeux)
        {


            printf("Choisie ton mode de jeux\n");
            printf("===Menu===\n");
            printf("1. En solo\n");
            printf("2. Multijoueur\n");
            printf("Tape un ou deux\n");
            scanf("%d", &choixDuJoueur);

            switch(choixDuJoueur)
            {
            case 1:
                erreurMenuModeDeJeux =0;
                printf("Tu as choisi le mode Solo\n");
                srand(time(NULL));
                nombreMystere =(rand() % (MAX - MIN +1)) + MIN;
                break;
            case 2:
                erreurMenuModeDeJeux =0;
                printf("Tu as choisi le mode MultiJoueur\n");
                printf("Choisi un nombre et ton partenaire doit le trouvé\n");
                scanf("%d",&nombreMystere);
                break;
            default:
                printf("Le choix n'est pas bon merci de recommencer\n");
                break;
            }
        }

        printf("Entre un nombre au clavier pour trouvé le bon chiffre\n");
        scanf("%d",&nombreATrouve);

        while(nombreATrouve != nombreMystere )
        {

            if(nombreATrouve > MAX)
            {
                printf("Le nombre est trop grand recommencez\n");
                scanf("%d",&nombreATrouve);
            }
            else if(nombreATrouve < 0)
            {
                printf("Le nombre est trop petit recommencez\n");
                scanf("%d",&nombreATrouve);
            }
            else if (nombreATrouve < nombreMystere)
            {
                printf("C'est plus recommencez\n");
                scanf("%d",&nombreATrouve);

            }
            else if(nombreATrouve > nombreMystere)
            {
                printf("C'est moins recommencez\n");
                scanf("%d", &nombreATrouve);
            }
            compt++;

        }

        printf("Victoire vous l'avez trouver en %d coups\n",compt);
        printf("Voulez-vous recommencer? si oui appuyez1 sur 1 sinon 0\n");
        scanf("%d", &continuerPartie);

        if (continuerPartie)
        {
            printf("C'est repartit\n");
        }
        else
        {
            printf("Au revoir\n");
        }
    }

    return 0;
}
