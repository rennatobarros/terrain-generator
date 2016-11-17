#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    //char *parametros[] = {"-d", "-o", "-s"};
    
    for(i = 0; i < argc; i++) {
        if(argc > 1){
            if(strcmp("-d",argv[i + 1]) == 0 || strcmp("-o",argv[i + 1]) == 0){
                printf("Argumentos aceitos!\n");
            }
        }
    }

            
    
    return 0;
}