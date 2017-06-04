#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

EMovie* newMovie()
{
    EMovie* movie = NULL;
    movie = malloc(sizeof(EMovie));
    return movie;
}


int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


int menu (int minimo, int maximo)
{
    char dato[10];
    int opc;
    system("cls");
    printf("1- Agregar pelicula\n2- Borrar pelicula\n3- Generar pagina web\n4- Salir\n");
    gets(dato);
    fflush(stdin);

    while(!esNumerico(dato))
    {
        pedirNuevamente:
        printf("La opcion ingresada es incorrecta, por favor reingrese:");
        gets(dato);
        fflush(stdin);
    }
    opc = atoi(dato);
    if (opc < minimo || opc > maximo)
    {
        goto pedirNuevamente;
    }
    return opc;
}
