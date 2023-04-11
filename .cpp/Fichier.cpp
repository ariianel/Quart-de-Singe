#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Fichier.hpp"

using namespace std;

/**
  * Recherche le mot donné dans un fichier dictionnaire.
  *
  * @param mot Le mot à rechercher.
  * @return 0 si le mot est trouvé dans le dictionnaire, 1 s'il n'est pas trouvé, 2 si le fichier du dictionnaire n'a pas pu être ouvert.
  */
int recherche(char mot[]){
	std::ifstream in("ods4.txt"); // on ouvre le fichier
	if (!in) { //Si le fichier ne peux pas s'ouvrir
		std::cout << "le dictionnaire n'a pu etre ouvert" << endl; //Message d'erreur
		return 2; //retourne 2 pour indiquer l'erreur
	}

	const int MAX = 26; //La longueur maximum d'un mot dans le dictionnaire
	char motdic[MAX]; //Un buffer pour lire les mots du dico
	in >> setw(MAX) >> motdic; // on essaye de lire le premier mot
	while (in) {
		if (strcmp(motdic, mot) == 0){ //Si le mot match avec celui que l'on cherche
			return 0; //retourne 0 pour indiquer que le mot est trouvé
		}
		in >> setw(MAX) >> motdic; // on essaye de lire le mot suivant
	}
	in.close(); // on ferme le fichier
	return 1; //retourne 1 pour indiquer que le mot n'a pas été trouvé
}

/**
  * Trouve un mot dans un dictionnaire qui commence par un mot donné.
  *
  * @param partie L'objet de jeu dont le mot sera utilisé comme préfixe.
  * @param t Le mot trouvé sera stocké dans cette chaîne.
  * @return 1 si un mot est trouvé, 2 si le fichier dictionnaire ne peut pas être ouvert, sinon 0.
  */

int robot(Partie &partie, char t[]){
	ifstream in("ods4.txt"); // on ouvre le fichier
	if (!in) {
		cout << "le dictionnaire n'a pu etre ouvert" << endl;
		return 2;
	}
	const int MAX = 26;
	char motdic[MAX];
	bool a = false;
	in >> setw(MAX) >> motdic; // on essaye de lire le premier mot
	while (in) {
		if (strlen(motdic) > strlen(partie.mot)){
			if(verifmot(partie, motdic)){
				strcpy(t, motdic);
				a = true;
				break;
			}
		}
		in >> setw(MAX) >> motdic; // on essaye de lire le mot suivant
	}
	if(a==false){
		strcpy(t, "!");
	}
	in.close(); // on ferme le fichier
	return 1;
}