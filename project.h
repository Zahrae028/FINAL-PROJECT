#include <stdio.h>
#include "vars.h"

void ajouter(){
    int n;
    printf("Combien d'avion pour ajouter :");
    scanf("%d",&n);

    int N  = nbAvions + n;

    for (int i = nbAvions; i < N; i++)
    {   
        plane[i].idAvions=i;
        printf("Entrez le modele d'avion de ID numero %d :",plane[i].idAvions);
        scanf("%s",plane[i].model);

        printf("Entrez la capacite : ");
        scanf("%d",plane[i].capacite);

        
    }
    
}


void modifier(){}
void afficher(){}
void rech_mod(){}
void rech_id(){}
void tirer_mod(){}
void tirer_id(){}
