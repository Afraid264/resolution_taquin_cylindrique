#ifndef _ETAT_
#define _ETAT_

#include "tab2d.h"

// Type énuméré Mouvement
typedef enum Mouvement { NORD, OUEST, SUD, EST, FIXE };

// Struct position pour case vide
struct Position {
	unsigned int abs;
	unsigned int ord;
};

// struct Etat du damier courant
struct Etat {
	Tab2D tab;//damier résultant
	Mouvement move;//mouvement
	unsigned int index; //index liste LEE
	unsigned int g;//nombre de coups g de l'état initial à e
	unsigned int h;//heuristique h de e à l'état but
	Position empty;//Position de la case vide
};

// Affichage d'un état du taquin
void afficher(const Etat& e);
// Création des différents états suivant les mouvements possible
Etat moves(const Etat& state, Mouvement move);
// Calcul f = g+ h d'un état
unsigned int f(const Etat& e);

#endif