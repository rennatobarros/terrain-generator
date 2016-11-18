#include <stdio.h>
#include <stlib.h>
#include <string.h>

/** Define o cabeçalho do arquivo. */
#define header "P3"

/** Armazena a imagem lida. */
FILE *foto;

/** Vetor que armazena o código da imagem .ppm. */
char code[3];

/** Largura e altura, respectivamente, da imagem em pixels. */
int linha, coluna;

/** Iteradores padrão */
int i, j;

/** 
 * Struct que armazena as cores (em RGB) de cada pixel
 */
typedef struct {
    int r, g, b;
} pixel;