#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void cargar(ePersonas* unaPersona)
{
    printf("Ingrese Legajo:");
    scanf("%d",&unaPersona->legajo);
    fflush(stdin);
    printf("Ingrese Nombre:");
    gets(unaPersona->nombre);
    printf("Ingrese Sueldo:");
    scanf("%f",&unaPersona->sueldo);
    fflush(stdin);
    printf("Ingrese sexo(f o m):");
    scanf("%c",&unaPersona->sexo);

}
