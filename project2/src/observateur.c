#include "observateur.h"
#include<gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum
{
	ENOM,
	EPRENOM,
	EJOUR,
	EMOIS,
	EANNEE,
        ECIN,
	EID,
	ENAT,
	EPRO,
	COLUMNS,
};

void ajouter_obs(observateur o )
{
     FILE *f;
  f=fopen("obs.txt","a+");
    if(f!=NULL)
    {
fprintf(f,"%s %s %d %d %d %s %s %s %s\n", o.nom, o.prenom,o.date.jour,o.date.mois,o.date.annee,o.cin,o.id,o.nat,o.pro);

     fclose(f);
              }
}
void modifier_obs(observateur o)
{

FILE *f=NULL,*x;
f=fopen("obs.txt","r");
x=fopen("mod.txt","a+");
observateur n;
if (f!=NULL)
{
while (fscanf(f,"%s %s %d %d %d %s %s %s %s\n", n.nom, n.prenom,&o.date.jour,&o.date.mois,&o.date.annee,n.cin,n.id,n.nat,n.pro)!= EOF)
{
if (strcmp(o.id,n.id)==0)
{
fprintf(x,"%s %s %d %d %d %s %s %s %s\n", o.nom, o.prenom,o.date.jour,o.date.mois,o.date.annee,o.cin,o.id,o.nat,o.pro) ;
}
else
{
fprintf(x,"%s %s %d %d %d %s %s %s %s\n", o.nom, o.prenom,o.date.jour,o.date.mois,o.date.annee,o.cin,o.id,o.nat,o.pro);
}
}
}
fclose(x);
fclose(f);
remove("obs.txt");
rename("mod.txt","obs.txt");

}
void supprimer_obs(observateur n, char ch[] )
{

FILE *f=NULL;
FILE *x=NULL ;
f=fopen("obs.txt","r");
x=fopen("mod.txt","a");
if (f!=NULL)
{
while (fscanf(f,"%s %s %d %d %d %s %s %s %s\n", n.nom, n.prenom,&n.date.jour,&n.date.mois,&n.date.annee,n.cin,n.id,n.nat,n.pro)!= EOF)
{
if (strcmp(ch,n.id)!=0)
{
fprintf(x,"%s %s %d %d %d %s %s %s %s\n", n.nom, n.prenom,n.date.jour,n.date.mois,n.date.annee,n.cin,n.id,n.nat,n.pro) ;
}
}
}
fclose(x);
fclose(f);

remove("obs.txt");
rename("mod.txt","obs.txt");
}
observateur chercher_obs(char ch[])
{
 
int trouve=0;
observateur n;
 //char ch1[200];
FILE *f=NULL;
f=fopen("obs.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %d %d %d %s %s %s %s\n", n.nom, n.prenom,&n.date.jour,&n.date.mois,&n.date.annee,n.cin,n.id,n.nat,n.pro)!= EOF)
{if (strcmp(n.id,ch)==0)
{

fclose(f);
return (n);}
    
}
}
}
void affi(GtkWidget *liste)
{
    
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char nom[20];
    char prenom[20];
    char jour[20];
    char mois[20];
    char annee[20];
    char cin[20];
    char id[20];
    char nat[20];
    char pro[20];
    store= NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nat",renderer,"text",ENAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" pro",renderer,"text",EPRO,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);




store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f=fopen("obs.txt","r");
   if (f==NULL)
   {
return;
}
else
{
f=fopen("obs.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n", nom, prenom,jour,mois,annee,cin,id,nat,pro)!= EOF)
    {
	gtk_list_store_append(store,&iter);
	gtk_list_store_set (store,&iter,ENOM,nom,EPRENOM,prenom,EJOUR,jour,EMOIS,mois,EANNEE,annee,ECIN,cin,EID,id,ENAT,nat,EPRO,pro,-1);

    
   }
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste) ,GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}




