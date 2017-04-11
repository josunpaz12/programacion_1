#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int num;
    float num1=0;
    float num2=0;
    float rta;
    float fact;
    float auxFloat;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A=%.2f)\n",num1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando: ");
                scanf("%f",&num1);
                break;

            case 2:
                printf("Ingrese el segundo operando: ");
                scanf("%f",&num2);
                break;

            case 3:
                rta=sumar(num1,num2);
                printf("\nEl resultado de la suma es:%.2f\n",rta);
                system("pause");
                break;
            case 4:
                rta=restar(num1,num2);
                if(rta!=0)
                {
                printf("\nEl resultado de la resta es:%.2f\n",rta);
                system("pause");
                break;
                }
                break;
            case 5:
                if(num2==0)
                {
                    printf("\nEl segundo operando no puede ser 0\n");
                }else
                {
                auxFloat=dividir(num1,num2);
                printf("\nEl resultado de la division es:%.2f\n",auxFloat);
                system("pause");
                }
                break;
            case 6:
                rta=multiplicar(num1,num2);
                printf("\nEl resultado de la multiplicacion es:%.2f\n",rta);
                system("pause");
                break;
            case 7:
                fact=factorial(num1);
                printf("\nEl factorial de %.2f es %.2f \n",num1,fact);
                system("pause");
                break;
            case 8:

                rta=sumar(num1,num2);
                printf("\nEl resultado de la suma es:%.2f\n",rta);

                rta=restar(num1,num2);
                if(rta!=0)
                {
                printf("\nEl resultado de la resta es:%.2f\n",rta);
                }

                if(num2==0)
                {
                    printf("\nEl segundo operando no puede ser 0\n");
                }else
                {
                auxFloat=dividir(num1,num2);
                printf("\nEl resultado de la division es:%.2f\n",auxFloat);
                }

                rta=multiplicar(num1,num2);
                printf("\nEl resultado de la multiplicacion es:%.2f\n",rta);

                num=num1;
                fact=factorial(num1);
                printf("\nEl factorial de %.2f es %.2f \n\n",num1,fact);
                system("pause");

                break;
            case 9:
                seguir = 'n';
                break;
        }

}
    return 0;
}
