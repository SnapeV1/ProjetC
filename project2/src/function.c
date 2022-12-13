#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "utilisateur.h"
#include <gtk/gtk.h>
enum 
{
	EID,
	ENUMERO,
	ECAPACITE,
	EADRESSE,
	EETAT,
	ENOMBREOBSERVATEUR,
	COLUMNS,
};
void ajouter(int ET ,int nombredobservateur,bureau bv )
{
    FILE *f=NULL ;
	if(ET==1)
	strcpy(bv.etat,"active");
	if(ET==2)
	strcpy(bv.etat,"inactive");
	if(nombredobservateur==1)
	strcpy(bv.nombredobservateur1,"2");
	if(nombredobservateur==2)
	strcpy(bv.nombredobservateur1,"4");
     f=fopen("bv.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %s %s %s \n",bv.id,bv.numero,bv.capacite,bv.adresse,bv.etat,bv.nombredobservateur1);
        fclose(f);
      
    }
    
}

int modifier(char * filename,int id, bureau nouv)
{
bureau bv;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %s %s %s \n",&bv.id,&bv.numero,&bv.capacite,bv.adresse,bv.etat,bv.nombredobservateur1)!=EOF)
{
if(bv.id==id)
        fprintf(f2,"%s %s %d %s %s %s \n",nouv.id,nouv.numero,nouv.capacite,nouv.adresse,nouv.etat,nouv.nombredobservateur1);
else

  fprintf(f2,"%s %s %d %s %s %s \n",bv.id,bv.numero,bv.capacite,bv.adresse,bv.etat,bv.nombredobservateur1);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }

}

/*void supprimer(int id, char * filename)
{
	FILE *f=NULL;
	FILE *tmp=NULL;

	bureau bv ;
	f=fopen("bv.txt" ,"r");
	tmp=fopen("tmp.txt","w");

	if(f!=NULL)
	{
		while (fscanf(f,"%s %s %d %s %s %s \n ",bv.id,bv.numero,&bv.capacite,bv.nombredobservateur,bv.adresse,bv.etat)!=EOF)
		{
			if(strcmp(bv.id,id)!=0)
			{
		fprintf(tmp,"%s %s %d %s %s %s \n",bv.id,bv.numero,bv.capacite,bv.nombredobservateur,bv.adresse,bv.etat); 
			}
		}
		fclose(f);
		fclose(tmp);
		remove("bv.txt");
		rename("tmp.txt","bv.txt");
}
}*/

/*void chercher(int id, char * filename)
{
bureau bv ; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %d %s %s %s \n",bv.id,bv.numero,bv.capacite,bv.adresse,bv.etat,bv.nombredobservateur)!=EOF && tr==0)
{if(id==bv.id)
tr=1;
}
}
if(tr==0)
//bv.id=-1;

return bv ;

}*/



/*void afficherbv (GtkWidget *liste) 
{	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char id [2000];
	char numero [2000];        
	char capacite[2000]  ;
	char adresse [2000];
	char etat [2000];
	char nombredobservateur [2000];
	store=NULL;
	FILE  *f;
	
	store = gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numero", renderer,"text",ENUMERO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("capacite", renderer,"text",ECAPACITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
		column = 	gtk_tree_view_column_new_with_attributes("nombredobservateur",renderer,"text",ENOMBREOBSERVATEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer,"text",EADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer,"text",EETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	
	
	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("bv.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("bv.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s \n",id,numero,capacite,adresse,etat,nombredobservateur)!=EOF)
		{
		
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EID,id,ENUMERO,numero,ECAPACITE,capacite,ENOMBREOBSERVATEUR,nombredobservateur,EADRESSE,adresse,EETAT,etat,-1);
			
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}  
	
}}*/
void chercher_bv(char ID[20],int choix1)
{
	FILE *f=NULL;
	FILE *tmp=NULL;
 bureau bv ;
	f=fopen("bv.txt","r");  
	tmp=fopen("tmp.txt","w");
	if (f!=NULL)
	{
		while (fscanf(f,"%s %s %d %s %s %s \n ",bv.id,bv.numero,&bv.capacite,bv.nombredobservateur1,bv.adresse,bv.etat)!=EOF)
{

if(choix1==1)
	if (strcmp(bv.id,ID) == 0)
	{
		fprintf(tmp,"%s %s %d %s %s %s \n",bv.id,bv.numero,bv.capacite,bv.nombredobservateur1,bv.adresse,bv.etat);
	}

	if(choix1==2)
	if (strcmp(bv.numero,ID) == 0)
	{
		fprintf(tmp,"%s %s %d %s %s %s \n",bv.id,bv.numero,bv.capacite,bv.nombredobservateur1,bv.adresse,bv.etat);
	}
}
fclose(f);
fclose(tmp);
}}
///////////////////////


