#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int len;    //tamaño actual del array
    char *data;
    int size;   //tamaño maximo que se puede guardar
} charList;

int length(charList* list)
{
    return list  ->  len;
}

charList* init()
{
    charList* l = (charList*)malloc(sizeof(charList));
    l  ->  len = 0; 
    l  ->  size = 10;
    l  ->  data = (char*)malloc(l  ->  size * sizeof(char));
    return l;
}

char get(charList* l, int i)
{
    if (i >= 0 && i < l  ->  len)
        return l  ->  data[i];
    else
        return -1;
}

int set(charList* l, int p, char c)
{
    if (p >= 0 && p < l  ->  len)
    {
        l  ->  data[p] = c;
        return 0;
    }
    else
        return -1;
}

int insert(charList* l, int i, char v)
{
    if (i < 0 || i > l  ->  len) // check i is valid
        return -1;

    if (l  ->  size == l ->  len)
    {
        l  ->  size = l -> size*2;
        l ->  data = (char*) realloc(l  ->  data, l  ->  size*sizeof(char));
    }

    for (int j = l -> len; j > i; j--)
        l -> data[j] = l -> data[j-1];

    l -> data[i] = v;
    l -> len++;
    
    return 0;
}

int main()
{
    charList* l = init();
}
