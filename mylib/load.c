#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "mylib.h"
void load(char const * cheminactuel,liste *l)
{
    char strtmp[4096];
    struct dirent *lecture;
    DIR *repertoire=NULL;
    repertoire=opendir(cheminactuel);

    if (repertoire==NULL)
    {
       perror("Dossier inexistant ou access denied");
       printf("%s\n",cheminactuel); 
    }
    else
    {
		liste tmp;
		tmp = malloc(sizeof(struct Dossier));
		strcpy(tmp->chemin, cheminactuel);//Ajout dans la liste
		tmp->suivant= *l;
		*l=tmp;
        while ((lecture=readdir(repertoire))!=NULL)
        {
            if (lecture->d_type==DT_DIR) //Si dossier alors
            {
              if (strcmp(lecture->d_name, ".") && strcmp(lecture->d_name, ".."))
              { 
                strcpy(strtmp, cheminactuel);
                if (strcmp(cheminactuel,"/") && cheminactuel[strlen(cheminactuel)-1]!='/')
                    strcat(strtmp, "/");
                strcat(strtmp, lecture->d_name);
                load(strtmp, &(*l)); //On relance la fonction 
              }
            }
            else 
            {  
                if (lecture->d_type==DT_REG) //Si fichier
                {
                    strcpy(strtmp, cheminactuel);
                    if (strcmp(cheminactuel,"/"))
                        strcat(strtmp, "/");
                    strcat(strtmp, lecture->d_name);      
					liste tmp2;
					tmp2 = malloc(sizeof(struct Dossier)); //Ajout dans la liste
					strcpy(tmp2->chemin, strtmp);
					tmp2->suivant= *l;
					*l=tmp;
                }
            }
        }
    }
    closedir(repertoire);
}