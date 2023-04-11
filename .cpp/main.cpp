#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <random> //generer mot
#include <limits.h>
#include "Fichier.hpp"
#include "Affichage.hpp"
#include "Partie.hpp"

using namespace std;

int main(int argc, const char* argv[]) {
	unsigned int nbjoueur = strlen(argv[1]);
	//cout << te << endl;
	if (nbjoueur >= 2) {
		Partie partie;
		initialisation(argv, partie, nbjoueur);
		//unsigned int tailleinit=2;
		strcpy(partie.mot, "");

		Tmp tmp;
		unsigned int ijoueur=0;
		char c[2];
		while (1){
			afficheTous(ijoueur%nbjoueur, partie, nbjoueur);

			tmp.mot = new char[strlen(partie.mot)+2];
			strcpy(tmp.mot, partie.mot);

			//si humain insérer input
			if(afficherNature(partie.joueur[ijoueur%nbjoueur].natureJoueur) == 'H') {
				cin >> setw(2) >> c;
				cin.ignore(INT_MAX, '\n');
			}
			//Sinon générer une lettre aléatoirement
			else {
				char a[2];
				//GENERER UN MOT
				generateurLettre(a);
				cout << a[0] << endl;
				c[0] = a[0];
			}
			conv(c);

			strcat(tmp.mot, c);
			if(strcmp(c,"?")==0){
				char idee[tailleMax+1];
				//Demande mot 
				tourdejeu(ijoueur-1, partie, nbjoueur);
				cout << ", saisir le mot > ";
				
				if(afficherNature(partie.joueur[(ijoueur-1)%nbjoueur].natureJoueur) == 'H') {
					cin >> setw(tailleMax+1) >> idee;
					cin.ignore(INT_MAX, '\n');
				}
				//Sinon générer une lettre aléatoirement
				else {
					robot(partie,idee);
					affichermot(idee);
					cout << endl;
				}
// et modif dans robot avec bool true et false
				if(strcmp(idee,"!")==0) {
					cout << "le joueur ";
					tourdejeu(ijoueur-1, partie, nbjoueur);
					cout << " abandonne la manche et prend un quart de singe" << endl;
					//Le joueur se prend un quart de singe
					partie.joueur[(ijoueur-1)%nbjoueur].scoreJoueur += 0.25;
					//fin de la manche donc on rénitialise le mot
					afficheScore(partie, ijoueur, nbjoueur);
					//cout << endl;

					if(partie.joueur[(ijoueur-1)%nbjoueur].scoreJoueur == 1.){
						//il faut detruire (mémoire) après le boucle while() juste avant return 0
						break;
					}
					else{
						partie.mot = new char[2];
						strcpy(partie.mot, "");
					}
				}else{
//avec le else et son acolade jusque en bas
					conv(idee);
					if(verifmot(partie, idee)){
						//cout << "mot identique" << endl;
						if(recherche(idee)==0){
							cout << "le mot ";
							affichermot(idee);
							cout << " existe, le joueur ";
							tourdejeu(ijoueur, partie, nbjoueur);
							cout << " prend un quart de singe" << endl;
							partie.joueur[ijoueur%nbjoueur].scoreJoueur += 0.25;
							afficheScore(partie, ijoueur, nbjoueur);

							if(partie.joueur[ijoueur%nbjoueur].scoreJoueur == 1.){
								//il faut detruire (mémoire) après le boucle while() juste avant return 0
								break;
							}else{
								partie.mot = new char[2];
								strcpy(partie.mot, "");
							}

						}else{
							cout << "le mot ";
							affichermot(idee);
							cout << " n'existe pas, le joueur ";
							tourdejeu(ijoueur-1, partie, nbjoueur);
							cout << " prend un quart de singe" << endl;
							partie.joueur[(ijoueur-1)%nbjoueur].scoreJoueur += 0.25;
							//affiche score
							afficheScore(partie, ijoueur, nbjoueur);

							if(partie.joueur[(ijoueur-1)%nbjoueur].scoreJoueur == 1.){
								//il faut detruire (mémoire) après le boucle while() juste avant return 0
								break;
							}else{
								partie.mot = new char[2];
								strcpy(partie.mot, "");
							}
							ijoueur -=1;
						}
					}else{
						cout << "le mot ";
						affichermot(idee);
						cout << " ne commence pas par les lettres attendues, le joueur ";
						tourdejeu(ijoueur-1, partie, nbjoueur);
						cout << " prend un quart de singe" << endl;
						partie.joueur[(ijoueur-1)%nbjoueur].scoreJoueur += 0.25;
						//Affiche score
						afficheScore(partie, ijoueur, nbjoueur);

						if(partie.joueur[(ijoueur-1)%nbjoueur].scoreJoueur == 1.){
							//perdu(partie, ijoueur-1, nbjoueur);
							//il faut detruire (mémoire) après le boucle while() juste avant return 0
							break;
						}else{
							partie.mot = new char[2];
							strcpy(partie.mot, "");
						}
						ijoueur -=1;
					}
				}
				strcpy(idee, "");
			}
			else if(strcmp(c,"!")==0) {
				cout << "le joueur ";
				tourdejeu(ijoueur, partie, nbjoueur);
				cout << " abandonne la manche et prend un quart de singe" << endl;
				//Le joueur se prend un quart de singe
				partie.joueur[ijoueur%nbjoueur].scoreJoueur += 0.25;
				//fin de la manche donc on rénitialise le mot
				afficheScore(partie, ijoueur, nbjoueur);
				//cout << endl;

				if(partie.joueur[ijoueur%nbjoueur].scoreJoueur == 1.){
					//il faut detruire (mémoire) après le boucle while() juste avant return 0
					break;
				}
				else{
					partie.mot = new char[2];
					strcpy(partie.mot, "");
				}
			}
			else if (strlen(partie.mot) < 2 || (strlen(partie.mot) >= 2 && recherche(tmp.mot) == 1)){
				partie.mot = new char[strlen(partie.mot)+2];
				strcpy(partie.mot, tmp.mot);
				ijoueur += 1;
			}
			else{
				cout << "le mot ";
				affichermot(tmp.mot);
				cout << " existe, le joueur ";
				tourdejeu(ijoueur, partie, nbjoueur);
				cout << " prend un quart de singe" << endl;
				//ajout point
				partie.joueur[ijoueur%nbjoueur].scoreJoueur += 0.25;
				//Affiche score
				afficheScore(partie, ijoueur, nbjoueur);
				//cout << endl;

				if(partie.joueur[ijoueur%nbjoueur].scoreJoueur == 1.){
					//il faut detruire (mémoire) après le boucle while() juste avant return 0
					break;
				}
				else{
					partie.mot = new char[2];
					strcpy(partie.mot, "");
				}
			}
		}
		cout << "La partie est finie";
		destru(partie, tmp);
	}else{
		cout << "Les parametre son incorrects" << endl;
	}
	//détruire mémoire ici
	return 0;
}