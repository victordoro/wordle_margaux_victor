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

char* meilleur_mot(char** dictionnaire, unsigned int size){

    double max = 0;
    double p = 0;
    int indice_du_max = 0;
    int size_nouv_dico = 0;
    char** nouv_dico;
    int liste_symbole[5];
    

    for(int j = 0; j<5; ++j){
        liste_symbole[j]=0;
    }

    for(int i = 0; i<size; ++i){

        double esperance = 0;

        for(int cas=0; cas<size; ++size){

            for(int lettres=0; lettres<5;++lettres){
                liste_symbole[lettres] = cas;

                nouv_dico(dictionnaire[i], liste_symbole, 5, size, size_nouv_dico, dictionnaire, nouv_dico);
                p = size_nouv_dico/size;
                esperance += p*(-ln(1/p)/ln(2));

            }
        }

        if (esperance>max){max=esperance; indice_du_max = i}
    }
    return(dictionnaire[indice_du_max]);
}
