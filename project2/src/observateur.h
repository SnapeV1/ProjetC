
#include <stdio.h>
#include<gtk/gtk.h>
typedef struct 
{ 
    int  jour;
    int  mois;
    int  annee;		
}Date_obs;
typedef struct
{ 
    char nom[20];
    char prenom[20];
    Date_obs date;
    char cin[20];
    char id[20];
    char nat[20];
    char pro[20];

  
} observateur;

void ajouter_obs(observateur o );
void modifier_obs(observateur o);
void supprimer_obs(observateur o, char [] );
observateur chercher_obs(char ch[]);
void affi(GtkWidget *liste);
//int total(char  *observateur);
//void taux(char * ,float * ,float * );


