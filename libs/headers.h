#ifndef __HEADERS_H
#define __HEADERS_H

#include "global.h"

int num_rand (int);
void gen_linhacontorno(int size, int fator_d, int altitudes[size]);
void salvar_img(pixel matriz[MAX][MAX]);
//void gen_terrain(pixel matriz[MAX][MAX], ponto vetorLinha[MAX]);

#endif