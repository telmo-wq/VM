#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TLB_SIZE 16
#define PAGE_TABLE_SIZE 256
#define FRAME_SIZE 256
#define NUM_FRAMES 128

typedef struct {
    int frame;
    int valido;
} entradaPaginas;

typedef struct {
    int pagina;
    int frame;
    int valido;
    int timestamp;
} TLB;

typedef struct {
    int indice;
    int pagina;
} argThread;

extern TLB tlb[TLB_SIZE];
extern int algoritmo_tlb;
extern int algoritmo_pagina;
extern entradaPaginas tabelaPaginas[PAGE_TABLE_SIZE];
extern int resultado_tlb;
extern int tempo_global;
extern int tlb_fifo_index;
extern pthread_mutex_t mutex;
extern signed char memoria_fisica[NUM_FRAMES][FRAME_SIZE]; 
extern int frame_usados;
extern int frame_fifo_index;
extern int frame_timestamps[NUM_FRAMES];

void converter_endereco(int endereco, FILE *log);

int buscar_tlb(int pagina);

void *thread_func(void *arg);

void atualizar_tlb(int frame, int pagina);


#endif