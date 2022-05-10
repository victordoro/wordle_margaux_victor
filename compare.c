#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



bool comparer (char *mot_ordi, char *mot_entre, int size)
{

    char L[size];
    char mot_modif_ordi[size];
    char mot_modif_entre[size];
    
    strcpy(mot_modif_ordi, mot_ordi);
    strcpy(mot_modif_entre, mot_entre);
 
 // recherche des lettres bien placées

    for (int i = 0; i < size; i++)
    {
        if ( mot_modif_ordi[i] == mot_modif_entre[i])
        {
            L[i]= 'X' ;
            mot_modif_ordi[i]= '1'; //pour qu il ne soit plus comparé
            mot_modif_entre[i]= '0'; //pour qu il ne soit plus comparé
        }
        else
        {
            L[i]= '.';
        }
    }

// verification de si on a le bon mot

   if (strcmp(mot_ordi, mot_entre) == 0)
    {
        return (true);
    }
  

// si on a pas le bon mot, lettres mal placées

    for (int i = 0; i < size; i++)
    {
        for( int j=0; j < size; j++)
        {
            if (i != j)
            {
                if ( mot_modif_entre[i] == mot_modif_ordi[j] )
                {
                    L[i] = 'O';
                    mot_modif_ordi[i]= '1'; //pour qu il ne soit plus comparé
                    mot_modif_entre[i]= '0'; //pour qu il ne soit plus comparé
                }
            }
        }
    }
    for (int i = 0; i < size; ++i)
    {
        printf("%c", L[i]);
    }
    printf("\n");
    return(false);
}
