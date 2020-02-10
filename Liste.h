#ifndef LISTE_H_
#define LISTE_H_


#include "Chaine.h"
/**
* Liste gérée dans une chaîne d'items
*/
struct Liste {
	Chaine ch;	// Stockage des éléments de liste dans une chaîne d'items
	unsigned int nb;    // nombre d'éléments dans la liste
	unsigned int index;	// index de la position courante dans la chaîne    
};

/**
* @brief Initialiser une liste vide
* la liste est allouée en mémoire dynamique
* @see detruire, elle est à désallouer en fin d’utilisation
* @param[out] l : la liste à initialiser (vide)
*/
void initialiser(Liste& l);

/**
* @brief Désallouer une liste
* @see initialiser, la liste a déjà été allouée en mémoire dynamique
* @param[out] l : la liste
*/
void detruire(Liste& l);

/**
* @brief Longueur de liste
* @param[in] l : la liste
* @return la longueur
*/
unsigned int longueur(const Liste& l);

/**
* @brief Lire un élément de liste
* @param[in] l : la liste
* @return l'item lu
* @pre 0<=i<=longueur(l)
*/
Etat lire(Liste& l, unsigned int i);

/**
* @brief Ecrire un item dans la liste
* @param[in,out] l : la liste
* @param[in] i : position de l'élément à écrire
* @param[in] it : l'item
* @pre 0<=i<=longueur(l)
*/
void ecrire(Liste& l, unsigned int i, const Etat& it);

/**
* @brief Insérer un élément dans une liste
* @param[in,out] l : la liste
* @param[in] i : la position avant laquelle l'élément est inséré
* @param[in] it : l'élément inséré
* @pre 0<=i<=longueur(l)+1
*/
void inserer(Liste& l, unsigned int i, const Etat& it);

/**
* @brief Supprimer un élément dans une liste
* @param[in,out] l : la liste
* @param[in] i : la position de l'élément à supprimer
* @pre 0<=i<=longueur(l)
*/
void supprimer(Liste& l, unsigned int i);

#endif /*LISTE_H_*/
