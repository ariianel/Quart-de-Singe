#ifndef DEF_PARTIE
#define DEF_PARTIE

#include <iostream>

/**
  * Une énumération des types de joueurs.
  *
  * H - Joueur humain
  * R - Joueur robot
**/

enum natureJ{H, R};
const unsigned int tailleMax = 25;

/**
  * Une structure pour le stockage temporaire d'un mot.
*/

typedef struct{
	char *mot;
}Tmp;

/**
  * Une structure pour un joueur dans le jeu.
  */

typedef struct {
	natureJ natureJoueur; //Nature joueur Humain ou Robot
	unsigned int numJoueur;
	float scoreJoueur;
}Joueur;

/**
  * Une structure pour un jeu.
  */

typedef	struct{
	Joueur *joueur; //Les joueurs de la partie
	unsigned int nbjoueur; //nombre de joueur
	char *mot; //Stock le mot
}Partie;

void initialisation(const char*argv[], Partie &partie, unsigned int nbjoueur);
void tourdejeu(unsigned int ijoueur, Partie &partie, unsigned int nbjoueur);
bool verifmot(Partie &partie, char mot[]);
void generateurLettre(char a[]);
void conv(char t[]);
void perdu(Partie &partie, unsigned int ijoueur, unsigned int nbjoueur);
void destru(Partie &partie, Tmp &tmp);

#endif // !DEF_FONCTIONS