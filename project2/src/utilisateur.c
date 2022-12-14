#include"utilisateur.h"
#include<stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>

enum 
{
	CIN,
	NOM,
	PRENOM,
	JOUR,
	MOIS,
	ANNEE,
	GENRE,
	TYPE,
	NUMBV,
	VOTE,
	COLUMNS,
};


int ajouterU(char *filename,utilisateur u,int test){
    FILE *f=fopen(filename,"a");
    u.vote=-1;
if(test==1)strcpy(u.genre,"homme");
else strcpy(u.genre,"femme");
    if(f!=NULL){
        fprintf(f,"%d %s %s %d %d %d %s %s %d %d\n",u.cin,u.nom,u.prenom,u.DateNaissance.annee,u.DateNaissance.mois,u.DateNaissance.jours,u.genre,u.type,u.numBV,u.vote);
    fclose(f);
    return 1;

    }
else return 0;
}







void afficherU (GtkWidget *liste,char * filename) 
{	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	int cin;
	char nom[50];
	char prenom[50];
	int jour;
	int mois;
	int annee;
	char genre[50];
	char type[50];
	int numBV;
	int vote;
utilisateur user;
	store=NULL;
	FILE  *f;
	
	store = gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Prenom", renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jour", renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Mois", renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
		column = 	gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Genre", renderer,"text",GENRE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type", renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("NumBV", renderer,"text",NUMBV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Vote", renderer,"text",VOTE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	
	store = gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);

	f=fopen(filename,"r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		while(fscanf(f,"%d %s %s %d %d %d %s %s %d %d",&user.cin,user.nom,user.prenom,&user.DateNaissance.annee,&user.DateNaissance.mois,&user.DateNaissance.jours,user.genre,user.type,&user.numBV,&user.vote)!=EOF)
		{
		
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,CIN,user.cin,NOM,user.nom,PRENOM,user.prenom,JOUR,user.DateNaissance.jours,MOIS,user.DateNaissance.mois,ANNEE,user.DateNaissance.annee,GENRE,user.genre,TYPE,user.type,NUMBV,user.numBV,VOTE,user.vote);
			
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}  
	
}}





// ------------------------------------------------------------verif functions -----------------------------------------------------
	//verif CIN
int Verif_CIN(int cin)
{
char ch[50];

sprintf(ch,"%d",cin);
if (strlen(ch)==8)
return 1;
else return 0;
}

int Verif_CIN2(char ch[])
{

if (strlen(ch)==8)
return 1;
else return 0;
}


	//verif strings
int verif_STRING(char ch[50]){
int i;
int test=1;
for(i=0;i<strlen(ch);i++){
if((ch[i]=='0')||(ch[i]=='1')||(ch[i]=='2')||(ch[i]=='3')||(ch[i]=='4')||(ch[i]=='5')||(ch[i]=='6')||(ch[i]=='7')||(ch[i]=='8')||(ch[i]=='9'))
test=0;

}
return test;
}

	//verif existence of an id
int verif_EXIST(int id){
int test=1;
utilisateur user;
FILE *f=fopen("utilisateur.txt","r");
	
while(fscanf(f,"%d %s %s %d %d %d %s %s %d %d",&user.cin,user.nom,user.prenom,&user.DateNaissance.annee,&user.DateNaissance.mois,&user.DateNaissance.jours,user.genre,user.type,&user.numBV,&user.vote)!=EOF)
{
if(user.cin==id)test=0;

}
fclose(f);
return test;
}









//------------------------------------------------------------------------------------------------------------------------------------------------------



