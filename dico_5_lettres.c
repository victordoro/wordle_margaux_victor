#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool dico_5_lettres(char* f_dico, char* f_nouveau_dico){

	FILE* dico = fopen(f_dico, "rb");
	FILE* nouveau_dico = fopen(f_nouveau_dico, "wb");


	if (dico == NULL) {
    printf ("Error. Unable to open input file '%s'.\n", f_dico) ;
    return (false) ;
  }

   	if (nouveau_dico == NULL) {
    printf ("Error. Unable to open output file '%s'.\n", f_nouveau_dico) ;
    fclose (dico) ;
    return (false) ;
  }

  char mot[256];
  fscanf (dico, "%s", mot) ;

  while (!feof (dico)) {
    if(strlen(mot)==5){
        fprintf(nouveau_dico, "%s\n", mot);
    }
    fscanf (dico, "%s", mot);
  }

	fclose(nouveau_dico);
	fclose(dico);
	return(true);
}
