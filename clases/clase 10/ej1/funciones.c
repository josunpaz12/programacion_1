#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <time.h>

void cargarSeries(eSerie series[])
{
   int idSerie[5]={100,101,102,103,104};
    int estado[5]={1,1,1,1,1};
     char titulo[5][30]={"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]={9,7,7,6,1};
    char genero[5][30]={"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};
    int visto[5]={0,0,0,0,0};

    int i;
     for(i=0; i<5;i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
        series[i].visto=visto[i];
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]={"marcos","maria","carlos","luis","romina","juan","andrea","patricia","juan","camila"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
 //   int marca[10]={0,0,0,0,0,0,0,0,0,0};
 //   int idSerie[10]={100,100,101,103,103,101,102,103,100,100};
    int i;

    for(i=0; i<10;i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];
 //       clientes[i].marca=marca[i];
  //      clientes[i].idSerie = idSerie[i];
    }

}


char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

int buscarCoindidenciaClienteSerie(eClienteSerie clienteSerie[],int idCliente,int idSerie,int TAMCS)
{
    int retorno =-1;
    int i;
    for(i=0;i<TAMCS;i++)
    {
        if(clienteSerie[i].idCliente==idCliente && clienteSerie[i].idSerie==idSerie);
        retorno=1;
    }

    return retorno;
}

void cargarClienteSerie(eCliente clientes[], eSerie series[],eClienteSerie clienteSerie[], int TAMCS)
{
    int i;
    int clienteAleatorio;
    int serieAleatorio;



        for(i=0;i<TAMCS;i++)
        {

        clienteAleatorio=getNumeroAleatorio(1,10,0);
        serieAleatorio=getNumeroAleatorio(100,104,0);

        //printf("\n\n en posicion %d el valor de cliente es %d y de serie es %d",i,clienteAleatorio,serieAleatorio);

        if(buscarCoindidenciaClienteSerie(clienteSerie,clienteAleatorio,serieAleatorio,TAMCS))//chequear aca
            {
            clienteSerie[i].idCliente=clienteAleatorio;
            clienteSerie[i].idSerie=serieAleatorio;

            }else
            {
                i--;
            }
    clienteSerie[i].marca=0;

        }




}

void machearNombreSolicitado(eCliente clientes[], eClienteSerie clienteSerie[],int TAMCS, char nombre[])
{
    int i;
    for (i=0;i<TAMCS;i++)
    {
        if(strcmp(clientes[i].nombre,nombre))
        {
            clienteSerie[i].marca=1;
        }
    }

    for(i=0;i<TAMCS;i++)
    {
        if(!clienteSerie[i].marca==1)
        {
        printf("\n El cliente %s ID %d se encuentra mirando: %d \n",nombre,clienteSerie[i].idCliente,clienteSerie[i].idSerie);
        }
    }
}

void mostrarSeries(eSerie serie[],int TAMS)
{
    int i;
    printf("-----------------LISTAR SERIES-----------------\n");
    for(i=0;i<TAMS;i++)
    {
        printf("\n-%s\n",serie[i].titulo);
    }

}


void mostrarClientes(eCliente cliente[], int TAMC)
{
    int i;
    printf("\n\n-----------------LISTAR CLIENTE-----------------\n");
    for(i=0;i<TAMC;i++)
    {
        printf("\n-%s\n",cliente[i].nombre);
    }


}


/*
void mostrarClientesConSerie(eCliente cliente[], eSerie serie[], int TAMC, int TAMS)
{
int i;
int j;
printf("\n\n-----------------LISTAR CLIENTE MIRANDO LA SERIE-----------------\n");

for(i=0;i<TAMC;i++)
{
    for(j=0;j<TAMS;j++)
    {
        if(cliente[i].idSerie==serie[j].idSerie)
            {printf("\n-%s esta mirando %s\n",cliente[i].nombre,serie[j].titulo);
            }
    }
}
}

void mostrarSeriesConClientes(eCliente cliente[], eSerie serie[],eLoser loser[], int TAMC, int TAMS)
{
int i;
int j;
printf("\n\n-----------------LISTAR SERIE POR CLIENTE-----------------\n");

for(i=0;i<TAMS;i++)
{
    printf("\n-%s esta siendo vista por:\n",serie[i].titulo);
    for(j=0;j<TAMC;j++)
    {
        if(serie[i].idSerie==cliente[j].idSerie)
            {printf("%s\n",cliente[j].nombre);
            loser[i].cont=1;
    }
    }
}
}


void mostrarSerieLoser(eLoser loser[],eSerie serie[], int TAMS)
{
int i;
int j;

for(i=0;i<TAMS;i++)
{
loser[i].idSerie=serie[i].idSerie;
}

printf("\n\nLa serie loser es:\n");
for (i=0;i<TAMS;i++)
{
    {
        for(j=0;j<TAMS;j++)
        {
         if(loser[i].idSerie==serie[j].idSerie && loser[i].cont != 1)
            {
                printf("-%s",serie[j].titulo);
            }

        }
    }
}
}


void mostrarClientesTBBT(eCliente cliente[], eSerie serie[], int TAMC, int TAMS)
{
int i;
char auxNomSerie[10];
int auxIdSerie;
printf("\n\nIngrese nombre de la serie y se listaran las personas mirando la misma(TBBT,BB,GOT,AHS,SCD:");
gets(auxNomSerie);

printf("\nLos clientes que ven %s es/son:\n",auxNomSerie);

for(i=0;i<TAMS;i++)
{
    if(!strcmp(auxNomSerie,serie[i].titulo))
        {
            auxIdSerie=serie[i].idSerie;
        }
}

for(i=0;i<TAMC;i++)
{
    if(auxIdSerie==cliente[i].idSerie)
    {
        printf("\n-%s\n",cliente[i].nombre);
    }
}


}
*/

