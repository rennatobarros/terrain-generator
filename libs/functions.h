#include "headers.h"
#include "global.h"
#include "manip_matriz.h"

int num_rand (int max) 
{
    return rand()%max;
}

void salvar_img(int MAX, pixel matriz[MAX][MAX], char file[])
{
    // Define que cada pixel só poderá ir até 255
    v_max = 255;

    // Concatena o nome do arquivo com a extensão ppm
    foto = fopen(strcat(file,".ppm"), "w");

    // Define o cabeçalho da imagem 
    fprintf (foto, "%s\n", header);
    // Define os valor de altura e largura da imagem
    fprintf (foto, "%d %d\n", MAX, MAX);
    // Define o valor máximo que cada pixel pode alcançar
    fprintf (foto, "%d\n", v_max);

    for (i=0; i < MAX; i++)
        for (j=0; j < MAX; j++)
            fprintf(foto, "%d %d %d\n", 
            //Operação ternária que verifica se o valor do pixel não ultrapassou os valores máximo e mínimo.
            (matriz[i][j].r > v_max) ? v_max : (matriz[i][j].r < 0) ? 0 : matriz[i][j].r,
            (matriz[i][j].g > v_max) ? v_max : (matriz[i][j].g < 0) ? 0 : matriz[i][j].g,
            (matriz[i][j].b > v_max) ? v_max : (matriz[i][j].b < 0) ? 0 : matriz[i][j].b);
    fclose(foto);
}

void init_prog(int MAX, int size, char arq[])
{
    strcpy(file_name, arq);

    // Inicia a matriz de pixels
    pixel matriz[MAX][MAX];
    // Inicia a matriz de altitudes do terreno
    int altitudes[MAX];
    
    // Chama a função que gera a linha de contorno
    gen_linhacontorno(MAX, size, altitudes);
    // Chama a função que gera o terreno de acordo com as altitudes
    gen_terrain(matriz, altitudes);
    // Salva a imagem em um arquivo
    salvar_img(MAX, matriz, arq);
}