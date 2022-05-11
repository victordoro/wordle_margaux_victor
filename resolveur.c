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
#include "nv_dico.h"
#include "algo.h"

void resolveur(char* texte){

    unsigned int size;
    char** dictionnaire = liste_dicho(texte, &size);

    unsigned int num_words=size;

    char* premier_mot = meilleur_mot(dictionnaire, num_words);

    printf("Le meilleur mot est : %s\n", premier_mot);

}