#include "headers.h"
#include "global.h"

int num_rand (int max) 
{
    return rand() % max;
}

void gen_linhacontorno(pixel matriz[MAX][MAX], ponto inicial, ponto final, ponto vetorLinha[MAX], int range)
{
    if(inicial.coluna < final.coluna && range != 0){
        
        ponto medio;
        
        medio.linha     = (inicial.linha + final.coluna)/2;
        medio.coluna    = (inicial.coluna + final.coluna)/2;
        
        int num         = num_rand(range);
        medio.linha     += (num-range/2);
        
        vetorLinha[medio.linha].linha   = medio.linha;
        vetorLinha[medio.coluna].coluna = medio.coluna;
        
        if(medio.coluna != final.coluna && medio.coluna != inicial.coluna){
            gen_linhacontorno(matriz, inicial, medio, vetorLinha, range/2);
            gen_linhacontorno(matriz, medio, final, vetorLinha, range/2);
        }
    }
}

void gen_terrain(pixel matriz[MAX][MAX], ponto vetorLinha[MAX])
{
    int l = 0;

    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; i++){
            matriz[i][j] = vetorLinha[l];
            l++;
        }
    }
}

void salvar_img(pixel matriz[MAX][MAX])
{
    
    //char nome_arq_salvar[50];
    //scanf("%s", nome_arq_salvar);

    foto = fopen(nome_arq_salvar, "w");

    fprintf (foto, "%s\n", header);
    fprintf (foto, "%d %d\n", height, width);
    fprintf (foto, "%d\n", v_max);

    for (i=0; i < height; i++)
        for (j=0; j < width; j++)
            fprintf(foto, "%d %d %d\n", 
            //Operação ternária que verifica se o valor do pixel não ultrapassou os valores máximo e mínimo.
            (matriz[i][j].r > v_max) ? v_max : (matriz[i][j].r < 0) ? 0 : matriz[i][j].r,
            (matriz[i][j].g > v_max) ? v_max : (matriz[i][j].g < 0) ? 0 : matriz[i][j].g,
            (matriz[i][j].b > v_max) ? v_max : (matriz[i][j].b < 0) ? 0 : matriz[i][j].b);
    fclose(fotoN);
}