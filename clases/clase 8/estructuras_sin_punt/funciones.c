#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void mostrar(ePersonas unaPersona)
{
    printf("Legajo: %d\n",unaPersona.legajo);
    printf("Nombre: %s\n",unaPersona.nombre);
    printf("Sueldo: $%f\n",unaPersona.sueldo);
    printf("Sexo: %c\n",unaPersona.sexo);
    printf("Fecha de nacimiento: %d/%d/%d\n\n",unaPersona.fnac.dia,unaPersona.fnac.mes,unaPersona.fnac.anio);

}

int validarNumeros(int valor,int max,int min)
{
    int retorno=1;

    if(valor<min || valor > max)
    {
        retorno=0;
    }
    return retorno;
}


