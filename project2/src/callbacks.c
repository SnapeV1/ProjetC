#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include"electorale.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"
#include "function.h"
#include "election.h"
#include "observateur.h"
int test;
int test2;
int testModifier;
int ToUse;
int z,y;
int t;
utilisateur userDeleted;

int ET=1;
int choix;
int choix1=1;
int nombredobservateur=1;

char ch[100];
int et;
int nb,and,nb2;
electorale x;
void
on_button_Ajouter_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry_cinU,*entry_nomU,*entry_prenomU,*jour,*mois,*annee,*radiobutton_hommeU,*radiobutton_femmeU,*type,*numbv,*validation;
utilisateur user;
GtkWidget*output ;
entry_cinU = lookup_widget (objet,"entry_cinU" );
entry_nomU =lookup_widget (objet,"entry_nomU" );
entry_prenomU =lookup_widget (objet,"entry_prenomU" );
jour = lookup_widget (objet,"spinbutton_jours" );
mois = lookup_widget (objet,"spinbutton_mois" );
annee = lookup_widget (objet,"spinbutton_annee" );
type = lookup_widget (objet,"type" );
numbv = lookup_widget (objet,"entry_bvU" );
validation=lookup_widget (objet,"checkbutton13" );

output = lookup_widget(objet, "verif") ;
//-------------------------------------------------------------

user.cin=atoi(gtk_entry_get_text(GTK_ENTRY(entry_cinU)));
strcpy(user.nom,gtk_entry_get_text(GTK_ENTRY(entry_nomU)));
strcpy(user.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenomU)));
user.DateNaissance.jours=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
user.DateNaissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
user.DateNaissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

strcpy(user.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
user.numBV=atoi(gtk_entry_get_text(GTK_ENTRY(numbv)));
if ((test2==1)&&(Verif_CIN(user.cin))&&(verif_STRING(user.nom))&&(verif_STRING(user.prenom))&&(verif_EXIST(user.cin))){
int x=ajouterU("utilisateur.txt",user,test);
gtk_label_set_text(GTK_LABEL(output),"--/ Added successfully /--");
}

else if (verif_EXIST(user.cin)==0)gtk_label_set_text(GTK_LABEL(output),"--/ ID already exists /--");
else gtk_label_set_text(GTK_LABEL(output),"--/ Verify your information /--");
}











void
on_button_Supprimerbv_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_AjouterSlim_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *GestionSlim ,*AjoutSlim;
	GestionSlim =lookup_widget(objet,"GestionSlim");
        gtk_widget_hide(GestionSlim );
        AjoutSlim=create_AjoutSlim();
	gtk_widget_show(AjoutSlim);
}


void
on_button_ModiferSlim_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
int y;
char cin[100],I[100];
electorale e,e1;
int h;
char k[100],ch3[100],ch4[100],ch5[100]; 
GtkWidget *GestionSlim;
GtkWidget*Modifier_slim;
	GestionSlim =lookup_widget(objet,"GestionSlim");
        gtk_widget_hide(GestionSlim );
Modifier_slim =lookup_widget(objet,"Modifier_slim");        
Modifier_slim=create_Modifier_slim();
	gtk_widget_show(Modifier_slim);


    GtkWidget*COMBO;    
    GtkWidget*ID;   
    GtkWidget*CINTETE;
    GtkWidget*NBCND;
    GtkWidget*CINCON;    
    GtkWidget*ORIEN;  
    GtkWidget*NBVO;
    GtkWidget*J;
    GtkWidget*M;
    GtkWidget*A;  
    GtkWidget *treeview_user;
e=chercher("ajoutslim.txt",x.id);
ID=lookup_widget (Modifier_slim, "entry32");
sprintf(ch3,"%d",e.id);
gtk_entry_set_text(GTK_ENTRY(ID),ch3);
COMBO=lookup_widget (Modifier_slim, "comboboxentry4"); 
int i;
if(strcmp(e.nom_liste,"1")==0)i=0;
if(strcmp(e.nom_liste,"2")==0)i=1;
if(strcmp(e.nom_liste,"3")==0)i=2;


 gtk_combo_box_set_active(GTK_COMBO_BOX(COMBO),i);
CINTETE=lookup_widget (Modifier_slim, "entry9");
sprintf(ch4,"%d",e.CIN_tete_liste);
gtk_entry_set_text(GTK_ENTRY(CINTETE),ch4);
CINCON=lookup_widget (Modifier_slim, "entry10");
gtk_entry_set_text(GTK_ENTRY(CINCON),e.CIN_condidats);

J=lookup_widget (Modifier_slim,"spinbutton8");
M=lookup_widget(Modifier_slim,"spinbutton9");
A=lookup_widget (Modifier_slim,"spinbutton10");	
	 gtk_spin_button_set_value(J,e.dat_naiisance.jour);
	 gtk_spin_button_set_value(M,e.dat_naiisance.mois);
	 gtk_spin_button_set_value(A,e.dat_naiisance.annees);

GtkWidget*G;
GtkWidget*D;
GtkWidget*L;   

G=lookup_widget (Modifier_slim,"modifier_gauche");
D=lookup_widget (Modifier_slim,"modifier_droit");
L=lookup_widget (Modifier_slim,"modifier_libertaire");
if(strcmp(e.orientation_polytique,"droit")==0) {   gtk_toggle_button_set_active(GTK_RADIO_BUTTON(G),FALSE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(D),TRUE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(L),FALSE);}
           
	


else if(strcmp(e.orientation_polytique,"gauche")==0) {   gtk_toggle_button_set_active(GTK_RADIO_BUTTON(G),TRUE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(D),FALSE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(L),FALSE);}
           
	else if(strcmp(e.orientation_polytique,"libertaire")==0) {   gtk_toggle_button_set_active(GTK_RADIO_BUTTON(G),FALSE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(D),FALSE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(L),TRUE);}	
	else {  gtk_toggle_button_set_active(GTK_RADIO_BUTTON(G),FALSE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(D),FALSE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(L),FALSE);}	



GtkWidget*X;
GtkWidget*C;
GtkWidget*V;   

G=lookup_widget (Modifier_slim,"modifier3");
D=lookup_widget (Modifier_slim,"modifier6");
L=lookup_widget (Modifier_slim,"modifier9");
if(e.nb_condidats==3) {   gtk_toggle_button_set_active(GTK_CHECK_BUTTON(G),TRUE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(D),FALSE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(L),FALSE);}
           
	


else if(e.nb_condidats==6) {   gtk_toggle_button_set_active(GTK_CHECK_BUTTON(G),FALSE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(D),TRUE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(L),FALSE);}
           
	else if(e.nb_condidats==9) {   gtk_toggle_button_set_active(GTK_CHECK_BUTTON(G),FALSE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(D),FALSE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(L),TRUE);}	
	else {  gtk_toggle_button_set_active(GTK_CHECK_BUTTON(G),FALSE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(D),FALSE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(L),FALSE);}	






}


void
on_button_SypprimerSlim_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *GestionSlim ,*SuppressionSlim;
	GestionSlim =lookup_widget(objet,"GestionSlim");
        gtk_widget_hide(GestionSlim );
       SuppressionSlim=create_SuppressionSlim();
	gtk_widget_show(SuppressionSlim);
}


void
on_button11_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
int y;
char cin[100],I[100];
electorale e,e1;
int h;
char x[100];
    GtkWidget*COMBO;    
    GtkWidget*ID;   
    GtkWidget*CINTETE;
    GtkWidget*NBCND;
    GtkWidget*CINCON;    
    GtkWidget*ORIEN;  
    GtkWidget*NBVO;
    GtkWidget*J;
    GtkWidget*M;
    GtkWidget*A;
