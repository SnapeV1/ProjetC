#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct{
int jour;
int mois;
int annees;
}date;
typedef struct{
  int id;
  char nom_liste[50];
  int CIN_tete_liste ;
  int nb_condidats;
  char CIN_condidats[20] ;
  char orientation_polytique[20];
  int nb_vote;
  date dat_naiisance;
}electorale;
typedef struct{
int id_user;
int idliste;
}user ;
int ajouter1(char*ajoutslim,electorale e);
int modifier1( char * ajoutslim,int , electorale nouv );
int supprimer1(char * ajoutslim,int id );
electorale chercher(char * ajoutslim, int);
/*int nbv(char*vote ,int id_user );
int L_ordre( char *xx, char t[], char * l_ordre);
*/void afficher_le(GtkWidget *liste, char*filname);

#endif // POINT_H_INCLUDED
