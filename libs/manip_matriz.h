/**
 *  \file manip_matriz.h
 *  \brief Arquivo com as funções para gerar o terreno
 *
 */

/** 
 * Função que gera os pontos médios do terreno a partir dos pontos extremos e atribui algumas cores aos pixeis
 *
 * \brief Função que gera os pontos médios do terreno
 *
 * @param MAX Valor máximo da linha e coluna da matriz
 * @montanha Vetor de altitudes que irá gerar a montanha
 * @param matriz Matriz de pixels
 * @param tipo Variável que auxilia na geração de três montanhas
 * @param p_dia Variável para controlar se as cores da montanha serão noturnas ou diurnas
 * @param deslocamento fator de deslocamento
 * @param arq Nome que será dado ao arquivo 
 * \return Nada
*/
void midPoint(int MAX, int montanha[MAX], pixel matriz[MAX][MAX], int tipo, int p_dia, int deslocamento, int inicial, int final)
{
    // Verifica se há espaço para calcular
    if((final - inicial) > 1){
        // Variável para definir um deslocamento aleatório
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
    
        // Variável temporaria que recebe as alturas
        int temp = ((montanha[inicial] + montanha[final])/2 + fator_d);
        
        // Evita erros de segmentação
        if(temp > MAX-1)
            montanha[midpoint] = MAX-1;
        else if(temp < 0)
           montanha[midpoint] = 0;
        else
            montanha[midpoint] = temp;

        // Aplicando cores diurnas ou noturnas em casa vetor de montanha dependendo da variável 'p_dia'
        if(tipo == 1 && p_dia == NOITE){
            for(i = montanha[midpoint]; i < MAX ; i++){
                matriz[i][midpoint].r = 25;
                matriz[i][midpoint].g = 29;
                matriz[i][midpoint].b = 76;
            }
        }else if(tipo == 2 && p_dia == NOITE){
            for(i = montanha[midpoint]; i < MAX ; i++){
                matriz[i][midpoint].r = 17;
                matriz[i][midpoint].g = 20;
                matriz[i][midpoint].b = 40;
            }
        }else if(tipo == 3 && p_dia == NOITE){
            for(i = montanha[midpoint]; i < MAX ; i++){
                matriz[i][midpoint].r = 10;
                matriz[i][midpoint].g = 10;
                matriz[i][midpoint].b = 5;
            }
        }else if(tipo == 1 && p_dia == MANHA){
            for(i = montanha[midpoint]; i < MAX ; i++){
                matriz[i][midpoint].r = 55;
                matriz[i][midpoint].g = 43;
                matriz[i][midpoint].b = 0;
            }
        }else if(tipo == 2 && p_dia == MANHA){
            for(i = montanha[midpoint]; i < MAX ; i++){
                matriz[i][midpoint].r = 41;
                matriz[i][midpoint].g = 32;
                matriz[i][midpoint].b = 0;
            }
        }else if(tipo == 3 && p_dia == MANHA){
            for(i = montanha[midpoint]; i < MAX ; i++){
                matriz[i][midpoint].r = 68;
                matriz[i][midpoint].g = 53;
                matriz[i][midpoint].b = 0;
            }
        }
            
        
        // Preenche recusivamente do inicio até o ponto médio
        midPoint(MAX, montanha, matriz, tipo, p_dia, deslocamento/2, inicial, midpoint);
        // Preenche recusivamente do ponto médio até o final
        midPoint(MAX, montanha, matriz, tipo, p_dia, deslocamento/2, midpoint, final);
    }
    
}

/** 
 * Função que inicializa os pontos extremos e chama a função MidPoint para gerar os valores médios
 *
 * \brief Função que gera os pontos extremos do terreno
 *
 * @param MAX Valor máximo da linha e coluna da matriz
 * @param deslocamento fator de deslocamento
 * @param tipo Variável que auxilia na geração de três montanhas
 * @param p_dia Variável para controlar se as cores da montanha serão noturnas ou diurnas
 * @montanha Vetor de altitudes que irá gerar a montanha
 * @param matriz Matriz de pixels
 * \return Nada
*/

void gen_linhacontorno(int MAX, int deslocamento, int tipo, int p_dia, int montanha[MAX], pixel matriz[MAX][MAX])
{
    if(tipo == 1){
        // Setando aleatoriamente os pontos inicial e final, respectivamente.
        montanha[0]       = 150 + num_rand(MAX);
        montanha[MAX-1]   = 150 + num_rand(MAX);
        // Chama a função para gerar os pontos médios.
        midPoint(MAX, montanha, matriz, tipo, p_dia, deslocamento, 0, MAX-1);
    }else if(tipo == 2){
        // Setando aleatoriamente os pontos inicial e final, respectivamente.
        montanha[0]       = 170 + num_rand(MAX);
        montanha[MAX-1]   = 170 + num_rand(MAX);
        // Chama a função para gerar os pontos médios.
        midPoint(MAX, montanha, matriz, tipo, p_dia, deslocamento, 0, MAX-1);
    }else if(tipo == 3){
        // Setando aleatoriamente os pontos inicial e final, respectivamente.
        montanha[0]       = 200 + num_rand(MAX);
        montanha[MAX-1]   = 200 + num_rand(MAX);
        // Chama a função para gerar os pontos médios.
        midPoint(MAX, montanha, matriz, tipo, p_dia, deslocamento, 0, MAX-1);
    }     
}

/** 
 * Função que inicializa a matriz de pixels com cores diurnas ou noturnas
 *
 * \brief Função que inicializa a matriz com algumas cores
 *
 * @param MAX Valor máximo da linha e coluna da matriz
 * @param matriz Matriz de pixels
 * @param p_dia Variável para controlar se as cores da montanha serão noturnas ou diurnas
 * \return Nada
*/

void init_matriz(int MAX, pixel matriz[MAX][MAX], int p_dia)
{
    // Inicia a matriz de pixels com cores diurnas ou noturnas
    if(p_dia == NOITE){
        for (i=0; i < MAX; i++){
            for (j=0; j < MAX; j++){
                matriz[i][j].r = 17; // Seta uma cor 'noturna' para todo o terreno
                matriz[i][j].g = 14;
                matriz[i][j].b = 25;
            }
        }

        // Variaveis para armazenar a linha e a coluna que a estrela será adicionada
        int l, c;
        // Gerando estrelas aleatoriamente
        for(i = 0; i < MAX; i += 25){
            for(j = 0; j < MAX; j += 30){
                // Não preenche todo o terreno com estrelas
                l = num_rand(MAX/2);
                c = num_rand(MAX);
                matriz[l][c].r = 255;// Seta a cor branca
                matriz[l][c].g = 255;
                matriz[l][c].b = 255;
            }
        }    
    }else{
        for (i=0; i < MAX; i++){
            for (j=0; j < MAX; j++){
                matriz[i][j].r = 214; // Seta uma cor 'diurna' para todo o terreno
                matriz[i][j].g = 238;
                matriz[i][j].b = 248;
            }
        }    
    }
}