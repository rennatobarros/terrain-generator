#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "libs/functions.h"

int main(int argc, char *argv[])
{
    srand ((unsigned)time(NULL));
    
    // Armazena o nome do arquivo a ser lido
    char arq[50];

    // Loop para capturar e fazer a verificação dos paramêtros passados
    for(i = 0; i < argc; i++){
        if(argc == 1){
            //Valores default
            size = 128, strcpy(arq, "terrain"), MAX = 513;
        // Verifica se tem argumentos seguido de parâmetros
        }else if(argc > 1 && argc % 2 == 1){
            // Verifica se a opção digitada confere com a já estabelicida e atribui o argumento passado a corresponde variável
            if(strcmp("-d",argv[i + 1]) == 0){
                size = atoi(argv[i + 1]);
            }else if(strcmp("-o",argv[i + 1]) == 0){
                strcpy(arq, argv[i + 1]);
            }else if(strcmp("-s",argv[i + 1]) == 0){
                MAX = atoi(argv[i + 1]);
            }
        }else{
            printf("Argumentos faltando!\n");
            exit(0);
        }
    }

    // Inicia o processamento da imagem
    init_prog(MAX, size, arq);
    
    // Mensagem de término do programa
    printf("Programa Finalizado!!\n");
    
    return 0;
}