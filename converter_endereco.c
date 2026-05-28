#include "biblioteca.h"

void converter_endereco(endereco){
    int pagina = endereco >> 8;
    int offset = endereco & 0xFF;

    int frame = buscar_tlb(pagina);

    if (frame == -1){
        //TLB miss
    }else {
        //TLB hit
    }
}