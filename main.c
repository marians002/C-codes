#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int age = 20;
	double gpa = 3.2;
	char grade = 'A';

	int *pAge = &age;
	double *pGpa = &gpa;
	char *pGrade = &grade;

	/* 
	Notas: 
	-   *pointer me da el dato en la direccion de memoria del puntero.
	-	&variable me da la direccion de memoria donde se almacena la variable.
	-	*&variable primero me da la direccion de memoria de la variable con el & y luego saca el dato que esta en esa direccion de memoria con el *, por lo que al final lo que me da es la variable.
	*/ 
	printf("%d\n%p\n%p\n", *pAge, *&pGpa, pGrade);
	return 0;
}