COMBO=lookup_widget (objet, "comboboxentry4"); 
ID=lookup_widget (objet, "entry32");
CINTETE=lookup_widget (objet, "entry9");
CINCON=lookup_widget (objet, "entry10");
strcpy(e.nom_liste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(COMBO)));
strcpy(I,gtk_entry_get_text(GTK_ENTRY(ID)));
e.id=atoi(I);
h=e.id;
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(CINTETE)));
e.CIN_tete_liste=atoi(cin);
strcpy(e.CIN_condidats,gtk_entry_get_text(GTK_ENTRY(CINCON)));

J=lookup_widget (objet,"spinbutton8");
M=lookup_widget(objet,"spinbutton9");
A=lookup_widget (objet,"spinbutton10");
e.dat_naiisance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(J));
e.dat_naiisance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(M));
e.dat_naiisance.annees=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(A));
if(nb2==1)
    {strcpy(e.orientation_polytique,"gauche");}
 if(nb2==2)
    {strcpy(e.orientation_polytique,"droit");}
 if(nb2==3)
   { strcpy(e.orientation_polytique,"libertaire");}
if(and==3)
	{e.nb_condidats=3;}
if(and==6)
	{e.nb_condidats=6;} 
if(and==9)
	{e.nb_condidats=9;}

y=modifier1("ajoutslim.txt",h,e);

GtkWidget *Modifier_slim;
GtkWidget *GestionSlim;
GtkWidget *treeview;


Modifier_slim = lookup_widget(objet,"Modifier_slim");
gtk_widget_hide(Modifier_slim);
GestionSlim=lookup_widget(objet,"GestionSlim");
GestionSlim = create_GestionSlim ();
  gtk_widget_show (GestionSlim);
treeview=lookup_widget(GestionSlim,"tableau");
afficher_le(treeview,"ajoutslim.txt");
}




void
on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on__clicked                            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button23_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button25_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button32_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton_hommeU_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
gboolean T=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
if (T) test=1;

}


void
on_radiobutton_femmeU_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
gboolean T=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
if (T) test=2;
}


void
on_checkbutton13_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data){
gboolean T=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
if (T) test2=1;




}











void
on_AfficherU_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
utilisateur user;
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview;

fenetre_ajout = lookup_widget(objet,"AjouterUtilisateur");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();

gtk_widget_show(fenetre_afficher);


fenetre_ajout=lookup_widget(objet,"AjoutUtilisateur");


gtk_widget_hide(fenetre_ajout);
treeview=lookup_widget(fenetre_afficher,"affichageTree");
afficherU(treeview,"utilisateur.txt");
}


void
on_affichageTree_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gint* cin;
gchar* nom;
gchar* prenom;
gint* jour;
gint* mois;
gint* annee;
gchar* genre;
gchar* type;
gint* numBV;
gint* vote;



GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&jour,4,&mois,5,&annee,6,&genre,7,&type,8,&numBV,9,&vote,-1);
userDeleted.cin=cin;
strcpy(userDeleted.nom,nom);
strcpy(userDeleted.prenom,prenom);
userDeleted.DateNaissance.jours=jour;
userDeleted.DateNaissance.mois=mois;
userDeleted.DateNaissance.annee=annee;
strcpy(userDeleted.genre,genre);
userDeleted.numBV=numBV;
userDeleted.vote=vote;


}

}
//-------------------------------------EDIT----------------------------------

void
on_ModiferUser_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
utilisateur user;
GtkWidget *entry_cinU,*entry_nomU,*entry_prenomU,*jour,*mois,*annee,*radiobutton_hommeU,*radiobutton_femmeU,*type,*numbv,*msg;
int id;
entry_cinU = lookup_widget (objet,"Modifier_cinU" );
entry_nomU =lookup_widget (objet,"Modifier_nomU" );
entry_prenomU =lookup_widget (objet,"Modifier_prenomU" );
jour = lookup_widget (objet,"Modifier_jourU" );
mois = lookup_widget (objet,"Modifier_moisU" );
annee = lookup_widget (objet,"Modifier_anneeU" );
type = lookup_widget (objet,"comboboxentry14" );
numbv = lookup_widget (objet,"Modifier_nbvU" );
msg=lookup_widget(objet,"Modifier_msg");
id=atoi(gtk_entry_get_text(GTK_ENTRY(entry_cinU)));

user.cin=id;
strcpy(user.nom,gtk_entry_get_text(GTK_ENTRY(entry_nomU)));
strcpy(user.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenomU)));
user.DateNaissance.jours=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
user.DateNaissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
user.DateNaissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

strcpy(user.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
user.numBV=atoi(gtk_entry_get_text(GTK_ENTRY(numbv)));

if(testModifier==1)strcpy(user.genre,"homme");
else strcpy(user.genre,"femme");
utilisateur u=chercherU("utilisateur.txt",atoi(gtk_entry_get_text(GTK_ENTRY(entry_cinU))));
user.vote=u.vote;
if ((Verif_CIN(u.cin))&&(verif_STRING(u.nom))&&(verif_STRING(u.prenom))){int x=modifierU("utilisateur.txt",ToUse,user);
gtk_label_set_text(GTK_LABEL(msg),"--/Edited Successfully/--");}

else gtk_label_set_text(GTK_LABEL(msg),"--/ Check your informations /--");



}



//----------------------------------------DELETE----------------------------------

void
on_button_SupprimerU_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
int x=supprimerU("utilisateur.txt",userDeleted.cin);
GtkWidget *fenetre_afficher,*w1;

GtkWidget *treeview1;


w1=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);

gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"affichageTree");
afficherU(treeview1,"utilisateur.txt");
}


void
on_refresh_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;

GtkWidget *treeview1;


w1=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);

gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"affichageTree");
afficherU(treeview1,"utilisateur.txt");


}


void
on_button_rechercher_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;

GtkWidget *treeview1;

GtkWidget  *id_entry;
int id;
id_entry = lookup_widget (objet,"entry_idRechercher");
id=atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));

utilisateur u=chercherU("utilisateur.txt",id);
 FILE *f=fopen("search.txt","w");
if(f!=NULL){
if (u.cin!=-1) fprintf(f,"%d %s %s %d %d %d %s %s %d %d\n",u.cin,u.nom,u.prenom,u.DateNaissance.annee,u.DateNaissance.mois,u.DateNaissance.jours,u.genre,u.type,u.numBV,u.vote);
    fclose(f);
}

w1=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"affichageTree");
afficherU(treeview1,"search.txt");


}




void
on_button_ModifierU_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview;

GtkWidget *cin,*id_entry,*nom_entry,*prenom_entry,*type_entry,*jour,*mois,*annee,*nbv,*homme,*femme,*msg;
w1=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);
fenetre_ajout=lookup_widget(objet,"ModifierU");

fenetre_ajout=create_ModifierU();
gtk_widget_hide(fenetre_ajout);
gtk_widget_show(fenetre_ajout);
id_entry = lookup_widget (fenetre_ajout,"Modifier_cinU");
nom_entry = lookup_widget (fenetre_ajout,"Modifier_nomU");
prenom_entry = lookup_widget (fenetre_ajout,"Modifier_prenomU");
type_entry=lookup_widget (fenetre_ajout,"comboboxentry14");
jour=lookup_widget (fenetre_ajout,"Modifier_jourU");
mois=lookup_widget (fenetre_ajout,"Modifier_moisU");
annee=lookup_widget (fenetre_ajout,"Modifier_anneeU");
nbv=lookup_widget (fenetre_ajout,"Modifier_nbvU");
homme=lookup_widget(fenetre_ajout,"Modifier_hommeU");
femme=lookup_widget(fenetre_ajout,"Modifier_femmeU");
char id[10];
sprintf(id,"%d",userDeleted.cin);
gtk_entry_set_text(GTK_ENTRY(id_entry),id);
gtk_entry_set_text(GTK_ENTRY(nom_entry),userDeleted.nom);
gtk_entry_set_text(GTK_ENTRY(prenom_entry),userDeleted.prenom);
int j;
if(strcmp(userDeleted.type,"Admin")==0)j=0;
if(strcmp(userDeleted.type,"Electeur")==0)j=1;
if(strcmp(userDeleted.type,"Observateur")==0)j=2;
if(strcmp(userDeleted.type,"ABV")==0)j=3;

 gtk_combo_box_set_active(GTK_COMBO_BOX(type_entry),j);
	 gtk_spin_button_set_value(jour,userDeleted.DateNaissance.jours);
	 gtk_spin_button_set_value(mois,userDeleted.DateNaissance.mois);
	 gtk_spin_button_set_value(annee,userDeleted.DateNaissance.annee);


