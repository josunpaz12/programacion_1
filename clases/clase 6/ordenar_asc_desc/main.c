#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
#define TAM 5
int main()
{
    int i;
    int vec[TAM]={15,35,92,16,65};
    for(i=0;i<TAM;i++)
    {
        printf("El vector sin orden en el indice %d es: %d\n",i,vec[i]);
    }

    ordenarVectorInt(vec,TAM,1);

    for(i=0;i<TAM;i++)
    {
        printf("El vector ordenado de manera ascendente en el indice %d es: %d\n",i,vec[i]);
    }

    ordenarVectorInt(vec,TAM,2);
    printf("\n\n");
    for(i=0;i<TAM;i++)
    {
        printf("El vector ordenado de manera descendente en el indice %d es: %d\n",i,vec[i]);
    }


    return 0;
}
