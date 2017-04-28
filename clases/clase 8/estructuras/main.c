#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    ePersonas* unaPersona;
    cargar(unaPersona);

    printf("Legajo: %d\n",unaPersona->legajo);
    printf("Nombre: %s\n",unaPersona->nombre);
    printf("Sueldo: %f\n",unaPersona->sueldo);
    printf("Sexo: %c\n\n",unaPersona->sexo);

    return 0;
}
