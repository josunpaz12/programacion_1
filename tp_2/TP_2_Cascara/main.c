#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 20
int main()
{
    char seguir='s';
    int opcion=0,auxNum;
    int index,dni;
    ePersona persona [CANT];
    eEdades edades[1];
    inicializarArray(persona,CANT);
    cargaSecuencialDePersonas(persona);

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
                dni=buscarPorDni(persona,auxNum,CANT);
                if(dni==-1)
                {printf("\n\n*El DNI ingresado no se encuentra en la base de datos.\n");
                break;
                }else
                {
                borrarPersona(persona,dni);
                }
                system("pause");
                break;

            case 3:
                ordenarAlfabeticamente(persona,CANT);
                break;

            case 4:
                system("cls");
                contarPorEdad(persona,edades,CANT);
                grafico(edades);
                system("pause");
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
