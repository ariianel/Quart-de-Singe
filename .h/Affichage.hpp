#ifndef DEF_AFFICHAGE
#define DEF_AFFICHAGE

#include <iostream>
#include "Partie.hpp"

/*PROTOTYPES*/
void afficher(Partie &partie, unsigned int nbjoueur);
void affichermot(char mot[]);
char afficherNature(natureJ natureJoueur);
void afficheTous(unsigned int ijoueur, Partie &partie, unsigned int nbjoueur);
void afficheScore(Partie &partie, unsigned int i, unsigned int nbjoueur);

#endif // !DEF_FONCTIONS