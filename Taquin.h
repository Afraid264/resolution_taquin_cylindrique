#ifndef _TAQUIN_
#define _TAQUIN_

#include "Liste.h"
//#include "Pile.h"

struct Taquin {
	Liste LEE; // Liste Etats Explor�s
	Liste LEAE;// Liste des Etats A Explorer
	Liste FinalState;// Liste des diff�rents �tats finaux possible
					 //Pile Solution;
	unsigned int nbRow; // Nombre de lignes du Taquin
	unsigned int nbCol; // Nombre de colonnes du Taquin
};

// Cr�er le jeu de taquin avec l��tat initial
void initialiser(Taquin& t);
// Destruction du jeu de taquin
void detruire(Taquin& t);
// It�ration de l�algorithme de recherche
bool jouer(Taquin& t);
// Afficher le contenu des listes adev et dev
void afficher(Taquin& t);
// renvoie vrai si l��tat existe d�j� dans le taquin
bool appartient(const Etat& ef, Taquin& t);
// renvoie vrai s�il s�agir de l��tat final, faux sinon
bool but(const Etat& ef, Taquin& t);
// cr�ation des �tats finaux du taquin
void init_FinalState(Taquin& t);
// Calcul heuristique
unsigned int heuristique(Etat& e, Taquin& t);
// Calcul de l'index dans LEAE de l'�tat avec le gmin
unsigned int gmin(Taquin&t);
// Calcul de l'index dans LEAE de l'�tat avec lef-gmin
unsigned int fmin(Taquin&t);
// Calcul de l'index dans LEAE de l'�tat avec lehgmin
unsigned int hmin(Taquin&t);
//affiche la solution 
void afficherSolution(Taquin& t); 

#endif