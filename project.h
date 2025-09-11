#include <stdio.h>
#include <string.h>
#include "vars.h"


void ajouter()
{
    if (nbAvions < 100)
    {

        int n;
        printf("Combien d'avion pour ajouter :");
        scanf("%d", &n);

        int N = nbAvions + n;
        if (N > 100)
        {
            printf("Vous ne pouvez pas depasser 100 avions !!!");
        }
        else
        {
            for (int i = nbAvions; i < N; i++)
            {
                airport.plane[i].idAvions_n = i + 1;
                printf("Entrez le modele d'avion numero %d :", i + 1);
                getchar();
                scanf("%[^\n]", airport.plane[i].model);

                do
                {
                    printf("Entrez la capacite : ");
                    scanf("%d", &airport.plane[i].capacite);
                    if (airport.plane[i].capacite < 0)
                    {
                        printf("Veuilez ressayer");
                    }

                } while (airport.plane[i].capacite < 0);
                int invalid = 1;
                do
                {
                    invalid--;
                    printf("Choisiez status :\n");
                    printf("\n1)Disponible \n2)En maintenance\n3)En vol\n");
                    scanf("%d", &c_status);

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
                        printf("invalid. ressayez.\n");
                        invalid++;
                        break;
                    }
                } while (invalid != 0);

                do{
                    printf("Entrez ma date d'entree (jj/mm/aaaa) :\n");
                    scanf("%d/%d/%d",&airport.plane[i].date.jour ,&airport.plane[i].date.mois ,&airport.plane[i].date.annee);
                    if (airport.plane[i].date.mois >12 || airport.plane[i].date.jour > 31)
                    {
                        printf("Invalide date !!!!!!\n");
                    }
                    
                }while (airport.plane[i].date.mois >12 || airport.plane[i].date.jour > 31);
                

            }
            nbAvions = nbAvions + n;
        }
    }
    else
    {
        printf("Vous ne pouvez pas depasser 100 avions !!!");
    }
}

void trier_date(){


    for (int i = 0; i < nbAvions; i++)
    {
        for (int j = i+1; j < nbAvions; j++)
        {
            if((airport.plane[i].date.annee >airport.plane[j].date.annee )|| (airport.plane[i].date.annee == airport.plane[j].date.annee && airport.plane[i].date.mois > airport.plane[j].date.mois) || (airport.plane[i].date.annee == airport.plane[j].date.annee && airport.plane[i].date.mois == airport.plane[j].date.mois && airport.plane[i].date.jour > airport.plane[j].date.jour))
            {
                int temp = airport.plane[i].capacite;
                airport.plane[i].capacite = airport.plane[j].capacite;
                airport.plane[j].capacite = temp;

                int temp2 = airport.plane[i].idAvions_n;
                airport.plane[i].idAvions_n = airport.plane[j].idAvions_n;
                airport.plane[j].idAvions_n = temp2;

                char s[50];
                strcpy(s, airport.plane[i].model);
                strcpy(airport.plane[i].model, airport.plane[j].model);
                strcpy(airport.plane[j].model, s);

                char k[50];
                strcpy(k, airport.plane[i].status);
                strcpy(airport.plane[i].status, airport.plane[j].status);
                strcpy(airport.plane[j].status, k);

                int date_a = airport.plane[i].date.annee;
                airport.plane[i].date.annee = airport.plane[j].date.annee ;
                airport.plane[j].date.annee = date_a ;

                int date_m = airport.plane[i].date.mois;
                airport.plane[i].date.mois = airport.plane[j].date.mois ;
                airport.plane[j].date.mois = date_m ;

                int date_j = airport.plane[i].date.jour;
                airport.plane[i].date.jour = airport.plane[j].date.jour ;
                airport.plane[j].date.jour = date_j ;

            // printf("%d/%d/%d est plus tôt que %d/%d/%d ",airport.plane[i].date.jour,month1,year1,day2,month2,year2);


            }
        }
        
    
    
        

    }
}


void afficher()
{
    printf("Aeroport de %s \n",airport.name);
    for (int i = 0; i < nbAvions; i++)
    {
        printf("l'avion d' Id numero %03d :\n", airport.plane[i].idAvions_n);
        printf(" le modele : %s\n", airport.plane[i].model);
        printf("la capacite : %d\n", airport.plane[i].capacite);
        printf("Statut : %s\n", airport.plane[i].status);
        printf("La date d'entree : %d/%d/%d \n",airport.plane[i].date.jour ,airport.plane[i].date.mois ,airport.plane[i].date.annee);
        printf("\n======================================\n");

    }
}

