#include <string.h>
#include <stdio.h>

void nv_dico (char* ancien_mot, int* resultat, int size_mot, int size_dico, int *size_nv_dico, char** dico, char** nouv_dico)
{
    int position_bien_place[size_mot];
    int position_mal_place[size_mot];
    int position_non_place[size_mot];
    char lettre_bien_place[size_mot];
    char lettre_mal_place[size_mot];
    char lettre_non_place[size_mot];

    int indice = 0;

    for (int i = 0; i<size_mot; ++i)
    {
        if (resultat[i] == 2)
        {
            position_bien_place[i]=i+1;
            lettre_bien_place[i]=ancien_mot[i];
        }
        else 
        {          
            position_bien_place[i]=0;
            lettre_bien_place[i]='.';
        }

        if (resultat[i] == 1)
        {
            position_mal_place[i]=i+1;
            lettre_mal_place[i]=ancien_mot[i];
        }
        else 
        { 
            position_mal_place[i]=0;
            lettre_mal_place[i]='.';
        }

        if ( resultat[i] == 0)
        { 
            position_non_place[i]=i+1;
            lettre_non_place[i]=ancien_mot[i];
        }
        else
        {
            position_non_place[i]=0;
            lettre_non_place[i]='.';
        }
    }


    for (int i = 0; i<size_dico; ++i)
    {
        int j = 0;

// verification lettre bien placée et non place
        while (j < size_mot )
        {
            if ( (position_bien_place[j] != 0) && (dico[i][j] != lettre_bien_place[j]))
            {
                j = size_mot + 1;
            }
            else
            {
                ++j;
            }
        }

// si tout est ok pour les lettres bien placées et non placées
        if ( j == size_mot ) 
        {
            int h = 0;
            while ( h<size_mot )
            {
                if (position_mal_place[h] != 0)
                {
                    int g = 0;
                    while( g<size_mot )
                    {
// si je trouve la lettre a un autre endroit j'arrête ma boucle
                        if ( (dico[i][g] == lettre_mal_place[h]) && (g != h))
                        {
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
                else if (position_non_place[h] != 0)
                {
                int g = 0;
                    while( g<size_mot )
                    {

// si je trouve la lettre a un  endroit j'arrête ma boucle
                        if (dico[i][g] == lettre_non_place[h])
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
            ++indice;
        } 
    }

    *size_nv_dico = indice;
}