char ch[50];
sprintf(ch,"%d",userDeleted.numBV);
gtk_entry_set_text(GTK_ENTRY(nbv),ch);
	if(strcmp(userDeleted.genre,"homme")==0) {   gtk_toggle_button_set_active(GTK_RADIO_BUTTON(homme),TRUE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(femme),FALSE);}
           
	else {   gtk_toggle_button_set_active(GTK_RADIO_BUTTON(homme),FALSE); gtk_toggle_button_set_active(GTK_RADIO_BUTTON(femme),TRUE);}

}




		//searching the id to modify
void
on_Modifier_Search_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *cin,*id_entry,*nom_entry,*prenom_entry,*type_entry,*jour,*mois,*annee,*nbv,*homme,*femme,*msg;
int id;

id_entry = lookup_widget (objet,"Modifier_cinU");
nom_entry = lookup_widget (objet,"Modifier_nomU");
prenom_entry = lookup_widget (objet,"Modifier_prenomU");
type_entry=lookup_widget (objet,"comboboxentry14");
jour=lookup_widget (objet,"Modifier_jourU");
mois=lookup_widget (objet,"Modifier_moisU");
annee=lookup_widget (objet,"Modifier_anneeU");
nbv=lookup_widget (objet,"Modifier_nbvU");
homme=lookup_widget(objet,"Modifier_hommeU");
femme=lookup_widget(objet,"Modifier_femmeU");
id=atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));

utilisateur u=chercherU("utilisateur.txt",id);
msg=lookup_widget(objet,"msgU");



if(u.cin!=-1){
gtk_label_set_text(GTK_LABEL(msg),"");
gtk_entry_set_text(GTK_ENTRY(nom_entry),u.nom);
gtk_entry_set_text(GTK_ENTRY(prenom_entry),u.prenom);
int j;
if(strcmp(u.type,"Admin")==0)j=0;
if(strcmp(u.type,"Electeur")==0)j=1;
if(strcmp(u.type,"Observateur")==0)j=2;
if(strcmp(u.type,"ABV")==0)j=3;

 gtk_combo_box_set_active(GTK_COMBO_BOX(type_entry),j);
	 gtk_spin_button_set_value(jour,u.DateNaissance.jours);
	 gtk_spin_button_set_value(mois,u.DateNaissance.mois);
	 gtk_spin_button_set_value(annee,u.DateNaissance.annee);


char ch[50];
sprintf(ch,"%d",u.numBV);
gtk_entry_set_text(GTK_ENTRY(nbv),ch);
	if(strcmp(u.genre,"homme")==0) {   gtk_toggle_button_set_active(GTK_RADIO_BUTTON(homme),TRUE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(femme),FALSE);}
           
	else {   gtk_toggle_button_set_active(GTK_RADIO_BUTTON(homme),FALSE); gtk_toggle_button_set_active(GTK_RADIO_BUTTON(femme),TRUE);}

}
else gtk_label_set_text(GTK_LABEL(msg),"Invalid Cin");
ToUse=id;


}


void
on_Modifier_hommeU_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
gboolean T=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
if (T) testModifier=1;
}


void
on_Modifier_femmeU_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
gboolean T=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
if (T) testModifier=2;
}


void
on_button_homeU_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_afficher,*admin;
fenetre_afficher = lookup_widget(objet,"GestionU");
gtk_widget_hide(fenetre_afficher);
admin=lookup_widget(objet,"Eadmin");
admin=create_Eadmin();
gtk_widget_show(admin);



}


void
on_button_GestionU_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*admin;
GtkWidget *treeview;
fenetre_afficher = lookup_widget(objet,"GestionU");
admin=lookup_widget(objet,"Eadmin");
gtk_widget_hide(admin);
fenetre_afficher=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();

gtk_widget_show(fenetre_afficher);

treeview=lookup_widget(fenetre_afficher,"affichageTree");
afficherU(treeview,"utilisateur.txt");

}


void
on_button_RechercherType_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;

GtkWidget *treeview1;

GtkWidget  *type;
int id;
char type1[50];
type = lookup_widget (objet,"Rechercher_typeU" );
strcpy(type1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

chercher_Type(type1);


w1=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"affichageTree");
afficherU(treeview1,"search.txt");





}


void
on_button_AjouterU_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *w1,*fenetre_afficher,*fenetre_ajout;
w1=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);
fenetre_ajout=lookup_widget(objet,"AjoutUtilisateur");

fenetre_ajout=create_AjoutUtilisateur();
gtk_widget_hide(fenetre_ajout);
gtk_widget_show(fenetre_ajout);


}


void
on_button_retour_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{

utilisateur user;
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview;

fenetre_ajout = lookup_widget(objet,"ModifierU");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();

gtk_widget_show(fenetre_afficher);


fenetre_ajout=lookup_widget(objet,"ModifierU");


gtk_widget_hide(fenetre_ajout);
treeview=lookup_widget(fenetre_afficher,"affichageTree");
afficherU(treeview,"utilisateur.txt");









}


void
on_statsU_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre,*fenetre_affichage;
GtkWidget *labelTPE,*labelTPHF,*labelTPF,*labelag,*labelnb;
char tpe[10];
int i=TPE("utilisateur.txt");
sprintf(tpe,"%d",i);
strcat(tpe,".00%");
fenetre = lookup_widget(objet,"statsU");


char ty[20];
GtkWidget *type;
fenetre_affichage=lookup_widget(objet,"GestionU");
type=lookup_widget(fenetre_affichage,"Rechercher_typeU");
strcpy(ty,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
fenetre=create_statsU();

gtk_widget_show(fenetre);
labelTPE=lookup_widget(fenetre,"TPE");
labelTPHF=lookup_widget(fenetre,"TPHF");
labelTPF=lookup_widget(fenetre,"TPF");
labelag=lookup_widget(fenetre,"ag");
labelnb=lookup_widget(fenetre,"nb");
char tph[20];
char tpf[20];
float h=40,f=60;

sprintf(tph,"%.2f",h);
strcat(tph,"%"	);
sprintf(tpf,"%.2f",f);
strcat(tpf,"%"	);
char agstr[10],nbstr[10];
gtk_label_set_text(GTK_LABEL(labelTPE),tpe);
gtk_label_set_text(GTK_LABEL(labelTPHF),tph);
gtk_label_set_text(GTK_LABEL(labelTPF),tpf);
int a=agemoyen("utilisateur.txt");
sprintf(agstr,"%d",a);
strcat(agstr,"ans");
gtk_label_set_text(GTK_LABEL(labelag),agstr);
a=NbrElec("utilisateur.txt");
sprintf(nbstr,"%d",a);
gtk_label_set_text(GTK_LABEL(labelnb),nbstr);

}


void
on_checkob2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
 nombredobservateur=1;
}


void
on_checkob4_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
 nombredobservateur=2;
}


void
on_radiobutton_act_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 ET=1;
}


void
on_radiobutton_inac_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 ET=2;


}


void
on_button_ajouterbv_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry_numbv,*entry_idagent,*cap ,*nbobs , *adresse ;
bureau bv ;
GtkWidget *fenetre_ajout ;
fenetre_ajout =lookup_widget(objet,"ajouter_bv");

