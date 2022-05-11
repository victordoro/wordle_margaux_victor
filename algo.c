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
#include <math.h>

char* meilleur_mot(char** dictionnaire, unsigned int size){

    double max = 0;
    int indice_du_max = 0;
    int liste_symbole[5];
    

    for(int j = 0; j<5; ++j){
        liste_symbole[j]=0;
    }

    for(int i = 0; i<size; ++i){

        double esperance = 0;

        for(int cas=0; cas<3; ++cas){

            for(int lettres=0; lettres<5;++lettres){
                liste_symbole[lettres] = cas;

                char* nouv_dico[size];
                int size_nouv_dico = 0;

                nv_dico(dictionnaire[i], liste_symbole, 5, size, &size_nouv_dico, dictionnaire, nouv_dico);

                if(size_nouv_dico !=0){
                    
                    double p = (double)size_nouv_dico/(double)size;

                    double bit = -log2(p);

                    esperance = esperance + p*bit;
                }

            }
        }

        if (esperance>max){max=esperance; indice_du_max = i;}
    }
    return(dictionnaire[indice_du_max]);
}
