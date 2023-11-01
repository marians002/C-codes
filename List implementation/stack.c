#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definición de la estructura para los nodos de la pila
struct Node {
    int data;
    struct Node* next;
};

// Función para crear un nuevo nodo con un valor dado
struct Node* newNode(int data) {
    struct Node* stackNode = (struct Node*) malloc(sizeof(struct Node));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Función para verificar si la pila está vacía
int isEmpty(struct Node* root) {
    return !root;
}

// Función para agregar un elemento a la pila
void push(struct Node** root, int data) {
    struct Node* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

// Función para eliminar un elemento de la pila
int pop(struct Node** root) {
    if (isEmpty(*root)) {
        return INT_MIN;
    }
    struct Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}