entry_numbv = lookup_widget (objet,"entry_num" );
entry_idagent =lookup_widget (objet,"entry_idbv"); 
cap = lookup_widget (objet,"spinbutton_cap" );

adresse = lookup_widget (objet,"combobox_adresse" );
bv.capacite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cap));
strcpy (bv.id,gtk_entry_get_text(GTK_ENTRY(entry_idagent)));

strcpy (bv.adresse,gtk_combo_box_get_active_text(GTK_COMBO_BOX(adresse)));
strcpy (bv.numero,gtk_entry_get_text(GTK_ENTRY(entry_numbv)));
GtkWidget *msg=lookup_widget(fenetre_ajout,"msgbv");
if((Verif_CIN2(bv.id))!=1){gtk_label_set_text(GTK_LABEL(msg),"cin invalide ");
}
else {
ajouter(ET,nombredobservateur,bv);
gtk_label_set_text(GTK_LABEL(msg),"Ajout aver succees");}
}


void
on_afficherbv1_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
bureau bv;
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview;

fenetre_ajout = lookup_widget(objet,"ajouter_bv");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"afficherbv");
fenetre_afficher=create_afficherbv();

gtk_widget_show(fenetre_afficher);

treeview=lookup_widget(fenetre_afficher,"treeview");
afficherbv(treeview);
}
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* numero;
	gchar* id;
	gchar* capacite;
	gchar* nombredobservateur;
	gchar* adresse;
	gchar* etat;
	bureau bv;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&numero,2,&capacite,3,&nombredobservateur,4,&adresse,5,&etat,-1);
		strcpy(bv.id,id);
		strcpy(bv.numero,numero);
		
		bv.capacite=atoi(capacite);
		strcpy(bv.nombredobservateur1,nombredobservateur);
	        strcpy(bv.adresse,adresse);
		bv.capacite=atoi(capacite);
		strcpy(bv.etat,etat);
		afficherbv(treeview);
}
}



void
on_checknum_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
 choix1=2;
}


void
on_checkid_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
 choix1=1;
}


void
on_button_annulerbv_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
char id[20];
		GtkWidget  *donnee ,*affichage,*treeview;
		donnee= lookup_widget(objet,"entry_idbv4");
		strcpy(id,gtk_entry_get_text(GTK_ENTRY(donnee)));
		supprimer(id);
		affichage = lookup_widget(objet,"afficherbv");
		gtk_widget_destroy(affichage);
		affichage = create_afficherbv();
		gtk_widget_show(affichage);
		treeview=lookup_widget(affichage,"treeview");
		afficherbv(treeview);
}


void
on_button_consulterbv_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
FILE *tmp=NULL;
char id[20];
GtkWidget *donnee ,*affichage,*treeview;
donnee=lookup_widget(objet,"entry_idbv4");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(donnee)));
chercher_bv(id,choix1);
affichage=lookup_widget(objet,"afficherbv");
gtk_widget_destroy(affichage);
affichage=create_afficherbv();
gtk_widget_show(affichage);
treeview=lookup_widget(affichage,"treeview");
afficherch(treeview);
remove("tmp.txt");
}


void
on_button_cre__rbv_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
{GtkWidget *fenetre_ajouter_bv;
GtkWidget *fenetre_afficher;

fenetre_afficher = lookup_widget(objet,"afficherbv");
gtk_widget_hide(fenetre_afficher);
fenetre_ajouter_bv=lookup_widget(objet,"ajouter_bv");
fenetre_ajouter_bv=create_ajouter_bv();
gtk_widget_show(fenetre_ajouter_bv);

}
}


void
on_button_modifierbv_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *entry_ID;
	GtkWidget *entry_num,*entry_id_ag,*label,*cap,*nombredobservateur2,*nombredobservateur4,*adress,*actif,*inactif;
	GtkWidget *fenetre_ajout,*fenetre_afficher, *treeview, *donnee;
	bureau bv;
	char id[2000];
	FILE *f=NULL;
	int i,j=0 ;
	f=fopen("bv.txt","r");

	donnee = lookup_widget(objet,"entry_idbv4");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(donnee)));

	fenetre_afficher = lookup_widget(objet ,"afficherbv");
	fenetre_ajout=lookup_widget(objet,"ajouter_bv");
	fenetre_ajout=create_ajouter_bv();
	gtk_widget_show(fenetre_ajout);

	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %d %s %s %s \n",bv.id,bv.numero, &bv.capacite,bv.nombredobservateur1,bv.adresse,bv.etat)!=EOF);
		{
			if(strcmp(bv.id,id)==0)
			{
			entry_id_ag= lookup_widget(fenetre_ajout ,"entry_idbv");
			entry_num= lookup_widget(fenetre_ajout,"entry_num");
			
			cap= lookup_widget(fenetre_ajout,"spinbutton_cap");
			
			adress = lookup_widget(fenetre_ajout,"combobox_adresse");
			actif = lookup_widget(fenetre_ajout,"radiobutton_act");
			inactif = lookup_widget(fenetre_ajout,"radiobutton_inac");
			nombredobservateur2 = lookup_widget(fenetre_ajout,"checkob2");
			nombredobservateur4 = lookup_widget(fenetre_ajout,"checkob4");

					if(strcmp(bv.etat,"inactif")==0)
					{	gtk_toggle_button_set_active(GTK_RADIO_BUTTON(inactif),TRUE);}
					else
						{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(actif),TRUE);}


					if(strcmp(bv.nombredobservateur1,"nombredobservateur2")==0)
					{	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (nombredobservateur2),TRUE);}
					else
						{gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (nombredobservateur4),TRUE);}
																

				gtk_entry_set_text(GTK_ENTRY(entry_num),bv.adresse);
					if(strcmp(bv.adresse,"ariana")==0)
						{j=0;}
	else if(strcmp(bv.adresse,"tunis")==0)
						{j=1;}
	else if(strcmp(bv.adresse,"manouba")==0)
						{j=2;}
	else if(strcmp(bv.adresse,"bizerte")==0)
						{j=3;}
	else
	{j=4;}
	

				
				gtk_combo_box_set_active(GTK_COMBO_BOX(adress),j);
				gtk_entry_set_text(GTK_ENTRY(entry_id_ag),bv.id);
				gtk_spin_button_set_value(cap,bv.capacite);
				gtk_entry_set_text(GTK_ENTRY(entry_num),bv.numero);

}}}
fclose(f);
//supprimer(id);
gtk_widget_hide(fenetre_afficher);
}










void
on_GestionBV_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*admin;
GtkWidget *treeview;

admin=lookup_widget(objet,"Eadmin");
gtk_widget_hide(admin);
fenetre_afficher = lookup_widget(objet,"afficherbv");
fenetre_afficher=create_afficherbv();

gtk_widget_show(fenetre_afficher);

treeview=lookup_widget(fenetre_afficher,"treeview");
afficherbv(treeview);
}


void
on_tableau_row_activated               (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
GtkWidget*NOM;    
    GtkWidget*ID;   
    GtkWidget*CINTETE;
    GtkWidget*NBCND;
    GtkWidget*CINCON;    
    GtkWidget*ORIEN;  
    GtkWidget*NBVO;
    GtkWidget*J;
    GtkWidget*M;
    GtkWidget*A;



GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ID,1,&NOM,2,&CINTETE,3,&NBCND,4,&CINCON,5,&ORIEN,6,&J,7,&M,8,&A,-1);
x.id=ID;
strcpy(x.nom_liste,NOM);
x.CIN_tete_liste=CINTETE;
x.nb_condidats=NBCND;
strcpy(x.CIN_condidats,CINCON);
x.dat_naiisance.jour=J;
x.dat_naiisance.mois=M;
x.dat_naiisance.annees=A;
}
}


void
on_button37_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget  *id_entry;
int id;
id_entry = lookup_widget (objet,"entry31");
id=atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));

