#ifndef LIST_H // Directiva de preprocesador para evitar la inclusión múltiple
#define LIST_H

#include "bnbStruct.h"

typedef struct
{
    int len;    //tamaño actual del array
    int size;   //tamaño maximo que se puede guardar
    bnbProcess* data;

} bnbList;

bnbList* initList();
#endif