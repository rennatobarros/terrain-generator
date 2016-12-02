#include "headers.h"
#include "global.h"

int num_rand (int max) 
{
    return rand()%max;
}

void midPoint(int size, int altitudes[size], int limit, int inicial, int final)
{
    
    int var;

    if(limit >= 2)
        var = (rand()%(2*limit+1)-limit);
    else
        var = 0;

    int midpoint = (final-inicial)/2;

    int aux = ((altitudes[inicial] + altitudes[final])/2 + var);
    altitudes[inicial+midpoint] = aux;
        
    if(aux > size-1)
        altitudes[inicial+midpoint] = size-1;
    else if(aux < 0)
       altitudes[inicial+midpoint] = 0;

    if(midpoint > 0){
        //int num = num_rand(limit);
        

        //Preenche do inicio até o ponto médio
        midPoint(size, altitudes, limit/2, inicial, midpoint+inicial);
        //Preenche do ponto médio até o final
        midPoint(size, altitudes, limit/2, midpoint+inicial, final);
        
    }
    

}

void gen_linhacontorno(int size, int limit, int altitudes[size])
{
    
    altitudes[0] = num_rand(size) - 20;
    altitudes[size] = num_rand(size) - 20;

    midPoint(size, altitudes, limit, 0, size);
}

void gen_terrain(pixel matriz[MAX][MAX], int altitudes[size])
{
    int aux1;
    
    for (i=0; i < MAX-1; i++){
		aux1 = altitudes[i];
		for (j=aux1; j < MAX-1; j++){
			matriz[i][j].r = 40,
            matriz[i][j].g = 20,
            matriz[i][j].b = 13;
			
		}
	}
}

void salvar_img(pixel matriz[MAX][MAX], char file[])
{
    foto = fopen(strcat(file,".ppm"), "w");

    fprintf (foto, "%s\n", header);
    fprintf (foto, "%d %d\n", 512, 512);
    fprintf (foto, "%d\n", v_max);

    for (i=0; i < MAX-1; i++)
        for (j=0; j < MAX-1; j++)
            fprintf(foto, "%d %d %d\n", 
            //Operação ternária que verifica se o valor do pixel não ultrapassou os valores máximo e mínimo.
            (matriz[i][j].r > v_max) ? v_max : (matriz[i][j].r < 0) ? 0 : matriz[i][j].r,
            (matriz[i][j].g > v_max) ? v_max : (matriz[i][j].g < 0) ? 0 : matriz[i][j].g,
            (matriz[i][j].b > v_max) ? v_max : (matriz[i][j].b < 0) ? 0 : matriz[i][j].b);
    fclose(foto);
}