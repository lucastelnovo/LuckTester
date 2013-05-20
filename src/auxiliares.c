/*
 * auxiliares.c
 *
 *  Created on: 19/05/2013
 *      Author: lucastelnovo
 */

#include "auxiliares.h"

void inicializarPantalla() {

	system("clear");
	puts("******------LUCK TESTER------******");
	puts("");
	puts("Presione la tecla ENTER para comenzar...");
	getchar();
	puts("Comenzando...");
}

void inicializarCore(t_core core[]) {

	int i;
	int j = 0;

	for (i = 0; i < CANTIDAD_DE_CARTAS; ++i) {

		j++;
		switch (j) {
		case 8:
			core[i].numero = j + 2;
			break;
		case 9:
			core[i].numero = j + 2;
			break;
		case 10:
			core[i].numero = j + 2; // CASO BASE: Le pone el valor "12" a numero por ende -> termina.
			j = 0;
			break;
		default:
			core[i].numero = j;
			break;
		}

	}
}

void inicializarVectorAux(t_aux vect[], int tamanioDelVect) {

	int i;
	for (i = 0; i < tamanioDelVect; ++i) {

		vect[i].vecesQueSalio = 0;

		if ((i + 1) == 8 || (i + 1) == 9)
			vect[i].numero = i + 3;
		else if ((i + 1) == 10) {
			vect[i].numero = i + 3;
			break;
		} else
			vect[i].numero = i + 1;

	}

}

int yaSalio(int nroRandom, t_aux vect[], int tamanioDelVect) {

	int i;

	for (i = 0; i < tamanioDelVect; ++i) {

		if (nroRandom == vect->numero) { // Si encuentra en numero en el vector
			if (vect->vecesQueSalio == 4) {
				return 1; // Ya salio 4 veces ese numero, no puede salir mas -> verdadero
			} else {
				vect->vecesQueSalio++;
				return 0; // No salio cuatro veces -> falso
			}
		}

		vect++;
	}

	return 0;

}

int random_between(int min, int max) {

	return rand() % (max - min + 1) + min;
}

void inicializarRandom(t_core core[]) {

	t_aux vect_aux[CANTIDAD_DE_CARTAS / 4];
	inicializarVectorAux(vect_aux, CANTIDAD_DE_CARTAS / 4);

	int nroRandom, k, j = 0;

	for (k = 0; k < CANTIDAD_DE_CARTAS; ++k) {

		while (1) { // Busco un nroRandom
			nroRandom = random_between(1, 12); // Me devuelve un nroRandom
			if ((nroRandom == 8 || nroRandom == 9)
					|| yaSalio(nroRandom, vect_aux, CANTIDAD_DE_CARTAS / 4)) {
			} // Si el nroRandom es 8 o 9 o ya salio, le pido otro nuevo nroRandom.
			else {
				break;
			}
		}

		core[k].numeroAlAzar = nroRandom;
		j++;
		if (j == 10) {
			j = 0;
		}
	}
}

void informar(t_core core[]) {

	int k;
	for (k = 0; k < CANTIDAD_DE_CARTAS; ++k) {

		printf("[%i]", core[k].numero);
		printf(" -> ");
		sleep(2);
		printf("[%i]\n", core[k].numeroAlAzar);

		if (core[k].numero == core[k].numeroAlAzar) {
			printf("¡PERDISTE!\n");
			int result = (k * 100 / CANTIDAD_DE_CARTAS);
			printf("TU PORCENTAJE DE SUERTE ES DE: %i", result);
			puts("%");
			exit(1);
		}

	}

	puts("¡GANASTE!");
	int result = (k * 100 / CANTIDAD_DE_CARTAS);
	printf("TU PORCENTAJE DE SUERTE ES DE: %i", result);
	puts("%");
	exit(1);

}
