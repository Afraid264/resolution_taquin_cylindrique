#include "Taquin.h"

// Créer le jeu de taquin avec l’état initial
/**@brief Initialisation de la partie de taquin
*@param[out] t : le taquin initialisé
*/
void initialiser(Taquin& t) {
	Tab2D m;
	initialiser(t.LEAE);
	initialiser(t.LEE);
	Etat initState;
	Etat FinalState;
	unsigned int nbRow, nbCol;
	cin >> nbRow >> nbCol;
	t.nbCol = nbCol;
	t.nbRow = nbRow;
	initialiser(m, nbRow, nbCol);
	lire(m);
	initState.tab = m;
	initState.move = FIXE;
	(initState.index) = 0;
	initState.g = 0;
	for (int x = 0; x < m.nbCol; x++) {
		for (int y = 0; y < m.nbRow; y++) {
			if (m.tab[x][y] == 0) {
				initState.empty.abs = x;
				initState.empty.ord = y;
				break;
			}
		}
	}
	init_FinalState(t);
	initState.h = heuristique(initState, t);
	inserer(t.LEAE, 0, initState);
}

/**@brief Destruction du jeu de taquin
*@param[in] t : le jeu de taquin
*/
void detruire(Taquin& t) {
	unsigned int lenLEAE, lenLEE, lenFS;
	Etat e;
	lenLEAE = longueur(t.LEAE);
	lenLEE = longueur(t.LEE);
	lenFS = longueur(t.FinalState);
	for (int a = 0; a < lenLEAE; a++) {
		e = lire(t.LEAE, a);
		detruire(e.tab);
	}
	for (int a = 0; a < lenLEE; a++) {
		e = lire(t.LEE, a);
		detruire(e.tab);
	}
	for (int a = 0; a < lenFS; a++) {
		e = lire(t.FinalState, a);
		detruire(e.tab);
	}
	detruire(t.LEE);
	detruire(t.LEAE);
	detruire(t.FinalState);
}

// Itération de l’algorithme de recherche
/**@brief Algorithme de recherche de solution
*@param[in,out] t : le taquin
*@return vrai si solution trouvée
*/
bool jouer(Taquin& t) {
	Tab2D m;
	Etat e;
	Etat s;
	unsigned int index = 0;
	int i = 0;
	e.g = 0;
	while ((longueur(t.LEAE) != 0) && (i < 100)) {
		/*cout << "Iteration " << i << endl;
		afficher(t);
		cout << "Fin iteration " << i << endl;
		cout << endl;
		cout << endl;*/
		for (int k = 0; k < longueur(t.LEAE); k++) {
			if (f(lire(t.LEAE, k)) == f(lire(t.LEAE, fmin(t)))) {
				index = fmin(t);
				break;
			}
			else {
				if (hmin(t) < lire(t.LEAE, k).h) {
					index = hmin(t);
				}
				else {
					index = gmin(t);
				}
			}
		}
		s = lire(t.LEAE, index);
		if (but(s, t)) {
			inserer(t.LEE, longueur(t.LEE), s);
			supprimer(t.LEAE, index);
			return true;
		}
		else {
			inserer(t.LEE, longueur(t.LEE), s);
			supprimer(t.LEAE, index);
			for (int j = 0; j < 4; j++) {
				switch (j) {
				case 0://NORD
					if (s.empty.ord != 0) {
						e = moves(s, NORD);
						e.h = heuristique(e, t);
						e.index = longueur(t.LEE) - 1;
						if (!appartient(e, t)) {
							inserer(t.LEAE, 0, e);
						}
						else {
							detruire(e.tab);
						}

					}
					break;
				case 1://OUEST
					e = moves(s, OUEST);
					e.h = heuristique(e, t);
					e.index = longueur(t.LEE) - 1;
					if (!appartient(e, t)) {
						inserer(t.LEAE, 0, e);
					}
					else {
						detruire(e.tab);
					}

					break;
				case 2://SUD
					if (s.empty.ord != t.nbRow - 1) {
						e = moves(s, SUD);
						e.h = heuristique(e, t);
						e.index = longueur(t.LEE) - 1;
						if (!appartient(e, t)) {
							inserer(t.LEAE, 0, e);
						}
						else {
							detruire(e.tab);
						}
					}
					break;
				case 3://EST
					e = moves(s, EST);
					e.h = heuristique(e, t);
					e.index = longueur(t.LEE) - 1;
					if (!appartient(e, t)) {
						inserer(t.LEAE, 0, e);
					}
					else {
						detruire(e.tab);
					}
					break;
				}
			}
		}
		i++;
	}
	return false;
}

// Afficher le contenu des listes adev et dev
/**@brief Affichage de LEE et LEAE
@param[in] t : le taquin
*/
void afficher(Taquin& t) {
	Etat e;
	unsigned int lenLEE, lenLEAE;
	lenLEE = longueur(t.LEE);
	lenLEAE = longueur(t.LEAE);
	cout << "*** LEE - long : " << lenLEE << endl;
	for (int i = 0; i < lenLEE; i++) {
		e = lire(t.LEE, i);
		afficher(e);
	}
	cout << endl;
	cout << "*** LEAE - long : " << lenLEAE << endl;
	for (int i = 0; i < lenLEAE; i++) {
		e = lire(t.LEAE, i);
		afficher(e);
	}
}

