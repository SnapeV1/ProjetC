#include <stdio.h>
#include <stdlib.h>
#include"utilisateur.h"
#include <string.h>
#include<math.h>
int main()
{
float h=0;
float f=0;
utilisateur user1={1,"nom1","prenom1",10,12,2000,'h',"electeur",1,0};
utilisateur user2={2,"nom2","prenom2",7,11,2016,'f',"electeur",1,0};
utilisateur user3={3,"nom3","prenom3",8,01,2015,'f',"type3",1,0};
int x;

x=ajouterU("utilisateur.txt",user2);
 




TPHF("utilisateur.txt",&h,&f);
printf("homme : %.2f% // femme :%.2f% \n",h,f);
/*
x=ajouterU("utilisateur.txt",user2);
 x=ajouterU("utilisateur.txt",user3);
x=supprimerU("utilisateur.txt",1);
 /*
x=modifierU("utilisateur.txt",2,user1);
utilisateur u=chercherU("utilisateur.txt",0);
if(u.cin!=-1){
        printf("%d %s %s %d %d %d %c %s %d %d\n",u.cin,u.nom,u.prenom,u.DateNaissance.annee,u.DateNaissance.mois,u.DateNaissance.jours,u.genre,u.type,u.numBV,u.vote);

}
else printf("n'existe pas");*/
printf("Le taux de participation des électeurs : %.2f% \n",round(TPE("utilisateur.txt")));



}

