#include "headers.h"
#include "global.h"

int num_rand (int max) 
{
    return rand() % max;
}

void gen_linhacontorno(pixel matriz[MAX+1][MAX+1], ponto inicial, ponto final, ponto vetorLinha[MAX+1], int range)
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

void gen_imagem(pixel matriz[MAX+1][MAX+1], ponto vetorLinha[MAX+1])
{
    
}