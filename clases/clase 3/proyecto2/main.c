#include <stdio.h>
#include <stdlib.h>

int sumar (int,int);

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese el primer numero:");
    scanf("%d",&num1);

    printf("Ingrese el segundo numero:");
    scanf("%d",&num2);

    resultado=sumar(num1,num2);

    printf("el resultado es:%d",resultado);

    return 0;
}

int sumar (int x, int y)
{
    int resultado;

    resultado=x+y;

    return resultado;
}