void afficherbv (GtkWidget *liste) 
{	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char id [2000];
	char numero [2000];        
	char capacite[2000]  ;
	char adresse [2000];
	char etat [2000];
	char nombredobservateur1 [2000];
	store=NULL;
	FILE  *f;
	
	store = gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numero", renderer,"text",ENUMERO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("capacite", renderer,"text",ECAPACITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
		column = 	gtk_tree_view_column_new_with_attributes("nombredobservateur1",renderer,"text",ENOMBREOBSERVATEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer,"text",EADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer,"text",EETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	
	
	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("bv.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("bv.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s \n",id,numero,capacite,adresse,etat,nombredobservateur1)!=EOF)
		{
		
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EID,id,ENUMERO,numero,ECAPACITE,capacite,ENOMBREOBSERVATEUR,nombredobservateur1,EADRESSE,adresse,EETAT,etat,-1);
			
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}  
	
}}
void supprimer(char id[2000])
{
	FILE *f=NULL;
	FILE *tmp=NULL;

	bureau bv ;
	f=fopen("bv.txt" ,"r");
	tmp=fopen("tmp.txt","w");

	if(f!=NULL)
	{
		while (fscanf(f,"%s %s %d %s %s %s \n ",bv.id,bv.numero,&bv.capacite,bv.nombredobservateur1,bv.adresse,bv.etat)!=EOF)
		{
			if(strcmp(bv.id,id)!=0)
			{
		fprintf(tmp,"%s %s %d %s %s %s \n",bv.id,bv.numero,bv.capacite,bv.nombredobservateur1,bv.adresse,bv.etat); 
			}
		}
		fclose(f);
		fclose(tmp);
		remove("bv.txt");
		rename("tmp.txt","bv.txt");
}
}

void afficherch (GtkWidget *liste) 
{	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char id [2000];
	char numero [2000];        
	char capacite[2000]  ;
	char adresse [2000];
	char etat [2000];
	char nombredobservateur1 [2000];
	store=NULL;
	FILE  *tmp;
	
	store = gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numero", renderer,"text",ENUMERO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("capacite", renderer,"text",ECAPACITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
		column = 	gtk_tree_view_column_new_with_attributes("nombredobservateur1",renderer,"text",ENOMBREOBSERVATEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer,"text",EADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer,"text",EETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	
	
	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	tmp=fopen("tmp.txt","r");
	if(tmp==NULL)
	{
		return;
	}
	else
	{
		tmp = fopen("tmp.txt","a+");
		while(fscanf(tmp,"%s %s %s %s %s %s \n",id,numero,capacite,adresse,etat,nombredobservateur1)!=EOF)
		{
		
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EID,id,ENUMERO,numero,ECAPACITE,capacite,ENOMBREOBSERVATEUR,nombredobservateur1,EADRESSE,adresse,EETAT,etat,-1);
			
		}
		fclose(tmp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}  
	
}}

int agemoyen(char * filename )
{
  FILE * f = fopen (filename, "r");
int n=NbrElec(filename);
int s = 0;
int age ;
utilisateur u;


while (fscanf (f , "%d %s %s %d %d %d %s %s %d %d \n " , &u.cin , u.nom , u.prenom , &u.DateNaissance.annee,  &u.DateNaissance.mois, &u.DateNaissance.jours , u.genre, u.type , &u.numBV , &u.vote)!=EOF)
{
if (strcmp(u.type,"Electeur")==0 ) { 

	
	age = 2022 - u.DateNaissance.annee ;
	s  = s + age ;

 	}
}
close(f);
int moyenage= s/n;

return moyenage ;  
}


int nbe(char * filename, int id )
{
  FILE *f = fopen (filename, "r");
int nbelect =0;
utilisateur u;


while (fscanf (f , "%d %s %s %d %d %d %s %s %d %d \n ", &u.cin , u.nom , u.prenom , &u.DateNaissance.annee,  &u.DateNaissance.mois, &u.DateNaissance.jours , u.genre, u.type , &u.numBV , &u.vote)!=EOF)
{
if (strcmp(u.type,"Electeur") == 0 ){

if (u.numBV == id ) 
	nbelect ++ ;
 
	
 }	
}

return nbelect ;  
}

