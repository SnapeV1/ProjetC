#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"
#include "function.h"
int test;
int test2;
int testModifier;
int ToUse;

utilisateur userDeleted;

int ET=1;
int choix1;
int choix1=1;
int nombredobservateur=1;

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
on_button_AjouterSlim_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ModiferSlim_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_SypprimerSlim_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

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
GtkWidget  *id_entry;

w1=lookup_widget(objet,"GestionU");
fenetre_afficher=create_GestionU();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);
fenetre_ajout=lookup_widget(objet,"ModifierU");

fenetre_ajout=create_ModifierU();
gtk_widget_hide(fenetre_ajout);
gtk_widget_show(fenetre_ajout);



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
float h=0,f=0;
TPHF("utilisateur.txt",&h,&f);
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
entry_idagent =lookup_widget (objet,"entry_idbv" ); 
cap = lookup_widget (objet,"spinbutton_cap" );

adresse = lookup_widget (objet,"combobox_adresse" );
bv.capacite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cap));
strcpy (bv.id,gtk_entry_get_text(GTK_ENTRY(entry_idagent)));

strcpy (bv.adresse,gtk_combo_box_get_active_text(GTK_COMBO_BOX(adresse)));
strcpy (bv.numero,gtk_entry_get_text(GTK_ENTRY(entry_numbv)));
ajouter(ET,nombredobservateur,bv);
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
	int i,j ;
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

