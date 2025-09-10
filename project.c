#include <stdio.h>
#include "project.h"



int main(){
    int choix;
do
{
// system("@cls||clear");

    printf("\n\n==========Menu===========\n\n");
    printf("1)-Ajouter un avion (ou plusieurs).\n");
    printf("2)-Modifier un avion (modele, capacité, statut).\n");
    printf("3)-Supprimer un avion .\n");
    printf("4)-Afficher la liste des avions.\n");
    printf("5)-Rechercher un avion (par id ou par modèle).\n");
    printf("6)-Trier les avions (par capacité, par modèle alphabétique,).\n");
    printf("0)-Quitter .\n");

    printf("choisiez : ");
    scanf("%d",&choix);
    
    switch (choix)
    {
    case 1:
        ajouter();
        break;

    case 2:
        afficher();
        break;

    case 3:
        trier_cap();
        break;

    case 4:
        trier_mod();
        break;

    case 5:
        
        break;

    case 6:
        
        break;
    
    default:
        break;

    }

    

} while (choix!=0);
    return 0;
}