#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

void cargaSecuencialDePersonas(ePersona persona[])
{

    char nombre[20][50]={"carlos","ailen","belen","abigail","juan","mariana","alexandra","federico","paola","patricio","maria del carmen","nicolas","beatriz","zao","mauricio","lucas","esquivel","justin","bieber","mada faca"};
    int edad[20]={30,25,14,6,2,9,32,55,63,42,23,73,14,64,74,24,2,5,8,55};
    int dni[20]={39549852,32364983,43826274,41123654,24234654,23643234,43254879,46234129,41543239,36123549,39549859,32364989,43826279,41123659,24234659,23643239,43254879,46234129,41543239,36123549};
    int estado[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


    int i;
    for(i=0;i<20;i++)
    {
        strcpy(persona[i].nombre,nombre[i]);
        persona[i].edad=edad[i];
        persona[i].dni=dni[i];
        persona[i].estado=estado[i];
    }
}

int buscarPorDni(ePersona persona[], int dni ,int CANT)
{
    int i;
    int retorno=-1;

    for (i=0;i<CANT;i++)
    {
        if(dni==persona[i].dni)
        {
            retorno=i;
            break;
        }

    }
    return retorno;
}

void borrarPersona(ePersona persona[],int index)
{
    char resp;
    printf("\nEsta seguro que quiere borrar este registro?(s/n):");
    fflush(stdin);
    scanf("%c",&resp);
    if(resp=='s')
    {
    persona[index].estado=0;
    printf("\n\n*La persona se borro correctamente.\n");
    }else
    {printf("\n\n*El registro no se elimino\n");
    }

}

void ordenarAlfabeticamente(ePersona persona [], int CANT)
{
    int i,j;
    char aux[50];
    int auxNum;


    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(persona[i].estado==1 && persona[j].estado==1)
                {
                if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                {
                strcpy(aux,persona[i].nombre);
                strcpy(persona[i].nombre,persona[j].nombre);
                strcpy(persona[j].nombre,aux);

                auxNum=persona[i].edad;
                persona[i].edad=persona[j].edad;
                persona[j].edad=auxNum;

                auxNum=persona[i].dni;
                persona[i].dni=persona[j].dni;
                persona[j].dni=auxNum;

                }
            }

        }
    }


    system("cls");
    printf("------LISTAR POR NOMBRE ORDENADOS ALFABETICAMENTE------\n\nEdad\tDni\t\tNombre");

    for (i=0;i<CANT;i++)
    {
        if(persona[i].estado==1)
        printf("\n%d\t%d\t%s\n",persona[i].edad,persona[i].dni,persona[i].nombre);
    }

    system("pause");


}
void contarPorEdad (ePersona persona[],eEdades edades[],int CANT)
{
    int i;
    edades[0].menor18=0;
    edades[0].entre18y35=0;
    edades[0].mayor35=0;

    for (i=0;i<CANT;i++)
    {
        if(persona[i].estado==1 && persona[i].edad<18)
        {
            edades[0].menor18=edades[0].menor18+1;
        }
        else if (persona[i].estado==1 && persona[i].edad>35)
        {
            edades[0].mayor35=edades[0].mayor35+1;
        }
        else if (persona[i].estado==1 && persona[i].edad>=18 && persona[i].edad<=35)
        {
            edades[0].entre18y35=edades[0].entre18y35+1;
        }
    }

}


void grafico (eEdades edades[])
{
    int max=0;
    int i=0;

    if(edades[0].menor18>=edades[0].mayor35 && edades[0].menor18>=edades[0].entre18y35)
    {
        max=edades[0].menor18;
    }
    else if(edades[0].mayor35>=edades[0].menor18 && edades[0].mayor35>=edades[0].entre18y35)
    {
        max=edades[0].mayor35;
    }
    else if(edades[0].entre18y35>=edades[0].menor18 && edades[0].entre18y35>=edades[0].mayor35)
    {
        max=edades[0].entre18y35;
    }

    for (i=max;i>0;i--)
    {
        printf("%d|",i);
        int flag=0;

        if(i<=edades[0].menor18)
        {
            printf("*");
        }
        if (i<=edades[0].entre18y35)
        {
            printf("\t*");
            flag=1;
        }
        if (i<=edades[0].mayor35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            if(flag==1)
            {
                printf("\t*");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("<18\t18-35\t>35");
    printf("\n");
    printf("%d\t %d \t%d\n",edades[0].menor18,edades[0].entre18y35,edades[0].mayor35);
    printf("\n");
}
