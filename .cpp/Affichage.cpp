#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Affichage.hpp"

using namespace std;

/**
  * Imprime les informations du joueur pour un objet de jeu.
  *
  * @param partie L'objet de jeu dont les informations sur le joueur seront imprimées.
  * @param nbjoueur Le nombre de joueurs dans la partie.
  */
void afficher(Partie &partie, unsigned int nbjoueur){
	for (unsigned int i=0; i<nbjoueur; ++i){
		cout << partie.joueur[i].natureJoueur << ", " << partie.joueur[i].numJoueur << ", " << partie.joueur[i].scoreJoueur << endl;
	}
}

/**
  * Affiche le mot donné sur la sortie standard.
  *
  * @param mot Le mot à afficher.
  */
void affichermot(char mot[]){
	unsigned int taille = strlen(mot);
	for (unsigned int i=0; i<taille; ++i){
		cout << mot[i];
	}
}

/**
  * Renvoie la représentation du personnage du type de joueur donné.
  *
  * @param natureJoueur Le type de joueur à représenter en tant que personnage.
  * @return 'H' si le type de joueur est H (humain), 'R' si le type de joueur est R (robot).
  */
char afficherNature(natureJ natureJoueur){
	if(natureJoueur == 0)
		return 'H';
	else if (natureJoueur == 1)
		return 'R';
}

/**
  * Affiche le joueur dont c'est le tour, le mot en cours de lecture et une invite de saisie.
  *
  * @param ijoueur L'index du joueur dont c'est le tour.
  * @param partie L'objet de jeu contenant les joueurs et le mot courant.
  * @param nbjoueur Le nombre de joueurs dans la partie.
  */
void afficheTous(unsigned int ijoueur, Partie &partie, unsigned int nbjoueur){
	tourdejeu(ijoueur, partie, nbjoueur);//Affiche le type de joueur et son numéro
	cout << ", (";
	affichermot(partie.mot);//Affiche le mot actuel
	cout << ") > ";
}

/**
  * Affiche les scores de tous les joueurs du jeu.
  *
  * @param partie L'objet de jeu contenant les joueurs et leurs scores.
  * @param i L'index du lecteur actuel.
  * @param nbjoueur Le nombre de joueurs dans la partie.
  */
void afficheScore(Partie &partie, unsigned int i, unsigned int nbjoueur) {
	for (int i = 0; i < nbjoueur; i++) { //Pour tout les joueurs
		if (i == nbjoueur-1) { //Si c'est le dernier joueur
			cout << partie.joueur[i].numJoueur << afficherNature(partie.joueur[i%nbjoueur].natureJoueur)<< " : " << partie.joueur[i].scoreJoueur <<endl; 
			break;
		}
		cout << partie.joueur[i].numJoueur << afficherNature(partie.joueur[i%nbjoueur].natureJoueur)<< " : " << partie.joueur[i].scoreJoueur << "; ";
	}
	
}