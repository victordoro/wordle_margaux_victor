#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dico.h"
#include "liste_dico.h"
#include "recherche_dico.h"

char* conditions(char* mot, char** dictionnaire, unsigned int num_words){

    bool condition;
    
    do{
        condition = true;

        printf("Tentez un mot de 5 lettres en majuscules\n\n");

        scanf("%s", mot);

        if (strlen(mot)==5){printf("Bon nombre de lettres.\n");}
        else {printf("Mauvais nombre de lettres.\n"); condition=false;}

        if (dicho(dictionnaire, mot, 0, num_words-1)==true){printf("Mot dans le dico.\n\n");}
        else {printf("Mot pas dans le dico\n"); condition=false;}
        

    } while(condition==false);

    return(mot);
}
