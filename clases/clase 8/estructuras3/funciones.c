#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void mostrar(ePersonas  unaPersona[])
{
    int i;

    for(i=0;i<3;i++)
    {
    printf("Legajo: %d\n",unaPersona[i].legajo);
    printf("Nombre: %s\n",unaPersona[i].nombre);
    printf("Sueldo: $%f\n",unaPersona[i].sueldo);
    printf("Sexo: %c\n",unaPersona[i].sexo);
    printf("Fecha de nacimiento: %d/%d/%d\n\n",unaPersona[i].fnac.dia,unaPersona[i].fnac.mes,unaPersona[i].fnac.anio);

    }

}

