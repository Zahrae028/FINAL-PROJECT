#include <stdio.h> 



int nbAvions =0;
typedef struct 
    {   
        char model[50];
        int capacite;
        char status[50];
        int idAvions;
        
    } Planes;

typedef struct {
    char name[50];
    Planes plane[50];
} Airport;

Airport airport;

int c_status ;

char t_status[3][50] = {"Displonible" , "En maintenance" , "En vol"};




