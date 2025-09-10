#include <stdio.h>
#include <string.h>
#include "vars.h"

void ajouter(){
    int n;
    printf("Combien d'avion pour ajouter :");
    scanf("%d",&n);

    int N = nbAvions + n;

    for (int i = nbAvions; i < N; i++)
    {   
        airport.plane[i].idAvions =i;
        printf("Entrez le modele d'avion de ID numero %d :",airport.plane[i].idAvions);
        scanf("%s",airport.plane[i].model);

        printf("Entrez la capacite : ");
        scanf("%d",&airport.plane[i].capacite);

        printf("Choose status :");
        printf("1)");
        scanf("%d",&c_status);


        switch (c_status)
        {
        case 1:
        strcpy(airport.plane[i].status, t_status[0]);
            break;


        case 2:
        strcpy(airport.plane[i].status, t_status[1]);
            break;


        case 3:
        strcpy(airport.plane[i].status, t_status[2]);
            break;


        default:
            break;
        }
        
    }
    nbAvions=nbAvions+N;
}

void afficher(){
    for (int i = 0; i < nbAvions; i++)
    {
        printf("l'avion d' Id numero %d :\n",airport.plane[i].idAvions);
        printf(" le modele : %s\n",airport.plane[i].model);
        printf("la capacite : %d\n",airport.plane[i].capacite);
        printf("Statut : %s\n",airport.plane[i].status);
    }
}


void modifier(){}

void rech_mod(){}
void rech_id(){}

// void swap(int i , int j){

//                 int temp = airport.plane[i].capacite;
//                 airport.plane[i].capacite = airport.plane[j].capacite ;
//                 airport.plane[j].capacite = temp ;

//                 char h[50];
//                 strcpy(h,airport.plane[i].idAvions);
//                 strcpy(airport.plane[i].idAvions , airport.plane[j].idAvions);
//                 strcpy(airport.plane[j].idAvions , h);

//                 char s[50];
//                 strcpy(s,airport.plane[i].model);
//                 strcpy(airport.plane[i].model , airport.plane[j].idAvions);
//                 strcpy(airport.plane[j].idAvions , s);

//                 char k[50];
//                 strcpy(k,airport.plane[i].status);
//                 strcpy(airport.plane[i].status , airport.plane[j].status);
//                 strcpy(airport.plane[j].status , k);

// }
void trier_mod(){

    for (int i = 0; i < nbAvions; i++)
    {
        for (int j = i+1; j < nbAvions ;j++)
        {
            if (strcmp(airport.plane[i].model,airport.plane[j].model)>0)
            {
                int temp = airport.plane[i].capacite;
                airport.plane[i].capacite = airport.plane[j].capacite ;
                airport.plane[j].capacite = temp ;

                int temp2 = airport.plane[i].idAvions;
                airport.plane[i].idAvions = airport.plane[j].idAvions ;
                airport.plane[j].idAvions = temp2 ;

                char s[50];
                strcpy(s,airport.plane[i].model);
                strcpy(airport.plane[i].model , airport.plane[j].model);
                strcpy(airport.plane[j].model , s);

                char k[50];
                strcpy(k,airport.plane[i].status);
                strcpy(airport.plane[i].status , airport.plane[j].status);
                strcpy(airport.plane[j].status , k);
            }
        }        
    }    
}

void trier_cap(){


    for (int i = 0; i < nbAvions; i++)
    {
        for (int j = i+1; j <nbAvions ; j++)
        {
            if (airport.plane[i].capacite < airport.plane[j].capacite)
            {
                int temp = airport.plane[i].capacite;
                airport.plane[i].capacite = airport.plane[j].capacite ;
                airport.plane[j].capacite = temp ;

                int temp2 = airport.plane[i].idAvions;
                airport.plane[i].idAvions = airport.plane[j].idAvions ;
                airport.plane[j].idAvions = temp2 ;

                char s[50];
                strcpy(s,airport.plane[i].model);
                strcpy(airport.plane[i].model , airport.plane[j].model);
                strcpy(airport.plane[j].model , s);

                char k[50];
                strcpy(k , airport.plane[i].status);
                strcpy(airport.plane[i].status , airport.plane[j].status);
                strcpy(airport.plane[j].status , k);
            }            
        }        
    }    
}

