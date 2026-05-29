#include "biblioteca.h"

void converter_endereco(int endereco, FILE *log){
    int pagina = endereco >> 8;
    int offset = endereco & 0xFF;

    int frame = buscar_tlb(pagina);

    if (frame == -1){
        //TLB Miss
    }else {
        int endereco_fisico = (frame * 256) + offset;
        signed char valor = memoria_fisica[frame][offset];
        fprintf(log, "Virtual address: %d Physical address: %d Value: %d\n", endereco, endereco_fisico, valor);
    }
}