#include "libs/functions.c"

int main(int argc, char *argv[])
{
    //char *parametros[] = {"-d", "-o", "-s"};
    srand ((unsigned)time(NULL));

    pixel matriz[MAX][MAX];
    int size = 128;

    int altitudes[MAX];
    
    //for(i = 0; i < size; i++)
      //  altitudes[i] = 0;

    //for(i = 0; i < size; i++)
      //  printf("%d ", altitudes[i]);
    //printf("\n");

    gen_linhacontorno(MAX-1, size, altitudes);
    gen_terrain(matriz, altitudes);

    //for(i = 0; i < size; i++)
      //  printf("%d ", altitudes[i]);
    //printf("\n");




    salvar_img(matriz);
    
    /* if(argc == 1){
        printf("Arquivo sem paramentros!!\n");
    }else if(argc > 1){
        if(argc % 2 != 0){
            if(strcmp("-d",argv[i + 1]) == 0 || strcmp("-o",argv[i + 1]) == 0){
                printf("Argumentos aceitos!\n");
            }
        }else{
                printf("Argumentos faltando!\n");
                exit(0);
         }
    } */
            
    
    return 0;
}