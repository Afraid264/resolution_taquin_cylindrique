#include "Taquin.h"

int main() {
	Taquin t;
	initialiser(t);
	if (jouer(t)) {
		afficherSolution(t);
	}
	detruire(t);
}