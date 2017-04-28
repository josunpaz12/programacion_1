#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarArray(ePersona persona [],int cant)
{
    int i;
    for (i=0;i<cant;i++)
    {
        persona[i].estado=-1;
    }
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
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

int buscarPrimeraOcurrencia(ePersona persona[], int CANT)
{
    int index=-1;
    int i;
    for(i=0;i<CANT;i++)
    {
        if (persona[i].estado==-1)
        {
            index=i;
            break;
        }
    }
    return index;
}


void cargarDatosPersona (ePersona persona[],int index)
{
    fflush(stdin);
    char auxDato[40];
    char auxEdadString[10];
    char auxDniString[10];
    int auxEdad;
    int auxDni;
    system("cls");
    printf("ALTA DE PERSONAS.\n\n");


    printf("Ingrese Nombre:");
    gets(auxDato);
    fflush(stdin);
    while(!esSoloLetras(auxDato))
    {
        printf("El nombre ingresado no es valido, por favor reingrese:");
        gets(auxDato);
        fflush(stdin);
    }

    printf("Ingrese Edad:");
    gets(auxEdadString);
    fflush(stdin);

    while(!esNumerico(auxEdadString))
    {
        pedirEdad_Nuevamente:
        printf("La edad ingresada no es valida, por favor reingrese:");
        gets(auxEdadString);
        fflush(stdin);
    }
        auxEdad=atoi(auxEdadString);
        if(auxEdad < 1 || auxEdad > 99)
        goto pedirEdad_Nuevamente;

    printf("Ingrese DNI:");
    gets(auxDniString);
    fflush(stdin);
    while(!esNumerico(auxDniString))
    {
        pedirDni_Nuevamente:
        printf("El DNI ingresado no es valido, por favor reingrese:");
        gets(auxDniString);
        fflush(stdin);
    }
    auxDni=atoi(auxDniString);
    if(auxDni < 15000000 || auxDni > 50000000)
    goto pedirDni_Nuevamente;


    strcpy(persona[index].nombre,auxDato);
    persona[index].edad=auxEdad;
    persona[index].dni=auxDni;
    persona[index].estado=1;
    printf("\n*La persona se agrego correctamente\n\n");
    system("pause");
    system("cls");

}


int buscarPorDni(ePersona lista[], int dni,int CANT)
{
    int i;
    int index = -1;

    for(i=0;i>CANT;i++)
    {
        if(dni==lista[i].dni)
        {
            index = dni;
            break;
        }
    }
    return index;
}


void borrarPersona(ePersona persona[], int dni, int CANT)
{

    char respuesta;
    int dniProcesado;
    dniProcesado=buscarPorDni(persona,dni,CANT);
    if(dniProcesado!=-1)
        {

        printf("\nEsta seguro que desea eliminar el siguiente registro %d? s/n:",dni);
        scanf("%c",&respuesta);
        if(respuesta=='s');
        printf("maravilla");
        system("pause");

        }
    else{
        printf("\n*No se encuentra el dni en la base de datos\n\n");
        system("pause");

    }
}











