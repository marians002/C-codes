#include <stdio.h>
#include <stdlib.h>

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

// Función para imprimir todos los elementos de la lista
void printList(struct LinkedList* list) {
   struct Node* temp = list -> head;

   while (temp != NULL) {
       printf("%d ", temp -> data);
       temp = temp -> next;
   }

   printf("\n");
}

int main() {
   struct LinkedList list; // Lista vacía

   append(&list, 1); // Añadir elementos a la lista
   append(&list, 2);
   append(&list, 3);
   append(&list, 4);
   append(&list, 5);
   append(&list, 6);
   append(&list, 7);
   append(&list, 8);
   append(&list, 9);
   append(&list, 10);

   deleteNode(&list, 2); // Borrar el elemento '2' de la lista

   modifyNode(&list, 3, 4); // Modificar el elemento '3' a '4'

   printList(&list); // Imprimir todos los elementos de la lista

   return 0;
}
