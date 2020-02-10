#ifndef _TAQUIN_
#define _TAQUIN_

#include "Liste.h"
//#include "Pile.h"

struct Taquin {
	Liste LEE; // Liste Etats Explorés
	Liste LEAE;// Liste des Etats A Explorer
	Liste FinalState;// Liste des différents états finaux possible
					 //Pile Solution;
	unsigned int nbRow; // Nombre de lignes du Taquin
	unsigned int nbCol; // Nombre de colonnes du Taquin
};

// Créer le jeu de taquin avec l’état initial
void initialiser(Taquin& t);
// Destruction du jeu de taquin
void detruire(Taquin& t);
// Itération de l’algorithme de recherche
bool jouer(Taquin& t);
// Afficher le contenu des listes adev et dev
void afficher(Taquin& t);
// renvoie vrai si l‘état existe déjà dans le taquin
bool appartient(const Etat& ef, Taquin& t);
// renvoie vrai s’il s’agir de l’état final, faux sinon
bool but(const Etat& ef, Taquin& t);
// création des états finaux du taquin
void init_FinalState(Taquin& t);
// Calcul heuristique
unsigned int heuristique(Etat& e, Taquin& t);
// Calcul de l'index dans LEAE de l'état avec le gmin
unsigned int gmin(Taquin&t);
// Calcul de l'index dans LEAE de l'état avec lef-gmin
unsigned int fmin(Taquin&t);
// Calcul de l'index dans LEAE de l'état avec lehgmin
unsigned int hmin(Taquin&t);
//affiche la solution 
void afficherSolution(Taquin& t); 

#endif