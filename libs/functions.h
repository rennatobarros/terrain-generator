#include "global.h"
#include "headers.h"
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
    imagem = fopen(strcat(file,".ppm"), "w");

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

void init_prog(int MAX, int deslocamento, char arq[], int p_dia)
{
    strcpy(file_name, arq);

    // Inicia a matriz de pixels
    pixel matriz[MAX][MAX];
    // Inicia a matriz de altitudes do terreno
    int montanha[MAX];
    int montanha2[MAX];
    int montanha3[MAX];
    
    // Inicia a matriz de pixels com cores diurnas ou noturnas
    if(p_dia == NOITE){
        for (i=0; i < MAX; i++)
		    for (j=0; j < MAX; j++)
			    matriz[i][j].r = 17, // Seta uma cor 'noturna' para todo o terreno
                matriz[i][j].g = 14,
                matriz[i][j].b = 25;
    }else{
        for (i=0; i < MAX; i++)
		    for (j=0; j < MAX; j++)
			    matriz[i][j].r = 214, // Seta uma cor 'diurna' para todo o terreno
                matriz[i][j].g = 238,
                matriz[i][j].b = 248;
    }


    // Chama a função que gera a linha de contorno
    gen_linhacontorno(MAX, deslocamento, 1, montanha, matriz);
    gen_linhacontorno(MAX, deslocamento, 2, montanha2, matriz);
    gen_linhacontorno(MAX, deslocamento, 3, montanha3, matriz);
    // Salva a imagem em um arquivo
    salvar_img(MAX, matriz, arq);
}