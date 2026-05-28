#include "biblioteca.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg){
    argThread *a = (argThread *)arg;

    if (tlb[a->indice].valido && tlb[a->indice].pagina == a->pagina){
        pthread_mutex_lock(&mutex);

        resultado_tlb = tlb[a->indice].frame;
        
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
    
}