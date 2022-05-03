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

    printf("Début de partie\nVoici les règles :\nIl faut deviner un mot de 5 lettres en 6 essais\nà chaque essai est précisé\nsi la lettre n'est pas présente : .\nsi la lettre est présente mais pas au bon endroit : O\nsi la lettre est bien placée : X\nBonne Chance !!\n\n");

    char mot[256];
    int victoire=0;
    int nombre_essai=0;
    
    do{
        char* bon_mot=conditions(mot, dictionnaire, num_words);

        printf("%s\n", bon_mot);

        if (comparer(mot_aleatoire, bon_mot, 5)==true) {victoire = 1;}

        ++nombre_essai;
        printf("Nombre d'essais : %d\n\n\n", nombre_essai);
    } while(nombre_essai<6 && victoire!=1);

    if(victoire == 1){printf("BRAVO !!\n");}
    else {printf("Dommage, le mot était : %s\n", mot_aleatoire);}
    return 0;
}

