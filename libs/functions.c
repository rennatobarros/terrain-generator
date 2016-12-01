#include "headers.h"
#include "global.h"

int num_rand (int max) 
{
    return rand()%max;
}

void midPoint(int size, int fator_d, int altitudes[size], int inicial, int final)
{
    int n = fator_d/2;
    // Evita erro de segmentação
    if(n == 0) 
        n = 1;

    if(inicial >= 0 && final < size){
        int num = num_rand(n);
        int midpoint = (inicial + final)/2;
        altitudes[midpoint] = (altitudes[inicial] + altitudes[final])/2;
        altitudes[midpoint] += num;

        if(midpoint != inicial && midpoint != final){
            midPoint(size, n, altitudes, inicial, midpoint);
            midPoint(size, n, altitudes, midpoint, final);
        }
    }
    

}

void gen_linhacontorno(int size, int fator_d, int altitudes[size])
{
    int n = fator_d/2;
    
    altitudes[0] = num_rand(n) + n;
    altitudes[size-1] = num_rand(n) + n;

    midPoint(size, n, altitudes, 0, size-1);
}

/*void gen_terrain(pixel matriz[MAX][MAX], ponto vetorLinha[MAX])
{
    int l = 0;

    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; i++){
            matriz[i][j] = vetorLinha[l];
            l++;
        }
    }
}*/

void salvar_img(pixel matriz[MAX][MAX])
{
    
    char nome_arq_salvar[] = "teste.ppm";
    //scanf("%s", nome_arq_salvar);

    foto = fopen(nome_arq_salvar, "w");

    fprintf (foto, "%s\n", header);
    fprintf (foto, "%d %d\n", 512, 512);
    fprintf (foto, "%d\n", v_max);

    for (i=0; i < height; i++)
        for (j=0; j < width; j++)
            fprintf(foto, "%d %d %d\n", 
            //Operação ternária que verifica se o valor do pixel não ultrapassou os valores máximo e mínimo.
            (matriz[i][j].r > v_max) ? v_max : (matriz[i][j].r < 0) ? 0 : matriz[i][j].r,
            (matriz[i][j].g > v_max) ? v_max : (matriz[i][j].g < 0) ? 0 : matriz[i][j].g,
            (matriz[i][j].b > v_max) ? v_max : (matriz[i][j].b < 0) ? 0 : matriz[i][j].b);
    fclose(foto);
}