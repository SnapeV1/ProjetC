#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"
int test;
int test2;


void
on_button_Ajouter_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry_cinU,*entry_nomU,*entry_prenomU,*jour,*mois,*annee,*radiobutton_hommeU,*radiobutton_femmeU,*type,*numbv,*validation;
utilisateur user;

entry_cinU = lookup_widget (objet,"entry_cinU" );
entry_nomU =lookup_widget (objet,"entry_nomU" );
entry_prenomU =lookup_widget (objet,"entry_prenomU" );
jour = lookup_widget (objet,"spinbutton_jours" );
mois = lookup_widget (objet,"spinbutton_mois" );
annee = lookup_widget (objet,"spinbutton_annee" );
type = lookup_widget (objet,"type" );
numbv = lookup_widget (objet,"entry_bvU" );
validation=lookup_widget (objet,"checkbutton13" );


//-------------------------------------------------------------

user.cin=atoi(gtk_entry_get_text(GTK_ENTRY(entry_cinU)));
strcpy(user.nom,gtk_entry_get_text(GTK_ENTRY(entry_nomU)));
strcpy(user.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenomU)));
user.DateNaissance.jours=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
user.DateNaissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
user.DateNaissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

strcpy(user.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
user.numBV=atoi(gtk_entry_get_text(GTK_ENTRY(numbv)));
if (test2==1){
int x=ajouterU("utilisateur.txt",user,test);
}

}


void
on_button_gestionU_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_gestionE_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_gestionBV_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ModifierU_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajouterbv_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_modifierbv_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

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

treeview=lookup_widget(fenetre_afficher,"affichageTree");
afficherU(treeview);
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
utilisateur user;


GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&jour,4,&mois,5,&annee,6,&genre,7,&type,8,&numBV,9,&vote,-1);
user.cin=cin;
strcpy(user.nom,nom);
strcpy(user.prenom,prenom);
user.DateNaissance.jours=jour;
user.DateNaissance.mois=mois;
user.DateNaissance.annee=annee;
strcpy(user.genre,genre);
user.numBV=numBV;
user.vote=vote;
afficherU(treeview);

}
}

