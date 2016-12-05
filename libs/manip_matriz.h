void gen_terrain(pixel matriz[MAX][MAX], int altitudes[MAX])
{
    
    
    // Variável auxiliar para receber os valores das altitudes
    int aux;
    
    for (j=0; j < MAX; j++){
		aux = altitudes[j];
		for (i=aux; i < MAX; i++){
			matriz[i][j].r = 120, // Seta a cor marrom para indicar uma montanha.
            matriz[i][j].g = 80,
            matriz[i][j].b = 20;
			
		}
	}
}

void midPoint(int size, int altitudes[MAX], int limit, int inicial, int final)
{
    
    if(inicial >= 0 && final < size){
        // Variável para definir a aleatoriedade das alturas
        int displacement;

        // Evita erros de divisão por zero
        if(limit >= 2){
            displacement = num_rand(limit);
        }else{
            displacement = 0;
        }

        // Cria o ponto médio 
        int midpoint = (final-inicial)/2;

        if(midpoint > 0){
            int temp = ((altitudes[inicial] + altitudes[final])/2 + displacement);
                
            altitudes[inicial+midpoint] = temp;

            // Evita erros de segmentação
            if(temp > size-1)
                altitudes[inicial+midpoint] = size-1;
            else if(temp < 0)
               altitudes[inicial+midpoint] = 0;
            
        
            // Preenche recusivamente do inicio até o ponto médio
            midPoint(size, altitudes, limit/2, inicial, midpoint+inicial);
            // Preenche recusivamente do ponto médio até o final
            midPoint(size, altitudes, limit/2, midpoint+inicial, final);
        }
    }
}

void gen_linhacontorno(int size, int limit, int altitudes[MAX])
{
    // Setando aleatoriamente os pontos inicial e final, respectivamente.
    altitudes[0]        = num_rand(size);
    altitudes[size-1]   = num_rand(size);

    // Chama a função para gerar os pontos médios.
    midPoint(size, altitudes, limit, 0, size-1);
}