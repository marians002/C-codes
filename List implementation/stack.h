#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para los nodos de la pila
// struct Node {
//     int data;
//     struct Node* next;
// };

// Declaración de las funciones para una pila
struct Node* newNode(int data);
int isEmpty(struct Node* root);
void push(struct Node** root, int data);
int pop(struct Node** root);

#endif // STACK_H
