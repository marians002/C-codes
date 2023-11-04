#include <stdio.h>
#include <stdlib.h>
#include "bnbStruct.h"
#include "listBNB.h"

// Devuelve la cantidad de elementos de la lista 
int length(bnbList* list)
{
    return list -> len;
}

// Inicializa la estructura
bnbList* initList()
{
    bnbList* l = (bnbList*)malloc(sizeof(bnbList));
    l -> len = 0; 
    l -> size = 10;
    l -> data = (bnbProcess*)malloc(l -> size * sizeof(bnbProcess));
    return l;
}

// Devuelve el proceso de una posición en un puntero result
// Ante un error devuelve -1. Else devuelve 0
int get(bnbList* l, int i, bnbProcess* result)
{
    if (i >= 0 && i < l -> len) 
    {
        *result = l -> data[i]; // Use the pointer to store the result
        return 0; // Return 0 for success
    }
    else
        return -1; // Return -1 for failure
}

// Setea un valor en una posición
int set(bnbList* l, int i, bnbProcess proc)
{
    if (i < 0 || i >= l -> len)
        return -1;
    else
    {
        l -> data[i] = proc;
        return 0;
    }
}

// Verifica que el índice se encuentre dentro del tamaño de la lista
int validIndex(bnbList* l, int i)
{
    if (i < 0 || i >= l -> len) // check i is valid
    {   
        printf("Posición inválida\n");
        return -1;
    }        
    return 0;
}

// Aumenta el tamaño de la lista si es necesario
void increaseSize(bnbList* l)
{
    if (l -> size == l -> len)
    {
        l -> size = l -> size*2;
        l ->  data = (bnbProcess*) realloc(l -> data, l -> size*sizeof(bnbProcess));
    }
}

// Inserta un elemento en una posición definida
int insert(bnbList* l, int i, bnbProcess proc)
{
    // index was invalid
    if (validIndex(l, i) == -1)
        return -1;

    increaseSize(l);    

    for (int j = l -> len; j > i; j--)
        l -> data[j] = l -> data[j-1];

    l -> data[i] = proc;
    l -> len++;
    
    return 0;
}

// Función para eliminar el elemento de una posición específica de la lista
int deleteAt(bnbList* l, int i) {
    // index was invalid
    if (validIndex(l, i) == -1)
        return -1;

    // Desplazar los elementos a la izquierda para sobrescribir el elemento en la posición i
    for (int j = i; j < l->len-1; j++) {
        l->data[j] = l->data[j + 1];
    }

    l->len--;  // Reducir el tamaño de la lista

    // Si el tamaño de la lista es menor que la mitad del tamaño del array, reducir el tamaño del array a la mitad
    if (l->len < l->size / 2) {
        l->size /= 2;
        l->data = (bnbProcess*) realloc(l->data, l->size * sizeof(bnbProcess));
    }

    return 0;
}

// Inserta un elemento al final de la lista
void push(bnbList* l, bnbProcess proc) 
{
    increaseSize(l);
    l -> data[length(l)] = proc;
    l -> len++;
}

// Elimina y devuelve el último elemento de la lista
int pop(bnbList* l, bnbProcess* result)
{
    int status = get(l, length(l)-1, result);

    // El get fue exitoso
    if (status == 0) 
    {
        deleteAt(l, length(l)-1);
        return 0;
    } 
    else // La función get falló
        return -1;
}

// Función para imprimir todos los elementos de la lista
void printAll(bnbList* l) {
    printf("La lista tiene %d elementos:\n", l->len);
    for (int i = 0; i < l->len; i++) {
        printf("%i ", l->data[i].pid_proceso);
    }
    printf("\n");
}

// Función para imprimir el elemento de una posición específica de la lista
void printAt(bnbList* l, int i) {
    if (i >= 0 && i < l->len) {
        printf("El elemento en la posición %d es: %i\n", i, l->data[i].pid_proceso);
    } else {
        printf("Posición inválida\n");
    }
}

