CFLAGS = -Wall -Wextra 
CC = gcc

vm: vm.o thread_func.o converter_endereco.o buscar_tlb.o
	$(CC) vm.o thread_func.o converter_endereco.o buscar_tlb.o -o vm -lpthread

vm.o: vm.c biblioteca.h
	$(CC) $(CFLAGS) -c vm.c

thread_func.o: thread_func.c biblioteca.h
	$(CC) $(CFLAGS) -c thread_func.c

converter_endereco.o: converter_endereco.c biblioteca.h
	$(CC) $(CFLAGS) -c converter_endereco.c 

buscar_tlb.o: buscar_tlb.c biblioteca.h 
	$(CC) $(CFLAGS) -c buscar_tlb.c 

clean:
	rm -rf *.o vm