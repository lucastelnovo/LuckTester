/*
 * auxiliares.h
 *
 *  Created on: 19/05/2013
 *      Author: lucastelnovo
 */

#ifndef AUXILIARES_H_
#define AUXILIARES_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define CANTIDAD_DE_CARTAS 40

typedef struct {
	int numero;
	int numeroAlAzar;
} t_core;

typedef struct {
	int numero;
	int vecesQueSalio;
} t_aux;

void inicializarPantalla();
void inicializarCore(t_core core[]);
void inicializarRandom(t_core core[]);
void informar(t_core core[]);

int yaSalio(int nroRandom, t_aux vect[], int tamanioDelVect);
int random_between(int min, int max);
void inicializarVectorAux(t_aux vect[], int tamanioDelVect);

#endif /* AUXILIARES_H_ */
