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

    MAX = 513;
    // Periodo do dia que a imagem será gerada.
    periodo p_dia;

    p_dia = MANHA, deslocamento = 128, strcpy(file_name, "terrain");

    // Loop para capturar e fazer a verificação dos paramêtros passados
    for(i = 1; i < argc; i++){
        if(argc > 1 && argc % 2 != 0){
            // Verifica se a opção digitada confere com a já estabelicida e atribui o argumento passado a variável correspondente
            // Verifica se foi passado somente um parametro
            if(argc == 3){
                if(strcmp("-d",argv[i]) == 0){
                    if(strcmp("-d",argv[i + 1]) != 0){
                        deslocamento = atoi(argv[i + 1]);
                    }
                }else if(strcmp("-o",argv[i]) == 0){
                    if(strcmp("-o",argv[i + 1]) != 0){
                        strcpy(file_name, argv[i + 1]);
                    }
                }else if(strcmp("-p",argv[i]) == 0){
                    if(strcmp("-p",argv[i + 1]) != 0){
                        p_dia = atoi(argv[i + 1]) == 0 ? NOITE : MANHA;
                    }
                }
            // Verifica se foram passados 2 parametros
            }else if(argc == 5){
                if(strcmp("-d",argv[i]) == 0){
                    if(strcmp("-d",argv[i + 1]) != 0){
                        deslocamento = atoi(argv[i + 1]);
                    }
                }else if(strcmp("-o",argv[i]) == 0){
                    if(strcmp("-o",argv[i + 1]) != 0){
                        strcpy(file_name, argv[i + 1]);
                    }
                }else if(strcmp("-p",argv[i]) == 0){
                   if(strcmp("-p",argv[i + 1]) != 0){
                        p_dia = atoi(argv[i + 1]) == 0 ? NOITE : MANHA;
                    }
                }else if(strcmp("-d",argv[i + 2]) == 0){
                    if(strcmp("-d",argv[i + 3]) != 0){
                        deslocamento = atoi(argv[i + 3]);
                    }
                }else if(strcmp("-o",argv[i + 2]) == 0){
                    if(strcmp("-o",argv[i + 3]) != 0){
                        strcpy(file_name, argv[i + 3]);
                    }
                }else if(strcmp("-p",argv[i + 2]) == 0){
                   if(strcmp("-p",argv[i + 3]) != 0){
                        p_dia = atoi(argv[i + 3]) == 0 ? NOITE : MANHA;
                    }
                }
            // Verifica se todos os parametros foram passados
            }else if(argc == 7){
                if(strcmp("-d",argv[i]) == 0){
                    if(strcmp("-d",argv[i + 1]) != 0){
                        deslocamento = atoi(argv[i + 1]);
                    }
                }else if(strcmp("-o",argv[i]) == 0){
                    if(strcmp("-o",argv[i + 1]) != 0){
                        strcpy(file_name, argv[i + 1]);
                    }
                }else if(strcmp("-p",argv[i]) == 0){
                   if(strcmp("-p",argv[i + 1]) != 0){
                        p_dia = atoi(argv[i + 1]) == 0 ? NOITE : MANHA;
                    }
                }else if(strcmp("-d",argv[i + 2]) == 0){
                    if(strcmp("-d",argv[i + 3]) != 0){
                        deslocamento = atoi(argv[i + 3]);
                    }
                }else if(strcmp("-o",argv[i + 2]) == 0){
                    if(strcmp("-o",argv[i + 3]) != 0){
                        strcpy(file_name, argv[i + 3]);
                    }
                }else if(strcmp("-p",argv[i + 2]) == 0){
                   if(strcmp("-p",argv[i + 3]) != 0){
                        p_dia = atoi(argv[i + 3]) == 0 ? NOITE : MANHA;
                    }
                }else if(strcmp("-d",argv[i + 4]) == 0){
                    if(strcmp("-d",argv[i + 5]) != 0){
                        deslocamento = atoi(argv[i + 5]);
                    }
                }else if(strcmp("-o",argv[i + 4]) == 0){
                    if(strcmp("-o",argv[i + 5]) != 0){
                        strcpy(file_name, argv[i + 5]);
                    }
                }else if(strcmp("-p",argv[i + 4]) == 0){
                    if(strcmp("-p",argv[i + 5]) != 0){
                        p_dia = atoi(argv[i + 5]) == 0 ? NOITE : MANHA;
                    }
                }
            }
        }else{
            // Quando a quantidade de argumentos é insuficiente
            printf("Argumentos faltando!\n");
            exit(0);
        }
    }
        

    // Inicia o processamento da imagem
    init_prog(MAX, deslocamento, file_name, p_dia);
    
    // Mensagem de término do programa
    printf("Programa Finalizado!!\n");
    
    return 0;
}