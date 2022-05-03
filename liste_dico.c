#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct word_list_t {
  char *word ;
  struct word_list_t *next ;
};


// transformer le fichier dictionnaire en une liste
char **liste_dicho (char *fname, unsigned int *size)
{
  unsigned int count_words = 0 ;
  struct word_list_t *wl = NULL ;
  char buffer[256] ;

// on ouvre le fichier
  FILE *f = fopen (fname, "rb") ;
  if (f == NULL) return (NULL) ;

// on commence a lire les mots dans le dictionnaire
  fscanf (f, "%s", buffer) ;
  while (! feof (f)) 
  {
    struct word_list_t *new_cell = malloc (sizeof (struct word_list_t*)) ;
    
    if (new_cell == NULL) 
    {
      fclose (f) ;
      free(new_cell);
      return (NULL) ;
    }

// on garde en mémoire chaque mot
    char *new_word = malloc ((1 + strlen (buffer)) * sizeof (char)) ;
    if (new_word == NULL) 
    {
      free(new_cell);
      free(new_word);
      fclose (f) ;
      return (NULL) ;
    }

    strcpy (new_word, buffer) ;
    new_cell->word = new_word ;
    new_cell->next = wl ;
    wl = new_cell ;
    count_words++ ;

    fscanf (f, "%s", buffer) ;
  }

  fclose (f) ;

// on crée notre future liste
  char** words_array = malloc (count_words * sizeof (char**)) ;
  if (words_array == NULL) 
  {
    return (NULL) ;
  }

  *size = count_words ;

// on met chaque mot dans notre liste
  while (count_words != 0) 
  {  
    struct word_list_t *tmp = wl->next ;
    count_words-- ;
    words_array[count_words] = wl->word ;
    wl = tmp ;
  }

  return (words_array) ;
}