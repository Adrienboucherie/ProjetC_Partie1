struct Dossier{
	char chemin[4096];
	struct Dossier * suivant;
};
typedef struct Dossier * liste;

void load(char const * chemin, liste *l);

void search(char recherche[40], liste l);