/**@brief Savoir si l'état étudié est déjà présent dans une liste
*@param[in] ef : l'état considéré
*@param[in] t : Accès au contenu des listes du taquin
*@return vrai si ef est présent dans une des listes de t
*/
bool appartient(const Etat& ef, Taquin& t) {
	Etat e;
	for (int i = 0; i < longueur(t.LEE); i++) {
		e = lire(t.LEE, i);
		if (same(ef.tab, e.tab)) {
			return true;
		}
	}
	for (int i = 0; i < longueur(t.LEAE); i++) {
		e = lire(t.LEAE, i);
		if (same(ef.tab, e.tab)) {
			return true;
		}
	}
	return false;
}

/**@brief Savoir si l'état est un des états finaux
*@param[in] e : l'état considéré
*@return vrai si e est un état final
*/
bool but(const Etat& ef, Taquin& t) {
	Etat e;
	for (int i = 0; i < longueur(t.FinalState); i++) {
		e = lire(t.FinalState, i);
		if (same(ef.tab, e.tab)) {
			return true;
		}
	}
	return false;
}

/**@brief Création des états finaux du taquin
*@param[out] FinalState : liste des états finaux du taquin
*/
void init_FinalState(Taquin& t) {
	Tab2D m;
	Etat FinalState;
	initialiser(m, t.nbRow, t.nbCol);
	initialiser(t.FinalState);
	for (int i = 0; i < t.nbCol; i++) {
		m = goal(t.nbRow, t.nbCol, i);
		FinalState.tab = m;
		FinalState.move = FIXE;
		FinalState.index = 0;
		FinalState.g = 0;
		FinalState.h = 0;
		for (int x = 0; x < m.nbCol; x++) {
			for (int y = 0; y < m.nbRow; y++) {
				if (m.tab[x][y] == 0) {
					FinalState.empty.abs = x;
					FinalState.empty.ord = y;
					break;
				}
			}
		}
		inserer(t.FinalState, i, FinalState);
	}
	//affichage des différentes solutions possible
	/*cout << "Nombre de solutions possible : " << longueur(t.FinalState) << endl;
	for (int i = 0; i < longueur(t.FinalState); i++) {
	cout << "Solution numero " << i << " :" << endl;
	FinalState = lire(t.FinalState, i);
	afficher(FinalState);
	}
	*/
}


/**@brief Calcul de l'heuristique
*@param[in] Etat : heuristique à déterminer sur cet état
*@return l'heuristique de l'état
*/
unsigned int heuristique(Etat& e, Taquin& t) {
	unsigned int hmin = (t.nbCol * t.nbRow) - 1;
	unsigned int h;
	Etat s;
	for (int i = 0; i < longueur(t.FinalState); i++) {
		s = lire(t.FinalState, i);
		h = 0;
		for (int x = 0; x < t.nbCol; x++) {
			for (int y = 0; y < t.nbRow; y++) {
				if (e.tab.tab[x][y] != s.tab.tab[x][y] && e.tab.tab[x][y] != 0) {
					h++;
				}
			}
		}
		if (h < hmin) {
			hmin = h;
		}
	}
	e.h = hmin;
	return hmin;
}


/**@brief renvoie l'index de l'état avec le plus petit g
*@param[in] t : le taquin
*@return index dans LEAE de l'état avec le plus petit g
*/
unsigned int gmin(Taquin&t) {
	unsigned int index = 0;
	unsigned int gmin = lire(t.LEAE, 0).g;
	for (int i = 0; i < longueur(t.LEAE); i++) {
		if (lire(t.LEAE, i).g < gmin) {
			gmin = lire(t.LEAE, i).g;
			index = i;
		}
	}
	return index;
}

/**@brief renvoie l'index de l'état avec le plus petit f
*@param[in] t : le taquin
*@return index dans LEAE de l'état avec le plus petit f
*/
unsigned int fmin(Taquin&t) {
	unsigned int index = 0;
	unsigned int fmin = lire(t.LEAE, 0).g + lire(t.LEAE, 0).h;
	for (int i = 0; i < longueur(t.LEAE); i++) {
		if (lire(t.LEAE, i).g + lire(t.LEAE, i).h < fmin) {
			fmin = lire(t.LEAE, i).g + lire(t.LEAE, i).h;
			index = i;
		}
	}
	return index;
}

/**@brief renvoie l'index de l'état avec le plus petit h
*@param[in] t : le taquin
*@return index dans LEAE de l'état avec le plus petit h
*/
unsigned int hmin(Taquin&t) {
	unsigned int index = 0;
	unsigned int hmin = lire(t.LEAE, 0).h;
	for (int i = 0; i < longueur(t.LEAE); i++) {
		if (lire(t.LEAE, i).h < hmin) {
			hmin = lire(t.LEAE, i).h;
			index = i;
		}
	}
	return index;
}

/**@brief Affiche la solution du taquin
*@param[in] t : le taquin
*/
void afficherSolution(Taquin& t) {
	Etat e;
	/*for (int i = longueur(t.LEE) - 1; i >= 0; i--) {
	afficher(lire(t.LEE, i));
	}*/
	e = lire(t.LEE.ch);
	//cout << "Solutions en " << lire(t.LEE.ch).g << " mouvements" << endl;
	//cout << lire(t.LEE.ch).g << endl;
	for (int i = longueur(t.LEE) - 2; i >= 0; i--) {
		if (i != e.index) {
			inserer(t.LEAE, 0, lire(t.LEE, i));
			supprimer(t.LEE, i);
		}
		else {
			e = lire(t.LEE, i);
		}
	}
	for (int i = 0; i < longueur(t.LEE); i++) {
		e = lire(t.LEE, i);
		afficher(e);
	}
}