#include "funciones.h"

int sumar(int x,int y)
{
    int resultado;
    resultado= x + y;
    return resultado;
}


int restar(int x,int y)
{
    int resultado;
    resultado= x - y;
    return resultado;
}


int dividir(int x,int y)
{
    float resultado;
    resultado= x / y;

    return resultado;
}


int multiplicar(int x,int y)
{
    int resultado;
    resultado= x * y;
    return resultado;
}

double factorial(int x)
{
       double respuesta;

        if(x==0 || x==1)
            return 1;

       respuesta= (double)x * factorial (x - 1);

    return respuesta;
}