electorale e=chercher("ajoutslim.txt",id);
 FILE *f=fopen("search.txt","w");
if(f!=NULL){
        fprintf(f,"%d %s %d %d %s %s %d %d %d",e.id,e.nom_liste,e.CIN_tete_liste,e.nb_condidats,e.CIN_condidats,e.orientation_polytique,e.dat_naiisance.jour,e.dat_naiisance.mois,e.dat_naiisance.annees);
    fclose(f);
}
GtkWidget *GestionSlim;
GtkWidget *treeview;

GestionSlim = lookup_widget(objet,"GestionSlim");
gtk_widget_hide(GestionSlim);
GestionSlim=lookup_widget(objet,"GestionSlim");
GestionSlim = create_GestionSlim ();
  gtk_widget_show (GestionSlim);
treeview=lookup_widget(GestionSlim,"tableau");
afficher_le(treeview,"search.txt");
}


void
on_modifier3_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active((togglebutton)))
{and=3;}
}


void
on_modifier_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active((togglebutton)))
{and=9;}
}


void
on_modifier6_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active((togglebutton)))
{and=6;}
}


void
on_modifier_libertaire_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
nb2=3;
}


void
on_modifier_droit_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
nb2=2;
}


void
on_modifier_gauche_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
nb2=1;
}


void
onutton42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active((togglebutton)))
{et=3;}
}


void
on_button6_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active((togglebutton)))
{et=6;}
}


void
on_button9_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active((togglebutton)))
{et=9;}
}


void
on_radio_libertaire_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
nb=1;
}


void
on_radio_droit_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
nb=2;
}


void
on_radio_gauche_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
nb=3;
}


void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button13_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
electorale e ;

GtkWidget *sup;

sup= lookup_widget (objet,"entry35");
e.id=atoi(gtk_entry_get_text(GTK_ENTRY(sup)));
supprimer1("ajoutslim.txt",e.id);

GtkWidget *SuppressionSlim;
GtkWidget *GestionSlim;
GtkWidget *treeview;


SuppressionSlim = lookup_widget(objet,"SuppressionSlim");
gtk_widget_hide(SuppressionSlim);
GestionSlim=lookup_widget(objet,"GestionSlim");
GestionSlim = create_GestionSlim ();
  gtk_widget_show (GestionSlim);
treeview=lookup_widget(GestionSlim,"tableau");
afficher_le(treeview,"ajoutslim.txt");



}


void
on_Svalider_ajout_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
int y;
char cin[15];
electorale e; 

   
    GtkWidget*ID;
    GtkWidget*NOM;
    GtkWidget*CINTETE;
    GtkWidget*NBCND;
    GtkWidget*CINCON;    
    GtkWidget*ORIEN;  
    GtkWidget*J;
    GtkWidget*M;
    GtkWidget*A;

ID=lookup_widget (objet, "entry34");
NOM=lookup_widget (objet, "entry33");
CINTETE=lookup_widget (objet, "entry13");
CINCON=lookup_widget (objet, "entry25");





e.id=atoi(gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy(e.nom_liste,gtk_entry_get_text(GTK_ENTRY(NOM)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(CINTETE)));
e.CIN_tete_liste=atoi(cin);
strcpy(e.CIN_condidats,gtk_entry_get_text(GTK_ENTRY(CINCON)));
J=lookup_widget (objet,"spinbutton_jours");
M=lookup_widget(objet,"spinbutton_mois");
A=lookup_widget (objet,"spinbutton_annee");
e.dat_naiisance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(J));
e.dat_naiisance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(M));
e.dat_naiisance.annees=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(A));
if(nb==1)
    {strcpy(e.orientation_polytique,"gauche");}
 if(nb==2)
    {strcpy(e.orientation_polytique,"droit");}
 if(nb==3)
   { strcpy(e.orientation_polytique,"libertaire");}
if(et==3)
	{e.nb_condidats=3;}
if(et==6)
	{e.nb_condidats=6;} 
if(et==9)
	{e.nb_condidats=9;}

sprintf(cin,"%d",et);

y=ajouter1("ajoutslim.txt",e);
int x=ajouter2("ajout.txt",e);
GtkWidget *AjoutSlim;
GtkWidget *GestionSlim;
GtkWidget *treeview;


AjoutSlim = lookup_widget(objet,"AjoutSlim");
gtk_widget_hide(AjoutSlim);
GestionSlim=lookup_widget(objet,"GestionSlim");
GestionSlim = create_GestionSlim ();
  gtk_widget_show (GestionSlim);
treeview=lookup_widget(GestionSlim,"tableau");
afficher_le(treeview,"ajoutslim.txt");


}


void
on_button40_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *AjoutSlim,*GestionSlim,*treeview;
	AjoutSlim =lookup_widget(objet,"AjoutSlim");
        gtk_widget_hide(GestionSlim );
        GestionSlim=create_GestionSlim();
	gtk_widget_show(GestionSlim);
treeview=lookup_widget(GestionSlim,"tableau");
afficher_le(treeview,"ajoutslim.txt");

}


void
on_button41_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Modifier_slim,*GestionSlim,*treeview;
	Modifier_slim =lookup_widget(objet,"Modifier_slim");
        gtk_widget_hide(GestionSlim );
        GestionSlim=create_GestionSlim();
	gtk_widget_show(GestionSlim);
treeview=lookup_widget(GestionSlim,"tableau");
afficher_le(treeview,"ajoutslim.txt");

}


void
on_button42_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *SuppressionSlim,*GestionSlim,*treeview;
	SuppressionSlim =lookup_widget(objet,"SuppressionSlim");
        gtk_widget_hide(GestionSlim );
        GestionSlim=create_GestionSlim();
	gtk_widget_show(GestionSlim);
treeview=lookup_widget(GestionSlim,"tableau");
afficher_le(treeview,"ajoutslim.txt");
}


void
on_modifier9_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active((togglebutton)))
{and=9;}
}


void
on_button4_retCal_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_calcul, *menu_election;
window_calcul=lookup_widget(button,"window_calcul");
gtk_widget_destroy(window_calcul);

menu_election=create_menu_election();
gtk_widget_show (menu_election);
}


void
on_button3_calculEl_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_toaffich_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowelection, *menu_election;
menu_election=lookup_widget(button,"menu_election");
gtk_widget_destroy(menu_election);
windowelection=create_window_election ();
gtk_widget_show (windowelection);
}


void
on_tosupp_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowelection, *menu_election;
menu_election=lookup_widget(button,"menu_election");
gtk_widget_destroy(menu_election);
windowelection=create_window_election ();
gtk_widget_show (windowelection);
}


void
on_tostat_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowstat, *menu_election;
menu_election=lookup_widget(button,"menu_election");
gtk_widget_destroy(menu_election);
windowstat=create_window_calcul ();
gtk_widget_show (windowstat);
}


void
on_toajout_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter_election, *menu_election;
menu_election=lookup_widget(button,"menu_election");
gtk_widget_destroy(menu_election);
window_ajouter_election=create_window_ajouter_election ();
gtk_widget_show (window_ajouter_election);
}


void
on_tomodif_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter_election, *menu_election;
menu_election=lookup_widget(button,"menu_election");
gtk_widget_destroy(menu_election);
window_ajouter_election=create_window_ajouter_election ();
gtk_widget_show (window_ajouter_election);
}


void
on_tocherch_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcherch, *menu_election;
menu_election=lookup_widget(button,"menu_election");
gtk_widget_destroy(menu_election);
windowcherch=create_window_recherelect ();
gtk_widget_show (windowcherch);
}


void
on_button3_rechercher_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rech, *menu_election;
window_rech=lookup_widget(button,"window_recherelect");
gtk_widget_destroy(window_rech);

menu_election=create_menu_election();
gtk_widget_show (menu_election);
}


