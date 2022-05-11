#ifndef __ALGO_H__
#define __ALGO_H__

char* meilleur_mot(char** dictionnaire, unsigned int size);
void resolveur(char* texte);
void nv_dico (char* ancien_mot, int* resultat, int size_mot, int size_dico, int *size_nv_dico, char** dico, char** nouv_dico);

#endif