void modifier()
{
    int id;
    int found = 0;
    printf("inserez l'identifiant de l'avion que vous souhaitez modifier :");
    scanf("%d", &id);

    for (int i = 0; i < nbAvions; i++)
    {
        if (id == airport.plane[i].idAvions_n)
        {

            found++;
            printf("Modifier le modele %d :", nbAvions + 1);
            getchar();
            scanf("%[^\n]", airport.plane[i].model);

            do
                {
                    printf("\nModifier la capacite : ");
                    scanf("%d", &airport.plane[i].capacite);
                    if (airport.plane[i].capacite < 0)
                    {
                        printf("Veuilez ressayer");
                    }

                } while (airport.plane[i].capacite < 0);

            int invalid = 1;
            do{
                invalid--;
                printf("Modifier le status :\n");
                printf("1)Disponible \n2)En maintenance\n3)En vol\n");
                scanf("%d", &c_status);

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
            } while (invalid != 0);
            do{
                    printf("Modifier ma date d'entree (jj/mm/aaaa) :\n");
                    scanf("%d/%d/%d",&airport.plane[i].date.jour ,&airport.plane[i].date.mois ,&airport.plane[i].date.annee);
                    if (airport.plane[i].date.mois >12 || airport.plane[i].date.jour > 31)
                    {
                        printf("Invalide date !!!!!!\n");
                    }
                    
                }while (airport.plane[i].date.mois >12 || airport.plane[i].date.jour > 31);
        }
    }

    if (found == 0)
    {
        printf("id non trouvé.");
    }
}

void rech_mod()
{
    int found = 0;
    char mod_rech[50];
    printf("inserer le model pour la recherche :");
    scanf("%s", mod_rech);

    for (int i = 0; i < nbAvions; i++)
    {

        if (strcasecmp(airport.plane[i].model, mod_rech) == 0)
        {
            found++;
            printf("l'avion d' Id numero %03d :\n", airport.plane[i].idAvions_n);
            printf(" le modele : %s\n", airport.plane[i].model);
            printf("la capacite : %d\n", airport.plane[i].capacite);
            printf("Statut : %s\n", airport.plane[i].status);
            printf("La date d'entree : %d/%d/%d \n",airport.plane[i].date.jour ,airport.plane[i].date.mois ,airport.plane[i].date.annee);
        }
    }

    if (found == 0)
    {
        printf("modele non trouvé.");
    }
}

void rech_id()
{
    int found = 0;
    int id;
    printf("inserer l' ID :");
    scanf("%d", &id);
    for (int i = 0; i < nbAvions; i++)
    {   
        if (airport.plane[i].idAvions_n == id)
        {
            found++;
            printf("l'avion d' Id numero %03d :\n", airport.plane[i].idAvions_n);
            printf(" le modele : %s\n", airport.plane[i].model);
            printf("la capacite : %d\n", airport.plane[i].capacite);
            printf("Statut : %s\n", airport.plane[i].status);
            printf("La date d'entree : %d/%d/%d \n",airport.plane[i].date.jour ,airport.plane[i].date.mois ,airport.plane[i].date.annee);
        }
    }
    if (found==0)
    {
        printf("id non trouvé.");
    }
    
    
}

void trier_mod()
{

    for (int i = 0; i < nbAvions; i++)
    {
        for (int j = i + 1; j < nbAvions; j++)
        {
            if (strcasecmp(airport.plane[i].model, airport.plane[j].model) > 0)
            {
                int temp = airport.plane[i].capacite;
                airport.plane[i].capacite = airport.plane[j].capacite;
                airport.plane[j].capacite = temp;

                int temp2 = airport.plane[i].idAvions_n;
                airport.plane[i].idAvions_n = airport.plane[j].idAvions_n;
                airport.plane[j].idAvions_n = temp2;

                char s[50];
                strcpy(s, airport.plane[i].model);
                strcpy(airport.plane[i].model, airport.plane[j].model);
                strcpy(airport.plane[j].model, s);

                char k[50];
                strcpy(k, airport.plane[i].status);
                strcpy(airport.plane[i].status, airport.plane[j].status);
                strcpy(airport.plane[j].status, k);

                int date_a = airport.plane[i].date.annee;
                airport.plane[i].date.annee = airport.plane[j].date.annee ;
                airport.plane[j].date.annee = date_a ;

                int date_m = airport.plane[i].date.mois;
                airport.plane[i].date.mois = airport.plane[j].date.mois ;
                airport.plane[j].date.mois = date_m ;

                int date_j = airport.plane[i].date.jour;
                airport.plane[i].date.jour = airport.plane[j].date.jour ;
                airport.plane[j].date.jour = date_j ;
            }
        }
    }
}

