#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char *argv[]){
    FILE *arquivo = fopen(argv[1], "r");
    char linha[200];

    if (arquivo == NULL){
        printf("ERRO! Arquivo nao encontrado\n");
        return 0;
    }

    if (strcmp(argv[2], "lru") != 0 && strcmp(argv[2], "fifo") != 0){
        printf("ERRO! Insira um algoritmo valido\n");
        return 0;
    }
    
}