void
on_button3_reche_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
remove("RechElect.txt");
char ident[20];
GtkWidget *id,*tree,*windowrechercher,*output;
int k;
windowrechercher=lookup_widget(button,"window_recherelect");
id = lookup_widget(button,"entry3_rechelect");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(id)));
k=rechercher_election(ident);
if (k==0)
	{

	output=lookup_widget(button,"label3_rechint");
	gtk_label_set_text(GTK_LABEL(output), "Election INTROUVABLE");
	}
if (k==1)	
	{	

tree=lookup_widget(windowrechercher,"treeview1_recElect");
afficher_rechercher_election(tree);
}
}


void
on_treeview1_recElect_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeview1_affElection_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* gou;
gchar* muni;
gchar* nbh;
gchar* nbc;
election e;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowajout,*windowelection,*tre,*idd,*jj,*mm,*aa,*go,*mu,*nh,*nc;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&jour,2,&mois,3,&annee,4,&gou,5,&muni,6,&nbh,7,&nbc,-1);

windowajout=create_window_ajouter_election();
windowelection=create_window_election();
gtk_widget_hide(windowelection);
gtk_widget_show(windowajout);

idd=lookup_widget(windowajout,"entry1_ideclection");
gtk_entry_set_text(GTK_ENTRY(idd),id);

jj=lookup_widget(windowajout,"spinbutton1_jour");
gtk_entry_set_text(GTK_ENTRY(jj),jour);

mm=lookup_widget(windowajout,"spinbutton1_mois");
gtk_entry_set_text(GTK_ENTRY(mm),mois);

aa=lookup_widget(windowajout,"spinbutton1_annee");
gtk_entry_set_text(GTK_ENTRY(aa),annee);

go=lookup_widget(windowajout,"entry1_gouvernorat");
gtk_entry_set_text(GTK_ENTRY(go),gou);
/*
mu=lookup_widget(windowajout,"comboboxentry1_munic");
gtk_combo_box_new_text(GTK_ENTRY(mu),muni);
*/


}
}


void
on_buttretaffich_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowelection, *menu_election;
windowelection=lookup_widget(button,"windowelection");
gtk_widget_destroy(windowelection);

menu_election=create_menu_election();
gtk_widget_show (menu_election);
}


void
on_button2_tachcalcul_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_calcul, *windowElection;
windowElection=lookup_widget(button,"window_election");
gtk_widget_destroy(windowElection);
window_calcul=create_window_calcul();
gtk_widget_show (window_calcul);
}


void
on_button2_windModif_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter_election, *windowElection;
windowElection=lookup_widget(button,"window_election");
gtk_widget_destroy(windowElection);
window_ajouter_election=create_window_ajouter_election ();
gtk_widget_show (window_ajouter_election);
}


void
on_button2_windAjouter_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter_election, *windowElection;
windowElection=lookup_widget(button,"window_election");
gtk_widget_destroy(windowElection);
window_ajouter_election=create_window_ajouter_election ();
gtk_widget_show (window_ajouter_election);
}


void
on_button2_affElect_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowElection;
windowElection=lookup_widget(button,"window_election");
gtk_widget_destroy(windowElection);
windowElection=create_window_election();
tree=lookup_widget(windowElection,"treeview1_affElection");

afficher_election(tree);

gtk_widget_hide(windowElection);
gtk_widget_show(windowElection);
}


void
on_button2_rechElect_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rech, *windowElection;
windowElection=lookup_widget(button,"window_election");
gtk_widget_destroy(windowElection);
window_rech=create_window_recherelect ();
gtk_widget_show (window_rech);
}


void
on_button1_retourajt_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *menu_election;
windowajouter=lookup_widget(button,"window_ajouter_election");
gtk_widget_destroy(windowajouter);
menu_election=create_menu_election();
gtk_widget_show (menu_election);
}


void
on_checkbutton1_confi_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
{y=1;}
}


void
on_radiobutton1_nbr2_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=2;}
}


void
on_radiobutton1_nbr2_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(button,"label1_nbrCons");
gtk_label_set_text(GTK_LABEL(output), "16");
}


void
on_radiobutton1_nbr1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}


void
on_radiobutton1_nbr1_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(button,"label1_nbrCons");
gtk_label_set_text(GTK_LABEL(output), "12");
}


void
on_radiobutton_nbr3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=3;}
}


void
on_radiobutton_nbr3_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(button,"label1_nbrCons");
gtk_label_set_text(GTK_LABEL(output), "22");
}


void
on_radiobutton_nbr4_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=4;}
}


void
on_radiobutton_nbr4_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(button,"label1_nbrCons");
gtk_label_set_text(GTK_LABEL(output), "30");
}


void
on_radiobutton_nbr5_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=5;}
}


void
on_radiobutton_nbr5_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(button,"label1_nbrCons");
gtk_label_set_text(GTK_LABEL(output), "36");
}


void
on_radiobutton_nbr6_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=6;}
}


void
on_radiobutton_nbr6_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(button,"label1_nbrCons");
gtk_label_set_text(GTK_LABEL(output), "60");
}


void
on_button1_ajouterElection_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
election e;
GtkWidget *windowajout, *windowelection,*id,*jour,*mois,*annee,*gou,*munic,*nbrh,*nbrc,*output,*output1;
windowajout=lookup_widget(button,"window_ajouter_election");
id = lookup_widget(windowajout,"entry1_ideclection");
gou= lookup_widget(windowajout,"entry1_gouvernorat");
jour = lookup_widget(button,"spinbutton1_jour");
mois = lookup_widget(button,"spinbutton1_mois");
annee = lookup_widget(button,"spinbutton1_annee");
munic=lookup_widget(button,"comboboxentry1_munic");
strcpy(e.identifiant,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(e.gouvernorat,gtk_entry_get_text(GTK_ENTRY(gou)));
e.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
e.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
e.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
strcpy(e.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(munic)));
if(z==1 )
{strcpy(e.nbhabit,"5000");
e.nbcons=12;
} 
else if(z==2)
{strcpy(e.nbhabit,"5001->10000");
e.nbcons=16;
}
else if(z==3)
{strcpy(e.nbhabit,"10001->25000");
e.nbcons=22;
}
else if(z==4)
{strcpy(e.nbhabit,"25001->50000");
e.nbcons=30;
}
else if(z==5)
{strcpy(e.nbhabit,"50001->100000");
e.nbcons=36;
}
else if(z==7)
{strcpy(e.nbhabit,"100001->500000");
e.nbcons=40;
}
else if(z==6)
{strcpy(e.nbhabit,"Plus500000");
e.nbcons=60;
}
if(y==1){
if ((strcmp(e.identifiant,"")==0)||( strcmp(e.gouvernorat,"")==0)||( strcmp(e.municipalite,"")==0)) {
output=lookup_widget(button,"label2_donnemanq");
gtk_label_set_text(GTK_LABEL(output), "Données manquantes. \n Veuillez remplir tout les champs!");
output1=lookup_widget(button,"label1_ajouter");
gtk_label_set_text(GTK_LABEL(output1), "");
}
else
{int k;

k=rechercher_election(e.identifiant);
if(k==1){output=lookup_widget(button,"label2_donnemanq");
gtk_label_set_text(GTK_LABEL(output), "id est deja existe");}
else{
ajouter_election(e);
output=lookup_widget(button,"label2_donnemanq");
gtk_label_set_text(GTK_LABEL(output), "");
output1=lookup_widget(button,"label1_ajouter");
gtk_label_set_text(GTK_LABEL(output1), "Ajouter avec Succes");
}}}
z=0;
y=0;


}


