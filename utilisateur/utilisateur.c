#include"utilisateur.h"
#include<stdio.h>
int ajouterU(char *filename,utilisateur u){
    FILE *f=fopen(filename,"a");
    u.vote=-1;
    if(f!=NULL){
        fprintf(f,"%d %s %s %d %d %d %c %s %d %d\n",u.cin,u.nom,u.prenom,u.DateNaissance.annee,u.DateNaissance.mois,u.DateNaissance.jours,u.genre,u.type,u.numBV,u.vote);
    fclose(f);
    return 1;

    }
else return 0;
}
int modifierU(char *filename,int id,utilisateur nu){
int test=0;
utilisateur u;
FILE *f=fopen(filename,"r");
FILE *f2=fopen("temp.txt","a");
if(f!=NULL && f2!=NULL)
    {
     while ((fscanf(f,"%d %s %s %d %d %d %c %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,&u.genre,u.type,&u.numBV,&u.vote))!=EOF){
    if(u.cin==id){
        fprintf(f2,"%d %s %s %d %d %d %c %s %d %d\n",nu.cin,nu.nom,nu.prenom,nu.DateNaissance.annee,nu.DateNaissance.mois,nu.DateNaissance.jours,nu.genre,nu.type,nu.numBV,nu.vote);
        test=1;
    }
    else{fprintf(f2,"%d %s %s %d %d %d %c %s %d %d\n",u.cin,u.nom,u.prenom,u.DateNaissance.annee,u.DateNaissance.mois,u.DateNaissance.jours,u.genre,u.type,u.numBV,u.vote);}
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
     while ((fscanf(f,"%d %s %s %d %d %d %c %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,&u.genre,u.type,&u.numBV,&u.vote))!=EOF){
    if(u.cin==id){
        test=1;
    }
    else{fprintf(f2,"%d %s %s %d %d %d %c %s %d %d\n",u.cin,u.nom,u.prenom,u.DateNaissance.annee,u.DateNaissance.mois,u.DateNaissance.jours,u.genre,u.type,u.numBV,u.vote);}
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
        while(fscanf(f,"%d %s %s %d %d %d %c %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,&u.genre,u.type,&u.numBV,&u.vote)!=EOF)
        {
            if(u.cin== id)
                test=1;
break;
        }
    }
    fclose(f);
    if(test==0)
        u.cin=-1;
    return u;

}

//-----------------------NbrUsers------------------
int NbrUsers(char *filename){
int n=0;
FILE *f1=fopen(filename,"r");
utilisateur u;


    if(f1!=NULL){
while(fscanf(f1,"%d %s %s %d %d %d %c %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,&u.genre,u.type,&u.numBV,&u.vote)!=EOF)
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
while(fscanf(f1,"%d %s %s %d %d %d %c %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,&u.genre,u.type,&u.numBV,&u.vote)!=EOF)
{
test=strcmp(u.type,"electeur");
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


while(fscanf(f1,"%d %s %s %d %d %d %c %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,&u.genre,u.type,&u.numBV,&u.vote)!=EOF)
        {
if((u.genre=='h')&&(u.vote!=-1)&&(strcmp(u.type,"electeur")==0))*h=*h+1;
else if((u.genre=='f')&&(u.vote!=-1)&&(strcmp(u.type,"electeur")==0))*f=*f+1;


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
while(fscanf(f1,"%d %s %s %d %d %d %c %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,&u.genre,u.type,&u.numBV,&u.vote)!=EOF)
        {
test=strcmp(u.type,"electeur");
if((u.vote!=-1)&&(test==0))nbrvote++;

}

}

fclose(f1);

return nbrvote;
}

//---------------------Le taux de participation des électeurs----------------------------




int TPE(char*filename){
int nbrvote=0;
FILE *f1=fopen(filename,"r");
utilisateur u;


    if(f1!=NULL){

int test;
while(fscanf(f1,"%d %s %s %d %d %d %c %s %d %d",&u.cin,u.nom,u.prenom,&u.DateNaissance.annee,&u.DateNaissance.mois,&u.DateNaissance.jours,&u.genre,u.type,&u.numBV,&u.vote)!=EOF)
        {
test=strcmp(u.type,"electeur");
if(test==0)nbrvote++;

}

}

fclose(f1);



return NbrElecVote(filename)*100/nbrvote;

}







