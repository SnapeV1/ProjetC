#ifndef function_H_
#define function_H_
#include <string.h>
#include <gtk/gtk.h>
typedef struct
{
char numero [2000];
char id [2000];
int capacite  ;
char adresse [2000];
char etat [2000];
char nombredobservateur1 [2000];
} bureau ;

void ajouter(int ET ,int nombredobservateur ,bureau bv);
void afficherbv (GtkWidget *liste);
int modifier(char *,int,bureau );
void afficherch(GtkWidget *liste);
void supprimer();

void chercher_bv(char * ,int );


#endif