void
on_button1_ModifierElection_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
election e1;
GtkWidget *windowajout, *windowelection,*id1,*jour1,*mois1,*annee1,*gou1,*munic1,*nbrh1,*nbrc1,*output2,*output3;
windowajout=create_window_ajouter_election();
windowelection=create_window_election();
id1 = lookup_widget(button,"entry1_ideclection");
gou1= lookup_widget(button,"entry1_gouvernorat");
jour1 = lookup_widget(button,"spinbutton1_jour");
mois1 = lookup_widget(button,"spinbutton1_mois");
annee1 = lookup_widget(button,"spinbutton1_annee");
munic1=lookup_widget(button,"comboboxentry1_munic");
strcpy(e1.identifiant,gtk_entry_get_text(GTK_ENTRY(id1)));
strcpy(e1.gouvernorat,gtk_entry_get_text(GTK_ENTRY(gou1)));
e1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
e1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois1));
e1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));
strcpy(e1.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(munic1)));
if(z==1 )
{strcpy(e1.nbhabit,"5000");
e1.nbcons=12;
} 
else if(z==2)
{strcpy(e1.nbhabit,"5001->10000");
e1.nbcons=16;
}
else if(z==3)
{strcpy(e1.nbhabit,"10001->25000");
e1.nbcons=22;
}
else if(z==4)
{strcpy(e1.nbhabit,"25001->50000");
e1.nbcons=30;
}
else if(z==5)
{strcpy(e1.nbhabit,"50001->100000");
e1.nbcons=36;
}
else if(z==7)
{strcpy(e1.nbhabit,"100001->500000");
e1.nbcons=40;
}
else if(z==6)
{strcpy(e1.nbhabit,"Plus500000");
e1.nbcons=60;
}if(y==1){
if ((strcmp(e1.identifiant,"")==0)||( strcmp(e1.gouvernorat,"")==0)||( strcmp(e1.municipalite,"")==0)) {
output2=lookup_widget(button,"label2_donnemanq");
gtk_label_set_text(GTK_LABEL(output2), "Données manquantes. \n Veuillez remplir tout les champs!");
output3=lookup_widget(button,"label1_modifier");
gtk_label_set_text(GTK_LABEL(output3), "");
}
else
{
modifier_election(e1.identifiant,e1,"Election.txt");
output2=lookup_widget(button,"label2_donnemanq");
gtk_label_set_text(GTK_LABEL(output2), "");
output3=lookup_widget(button,"label1_modifier");
gtk_label_set_text(GTK_LABEL(output3), "Modifier avec Succes");
}}
z=0;
y=0;
}


void
on_radiobutton_nbr7_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=7;}
}


void
on_radiobutton_nbr7_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(button,"label1_nbrCons");
gtk_label_set_text(GTK_LABEL(output), "40");
}




void
on_Conf_AjoutO_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_DroitOA_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_GaucheOA_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_LibertaireOA_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_HommeOA_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button50_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
user u; 
   GtkWidget*P;
P=lookup_widget (objet, "entry44");
u.idliste=atoi(gtk_entry_get_text(GTK_ENTRY(P)));
GtkWidget *P2;
P2=lookup_widget (objet, "entry45");
nbv(u.idliste,&t);
char str[50];
sprintf(str,"%d",t);
gtk_entry_set_text(GTK_ENTRY(P2),str);
}


void
on_AFFICHER_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview;
int y;
 y=L_ordre("ajoutx.txt","l_ordre.txt");
GtkWidget *STATS2 ,*STATS;
	STATS =lookup_widget(objet,"STATS");
        gtk_widget_hide(STATS );
        STATS2=create_STATS2();
	gtk_widget_show(STATS2);
treeview=lookup_widget(STATS2,"treeview4"); 
afficher_xx(treeview,"l_ordre.txt");
}


void
on_button53_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *GestionSlim ,*STATS;
	GestionSlim =lookup_widget(objet,"GestionSlim");
        gtk_widget_hide(GestionSlim );
        STATS=create_STATS();
	gtk_widget_show(STATS);
}


void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button52_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *GestionSlim ,*STATS2,*treeview;
	STATS2 =lookup_widget(objet,"STATS2");
        gtk_widget_hide(STATS2 );
        GestionSlim=create_GestionSlim();
	gtk_widget_show(GestionSlim);
treeview=lookup_widget(GestionSlim,"tableau");
afficher_le(treeview,"ajoutslim.txt");


}


void
on_AfficherO_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur; 
GtkWidget *treeview1;
lobservateur=lookup_widget(objet,"lobservateur");
treeview1=lookup_widget(lobservateur,"treeview1");
affi(treeview1);
}


void
on_AjoutO_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ModifO_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur, *modifiero;
lobservateur=lookup_widget(objet,"lobservateur");  
gtk_widget_destroy(lobservateur);
modifiero=create_modifiero();
gtk_widget_show(modifiero);
}


void
on_SuppressionO_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Conf_ModifO_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ChercherO_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{

}


void
on_FemmeOM_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_HommeOM_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_DroitOM_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_GaucheOM_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_LibertaireOM_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_Conf_SupO_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}




void
on_confirmerao_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
observateur o;
GtkWidget *ao1,*ao2,*jj,*mm,*aa,*ao4,*ao5, *ao6;
GtkWidget *ajouto;
GtkWidget *spinbuttonau;
ajouto=lookup_widget(objet,"ajouto");
ao1=lookup_widget(objet,"ao1");
ao2=lookup_widget(objet,"ao2");
jj=lookup_widget(objet,"spinbutton1_jour");
mm=lookup_widget(objet,"spinbutton1_mois");
aa=lookup_widget(objet,"spinbutton1_annee");
ao4=lookup_widget(objet,"ao4");
ao5=lookup_widget(objet,"ao5");
ao6=lookup_widget(objet,"combobox1_proffesion");


strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(ao1)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(ao2)));
o.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jj));
o.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mm));
o.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (aa));
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(ao4)));
strcpy(o.id,gtk_entry_get_text(GTK_ENTRY(ao5)));
strcpy(o.pro,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ao6)));


if(choix==0)

strcpy(o.nat,"tunisien");
else 
if(choix==1)
strcpy(o.nat,"etranger");
ajouter_obs(o);
}


void
on_retourao_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur, *ajouto;
ajouto=lookup_widget(objet,"ajouto");  
gtk_widget_destroy(ajouto);
lobservateur=create_lobservateur();
gtk_widget_show(lobservateur);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix=0;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix=1;
}


void
on_confirmermo_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
observateur o;
GtkWidget *mo1,*mo2,*jj,*mm,*aa,*mo4,*mo5, *mo6;
GtkWidget *modifiero;
modifiero=lookup_widget(objet,"modifiero");
mo1=lookup_widget(objet,"mo1");
mo2=lookup_widget(objet,"mo2");
jj=lookup_widget(objet,"spinbutton2_jour");
mm=lookup_widget(objet,"spinbutton2_mois");
aa=lookup_widget(objet,"spinbutton2_annee");
mo4=lookup_widget(objet,"mo4");
mo5=lookup_widget(objet,"mo5");
mo6=lookup_widget(objet,"combobox2_proffesion");


strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(mo1)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(mo2)));
o.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jj));
o.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mm));
o.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (aa));
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(mo4)));
strcpy(o.id,gtk_entry_get_text(GTK_ENTRY(mo5)));
strcpy(o.pro,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mo6)));

if(choix1==0)

strcpy(o.nat,"tunisien");
else 
if(choix1==1)
strcpy(o.nat,"etranger");
modifier_obs(o);
}


void
on_retourmo_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur, *modifiero;
modifiero=lookup_widget(objet,"modifiero");  
gtk_widget_destroy(modifiero);
lobservateur=create_lobservateur();
gtk_widget_show(lobservateur);
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1=0;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1=1;
}


void
on_supo_clicked                        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *suppo,*suo;
observateur o;
char ch1[20];
suo=lookup_widget(objet,"suo");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(suo)));
supprimer_obs(o,ch1);
}


