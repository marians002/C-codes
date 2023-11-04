#ifndef BNBSTRUCT_H // Directiva de preprocesador para evitar la inclusión múltiple
#define BNBSTRUCT_H
typedef struct 
{   
    // process_t proceso;
    int base;
    int bounds;
    int* heap;
    int stack;
} bnbProcess;

bnbProcess init();

#endif