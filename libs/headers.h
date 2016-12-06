#ifndef __HEADERS_H
#define __HEADERS_H

#include "global.h"

int 	num_rand 			(int);
void 	init_prog			(int MAX, int deslocamento, char arq[], int p_dia);
void 	gen_linhacontorno	(int MAX, int deslocamento, int tipo, int montanha[MAX], pixel matriz[MAX][MAX]);
void    midPoint            (int MAX, int montanha[MAX], pixel matriz[MAX][MAX], int tipo, int deslocamento, int inicial, int final);
void 	salvar_img			(int MAX, pixel matriz[MAX][MAX], char file[]);


#endif