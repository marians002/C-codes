#ifndef LIST_H // Directiva de preprocesador para evitar la inclusión múltiple
#define LIST_H

typedef struct
{
    int len;    //tamaño actual del array
    int* data;
    int size;   //tamaño maximo que se puede guardar
} list_t;

int length(list_t* list);
list_t* initList(int cant);
int get(list_t* l, int i);
int set(list_t* l, int i, int num);
int validIndex(list_t* l, int i);
void increaseSize(list_t* l);
int insert(list_t* l, int i, int num);
int deleteAt(list_t* l, int i);
void push(list_t* l, int num);
int pop(list_t* l);
void printAll(list_t* l);
void printAt(list_t* l, int i);

#endif