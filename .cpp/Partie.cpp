#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Partie.hpp"
#include "Affichage.hpp"

using namespace std;

/**
  * Initialise les joueurs et le mot pour un nouveau jeu.
  *
  * @param argv Les arguments de la ligne de commande passés au programme. Le premier argument devrait contenir les types de joueurs (H pour humain, R pour robot).
  * @param partie Une référence au jeu à initialiser.
  * @param nbjoueur Le nombre de joueurs dans la partie.
  */
void initialisation(const char*argv[], Partie &partie, unsigned int nbjoueur) {
	unsigned int j=0;
	partie.joueur  = new Joueur[nbjoueur];
	partie.mot = new char[2];
	while (argv[1][j]){
		partie.nbjoueur = nbjoueur;
		if (argv[1][j] == 'H')
			partie.joueur[j].natureJoueur = H;
		else if (argv[1][j] == 'R')
			partie.joueur[j].natureJoueur = R;
		partie.joueur[j].numJoueur = j+1;
		partie.joueur[j].scoreJoueur = 0.;
		++j; 
	}
	
}

/**
  * Affiche le nombre et le type de joueur dont c'est le tour.
  *
  * @param ijoueur L'index du joueur dont c'est le tour.
  * @param partie L'objet de jeu contenant les joueurs.
  * @param nbjoueur Le nombre de joueurs dans la partie.
  */
void tourdejeu(unsigned int ijoueur, Partie &partie, unsigned int nbjoueur){
	cout << partie.joueur[ijoueur%nbjoueur].numJoueur << afficherNature(partie.joueur[ijoueur%nbjoueur].natureJoueur);
}

/**
  * Vérifie que le mot donné est une continuation valide du mot courant.
  *
  * @param partie L'objet de jeu contenant le mot courant.
  * @param mot Le mot à vérifier comme suite valide.
  * @return true si le mot donné est une continuation valide, false sinon.
  */
bool verifmot(Partie &partie, char mot[]){
	for (int i=0; i<strlen(partie.mot); ++i){
		if(partie.mot[i] != mot[i]) //si le caractère à la même position que le mot donnée est différents
			return false; //return faux
	}
	return true; //return true si tous les caractères match
}

/**
  * Génère une lettre aléatoire.
  *
  * @param a Le tableau pour stocker la lettre générée.
  */
void generateurLettre(char a[]) {
	srand(time(NULL)); //Initialisation du générateur de lettre
	*a = rand() % ('Z' - 'A' + 1) + 'A'; //génère une lettre entre 'A' et 'Z'
}

/** Convertit tous les caractères de la chaîne donnée en majuscules.
  *
  * @param t Une chaîne terminée par un caractère nul à convertir en majuscules.
  * La chaîne est modifiée sur place.
  */

void conv(char t[]){
	for (int i = 0; i < strlen(t); i++) {
	t[i] = toupper(t[i]);
  }
}

/**
  * Affiche le joueur qui a perdu la partie.
  *
  * @param partie L'objet de jeu contenant les joueurs.
  * @param ijoueur L'index du joueur qui a perdu la partie.
  * @param nbjoueur Le nombre de joueurs dans la partie.
  */

void perdu(Partie &partie, unsigned int ijoueur, unsigned int nbjoueur){
	tourdejeu(ijoueur, partie, nbjoueur); //Affiche le numéro et type de joueur
	cout << " a perdu la partie" << endl; //output message pour indiquer le joueur perdant
}

/** Supprime la mémoire allouée dynamiquement pour un objet de jeu.
  *
  * @param partie L'objet de jeu dont la mémoire allouée dynamiquement sera supprimée.
  * @param tmp L'objet de jeu dont la mémoire allouée dynamiquement sera supprimée.
  */
void destru(Partie &partie, Tmp &tmp) {
	delete[] partie.joueur;
	delete[] partie.mot;
	delete[] tmp.mot;
}