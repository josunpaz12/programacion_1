#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAMS 5
#define TAMC 10
/*
2- mostrar cada uno
3- mostrar clientes con su serie
4- por cada serie los clientes que la estan viendo
5- todos los clientes que ven TBBT (100)
6- La serie menos popular

Crear una cuarta estructura que permita relacionar un cliente con una serie, de esta manera podremos obtener una relacion
muchos a muchos (Un cliente que ve muchas series)

7- Todas las series que ven los clientes de nombre "Juan"
*/

int main()
{

    eSerie series[TAMS];
    eCliente clientes[TAMC];
    eLoser loser[TAMS];

    cargarSeries(series);
    cargarClientes(clientes);

    mostrarSeries(series, TAMS);
    mostrarClientes(clientes, TAMC);

    mostrarClientesConSerie(clientes, series, TAMC,TAMS);

    mostrarSeriesConClientes(clientes,series,loser,TAMC,TAMS);

    mostrarSerieLoser(loser,series,TAMS);

    mostrarClientesTBBT(clientes, series,TAMC,TAMS);

    return 0;
}
