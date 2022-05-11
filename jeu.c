#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dico.h"
#include "liste_dico.h"
#include "recherche_dico.h"
#include "compare.h"
#include <time.h>
#include "algo.h"

int main (int argc, char *argv[]){

// Vérification du nombre d'arguments.
    if (argc != 3) {
        printf ("Wrong argument. Expected <nb initial points>.\n") ;
        return (-1) ;
    }


// Création du nouveau dico avec que des mots de 5 lettres.
    if (dico_5_lettres(argv[1],argv[2])==false) {return(-1);}

    unsigned int size;
    char** dictionnaire = liste_dicho(argv[2], &size);

    unsigned int num_words=size;
    
    srand(time(NULL));
    int n_aleatoire = rand() % num_words;

    char mot_aleatoire[256];
    strcpy(mot_aleatoire,dictionnaire[n_aleatoire]); 


// Début de la partie

    printf("WORDLE\n\nVoici les règles :\n\nIl faut deviner un mot de 5 lettres en 6 essais\nà chaque essai est précisé\nsi la lettre n'est pas présente : .\nsi la lettre est présente mais pas au bon endroit : O\nsi la lettre est bien placée : X\n\nBonne Chance !!\n\n");

    char mot[256];
    int victoire=0;
    int nombre_essai=0;

    printf("Voulez-vous jouer avec l'algorithme resolveur ?\nTapez O ou N\n");
    char aide[256];
    scanf("%s", aide);
    if(strcmp(aide,"N")==0){
    
    do{
        char* bon_mot=conditions(mot, dictionnaire, num_words);

        printf("%s\n", bon_mot);

        if (comparer(mot_aleatoire, bon_mot, 5)==true) {victoire = 1;}

        ++nombre_essai;
        printf("Nombre d'essais : %d\n\n\n", nombre_essai);
    } while(nombre_essai<6 && victoire!=1);

    if(victoire == 1){printf("BRAVO !!\n");}
    else {printf("Dommage, le mot était : %s\n", mot_aleatoire);}

    }

    else if(strcmp(aide,"O")==0){

        resolveur(argv[2]);
        char* ancien_dico[num_words];
        int size_ancien_dico = num_words;
        char* nouveau_dico[num_words];
        int size_nv_dico = num_words;

        for(int i=0; i<num_words; ++i){
            ancien_dico[i] = dictionnaire[i];
            nouveau_dico[i] = dictionnaire[i];
        }


        do{

        char* bon_mot=conditions(mot, nouveau_dico, size_nv_dico);

        printf("%s\n", bon_mot);

        if (comparer(mot_aleatoire, bon_mot, 5)==true) {victoire = 1;}

        ++nombre_essai;

        printf("Rentrez le résulat : \n");

        char symbole[5];
        scanf("%s", symbole);

        int resultat[5];
        for(int j=0; j<5; ++j){
            if(symbole[j]=='X'){resultat[j]=2;}
            else if(symbole[j] =='O'){resultat[j]=1;}
            else {resultat[j]=0;}
        }

        char* nouveau_dico[num_words];
        size_nv_dico = 0;

        nv_dico (bon_mot, resultat, 5, size_ancien_dico, &size_nv_dico, ancien_dico, nouveau_dico);

        size_ancien_dico = size_nv_dico;

        for(int i=0; i<size_nv_dico; ++i){
            printf("%s\n",nouveau_dico[i]);
            strcpy(ancien_dico[i],nouveau_dico[i]);
        }

        char* premier_mot = meilleur_mot(nouveau_dico, size_nv_dico);

        printf("Le meilleur mot est : %s\n", premier_mot);

        printf("Nombre d'essais : %d\n\n\n", nombre_essai);
    } while(nombre_essai<6 && victoire!=1);

    if(victoire == 1){printf("BRAVO !!\n");}
    else {printf("Dommage, le mot était : %s\n", mot_aleatoire);}
    }

    else {printf("Commande non existante.\n"); return(-1);}

    return 0;
}

