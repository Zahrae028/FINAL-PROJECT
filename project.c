#include <stdio.h>
#include "project.h"

int main()
{
    int choix;
    int tri;
    int rech;

    printf("Entrer le nom de l'aeroport : ");
    getchar();
    scanf("%[^\n]", airport.name);

    do
    {
        // system("@cls||clear");

        printf("\n\n==========Menu===========\n\n");
        printf("1)-Ajouter un avion (ou plusieurs) .\n");
        printf("2)-Modifier un avion (modele, capacité, statut) .\n");
        printf("3)-Supprimer un avion .\n");
        printf("4)-Afficher la liste des avions.\n");
        printf("5)-Rechercher un avion (par id ou par modele) .\n");
        printf("6)-Trier les avions (par capacite, par modele alphabetique,par date d'entree) .\n");
        printf("7)-Statistiaues . \n");
        printf("0)-Quitter .\n");

        printf("choisiez : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouter();
            break;

        case 2:
            modifier();
            break;

        case 3:
            supprimer();
            break;

        case 4:
            afficher();
            break;

        case 5:

            printf("choisir la methode de recherche : \n");
            printf("1) par ID \n2) par model \n");
            scanf("%d", &rech);
            switch (rech)
            {
            case 1:
                rech_id();
                break;
            case 2:
                rech_mod();
                break;
            default:
                printf("pas une option disponible .");
                break;
            }
            break;

        case 6:

            printf("choisir la methode de tri : \n");
            printf("1) par capacite \n2) par model \n3) par date d'entree\n");
            scanf("%d", &tri);

            switch (tri)
            {
            case 1:
                trier_cap();
                afficher();
                break;
            case 2:
                trier_mod();
                afficher();
                break;
            case 3:
                trier_date();
                afficher();
                break;
            default:
                printf("pas une option disponible .");
                break;
            }

            break;

        case 7:
            statistiques();
            break;

        case 0:
            printf("Merci beaucoup d'avoir utilise notre programme!!!");
            break;

        default:
            break;
        }

    } while (choix != 0);
    return 0;
}