#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 2
int main()
{
    char seguir='s';
    int opcion=0,auxNum;
    int index;
    ePersona persona [CANT];
    inicializarArray(persona,CANT);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                index=buscarPrimeraOcurrencia(persona,CANT);
                if(index!=-1)
                {
                cargarDatosPersona(persona,index);
                }else{
                    printf("\n*No hay mas espacio para agregar personas\n");
                    system("pause");}
                break;

            case 2:
                system("cls");
                printf("\nBORRAR PERSONA:\n\nIngrese dni:");
                scanf("%d",&auxNum);
                borrarPersona( persona,auxNum,CANT);
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
