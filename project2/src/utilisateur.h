#include <gtk/gtk.h>
typedef struct{
int jours;
int mois;
int annee;
}Date;

typedef struct{
int cin;
char nom[50];
char prenom[50];
Date DateNaissance;
char genre[50];
char type[50];
int numBV;
int vote;


}utilisateur;





int modifierU(char *,int,utilisateur);
int ajouterU(char*,utilisateur u,int);
int supprimerU(char *,int);
utilisateur chercherU(char *,int);
void TPHF(char*,float*,float*);
int NbrUsers(char *filename);
int TPE(char*filename);
int NbrElecVote(char * filename);
void afficherU (GtkWidget *liste) ;
