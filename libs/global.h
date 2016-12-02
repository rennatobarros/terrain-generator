#ifndef __GLOBAL_H
#define __GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/** Define o cabeçalho do arquivo. */
#define header "P3"

/** Armazena a imagem lida. */
FILE *foto;

/** Largura e altura, respectivamente, da imagem em pixels. */
int height, width;

/** Iteradores padrão */
int i, j;

/** Valor máximo que um pixel pode atingir*/
int v_max = 255;

/** 
 * Struct que armazena as cores (em RGB) de cada pixel
 */
typedef struct {
    int r, g, b;
} pixel;

#endif