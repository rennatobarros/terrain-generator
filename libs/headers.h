/** 
 * \file headers.h
 * \brief Arquivo com os cabeçalhos das funções
 *
 * Arquivo com os cabeçalhos de cada função afim de evitar erros de declaração implicita
 *
 */

#ifndef __HEADERS_H
#define __HEADERS_H

// functions.h
int 	num_rand 			(int);
void 	init_prog			(int MAX, int deslocamento, char arq[], int p_dia);
void 	salvar_img			(int MAX, pixel matriz[MAX][MAX], char file[]);

// manip_matriz.h
void    init_matriz         (int MAX, pixel matriz[MAX][MAX], int p_dia);
void    midPoint            (int MAX, int montanha[MAX], pixel matriz[MAX][MAX], int tipo, int p_dia, int deslocamento, int inicial, int final);
void 	gen_linhacontorno	(int MAX, int deslocamento, int tipo, int p_dia, int montanha[MAX], pixel matriz[MAX][MAX]);

#endif