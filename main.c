#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//Função de comparação
int myCOMP(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx < pty){
		return -1;
	}else{
		if(ptx > pty) return 1;
		else return 0;
	}
}

//Print para a estrutura
void print(void** vet, int P){
	int i;
	printf("VETOR DE %d POSIÇÕES:\n", P);
	for(i = 0; i < 10; i++){
		printf(" %d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	HEAP* vet = HEAP_create(10, myCOMP);
   	
   	int* x;
   	int i;
   	
   	printf("INCLUINDO...\n");
	for(i = 0; i < 10; i++){
		x = malloc(sizeof(int));
		*x = i*10;
		HEAP_add(vet, x);
	}
	
	print(vet->elems, vet->P);
  
  	printf("REMOVENDO!\n");
  	HEAP_remove(vet);	
	HEAP_remove(vet);	
	HEAP_remove(vet);	
  	
	print(vet->elems, vet->P);
   
	return 0;  
}