void trier_cap()
{

    for (int i = 0; i < nbAvions; i++)
    {
        for (int j = i + 1; j < nbAvions; j++)
        {
            if (airport.plane[i].capacite < airport.plane[j].capacite)
            {
                int temp = airport.plane[i].capacite;
                airport.plane[i].capacite = airport.plane[j].capacite;
                airport.plane[j].capacite = temp;

                int temp2 = airport.plane[i].idAvions_n;
                airport.plane[i].idAvions_n = airport.plane[j].idAvions_n;
                airport.plane[j].idAvions_n = temp2;

                char s[50];
                strcpy(s, airport.plane[i].model);
                strcpy(airport.plane[i].model, airport.plane[j].model);
                strcpy(airport.plane[j].model, s);

                char k[50];
                strcpy(k, airport.plane[i].status);
                strcpy(airport.plane[i].status, airport.plane[j].status);
                strcpy(airport.plane[j].status, k);

                int date_a = airport.plane[i].date.annee;
                airport.plane[i].date.annee = airport.plane[j].date.annee ;
                airport.plane[j].date.annee = date_a ;

                int date_m = airport.plane[i].date.mois;
                airport.plane[i].date.mois = airport.plane[j].date.mois ;
                airport.plane[j].date.mois = date_m ;

                int date_j = airport.plane[i].date.jour;
                airport.plane[i].date.jour = airport.plane[j].date.jour ;
                airport.plane[j].date.jour = date_j ;
            }
        }
    }
}



void supprimer()
{
    int id;
    int found = 0;
    printf("inserez l'identifiant de l'avion que vous souhaitez suprimer :");
    scanf("%d", &id);

    for (int i = 0; i < nbAvions; i++)
    {
        if (id == airport.plane[i].idAvions_n)
        {
            for (int j = i; j < nbAvions; j++)
            {

                airport.plane[j].capacite = airport.plane[j + 1].capacite;

                airport.plane[j].idAvions_n = airport.plane[j + 1].idAvions_n;

                strcpy(airport.plane[j].model, airport.plane[j + 1].model);

                strcpy(airport.plane[j].status, airport.plane[j + 1].status);

                airport.plane[j].date.jour = airport.plane[j + 1].date.jour ;

                airport.plane[j].date.mois = airport.plane[j + 1].date.mois ;

                airport.plane[j].date.annee = airport.plane[j + 1].date.annee ;

                
                
            }
            found++;
            nbAvions--;
        }
    }

    if (found == 0)
    {
        printf("id non trouvé.");
    }
}
void largest()
{
    int index_largest = 0;
    int largest = airport.plane[index_largest].capacite;

    for (int i = 0; i < nbAvions; i++)
    {
        if (largest < airport.plane[i].capacite)
        {
            largest = airport.plane[i].capacite;
            index_largest = i;
        }
    }

    printf("\nl'avion avec la plus grande capacite est :\n");
    printf("l'avion d' Id numero %03d :\n", airport.plane[index_largest].idAvions_n);
    printf(" le modele : %s\n", airport.plane[index_largest].model);
    printf("la capacite : %d\n", airport.plane[index_largest].capacite);
    printf("Statut : %s\n", airport.plane[index_largest].status);
    printf("La date d'entree : %d/%d/%d \n",airport.plane[index_largest].date.jour ,airport.plane[index_largest].date.mois ,airport.plane[index_largest].date.annee);
}

void smallest()
{
    int index_smallest = 0;
    int smallest = airport.plane[index_smallest].capacite;

    for (int i = 0; i < nbAvions; i++)
    {
        if (smallest > airport.plane[i].capacite)
        {
            smallest =airport.plane[i].capacite ;
            index_smallest = i;
        }
    }

    printf("\n\nl'avion avec la plus petite capacite est :\n");
    printf("l'avion d' Id numero %03d :\n", airport.plane[index_smallest].idAvions_n);
    printf(" le modele : %s\n", airport.plane[index_smallest].model);
    printf("la capacite : %d\n", airport.plane[index_smallest].capacite);
    printf("Statut : %s\n", airport.plane[index_smallest].status);
    printf("La date d'entree : %d/%d/%d \n",airport.plane[index_smallest].date.jour ,airport.plane[index_smallest].date.mois ,airport.plane[index_smallest].date.annee);
}

void capacity_t()
{
    int sum = 0;
    for (int i = 0; i < nbAvions; i++)
    {
        sum = sum + airport.plane[i].capacite;
    }

    printf("\n Capacite totale de la flotte : %d \n", sum);
}

void calcul_statu()
{
    disp = 0 ;
    vol = 0 ;
    maint = 0;

    for (int i = 0; i < nbAvions; i++)
    {
        if (strcasecmp(airport.plane[i].status, t_status[0]) == 0)
        {
            disp++;
        }
        else if (strcasecmp(airport.plane[i].status, t_status[1]) == 0)
        {
            maint++;
        }
        else if (strcasecmp(airport.plane[i].status, t_status[2]) == 0)
        {
            vol++;
        }
    }

    printf("le nombre d'avions disponibles : %d \n", disp);
    printf("le nombre d'avions en maintenance : %d \n", maint);
    printf("le nombre d'avions en vol : %d \n", vol);
}

void coefficient()
{
    calcul_statu();
    float coeff;
    capacity_t();
    coeff = ((float)disp / nbAvions) * 100;
    printf("\nLe coefficient d'occupation du parc : %.2f %% \n", coeff);
}

void statistiques()
{
    printf("======================================");
    printf("Nombre total d'avions dans le parc : %d \n", nbAvions);
    capacity_t();
    largest();
    smallest();
    coefficient();
}