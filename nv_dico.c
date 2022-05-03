#include <string.h>
#include <stdio.h>

void nv_dico (char* ancien_mot, int* resultat, int size_mot, int size_dico, int size_nv_dico, char** dico, char** nouv_dico)
{
    printf("a\n");
    char position_bien_place[size_mot];
    printf("1");
    char position_mal_place[size_mot];
    char position_non_place[size_mot];
    char lettre_bien_place[size_mot];
    char lettre_mal_place[size_mot];
    char lettre_non_place[size_mot];
    printf("2");
    for (int i = 0; i<size_mot; ++i)
    {
        if (resultat[i] == '2')
        {
            printf("%d 1", i);
            position_bien_place[i]=i;
            lettre_bien_place[i]=ancien_mot[i];
        }
        else 
        {
            printf("%d 2", i);            
            position_bien_place[i]='.';
            lettre_bien_place[i]='.';
        }
        if (resultat[i] == '1')
        {
            printf("%d 3", i);   
            position_mal_place[i]=i;
            lettre_mal_place[i]=ancien_mot[i];
        }
        else 
        {
            printf("%d 4", i);   
            position_mal_place[i]='.';
            lettre_mal_place[i]='.';
        }
        if ( resultat[i] == '0')
        {
            printf("%d 5", i);   
            position_non_place[i]=i;
            lettre_non_place[i]=i;
        }
    }


    for (int i = 0; i<size_dico; ++i)
    {
        int j = 0;

// verification lettre bien placée et non place
        while (j < size_mot )
        {
            if ( (position_bien_place[j] != '.') && (dico[i][j] != lettre_bien_place[j]))
            {
                j = size_mot + 1;
            }
            else if ( (position_non_place[j] != '.') && (dico[i][j] == lettre_non_place[j]))
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
                if (position_mal_place[h] != '.')
                {
                    int g = 0;
                    while( g<size_mot )
                    {

// si je trouve la lettre a un autre endroit j'arrête ma boucle
                        if ( (dico[i][g] == lettre_mal_place[h]) && (g != h))
                        {
                            g = size_mot + 1;
                        }
                        ++g;
                    }

// si j'ai parcouru tout mon mot c'est que la lettre n'y est pas
                    if (g == size_mot)
                    {
                        h = size_mot +1;
                        j = size_mot + 1;
                    }
                }
            }
        }

// si tout est ok
        if (j == size_mot)
        {
            stpcpy(nouv_dico[size_nv_dico], dico[i]);
            ++size_nv_dico;
        } 
    }
}

int main()
{
    char* dico [3];
    dico[0]="abc";
    dico[1]="bde";
    dico[2]="arb";
    int size_nv_dico = 0;
    char* nouv_dico[3];
    char ancien_mot[3];
    ancien_mot[0] = 'a';
    ancien_mot[1] = 'r';
    ancien_mot[2] = 'e';
    int resultat[3];
    resultat[0] = 2;
    resultat[1] = 1;
    resultat[2] = 0;
    int size_mot = 3;
    int size_dico = 9;
    printf("debut\n");
    nv_dico(ancien_mot, resultat, size_mot, size_dico, size_nv_dico, dico, nouv_dico);
    printf("fin\n");
    for (int i; i<3; ++i)
    {
        printf("%s\n", dico[i]);
    }
    return 0;
}