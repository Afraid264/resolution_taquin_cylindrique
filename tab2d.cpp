#include "tab2d.h"

/**@brief Allocation dynamique d'un tableau 2D
*@param[in] nbRow : nombre de lignes
*@param[in] nbCol : nombre de colonnes
*@param[out] Le tableau 2D
*@pre Lignes et Colonnes supérieur à 0
*/
void initialiser(Tab2D& m, unsigned int nbRow, unsigned int nbCol) {
	assert(nbRow > 0 && nbCol > 0);
	m.nbRow = nbRow;
	m.nbCol = nbCol;
	m.tab = new Item*[nbCol];
	for (int i = 0; i < nbCol; i++) {
		m.tab[i] = new Item[nbRow];
	}
}

/**@brief Desallocation du tableau 2D
*@see initialiser, le tableau a déjà été alloué en mémoire dynamique
*@param[out] m: le tableau
*/
void detruire(Tab2D& m) {
	for (int i = 0; i < m.nbCol; i++) {
		delete[] m.tab[i];
	}
	delete[] m.tab;
	m.tab = NULL;
}

/*
*@brief Lecture d'une matrice pour résolution
*@param[out] la matrice entrée
*/
void lire(Tab2D& m) {
	//cout << "Damier : " << m.nbRow << " Lignes, " << m.nbCol << " Colonnes" << endl;
	char test[10];
	for (int j = 0; j < m.nbRow; j++) {
		for (int i = 0; i < m.nbCol; i++) {
			cin >> test;
			if (test == "#") {
				m.tab[i][j] = 0;
			}
			else {
				m.tab[i][j] = atoi(test);
			}
		}
	}
}

/*
*@brief Affichage d'une matrice
*@param[in] la matrice à afficher
*/
void afficher(const Tab2D& m) {
	for (int j = 0; j < m.nbRow; j++) {
		for (int i = 0; i < m.nbCol; i++) {
			if (m.tab[i][j] == 0) {
				cout << setw(3) << "#";
			}
			else {
				cout << setw(3) << m.tab[i][j];
			}
		}
		cout << endl;
	}
}


/**@brief Création des états finaux
*@param[in] nbRow : Nombre de lignes
*@param[in] nbCol : Nombre de Colonnes
*@return un type Tab2D contenant un état final
*/
Tab2D goal(unsigned int nbRow, unsigned int nbCol, unsigned int Col) {
	Tab2D m;
	unsigned int nb;
	initialiser(m, nbRow, nbCol);
	if (Col == nbCol - 1) {
		for (int x = 0; x < nbRow; x++) {
			for (int y = 0; y < nbCol; y++) {
				m.tab[y][x] = (x * nbCol) + y + 1;
			}
		}
		m.tab[Col][nbRow - 1] = 0;
		return m;
	}
	if (Col == 0) {
		for (int y = 0; y < nbRow; y++) {
			for (int x = 1; x < nbCol; x++) {
				m.tab[x][y] = (y * nbCol) + x;
			}
		}
		for (int i = 1; i < nbRow; i++) {
			m.tab[0][i - 1] = i * nbCol;
		}
		m.tab[0][nbRow - 1] = 0;
		return m;
	}
	nb = nbCol - Col - 1;
	for (int y = 0; y < nbRow; y++) {
		for (int x = 0; x < nb; x++) {
			m.tab[Col + 1 + x][y] = (y * nbCol) + x + 1;
		}
	}
	for (int y = 0; y < nbRow; y++) {
		for (int x = 0; x <= Col; x++) {
			m.tab[x][y] = nb + (y * nbCol) + x + 1;
		}
	}
	m.tab[Col][nbRow - 1] = 0;
	return m;
}

/**@brief Test pour comparer deux tableaux
*@param[in] m : le premier tableau
*@param[in] n : le deuxieme tableau
*@return vrai si les deux tableaux sont identiques
*/
bool same(const Tab2D& m, const Tab2D& n) {
	for (int x = 0; x < m.nbCol; x++) {
		for (int y = 0; y < m.nbRow; y++) {
			if (m.tab[x][y] != n.tab[x][y]) {
				return false;
			}
		}
	}
	return true;
}