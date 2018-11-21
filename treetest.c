#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "mylib/mylib.h"
#define MAX 40



int main(int argc, char  *argv[]){
	liste l = NULL;
	char v3[MAX] = "/var"; //Chemin de départ

	load(v3, &l);
	search( argv[1] , l); //recherche en fonction du paramètre rentré dans le terminal
	free(l);
return 0;
}