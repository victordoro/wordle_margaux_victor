#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "liste_dico.h"

bool dicho (char **words, char *word, int left, int right) {

  if (left > right) {return (false);}
  int m = (left + right)/2;

  if (strcmp (word, words[m]) == 0) {return (true);}

  if (strcmp (word, words[m])<0) {return (dicho (words, word, left, m-1));}


  return (dicho (words, word, m+1, right)) ;
}
