#include "biblioteca.h"

#define TLB_SIZE 16
#define PAGE_TABLE_SIZE 256
#define FRAME_SIZE 256
#define NUM_FRAMES 128

TLB tlb[TLB_SIZE];
int tlb_fifo_index = 0;
int tempo_global = 0;
int resultado_tlb = -1;

int buscar_tlb(int pagina){
    resultado_tlb = -1;
    pthread_t threads[TLB_SIZE];
    argThread args[TLB_SIZE];

    for (int i = 0; i < TLB_SIZE; i++){
        args[i].indice = i;
        args[i].pagina = pagina;
    }

    for (int i = 0; i < TLB_SIZE; i++){
        pthread_create(&threads[i], NULL, thread_func, &args[i]);
    }

    for (int i = 0; i < TLB_SIZE; i++){
        pthread_join(threads[i], NULL);
    }

    if (resultado_tlb != -1){
        for (int i = 0; i < TLB_SIZE; i++){
            if (tlb[i].valido && tlb[i].pagina == pagina){
                tlb[i].timestamp = ++ tempo_global;
                break;
            }
        }
    }

    return resultado_tlb;
}
