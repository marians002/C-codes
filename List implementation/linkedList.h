// linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Definición de la estructura para los nodos de la lista
struct Node {
    int data; // Datos del nodo
    struct Node* next; // Puntero al siguiente nodo
};

// Definición de la estructura para la lista enlazada
struct LinkedList {
    struct Node* head; // Puntero al primer nodo
    struct Node* tail; // Puntero al último nodo
};

// Declaraciones de las funciones
void append(struct LinkedList* list, int new_data);
void deleteNode(struct LinkedList* list, int key);
void printList(struct LinkedList* list);
void deleteLastNode(struct LinkedList* list);

#endif
