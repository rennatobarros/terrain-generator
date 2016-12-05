#ifndef __HEADERS_H
#define __HEADERS_H

#include "global.h"

int 	num_rand 			(int);
void 	init_prog			(int MAX, int size, char arq[]);
void 	gen_linhacontorno	(int size, int limit, int altitudes[MAX]);
void 	salvar_img			(int MAX, pixel matriz[MAX][MAX], char file[]);
void 	gen_terrain			(pixel matriz[MAX][MAX], int altitudes[MAX]);


#endif