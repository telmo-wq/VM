#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include "biblioteca.h"

TLB tlb[TLB_SIZE];
int algoritmo_tlb;
int algoritmo_pagina;
entradaPaginas tabelaPaginas[PAGE_TABLE_SIZE];
int resultado_tlb = -1;
int tempo_global = 0;
int tlb_fifo_index = 0;
pthread_mutex_t mutex;
signed char memoria_fisica[NUM_FRAMES][FRAME_SIZE];
int frames_usados = 0;
int frame_fifo_index = 0;
int frame_timestamps[NUM_FRAMES];

int main(int argc, char *argv[]){
    if (argc != 4){
        printf("ERRO! Insira uma quantidade válida de argumentos!\n");
        return 0;
    }

    FILE *arquivo = fopen(argv[1], "r");
    char linha[200];

    if (arquivo == NULL){
        printf("ERRO! Arquivo nao encontrado\n");
        return 0;
    }

    if (strcmp(argv[2], "lru") != 0 && strcmp(argv[2], "fifo") != 0){
        printf("ERRO! Insira um algoritmo valido\n");
        return 0;
    }else if (strcmp(argv[2], "lru") == 0){
        algoritmo_pagina = 0;
    }else {
        algoritmo_pagina = 1;
    }

    if (strcmp(argv[3], "lru") != 0 && strcmp(argv[3], "fifo") != 0){
        printf("ERRO! Insira um algoritmo válido\n");
        return 0;
    }else if (strcmp(argv[3], "lru") == 0){
        algoritmo_tlb = 0;
    }else {
        algoritmo_tlb = 1;
    }
    
}