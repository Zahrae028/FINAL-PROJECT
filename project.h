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
        airport.plane[i].idAvions_n = i+1;
        printf("Entrez le modele d'avion numero %d :",i+1);
        scanf("%s",airport.plane[i].model);



        printf("Entrez la capacite : ");
        scanf("%d",&airport.plane[i].capacite);

        printf("Choisiez status :");
        printf("1)Disponible \n2)En maintenance\n3)En vol");
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
    nbAvions=nbAvions+n;
}

void afficher(){
    for (int i = 0; i < nbAvions; i++)
    {
        printf("l'avion d' Id numero %03d :\n", airport.plane[i].idAvions_n);
        printf(" le modele : %s\n",airport.plane[i].model);
        printf("la capacite : %d\n",airport.plane[i].capacite);
        printf("Statut : %s\n",airport.plane[i].status);
    }
}


void modifier(){
    int id;
    int found =0;
        printf("inserez l'identifiant de l'avion que vous souhaitez modifier :");
        scanf("%d",&id); 

        for (int i = 0; i < nbAvions; i++)
        {
            if (id == airport.plane[i].idAvions_n)
            {

                    found++;
                    printf("Modifier le modele %d :",nbAvions+1);
                    scanf("%s",airport.plane[i].model);

                    printf("Modifier la capacite : ");
                    scanf("%d",&airport.plane[i].capacite);

                    printf("Modifier le status :");
                    printf("1)Disponible \n2)En maintenance\n3)En vol");
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
            
        }
        
        if (found==0)
        {
            printf("id non trouvé.");
        }
        


}

void rech_mod(){
    char mod_rech[50];
    printf("inserer le model pour la recherche :");
    scanf("%s",mod_rech);

    for (int i = 0; i < nbAvions; i++)
    {
        
        if (strcasecmp(airport.plane[i].model,mod_rech)==0)
        {
            printf("l'avion d' Id numero %03d :\n", airport.plane[i].idAvions_n);
            printf(" le modele : %s\n",airport.plane[i].model);
            printf("la capacite : %d\n",airport.plane[i].capacite);
            printf("Statut : %s\n",airport.plane[i].status);
        }
        
    }
    


}
void rech_cap(){
    int cap;
    printf("inserer la capacite :");
    scanf("%d",&cap);
        for (int i = 0; i < nbAvions; i++)
        {
            if (airport.plane[i].capacite == cap)
            {
                printf("l'avion d' Id numero %03d :\n", airport.plane[i].idAvions_n);
                printf(" le modele : %s\n",airport.plane[i].model);
                printf("la capacite : %d\n",airport.plane[i].capacite);
                printf("Statut : %s\n",airport.plane[i].status);
            }
            
        }
        

}


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

                int temp2 = airport.plane[i].idAvions_n;
                airport.plane[i].idAvions_n = airport.plane[j].idAvions_n ;
                airport.plane[j].idAvions_n = temp2 ;

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

                int temp2 = airport.plane[i].idAvions_n;
                airport.plane[i].idAvions_n = airport.plane[j].idAvions_n ;
                airport.plane[j].idAvions_n = temp2 ;

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

void supprimer(){
    int id;
    int found =0;
        printf("inserez l'identifiant de l'avion que vous souhaitez suprimer :");
        scanf("%d",&id); 


        for (int i = 0; i < nbAvions; i++)
        {
            if (id == airport.plane[i].idAvions_n)
            {
                for (int j = i; j < nbAvions; j++)
                {
                    
                    
                    airport.plane[j].capacite = airport.plane[j+1].capacite ;
                    
                    airport.plane[j].idAvions_n = airport.plane[j+1].idAvions_n ;
                    
                    strcpy(airport.plane[j].model , airport.plane[j+1].model);
                    
                    strcpy(airport.plane[j].status , airport.plane[j+1].status);

                    nbAvions--;
                }
                
            }
            
        }
        
}
