#include "electorale.h"
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>


enum
{
 EID,
ENOM, 
ECINTETE,
 ENBCAND,
 ECONDIDAT,
 EOP,
 EJOUR,
 EMOIS,
 EANNEES,
 COLUMNS,
};
enum
{
 ID,
 NBV,

 COLUMNSS,
};
electorale e;

int ajouter1(char*ajoutslim,electorale e)
{

	
    FILE* f=fopen(ajoutslim, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %d %d %s %s %d %d %d\n",e.id,e.nom_liste,e.CIN_tete_liste,e.nb_condidats,e.CIN_condidats,e.orientation_polytique,e.dat_naiisance.jour,e.dat_naiisance.mois,e.dat_naiisance.annees);
        fclose(f);
        return 1;
    }
    else 
	return 0;
}
int ajouter2(char*ajout,electorale e)
{

	
    FILE* f=fopen(ajout,"a");
    if(f!=NULL)
    {
e.nb_vote=0;                
fprintf(f,"%d %s %d %d %s %s %d %d %d %d\n",e.id,e.nom_liste,e.CIN_tete_liste,e.nb_condidats,e.CIN_condidats,e.orientation_polytique,e.nb_vote,e.dat_naiisance.jour,e.dat_naiisance.mois,e.dat_naiisance.annees);

fclose(f);
        return 1;
    }
    else 
	return 0;
}
int modifier1( char * ajoutslim,int id, electorale nouv )
{
int test;    
int tr=0;
   electorale e;
     FILE * f=fopen( ajoutslim, "r");
     FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %s %s %d %d %d",&e.id,e.nom_liste,&e.CIN_tete_liste,&e.nb_condidats,e.CIN_condidats,e.orientation_polytique,&e.dat_naiisance.jour,&e.dat_naiisance.mois,&e.dat_naiisance.annees)!=EOF)
        {
if(id==e.id)
            {


                fprintf(f2,"%d %s %d %d %s %s %d %d %d\n",nouv.id,nouv.nom_liste,nouv.CIN_tete_liste,nouv.nb_condidats,nouv.CIN_condidats,nouv.orientation_polytique,nouv.dat_naiisance.jour,nouv.dat_naiisance.mois,nouv.dat_naiisance.annees);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %d %d %s %s %d %d %d\n",e.id,e.nom_liste,e.CIN_tete_liste,e.nb_condidats,e.CIN_condidats,e.orientation_polytique,e.dat_naiisance.jour,e.dat_naiisance.mois,e.dat_naiisance.annees);

        }
    }
    fclose(f);
    fclose(f2);
    remove(ajoutslim);
    rename("nouv.txt", ajoutslim);
    return tr;

}
int modifier2(int id, electorale nouv )
{
int test;    
int tr=0;
   electorale e;
     FILE * f=fopen( "ajout.txt", "r");
     FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %s %s %d %d %d %d",&e.id,e.nom_liste,&e.CIN_tete_liste,&e.nb_condidats,e.CIN_condidats,e.orientation_polytique,&e.nb_vote,&e.dat_naiisance.jour,&e.dat_naiisance.mois,&e.dat_naiisance.annees)!=EOF)
        {
if(id==e.id)
            {


                fprintf(f2,"%d %s %d %d %s %s %d %d %d %d\n",nouv.id,nouv.nom_liste,nouv.CIN_tete_liste,nouv.nb_condidats,nouv.CIN_condidats,nouv.orientation_polytique,nouv.nb_vote,nouv.dat_naiisance.jour,nouv.dat_naiisance.mois,nouv.dat_naiisance.annees);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %d %d %s %s %d %d %d %d\n",e.id,e.nom_liste,e.CIN_tete_liste,e.nb_condidats,e.CIN_condidats,e.orientation_polytique,e.nb_vote,e.dat_naiisance.jour,e.dat_naiisance.mois,e.dat_naiisance.annees);

        }
    }
    fclose(f);
    fclose(f2);
    remove("ajout.txt");
    rename("nouv.txt","ajout.txt");
    return tr;

}
int supprimer1(char * ajoutslim,int id)
{
    int tr=0;
    electorale e;
    FILE * f=fopen(ajoutslim, "r");
    FILE * f2=fopen("nouv.txt", "w");
   
    
        while(fscanf(f,"%d %s %d %d %s %s %d %d %d",&e.id,e.nom_liste,&e.CIN_tete_liste,&e.nb_condidats,e.CIN_condidats,e.orientation_polytique,&e.dat_naiisance.jour,&e.dat_naiisance.mois,&e.dat_naiisance.annees)!=EOF)
        {
             
            if(e.id==id)
                tr=1;
            else
                fprintf(f2,"%d %s %d %d %s %s %d %d %d\n",e.id,e.nom_liste,e.CIN_tete_liste,e.nb_condidats,e.CIN_condidats,e.orientation_polytique,e.dat_naiisance.jour,e.dat_naiisance.mois,e.dat_naiisance.annees);
        
    }
    fclose(f);
    fclose(f2);
    remove(ajoutslim);
    rename("nouv.txt",ajoutslim);
    return tr;
}
electorale chercher(char * ajoutslim,int id)
{

     electorale e;
    int tr=0;
    FILE * f=fopen(ajoutslim, "r");
    if(f!=NULL)
    {

        while((tr==0)&&(fscanf(f,"%d %s %d %d %s %s %d %d %d\n",&e.id,e.nom_liste,&e.CIN_tete_liste,&e.nb_condidats,e.CIN_condidats,e.orientation_polytique,&e.dat_naiisance.jour,&e.dat_naiisance.mois,&e.dat_naiisance.annees)!=EOF))
        {

            if(e.id==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0) e.id=-1;

    return e;

}


electorale chercher2(int id)
{

     electorale e;
    int tr=0;
    FILE * f=fopen("ajout.txt", "r");
    if(f!=NULL)
    {

        while((tr==0)&&(fscanf(f,"%d %s %d %d %s %s %d %d %d %d\n",&e.id,e.nom_liste,&e.CIN_tete_liste,&e.nb_condidats,e.CIN_condidats,e.orientation_polytique,&e.nb_vote,&e.dat_naiisance.jour,&e.dat_naiisance.mois,&e.dat_naiisance.annees)!=EOF))
        {
e.nb_vote=0;
            if(e.id==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0) e.id=-1;

    return e;

}

void nbv(int id_liste,int *t)
{
int x;
electorale e;
 FILE * f=fopen("vote.txt","r");
 FILE * f2=fopen("ajout.txt","r");
 FILE * f1=fopen("nbv.txt","a");

 if(f!=NULL)
{user u;

 while (fscanf(f,"%d %d\n",&u.id_user,&u.idliste)!=EOF)
    {


            if(u.idliste==id_liste)
                {
                    e=chercher2(id_liste);
                
                    e.nb_vote++;

                }


}
int y=modifier2(e.id,e);  
                 fprintf(f1,"%d %d\n",e.id,e.nb_vote);
}

fclose(f);
fclose(f1);
fclose(f2);
t=e.nb_vote;
}

int L_ordre( char *ajoutx,char * l_ordre)
{
    int n=0,x;
int i=0,c=0,test=1,a=0,aux2,aux,tr=0,min,index,j;
electorale e,tri;

user u;
 int r[50];
int b[50];
int h=0;
FILE *f=fopen(ajoutx,"r");
FILE *f1=fopen(l_ordre,"w");


 if(f!=NULL)
{
    while ((fscanf(f,"%d %d\n",&e.id,&e.nb_vote)!=EOF))

{

r[i]=e.id;
b[i]=e.nb_vote;
i++;

}
x=0;

  for (c=0;c<i-1; c++)
  {
    index=c;

    for (j=c + 1; j <i; j++)
    {
      if (b[index]<b[j])
        index = j;
    }
    if (index!=c)
    {
      aux=b[c];
      aux2=r[c] ;
      b[c]=b[index];
      r[c]=r[index];
      b[index]=aux;
      r[index]=aux2;
    }

  }

c=0;
while(c<i)
{
fprintf(f1,"%d %d\n",r[c],b[c]);
c++;

}
fclose(f);
fclose(f1);
 return a;

}
}



void afficher_le(GtkWidget *liste, char*filname) 
{	
	GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store; 

  int id ;
  char nom_liste[50];
  int CIN_tete_liste ;
  int nb_condidats;
  char CIN_condidats[20] ;
  char orientation_polytique[20];
  int jour;
  int mois;
  int annees;
store=NULL;

FILE *f;
	
	store = gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom_liste", renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Cin_tete_liste", renderer,"text",ECINTETE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	column = gtk_tree_view_column_new_with_attributes("nb_condidats", renderer,"text",ENBCAND,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	column = gtk_tree_view_column_new_with_attributes("CIN_condidats",renderer,"text",ECONDIDAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("orientation_polytique",renderer,"text",EOP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer,"text",EJOUR,NULL);	
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annees", renderer,"text",EANNEES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	
	
	store = gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

	f=fopen(filname,"r");
	if(f==NULL)
	{
		return;
	}
	else
	{
	
		while(fscanf(f,"%d %s %d %d %s %s %d %d %d \n",&e.id,e.nom_liste,&e.CIN_tete_liste,&e.nb_condidats,e.CIN_condidats,e.orientation_polytique,&e.dat_naiisance.jour,&e.dat_naiisance.mois,&e.dat_naiisance.annees)!=EOF)
		{
		
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EID,e.id,ENOM,e.nom_liste,ECINTETE,e.CIN_tete_liste,ENBCAND,e.nb_condidats,ECONDIDAT,e.CIN_condidats,EOP,e.orientation_polytique,EJOUR,e.dat_naiisance.jour,EMOIS,e.dat_naiisance.mois,EANNEES,e.dat_naiisance.annees,-1);
			
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}  
	
}}
void afficher_xx(GtkWidget *liste, char*filname) 
{	
	GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store; 

  int id ;
  int nb_vote;
 
store=NULL;

FILE *f;
	
	store = gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nb_vote", renderer,"text",NBV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	

	
	
	
	store = gtk_list_store_new(COLUMNSS,G_TYPE_INT,G_TYPE_INT);

	f=fopen(filname,"r");
	if(f==NULL)
	{
		return;
	}
	else
	{
	
		while(fscanf(f,"%d %d \n",&e.id,&e.nb_vote)!=EOF)
		{
		
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID,e.id,NBV,e.nb_vote,-1);
			
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}  
	
}}



