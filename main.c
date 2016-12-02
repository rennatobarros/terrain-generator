#include "libs/functions.c"

int main(int argc, char *argv[])
{
    srand ((unsigned)time(NULL));

    /** Valor dos limites da linha de contorno. */
    int size;

    /** Nome do arquivo a ser salvo. */
    char *arq[20];

    /** Define o tamanho máximo que a imagem pode ter. */
    int MAX;
    
    // Loop para capturar e fazer a verificação dos paramêtros passados
    for(i = 0; i < argc; i++){
        if(argc == 1){
            //Valores default
            size = 128, arq = "terrain", MAX = 513;
        // Verifica se tem argumentos seguido de parâmetros
        }else if(argc > 1 && argc % 2 == 1){
            // Verifica se a opção digitada confere com a já estabelicida e atribui o argumento passado a corresponde variável
            if(strcmp("-d",argv[i + 1]) == 0){
                size = atoi(argv[i + 1]);
            }else if(strcmp("-o",argv[i + 1]) == 0){
                arq = argv[i + 1];
            }else if(strcmp("-s",argv[i + 1]) == 0){
                MAX = atoi(argv[i + 1]);
            }
        }else{
            printf("Argumentos faltando!\n");
            exit(0);
        }
    }

    pixel matriz[MAX][MAX];
    int altitudes[MAX];
    
    gen_linhacontorno(MAX-1, size, altitudes);
    gen_terrain(matriz, altitudes);
    salvar_img(matriz, arq);
            
    
    return 0;
}