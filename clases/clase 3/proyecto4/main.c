#include <stdio.h>
#include <stdlib.h>

void suma();

int main()
{
   suma();
    return 0;
}


void suma()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese el primer numero:");
    scanf("%d",&num1);

    printf("Ingrese el segundo numero:");
    scanf("%d",&num2);

    resultado=num1+num2;

    printf("El resultado es:%d",resultado);



}
