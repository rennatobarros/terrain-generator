/** 
 * \file global.h
 * \brief Arquivo com variáveis globais
 *
 * Arquivo com cabeçalhos e estruturas necessárias em todo o programa.
 *
 */

#ifndef __GLOBAL_H
#define __GLOBAL_H

/** Define o cabeçalho do arquivo. */
#define header "P3"

/** Armazena a imagem lida. */
FILE *imagem;

/** Valor dos limites da linha de contorno. */
int deslocamento;

/** Nome do arquivo a ser salvo. */
char file_name[50];

/** Define o tamanho máximo que a imagem pode ter. */
int MAX;

/** Iteradores padrão */
int i, j;

/** Valor máximo que um pixel pode atingir. */
int v_max;

/** 
 * Struct que armazena as cores (em RGB) de cada pixel
 */
typedef struct {
    int r, g, b;
} pixel;

/** 
 * Enum que armazena os possveis periodos a ser gerado no terreno
 */
typedef enum {
    NOITE,
    MANHA
} periodo;

#endif