void
on_retoursupp_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur, *suppo;
suppo=lookup_widget(objet,"suppo");  
gtk_widget_destroy(suppo);
lobservateur=create_lobservateur();
gtk_widget_show(lobservateur);
}


void
on_retourchercher_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur, *chercheo;
chercheo=lookup_widget(objet,"chercheo");  
gtk_widget_destroy(chercheo);
lobservateur=create_lobservateur();
gtk_widget_show(lobservateur);
}


void
on_chero_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
char ch1[30];
observateur u;
  GtkWidget *label20;
  GtkWidget *label21;
  GtkWidget *label22;
  GtkWidget *label23;
  GtkWidget *label24;
  GtkWidget *label25;
  GtkWidget *label26;

label20=lookup_widget(objet,"label20");
label21=lookup_widget(objet,"label21");
label22=lookup_widget(objet,"label22");
label23=lookup_widget(objet,"label23");
label24=lookup_widget(objet,"label24");
label25=lookup_widget(objet,"label25");
label26=lookup_widget(objet,"label26");


GtkWidget *cher;
cher=lookup_widget(objet,"cher");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(cher)));
u=chercher_obs(ch1);
if (strcmp(u.cin,"")==0){
gtk_label_set_text(GTK_LABEL(label21),"Introuvable");
gtk_label_set_text(GTK_LABEL(label20),"");
gtk_label_set_text(GTK_LABEL(label22),"");
gtk_label_set_text(GTK_LABEL(label23),"");
gtk_label_set_text(GTK_LABEL(label24),"");
gtk_label_set_text(GTK_LABEL(label25),"");
gtk_label_set_text(GTK_LABEL(label26),"");

}
else{
gtk_label_set_text(GTK_LABEL(label20),u.nom);
gtk_label_set_text(GTK_LABEL(label21),u.prenom);
gtk_label_set_text(GTK_LABEL(label23),u.cin);
gtk_label_set_text(GTK_LABEL(label24),u.id);
gtk_label_set_text(GTK_LABEL(label25),u.nat);
gtk_label_set_text(GTK_LABEL(label26),u.pro);}
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
    gchar* nom;
    gchar* prenom;
    gchar* dateo;
    gchar* cin;
    gchar* id;
    gchar* nat;
    gchar* pro;
     
   observateur u;

GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowMod,*windowobs,*tre,*no,*pre,*dat,*ci,*idd,*na,*pr;


if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&dateo,3,&cin,4,&id,5,&nat,6,&pro,-1);
windowMod=create_modifiero();
windowobs=create_lobservateur();
gtk_widget_hide(windowobs);
gtk_widget_show(windowMod);


no=lookup_widget(windowMod,"mo1");
gtk_entry_set_text(GTK_ENTRY(no),nom);

pre=lookup_widget(windowMod,"mo2");
gtk_entry_set_text(GTK_ENTRY(pre),prenom);

dat=lookup_widget(windowMod,"mo3");
gtk_entry_set_text(GTK_ENTRY(dat),dateo);

ci=lookup_widget(windowMod,"mo4");
gtk_entry_set_text(GTK_ENTRY(ci),cin);

idd=lookup_widget(windowMod,"mo5");
gtk_entry_set_text(GTK_ENTRY(idd),id);

pr=lookup_widget(windowMod,"mo6");
gtk_entry_set_text(GTK_ENTRY(pr),pro);




}
}


void
on_affichero_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur; 
GtkWidget *treeview1;
lobservateur=lookup_widget(objet,"lobservateur");
treeview1=lookup_widget(lobservateur,"treeview1");
affi(treeview1);
}


void
on_modifiero_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur, *modifiero;
lobservateur=lookup_widget(objet,"lobservateur");  
gtk_widget_destroy(lobservateur);
modifiero=create_modifiero();
gtk_widget_show(modifiero);
}


void
on_ajoutero_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur, *ajouto;
lobservateur=lookup_widget(objet,"lobservateur");  
gtk_widget_destroy(lobservateur);
ajouto=create_ajouto();
gtk_widget_show(ajouto);
}


void
on_supprimero_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur, *suppo;
lobservateur=lookup_widget(objet,"lobservateur");  
gtk_widget_destroy(lobservateur);
suppo=create_suppo();
gtk_widget_show(suppo);
}


void
on_button_gestionElection_clicked      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionElec,*admin;
gestionElec=lookup_widget(objet,"Election_Electorale");  
gestionElec=create_Election_Electorale();
gtk_widget_show(gestionElec);
admin=lookup_widget(objet,"Eadmin");
gtk_widget_hide(admin);

}


void
on_Gelection_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionElec,*admin;
gestionElec=lookup_widget(objet,"menu_election");  
gestionElec=create_menu_election();
gtk_widget_show(gestionElec);
admin=lookup_widget(objet,"Election_Electorale");
gtk_widget_hide(admin);


}


void
on_Gelectorale_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionElec,*admin;

gestionElec=lookup_widget(objet,"GestionSlim");
gestionElec=create_GestionSlim();
gtk_widget_show(gestionElec);
admin=lookup_widget(objet,"Election_Electorale");
gtk_widget_hide(admin);
}


void
on_Home2_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_afficher,*admin;
fenetre_afficher = lookup_widget(objet,"Election_Electorale");
gtk_widget_hide(fenetre_afficher);
admin=lookup_widget(objet,"Eadmin");
admin=create_Eadmin();
gtk_widget_show(admin);

}


void
on_Gobservateur_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *observ,*admin;

observ=lookup_widget(objet,"lobservateur");
observ=create_lobservateur();
gtk_widget_show(observ);
admin=lookup_widget(objet,"Eadmin");
gtk_widget_hide(admin);
}


void
on_logout_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *login;
GtkWidget *Espace_d_administrateur;
login=lookup_widget(objet,"Login");
Espace_d_administrateur=lookup_widget(objet,"Eadmin");
gtk_widget_hide(Espace_d_administrateur);
login=create_Login();
gtk_widget_show(login);



}


void
on_login_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Espace_d_administrateur,*name,*pass;
name=lookup_widget(objet,"Nom_login");
pass=lookup_widget(objet,"Password");
char nom[20];
char password[20];

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(name)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass)));
GtkWidget *log;
GtkWidget *msg;
msg=lookup_widget(objet,"logMSG");
log=lookup_widget(objet,"Login");

if(VerifAdmin(nom,password)){

Espace_d_administrateur = create_Eadmin();
  gtk_widget_show (Espace_d_administrateur);
gtk_widget_hide(log);
}
else {gtk_label_set_text(GTK_LABEL(msg),"Verify your informations");}
}



void
on_home3_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*admin;
fenetre_afficher = lookup_widget(objet,"GestionSlim");
gtk_widget_hide(fenetre_afficher);
admin=lookup_widget(objet,"Eadmin");
admin=create_Eadmin();
gtk_widget_show(admin);
}


void
on_home6_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*admin;
fenetre_afficher = lookup_widget(objet,"afficherbv");
gtk_widget_hide(fenetre_afficher);
admin=lookup_widget(objet,"Eadmin");
admin=create_Eadmin();
gtk_widget_show(admin);
}


void
on_home4_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*admin;
fenetre_afficher = lookup_widget(objet,"menu_election");
gtk_widget_hide(fenetre_afficher);
admin=lookup_widget(objet,"Eadmin");
admin=create_Eadmin();
gtk_widget_show(admin);
}


void
on_home5_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_afficher,*admin;
fenetre_afficher = lookup_widget(objet,"lobservateur");
gtk_widget_hide(fenetre_afficher);
admin=lookup_widget(objet,"Eadmin");
admin=create_Eadmin();
gtk_widget_show(admin);
}





void
on_chercherobs_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *lobservateur, *chercheo;
lobservateur=lookup_widget(objet,"lobservateur");  
gtk_widget_destroy(lobservateur);
chercheo=create_chercheo();
gtk_widget_show(chercheo);
}

