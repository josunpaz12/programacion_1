#include <stdio.h>
#include <stdlib.h>

void suma(int,int);


int main()
{
    int num1;
    int num2;

    printf("ingrese el primer numero: ");
    scanf("%d",&num1);

    printf("ingrese el segundo numero: ");
    scanf("%d",&num2);

    suma(num1,num2);

    return 0;

}

void suma(int num1, int num2)
{
    int rta;
    rta=num1+num2;
    printf("El resultado es: %d",rta);

}
