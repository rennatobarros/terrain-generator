/**
 *  \file functions.h
 *  \brief Arquivo com as funções essenciais do programa.
 *
 */

#include "global.h"         /** Variáveis globais. */
#include "headers.h"        /** Inicialização das funções. */
#include "manip_matriz.h"   /** Principais funções para gerar o terreno. */

/** 
 * Função que gera um número entre 0 e max
 *
 * \brief Função para gerar número aleatório
 * @param max Valor máximo que o número aleatório poderá atingir 
 * \return númeo aleatorio
*/
int num_rand (int max) 
{
    return rand()%max;
}

/** 
 * Função que salva a matriz de pixels em um arquivo .ppm
 *
 * \brief Função para salvar a matriz de pixels em um arquivo
 * @param MAX Valor máximo da linha e coluna da matriz
 * @param matriz Matriz a ser salva no arquivo
 * @param arq Nome que será dado ao arquivo 
 * \return Nada
*/

void salvar_img(int MAX, pixel matriz[MAX][MAX], char arq[])
{
    // Define que cada pixel só poderá ir até 255
    v_max = 255;

    // Concatena o nome do arquivo com a extensão ppm
    imagem = fopen(strcat(arq,".ppm"), "w");

    // Define o cabeçalho da imagem 
    fprintf (imagem, "%s\n", header);
    // Define os valor de altura e largura da imagem
    fprintf (imagem, "%d %d\n", MAX, MAX);
    // Define o valor máximo que cada pixel pode alcançar
    fprintf (imagem, "%d\n", v_max);

    for (i=0; i < MAX; i++)
        for (j=0; j < MAX; j++)
            fprintf(imagem, "%d %d %d\n", 
            //Operação ternária que verifica se o valor do pixel não ultrapassou os valores máximo e mínimo.
            (matriz[i][j].r > v_max) ? v_max : (matriz[i][j].r < 0) ? 0 : matriz[i][j].r,
            (matriz[i][j].g > v_max) ? v_max : (matriz[i][j].g < 0) ? 0 : matriz[i][j].g,
            (matriz[i][j].b > v_max) ? v_max : (matriz[i][j].b < 0) ? 0 : matriz[i][j].b);
    fclose(imagem);
}

/** 
 * Função para inicializar as matrizes e vetores do programa
 *
 * \brief Função que inicializa o programa
 * @param MAX Valor máximo da linha e coluna da matriz
 * @param deslocamento valor da variação da montanha
 * @param arq Nome que será dado ao arquivo 
 * @param p_dia Período do dia a imagem será gerada 
 * \return Nada
*/

void init_prog(int MAX, int deslocamento, char arq[], int p_dia)
{

    // Inicia a matriz de pixels
    pixel matriz[MAX][MAX];

    // Inicia as três montanhas que aparecerão no terreno
    int montanha[MAX];
    int montanha2[MAX];
    int montanha3[MAX];
    
    init_matriz(MAX, matriz, p_dia);


    // Chama a função que gera a linha de contorno
    gen_linhacontorno(MAX, deslocamento, 1, p_dia, montanha, matriz);
    gen_linhacontorno(MAX, deslocamento, 2, p_dia, montanha2, matriz);
    gen_linhacontorno(MAX, deslocamento, 3, p_dia, montanha3, matriz);
    
    // Salva a imagem em um arquivo
    salvar_img(MAX, matriz, arq);
}