#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// Devuelve la cantidad de elementos de la lista 
int length(list_t* list)
{
    return list -> len;
}

// Inicializa la estructura
list_t* initList(int cant)
{
    list_t* l = (list_t*)malloc(sizeof(list_t));
    l -> len = 0; 
    l -> size = cant;
    l -> data = (int*)malloc(l -> size * sizeof(int));
    return l;
}

// Devuelve el caracter de una posición
int get(list_t* l, int i)
{
    if (i < 0 || i >= l -> len)
        return l -> data[i];
    else
        return -1;
}

// Setea un valor en una posición
int set(list_t* l, int i, int num)
{
    if (i < 0 || i >= l -> len)
        return -1;
    else
    {
        l -> data[i] = num;
        return 0;
    }
}

// Verifica que el índice se encuentre dentro del tamaño de la lista
// -1 => Inválido, 0 => válido
int validIndex(list_t* l, int i)
{
    if (i < 0 || i >= l -> len) // check i is valid
    {   
        printf("Posición inválida\n");
        return -1;
    }        
    return 0;
}

// Aumenta el tamaño de la lista si es necesario
void increaseSize(list_t* l)
{
    if (l -> size == l -> len)
    {
        l -> size = l -> size*2;
        l ->  data = (int*) realloc(l -> data, l -> size*sizeof(int));
    }
}

// Inserta un elemento en una posición definida
int insert(list_t* l, int i, int num)
{
    // index was invalid
    if (validIndex(l, i) == -1)
        return -1;

    increaseSize(l);    

    for (int j = l -> len; j > i; j--)
        l -> data[j] = l -> data[j-1];

    l -> data[i] = num;
    l -> len++;
    
    return 0;
}

// Función para eliminar el elemento de una posición específica de la lista
int deleteAt(list_t* l, int i) 
{
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
        l->data = (int*) realloc(l->data, l->size * sizeof(int));
    }
    return 0;
}

// Inserta un elemento al final de la lista
void push(list_t* l, int num) 
{
    increaseSize(l);
    l -> data[length(l)] = num;
    l -> len++;
}

// Elimina y devuelve el último elemento de la lista
int pop(list_t* l)
{
    int num = get(l, length(l)-1);
    deleteAt(l, length(l)-1);
    return num;
}

// Función para imprimir todos los elementos de la lista
void printAll(list_t* l) 
{
    printf("La lista tiene %d elementos:\n", l->len);
    for (int i = 0; i < l->len; i++) {
        printf("%i ", l->data[i]);
    }
    printf("\n");
}

// Función para imprimir el elemento de una posición específica de la lista
void printAt(list_t* l, int i) 
{
    if (i >= 0 && i < l->len) {
        printf("El elemento en la posición %d es: %i\n", i, l->data[i]);
    } else {
        printf("Posición inválida\n");
    }
}