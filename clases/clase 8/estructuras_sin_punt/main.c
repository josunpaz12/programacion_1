#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
   ePersonas unaPersona;
   ePersonas otraPersona;



    printf("Ingrese Legajo:");
    scanf("%d",&unaPersona.legajo);
    fflush(stdin);
    printf("Ingrese Nombre:");
    gets(unaPersona.nombre);
    printf("Ingrese Sueldo:");
    scanf("%f",&unaPersona.sueldo);
    fflush(stdin);
    printf("Ingrese sexo(f o m):");
    scanf("%c",&unaPersona.sexo);

    printf("Ingrese dia de nacimiento:");
    scanf("%d",&unaPersona.fnac.dia);
    while(!validarNumeros(unaPersona.fnac.dia,31,1))
    {
    printf("Reingrese dia de nacimiento:");
    scanf("%d",&unaPersona.fnac.dia);
    }


    printf("Ingrese mes de nacimiento:");
    scanf("%d",&unaPersona.fnac.mes);
    while(!validarNumeros(unaPersona.fnac.mes,12,1))
    {
    printf("Reingrese mes de nacimiento:");
    scanf("%d",&unaPersona.fnac.mes);
    }


    printf("Ingrese anio de nacimiento:");
    scanf("%d",&unaPersona.fnac.anio);
    while(!validarNumeros(unaPersona.fnac.anio,2015,1940))
    {
    printf("Reingrese anio de nacimiento:");
    scanf("%d",&unaPersona.fnac.anio);
    }

    mostrar(unaPersona);


    //atoi(cadena de caracteres);
    //variable entera( array);


    return 0;
}
