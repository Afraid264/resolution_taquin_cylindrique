#ifndef _ETAT_
#define _ETAT_

#include "tab2d.h"

// Type �num�r� Mouvement
typedef enum Mouvement { NORD, OUEST, SUD, EST, FIXE };

// Struct position pour case vide
struct Position {
	unsigned int abs;
	unsigned int ord;
};

// struct Etat du damier courant
struct Etat {
	Tab2D tab;//damier r�sultant
	Mouvement move;//mouvement
	unsigned int index; //index liste LEE
	unsigned int g;//nombre de coups g de l'�tat initial � e
	unsigned int h;//heuristique h de e � l'�tat but
	Position empty;//Position de la case vide
};

// Affichage d'un �tat du taquin
void afficher(const Etat& e);
// Cr�ation des diff�rents �tats suivant les mouvements possible
Etat moves(const Etat& state, Mouvement move);
// Calcul f = g+ h d'un �tat
unsigned int f(const Etat& e);

#endif