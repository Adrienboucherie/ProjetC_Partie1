#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

void search(char recherche[40], liste l)
{
    char *tmp;
    int nboccur=0;
    while (l!=NULL)
    {
        tmp=strstr(l->chemin, recherche); 
        if (tmp != NULL && !strcmp(tmp, recherche))
        {
            printf("Chemin : %s\n", l->chemin);
            l=l->suivant;
            nboccur++;
        }
        else
            l=l-> suivant;
    }
    if (nboccur==0) //Si pas de correspondance
    {
        printf("Aucun fichier/dossier trouvé\n");
    }
}