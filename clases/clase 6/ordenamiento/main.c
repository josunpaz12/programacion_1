#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{

 char nombre[20];

    printf("Ingrese su nombre:");
    gets(nombre);
    //scanf("%s",nombre);

    printf("usted se llama %s",nombre);
    return 0;
}
