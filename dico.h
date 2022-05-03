#ifndef __DICO_H__
#define __DICO_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool dico_5_lettres(char* dico, char* nouveau_dico);
char* conditions(char* mot, char** dictionnaire, unsigned int num_words);

#endif