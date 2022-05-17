#include <string.h>
#include <stdio.h>

void nv_dico (char* ancien_mot, int* resultat, int size_mot, int size_dico, int *size_nv_dico, char** dico, char** nouv_dico)
{
    char lettre_bien_place[size_mot];
    char lettre_mal_place[size_mot];
    char lettre_non_place[size_mot];
    char copy_mot_dico[size_mot];

    int indice = 0;

    for (int i = 0; i<size_mot; ++i)
    {
        if (resultat[i] == 2) {lettre_bien_place[i]=ancien_mot[i];}
        else { lettre_bien_place[i]='.'; }

        if (resultat[i] == 1) { lettre_mal_place[i]=ancien_mot[i];}
        else { lettre_mal_place[i]='.'; }

        if ( resultat[i] == 0) { lettre_non_place[i]=ancien_mot[i];}
        else { lettre_non_place[i]='.'; }
    }


    for (int i = 0; i<size_dico; ++i)
    {
        int j = 0;
        strcpy(copy_mot_dico, dico[i]);
    

// verification lettre bien placée
        while (j < size_mot )
        {
            if ( (lettre_bien_place[j] != '.') && (copy_mot_dico[j] != lettre_bien_place[j]))
            {
                j = size_mot + 1;
            }
            else
            {
                ++j;
            }
        }

// si tout est ok pour les lettres bien placées
        if ( j == size_mot ) 
        {
            int h = 0;
            while ( h<size_mot )
            {
                if (lettre_mal_place[h] != '.')
                {
                    int g = 0;
                    while( g<size_mot )
                    {
// si je trouve la lettre a un autre endroit j'arrête ma boucle
                        if ( (copy_mot_dico[g] == lettre_mal_place[h]) && (g != h) && (copy_mot_dico[g] != lettre_non_place[h]) && (lettre_bien_place[g] != copy_mot_dico[g]))
                        {
                            copy_mot_dico[g]='.';
                            g = size_mot + 1;
                        }
                        else
                        {
                            ++g;
                        }
                    }

// si j'ai parcouru tout mon mot c'est que la lettre n'y est pas
                    if (g == size_mot)
                    {
                        h = size_mot +1;
                        j = size_mot + 1;
                    }

                }
                else if (lettre_non_place[h] != '.')
                {
                int g = 0;
                    while( g<size_mot )
                    {

// si je trouve la lettre a un  endroit j'arrête ma boucle
                        if ( (copy_mot_dico[g] == lettre_non_place[h]) && (copy_mot_dico[g] !=lettre_bien_place[g]) )
                        {
                            g = size_mot + 1;
                        }
                        else
                        {
                            ++g;
                    
                        }    
                    }

// si je n'ai pas parcouru tout mon mot c'est que la lettre y est
                    if ( g !=size_mot)
                    {
                        h = size_mot +1;
                        j = size_mot + 1;                        
                    } 

                }
                ++h;
                
            }
        }

// si tout est ok
        if (j == size_mot)
        {
            nouv_dico[indice] = dico[i];
            indice++;
        } 
    }

    *size_nv_dico = indice;
}

/*
int main()
{
    char* dico [15];
    dico[0]="ABACA";
    dico[1]="ARBRE";
    dico[2]="ATMAN";
    int size_nv_dico = 0;
    char* nouv_dico[256];
    char ancien_mot[5];
    ancien_mot[0] = 'A';
    ancien_mot[1] = 'B';
    ancien_mot[2] = 'A';
    ancien_mot[3] = 'C';
    ancien_mot[4] = 'A';
    int resultat[5];
    resultat[0] = 2;
    resultat[1] = 0;
    resultat[2] = 1;
    resultat[3] = 0;
    resultat[4] = 0;
    int size_mot = 5;
    int size_dico = 3;
    nv_dico(ancien_mot, resultat, size_mot, size_dico, &size_nv_dico, dico, nouv_dico);
    for (int i = 0; i< size_nv_dico; i++)
    {
        printf("%s\n", nouv_dico[i]);
    }
    return 0;
}
*/