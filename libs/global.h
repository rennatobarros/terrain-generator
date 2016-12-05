#ifndef __GLOBAL_H
#define __GLOBAL_H

/** Define o cabeçalho do arquivo. */
#define header "P3"

/** Armazena a imagem lida. */
FILE *foto;

/** Valor dos limites da linha de contorno. */
int size;

/** Nome do arquivo a ser salvo. */
char file_name[50];

/** Define o tamanho máximo que a imagem pode ter. */
int MAX;

/** Iteradores padrão */
int i, j;

/** Valor máximo que um pixel pode atingir*/
int v_max;

/** 
 * Struct que armazena as cores (em RGB) de cada pixel
 */
typedef struct {
    int r, g, b;
} pixel;

#endif