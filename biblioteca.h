#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TLB_SIZE 16
#define PAGE_TABLE_SIZE 256
#define FRAME_SIZE 256
#define NUM_FRAMES 128

extern TLB tlb[TLB_SIZE];
extern int resultado_tlb;
extern int tempo_global;
extern int tlb_fifo_index;
extern pthread_mutex_t mutex;


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

void converter_endereco(int endereco);

int buscar_tlb(int pagina);

void *thread_func(void *arg);


#endif