#include "Etat.h"

/**@brief Affichage d'un état du taquin
@param[in] e : l'état à afficher
*/
void afficher(const Etat& e) {
	if (e.move != FIXE) {
		switch (e.move) {
		case 0:
			cout << "NORD" << endl;
			break;
		case 1:
			cout << "OUEST" << endl;
			break;
		case 2:
			cout << "SUD" << endl;
			break;
		case 3:
			cout << "EST" << endl;
			break;
		}
	}
	//afficher(e.tab);
	
}

/**@brief Déplacements possible du taquin
*@param[in] state : état dont découle les mouvements
*@param[in] move : direction du mouvement
*@return l'état produit suivant le move donné
*/
Etat moves(const Etat& state, Mouvement move) {
	Tab2D m;
	Etat e;
	unsigned int swap;
	if (move == NORD) {
		initialiser(m, state.tab.nbRow, state.tab.nbCol);
		for (int x = 0; x < state.tab.nbCol; x++) {
			for (int y = 0; y < state.tab.nbRow; y++) {
				m.tab[x][y] = state.tab.tab[x][y];
			}
		}
		e.move = NORD;
		e.empty.ord = state.empty.ord - 1;
		e.empty.abs = state.empty.abs;
		swap = m.tab[e.empty.abs][e.empty.ord];
		m.tab[e.empty.abs][e.empty.ord] = 0;
		m.tab[e.empty.abs][e.empty.ord + 1] = swap;
		e.tab = m;
		e.g = state.g + 1;
		e.h = 0;
		return e;
	}
	if (move == OUEST) {
		initialiser(m, state.tab.nbRow, state.tab.nbCol);
		for (int x = 0; x < state.tab.nbCol; x++) {
			for (int y = 0; y < state.tab.nbRow; y++) {
				m.tab[x][y] = state.tab.tab[x][y];
			}
		}
		e.move = OUEST;
		e.empty.ord = state.empty.ord;
		if (state.empty.abs == 0) {
			e.empty.abs = state.tab.nbCol - 1;
		}
		else {
			e.empty.abs = state.empty.abs - 1;
		}
		swap = m.tab[e.empty.abs][e.empty.ord];
		m.tab[e.empty.abs][e.empty.ord] = 0;
		if (state.empty.abs == 0) {
			m.tab[0][e.empty.ord] = swap;
		}
		else {
			m.tab[e.empty.abs + 1][e.empty.ord] = swap;
		}
		e.tab = m;
		e.g = state.g + 1;
		e.h = 0;
		return e;
	}
	if (move == SUD) {
		initialiser(m, state.tab.nbRow, state.tab.nbCol);
		for (int x = 0; x < state.tab.nbCol; x++) {
			for (int y = 0; y < state.tab.nbRow; y++) {
				m.tab[x][y] = state.tab.tab[x][y];
			}
		}
		e.move = SUD;
		e.empty.ord = state.empty.ord + 1;
		e.empty.abs = state.empty.abs;
		swap = m.tab[e.empty.abs][e.empty.ord];
		m.tab[e.empty.abs][e.empty.ord] = 0;
		m.tab[e.empty.abs][e.empty.ord - 1] = swap;
		e.tab = m;
		e.g = state.g + 1;
		e.h = 0;
		return e;
	}
	if (move == EST) {
		initialiser(m, state.tab.nbRow, state.tab.nbCol);
		for (int x = 0; x < state.tab.nbCol; x++) {
			for (int y = 0; y < state.tab.nbRow; y++) {
				m.tab[x][y] = state.tab.tab[x][y];
			}
		}
		e.move = EST;
		e.empty.ord = state.empty.ord;
		if (state.empty.abs == state.tab.nbCol - 1) {
			e.empty.abs = 0;
		}
		else {
			e.empty.abs = state.empty.abs + 1;
		}
		swap = m.tab[e.empty.abs][e.empty.ord];
		m.tab[e.empty.abs][e.empty.ord] = 0;
		if (state.empty.abs == state.tab.nbCol - 1) {
			m.tab[state.tab.nbCol - 1][e.empty.ord] = swap;
		}
		else {
			m.tab[e.empty.abs - 1][e.empty.ord] = swap;
		}
		e.tab = m;
		e.g = state.g + 1;
		e.h = 0;
		return e;
	}
}


/**@brief Calcul f = g + h
*@param[in] e : l'état à calculer
*@return f = g + h
*/
unsigned int f(const Etat& e) {
	return e.g + e.h;
}