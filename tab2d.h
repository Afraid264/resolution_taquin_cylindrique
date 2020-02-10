#ifndef _TAB2D_
#define _TAB2D_

#include "Item.h"
#include <iomanip>
#include <cassert>
#include <iostream>
using namespace std;

struct Tab2D {
	Item** tab;//superpointeur vers les tableaux
	unsigned int nbRow;// nombre de lignes du tableau
	unsigned int nbCol;// nombre de colonnes (et de tableaux)
};

// Allouer en mémoire dynamique un Tableau2D
void initialiser(Tab2D& m, unsigned int nbRow, unsigned int nbCol);

// Desallouer un Tableau2D
void detruire(Tab2D& m);

// Lire un Tableau2D
void lire(Tab2D& m);

// Afficher un Tableau2D
void afficher(const Tab2D& m);

//Création des états finaux 
Tab2D goal(unsigned int nbRow, unsigned int nbCol, unsigned int Col);

//renvoie vrai si les deux tableaux sont identiques
bool same(const Tab2D& m, const Tab2D& n);

#endif