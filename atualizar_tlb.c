#include "biblioteca.h"


void atualizar_tlb(int frame, int pagina){
    for (int i = 0; i < TLB_SIZE; i++){
        if (tlb[i].valido == 0){
            tlb[i].pagina = pagina;
            tlb[i].frame = frame;
            tlb[i].timestamp = ++tempo_global;
            tlb[i].valido = 1;
            return;

        }
    }

    if (algoritmo_tlb == 1){   //FIFO
        tlb[tlb_fifo_index].frame = frame;
        tlb[tlb_fifo_index].pagina = pagina;
        tlb[tlb_fifo_index].timestamp = ++tempo_global;
        tlb_fifo_index = (tlb_fifo_index + 1) % TLB_SIZE;
        return;
              
    }
}