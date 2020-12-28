#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menuDeDifficulter();
int menuSoloOuMulti();

int main()
{
    int nombreMystere = 0, nombreATrouve = 1,continuerPartie = 1;
    int MAX = 100, MIN = 1;

    printf("Bienvenu au game: trouve le nombre\n");

    while (continuerPartie)
    {

        int compt = 1;


        switch(menuDeDifficulter())
        {
        case 1:
            printf("Tu as choisi le mode facile tu dois trouver un nombre entre 1 et 100\n");
            break;
        case 2:
            printf("Tu as choisi le mode intermediaire tu dois trouver un nombre entre 1 et 1000\n");
            MAX = 1000;
            break;
        case 3:
            printf("Tu as choisi le mode difficile tu dois trouver un nombre entre 1 et 10000\n");
            MAX = 10000;
        }


            switch(menuSoloOuMulti())
            {
            case 1:
                printf("Tu as choisi le mode Solo\n");
                srand(time(NULL));
                nombreMystere =(rand() % (MAX - MIN +1)) + MIN;
                break;
            case 2:
                printf("Tu as choisi le mode MultiJoueur\n");
                printf("Choisi un nombre et ton partenaire doit le trouvé\n");
                scanf("%d",&nombreMystere);
                break;

            }


        printf("Entre un nombre au clavier pour trouvé le bon chiffre, tu dois trouver un nombre entre %d et %d\n", MIN, MAX);
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
        printf("Voulez-vous recommencer? si oui appuyez sur 1 sinon 0\n");
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


int menuDeDifficulter ()
{
    int choix = 0;

    while( choix < 1 || choix > 3)
    {
        printf("Choisis la difficulte\n");
        printf("===Menu===\n");
        printf("1. facile\n");
        printf("2. intermediaire\n");
        printf("3. Difficile\n");
        printf("Ecrivez le chiffre qui correspond au niveau\n");
        scanf("%d", &choix);
        if (choix < 1 || choix >3)
        {
            printf("Le choix n'est pas bon merci de recommencer\n");
        }
    }

    return choix;
}

int menuSoloOuMulti ()
{
  int choix = 0;

         while(choix < 1 || choix > 2)
        {
            printf("Choisie ton mode de jeux\n");
            printf("===Menu===\n");
            printf("1. En solo\n");
            printf("2. Multijoueur\n");
            printf("Tape un ou deux\n");
            scanf("%d", &choix);

         if (choix<1 || choix > 2)
         {
             printf("Le choix n'est pas bon merci de recommencer\n");
         }
        }
        return choix;
}
