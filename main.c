/** 
 * \mainpage Gerador de Terrenos
 * \author Renato Barros de Lima Freitas
 * \date 08/12/2016
 * \version 1.0
 *
 * \file main.c
 * \brief Arquivo principal do programa
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "libs/functions.h"

/**
     * \brief Função que executa a principal parte do programa
     * @param argc Inteiro que guarda a quantidade de argumentos passados
     * @param argv Vetor que guarda as strings passadas por linha de comando
     * \return 0
*/
int main(int argc, char *argv[])
{
    // Semente para números aleeatórios
    srand ((unsigned)time(NULL));
    
    // Armazena o nome do arquivo a ser lido
    char arq[50];
    
    // Valor da dimensão da matriz
    int MAX = 513;

    // Periodo do dia que a imagem será gerada.
    periodo p_dia;

    // Loop para capturar e fazer a verificação dos paramêtros passados
    if(argc == 1){
        //Valores default
        p_dia = NOITE, deslocamento = 128, strcpy(arq, "terrain");
    // Verifica se tem argumentos seguido de parâmetros
    }else if(argc > 1 && argc % 2 != 0){
        // Verifica se a opção digitada confere com a já estabelicida e atribui o argumento passado a variável correspondente
        if(argc == 3){
            if(strcmp("-d",argv[1]) == 0){
                deslocamento = atoi(argv[2]);
            }else if(strcmp("-o",argv[1]) == 0){
                strcpy(arq, argv[2]);
            }else if(strcmp("-p",argv[1]) == 0){
                p_dia = atoi(argv[2]);
            }else{
                printf("Erro!");
            }
        }else if(argc == 5){
            if(strcmp("-d",argv[1]) == 0){
                deslocamento = atoi(argv[2]);
            }else if(strcmp("-o",argv[1]) == 0){
                strcpy(arq, argv[2]);
            }else if(strcmp("-p",argv[1]) == 0){
                p_dia = atoi(argv[2]);
            }else if(strcmp("-d",argv[3]) == 0){
                deslocamento = atoi(argv[4]);
            }else if(strcmp("-o",argv[3]) == 0){
                strcpy(arq, argv[4]);
            }else if(strcmp("-p",argv[3]) == 0){
                p_dia = atoi(argv[4]);
            }else{
                printf("Erro!");
            }
        }else if(argc == 7){
            if(strcmp("-d",argv[1]) == 0){
                deslocamento = atoi(argv[2]);
            }else if(strcmp("-o",argv[1]) == 0){
                strcpy(arq, argv[2]);
            }else if(strcmp("-p",argv[1]) == 0){
                p_dia = atoi(argv[2]);
            }else if(strcmp("-d",argv[3]) == 0){
                deslocamento = atoi(argv[4]);
            }else if(strcmp("-o",argv[3]) == 0){
                strcpy(arq, argv[4]);
            }else if(strcmp("-p",argv[3]) == 0){
                p_dia = atoi(argv[4]);
            }else if(strcmp("-d",argv[5]) == 0){
                deslocamento = atoi(argv[6]);
            }else if(strcmp("-o",argv[5]) == 0){
                strcpy(arq, argv[6]);
            }else if(strcmp("-p",argv[5]) == 0){
                p_dia = atoi(argv[6]);
            }else{
                printf("Erro!");
            }
        }
    }else{
        printf("Argumentos faltando!\n");
        exit(0);
    }

    // Inicia o processamento da imagem
    init_prog(MAX, deslocamento, arq, p_dia);
    
    // Mensagem de término do programa
    printf("Programa Finalizado!!\n");
    
    return 0;
}