#include <stdio.h>
#include <stdlib.h>
#include "bnbStruct.h"

// Inicializa la estructura bnbProcess

void init_heap(int* heap) // Cambia el tipo de retorno a void
{
    for (int i=0; i<12; i++)
        heap[i] = i+10;
}
int heapSize = 20;
bnbProcess init() {    
    bnbProcess p;
    p.heap = (int*)malloc(heapSize * sizeof(int)); // Asigna memoria al heap antes de inicializarlo
    init_heap(p.heap); // Llama a init_heap sin asignar el resultado a p.heap
    p.stack = 1212;
    
    return p;
}