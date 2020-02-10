#include "Liste.h"

/**
* @brief Initialiser une liste vide
* la liste est allouée en mémoire dynamique
* @see detruire, elle est à désallouer en fin d’utilisation
* @param[out] l : la liste à initialiser (vide)
*/
void initialiser(Liste& l) {
	initialiser(l.ch);
	l.nb = 0;
	l.index = 0;
}

/**
* @brief Désallouer une liste
* @see initialiser, la liste a déjà été allouée en mémoire dynamique
* @param[out] l : la liste
*/
void detruire(Liste& l) {
	detruire(l.ch);
}

/**
* @brief Longueur de liste
* @param[in] l : la liste
* @return la longueur
*/
unsigned int longueur(const Liste& l) {
	return l.nb;
}

/**
* @brief Déplacer la position courante à une position donnée dans la liste
* @param[in,out] l : la liste
* @param[in] i : la position de déplacement
* @pre 0<=i<=longueur(l)
* La fonction ci-dessous n'est pas présente dans le fichier d'entête.
* C'est une fonction utilitaire qui n'a pas vocation à être employée par les
* utilisateurs du type Liste. C'est pourquoi elle est déclarée 'static'.
*/
static void deplacer(Liste& l, unsigned int i) {
	// Codez la fonction ......................................................
	assert(i <= longueur(l));
	if (l.index > i) {
		debut(l.ch);
		l.index = 0;
	}
	while (l.index != i) {
		suivant(l.ch);
		l.index++;
	}
}

/**
* @brief Lire un élément de liste
* @param[in] l : la liste
* @return l'item lu
* @pre 0<=i<longueur(l)
*/
Etat lire(Liste& l, unsigned int i) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	return (lire(l.ch));
}

/**
* @brief Ecrire un item dans la liste
* @param[in,out] l : la liste
* @param[in] i : position de l'élément à écrire
* @param[in] it : l'item
* @pre 0<=i<longueur(l)
*/
void ecrire(Liste& l, unsigned int i, const Etat& it) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	ecrire(l.ch, it);
}

/**
* @brief Insérer un élément dans une liste
* @param[in,out] l : la liste
* @param[in] i : la position avant laquelle l'élément est inséré
* @param[in] it : l'élément inséré
* @pre 0<=i<=longueur(l)
*/
void inserer(Liste& l, unsigned int i, const Etat& it) {
	assert((i >= 0) && (i <= longueur(l)));
	deplacer(l, i);
	inserer(l.ch, it);
	l.nb++;
}

/**
* @brief Supprimer un élément dans une liste
* @param[in,out] l : la liste
* @param[in] i : la position de l'élément à supprimer
* @pre 0<=i<longueur(l)
*/
void supprimer(Liste& l, unsigned int i) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	supprimer(l.ch);
	l.nb--;
}
