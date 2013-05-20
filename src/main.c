/*
 * main.c
 *
 *  Created on: 19/05/2013
 *      Author: lucastelnovo
 */

#include "auxiliares.h"

int main(int argc, char **argv) {

	t_core core[CANTIDAD_DE_CARTAS]; // Va hardcodeado, se hace para la cartas del truco
	srand(getpid()); // Aca esta la magia del nroRandom

	inicializarPantalla();

	inicializarCore(core);

	inicializarRandom(core);

	informar(core);

	return 0;
}
