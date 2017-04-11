#include "funciones.h"

int sumar(float x,float y)
{
    float resultado;
    resultado= x + y;
    return resultado;
}


int restar(float x,float y)
{
    float resultado;
    resultado= x - y;
    return resultado;
}


int dividir(float x,float y)
{
    float resultado;
    resultado= x / y;

    return resultado;
}


int multiplicar(float x,float y)
{
    float resultado;
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

