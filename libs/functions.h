#include "headers.h"
#include "global.h"

int num_rand (int max) 
{
    return rand()%max;
}

void gen_terrain(pixel matriz[MAX][MAX], int altitudes[MAX])
{
    int aux;
    
    for (j=0; j < MAX; j++){
		aux = altitudes[j];
		for (i=aux; i < MAX; i++){
			matriz[i][j].r = 40, // Seta a cor marrom para indicar uma montanha.
            matriz[i][j].g = 20,
            matriz[i][j].b = 13;
			
		}
	}
}

void salvar_img(int MAX, pixel matriz[MAX][MAX], char file[])
{
    v_max = 255;

    // Concatena o nome do arquivo com a extensão ppm
    foto = fopen(strcat(file,".ppm"), "w");

    fprintf (foto, "%s\n", header);
    fprintf (foto, "%d %d\n", MAX, MAX);
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

void midPoint(int size, int altitudes[MAX], int limit, int inicial, int final)
{
    
    if (inicial >= 0 && final < size)
    {
        int displacement;
        if(limit >= 2){
            displacement = num_rand(limit);
        }else{
            displacement = 0;
        }

        int midpoint = (final-inicial)/2;

        if(midpoint > 0){
            int temp = ((altitudes[inicial] + altitudes[final])/2 + displacement);
                
            altitudes[inicial+midpoint] = temp;

            if(temp > size-1)
                altitudes[inicial+midpoint] = size-1;
            else if(temp < 0)
               altitudes[inicial+midpoint] = 0;

        
            //int num = num_rand(limit);
            
        
            // Preenche do inicio até o ponto médio
            midPoint(size, altitudes, limit/2, inicial, midpoint+inicial);
            // Preenche do ponto médio até o final
            midPoint(size, altitudes, limit/2, midpoint+inicial, final);
        }
            
    }
}

void gen_linhacontorno(int size, int limit, int altitudes[MAX])
{
    // Setando aleatoriamente os pontos inicial e final, respectivamente.
    altitudes[0] = num_rand(size);
    altitudes[size-1] = num_rand(size);

    // Chama a função para gerar os pontos médios.
    midPoint(size, altitudes, limit, 0, size-1);
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