int modifierU(char *filename,int id,utilisateur nu){
int test=0;
utilisateur u;
FILE *f=fopen(filename,"r");
FILE *f2=fopen("temp.txt","a");
if(f!=NULL && f2!=NULL)
    {
     while ((fscanf(f,"%d %s %s %d %d %d %s %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,u.genre,u.type,&u.numBV,&u.vote))!=EOF){
    if(u.cin==id){
        fprintf(f2,"%d %s %s %d %d %d %s %s %d %d\n",nu.cin,nu.nom,nu.prenom,nu.DateNaissance.annee,nu.DateNaissance.mois,nu.DateNaissance.jours,nu.genre,nu.type,nu.numBV,nu.vote);
        test=1;
    }
    else{fprintf(f2,"%d %s %s %d %d %d %s %s %d %d\n",u.cin,u.nom,u.prenom,u.DateNaissance.annee,u.DateNaissance.mois,u.DateNaissance.jours,u.genre,u.type,u.numBV,u.vote);}
    }

    }
fclose(f);
fclose(f2);
remove(filename);
rename("temp.txt",filename);
return test;

}
int supprimerU(char *filename,int id){
int test;
utilisateur u;
FILE * f=fopen(filename,"r");
FILE * f2=fopen("temp.txt","w");
if(f!=NULL && f2!=NULL)
    {
     while ((fscanf(f,"%d %s %s %d %d %d %s %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,u.genre,u.type,&u.numBV,&u.vote))!=EOF){
    if(u.cin==id){
        test=1;
    }
    else{fprintf(f2,"%d %s %s %d %d %d %s %s %d %d\n",u.cin,u.nom,u.prenom,u.DateNaissance.annee,u.DateNaissance.mois,u.DateNaissance.jours,u.genre,u.type,u.numBV,u.vote);}
    }

    }
    fclose(f);
fclose(f2);
remove(filename);
rename("temp.txt",filename);
return test;

}



utilisateur chercherU(char * filename,int id){
utilisateur u;
int test=0;
FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
u.cin=0;
        while((test==0)&&(fscanf(f,"%d %s %s %d %d %d %s %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,u.genre,u.type,&u.numBV,&u.vote)!=EOF))
        {
            if(u.cin==id)
                test=1;
        }
    }
    fclose(f);
    if(test==0)
        u.cin=-1;

    return u;

}


void chercher_Type(char type[50]){
FILE *f1=fopen("utilisateur.txt","r");

 FILE *f=fopen("search.txt","w");
utilisateur u;

if((f1!=NULL)&&(f!=NULL)){
while((fscanf(f1,"%d %s %s %d %d %d %s %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,u.genre,u.type,&u.numBV,&u.vote))!=EOF){
if(strcmp(type,u.type)==0)fprintf(f,"%d %s %s %d %d %d %s %s %d %d\n",u.cin,u.nom,u.prenom,u.DateNaissance.annee,u.DateNaissance.mois,u.DateNaissance.jours,u.genre,u.type,u.numBV,u.vote);
}
}




	fclose(f1);
	fclose(f);
}











//-----------------------NbrUsers------------------
int NbrUsers(char *filename){
int n=0;
FILE *f1=fopen(filename,"r");
utilisateur u;


    if(f1!=NULL){
while(fscanf(f1,"%d %s %s %d %d %d %s %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,u.genre,u.type,&u.numBV,&u.vote)!=EOF)
{
 n++;
}

    }
fclose(f1);
return n;
}



//-----------------------NbrElec--------------------
int NbrElec(char *filename){
int n=0;
FILE *f1=fopen(filename,"r");
utilisateur u;

int test;
    if(f1!=NULL){
while(fscanf(f1,"%d %s %s %d %d %d %s %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,u.genre,u.type,&u.numBV,&u.vote)!=EOF)
{
test=strcmp(u.type,"Electeur");
if(test==0)  n++;
}

    }
fclose(f1);
return n;

}
//------------TPHF------------------

void TPHF(char *filename,float *h,float *f){
FILE *f1=fopen(filename,"r");
utilisateur u;


    if(f1!=NULL){


while(fscanf(f1,"%d %s %s %d %d %d %s %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,u.genre,u.type,&u.numBV,&u.vote)!=EOF)
        {
if((strcmp(u.genre,"homme")==0)&&(u.vote!=-1)&&(strcmp(u.type,"Electeur")==0))*h=*h+1;
if((strcmp(u.genre,"femme")==0)&&(u.vote!=-1)&&(strcmp(u.type,"Electeur")==0))*f=*f+1;


}

}


fclose(f1);
*f=*f*100/NbrElecVote(filename);
*h=*h*100/NbrElecVote(filename);

 }






//--------------------------------------------NbrElcVote------------------------------------------
int NbrElecVote(char * filename){
int nbrvote=0;
FILE *f1=fopen(filename,"r");
utilisateur u;


    if(f1!=NULL){

int test;
while(fscanf(f1,"%d %s %s %d %d %d %s %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,u.genre,u.type,&u.numBV,&u.vote)!=EOF)
        {
test=strcmp(u.type,"Electeur");
if((u.vote!=-1)&&(test==0))nbrvote++;

}

}

fclose(f1);

return nbrvote;
}

//---------------------Le taux de participation des électeurs----------------------------




int TPE(char*filename){

return NbrElecVote(filename)*100/NbrElec(filename);

}


int VerifAdmin(char name[],char password[]){
int res=0;
FILE *f1=fopen("utilisateur.txt","r");
utilisateur u;


    if(f1!=NULL){

int test;
while(fscanf(f1,"%d %s %s %d %d %d %s %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,u.genre,u.type,&u.numBV,&u.vote)!=EOF)
        {
char str[20]="";
strcat(str,u.nom);
strcat(str,".");
strcat(str,u.prenom);
test=strcmp(str,name);
	if(test==0)
		{if(strcmp(u.type,"Admin")==0)res=1;}

}





}

if(strcmp(password,"admin")!=0)res=0;
return res;
}

