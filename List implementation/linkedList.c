#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

// Función para añadir un nodo al final de la lista
void append(struct LinkedList* list, int new_data) {
    // 1. Asignar memoria para el nuevo nodo
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // 2. Asignar los datos al nuevo nodo y su próximo será NULL
    new_node -> data = new_data;
    new_node -> next = NULL;

    // 3. Si la lista está vacía, el nuevo nodo es también el primer y último nodo
    if (list -> head == NULL) {
        list -> head = list -> tail = new_node;
        return;
    }

    // 4. Si la lista no está vacía, añadir el nuevo nodo al final y actualizar el último nodo
    list -> tail -> next = new_node;
    list -> tail = new_node;
}

// Función para borrar un nodo de la lista por clave
void deleteNode(struct LinkedList* list, int key) {
    // 1. Almacenar el nodo cabeza y el nodo anterior
    struct Node* temp = list -> head, *prev;

    // 2. Si la clave está en el nodo cabeza, cambiar la cabeza
    if (temp != NULL && temp -> data == key) {
        list -> head = temp -> next; 
        free(temp); 
        return;
    }

    // 3. Buscar la clave que se va a borrar
    while (temp != NULL && temp -> data != key) {
        prev = temp;
        temp = temp -> next;
    }

    // 4. Si la clave no está en la lista
    if (temp == NULL) return;

    // 5. Desenlazar el nodo de la lista
    prev -> next = temp -> next;

    // 6. Si el nodo a borrar es el último, actualizar el último nodo
    if (temp == list -> tail) {
        list -> tail = prev;
    }

    // 7. Liberar memoria
    free(temp);
}

// Función para modificar un elemento de la lista por clave
void modifyNode(struct LinkedList* list, int key, int new_data) {
   // 1. Almacenar el nodo cabeza
   struct Node* temp = list -> head;

   // 2. Buscar la clave que se va a modificar
   while (temp != NULL && temp -> data != key) {
       temp = temp -> next;
   }

   // 3. Si la clave no está en la lista, salir de la función
   if (temp == NULL) return;

   // 4. Cambiar los datos del nodo a los nuevos datos
   temp -> data = new_data;
}

// Función para eliminar el último nodo de la lista
void deleteLastNode(struct LinkedList* list) {
    // 1. Si la lista está vacía, no hay nada que eliminar
    if (list -> head == NULL) {
        return;
    }

    // 2. Si la lista solo tiene un nodo, eliminar ese nodo
    if (list -> head == list -> tail) {
        free(list -> head);
        list -> head = list -> tail = NULL;
        return;
    }

    // 3. Almacenar el nodo cabeza y el nodo anterior
    struct Node* temp = list -> head;
    struct Node* prev = NULL;

    // 4. Recorrer la lista hasta el último nodo
    while (temp != list -> tail) {
        prev = temp;
        temp = temp -> next;
    }

    // 5. Desenlazar el último nodo de la lista
    prev -> next = NULL;

    // 6. Actualizar el último nodo
    list -> tail = prev;

    // 7. Liberar memoria
    free(temp);
}

// Función para imprimir todos los elementos de la lista
void printList(struct LinkedList* list) {
   struct Node* temp = list -> head;

   while (temp != NULL) {
       printf("%d ", temp -> data);
       temp = temp -> next;
   }

   printf("\n");
}
