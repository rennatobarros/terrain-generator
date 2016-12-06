void midPoint(int MAX, int montanha[MAX], pixel matriz[MAX][MAX], int tipo, int deslocamento, int inicial, int final)
{
    if((final - inicial) > 1){
        // Variável para definir a aleatoriedade das alturas
        int fator_d;   
        // Evita erros de divisão por zero
        if(deslocamento > 1){
            // Gera valor aleatório entre deslocamento e -deslocamento
            fator_d = (num_rand(2*deslocamento)) - deslocamento;
        }else{
            fator_d = 0;
        }
    
        // Calcula o indice do ponto médio 
        int midpoint = (final+inicial)/2;
    
        int temp = ((montanha[inicial] + montanha[final])/2 + fator_d);
        
        // Evita erros de segmentação
        if(temp > MAX-1)
            montanha[midpoint] = MAX-1;
        else if(temp < 0)
           montanha[midpoint] = 0;
        else
            montanha[midpoint] = temp;

        if(tipo == 1){
            for(i = montanha[midpoint]; i < MAX ; i++){
                matriz[i][midpoint].r = 25;
                matriz[i][midpoint].g = 29;
                matriz[i][midpoint].b = 76;
            }
        }else if(tipo == 2){
            for(i = montanha[midpoint]; i < MAX ; i++){
                matriz[i][midpoint].r = 17;
                matriz[i][midpoint].g = 20;
                matriz[i][midpoint].b = 40;
            }
        }else if(tipo == 3){
            for(i = montanha[midpoint]; i < MAX ; i++){
                matriz[i][midpoint].r = 10;
                matriz[i][midpoint].g = 10;
                matriz[i][midpoint].b = 5;
            }
        }
            
        
        // Preenche recusivamente do inicio até o ponto médio
        midPoint(MAX, montanha, matriz, tipo, deslocamento/2, inicial, midpoint);
        // Preenche recusivamente do ponto médio até o final
        midPoint(MAX, montanha, matriz, tipo, deslocamento/2, midpoint, final);
    }
    
}

void gen_linhacontorno(int MAX, int deslocamento, int tipo, int montanha[MAX], pixel matriz[MAX][MAX])
{
    if(tipo == 1){
        // Setando aleatoriamente os pontos inicial e final, respectivamente.
        montanha[0]       = num_rand(MAX);
        montanha[MAX-1]   = num_rand(MAX);
        // Chama a função para gerar os pontos médios.
        midPoint(MAX, montanha, matriz, tipo, deslocamento, 0, MAX-1);
    }else if(tipo == 2){
        // Setando aleatoriamente os pontos inicial e final, respectivamente.
        montanha[0]       = num_rand(MAX);
        montanha[MAX-1]   = num_rand(MAX);
        // Chama a função para gerar os pontos médios.
        midPoint(MAX, montanha, matriz, tipo, deslocamento, 0, MAX-1);
    }else if(tipo == 3){
        // Setando aleatoriamente os pontos inicial e final, respectivamente.
        montanha[0]       = num_rand(MAX);
        montanha[MAX-1]   = num_rand(MAX);
        // Chama a função para gerar os pontos médios.
        midPoint(MAX, montanha, matriz, tipo, deslocamento, 0, MAX-1);
    }     
}