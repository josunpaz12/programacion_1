#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"


void ordenarVectorInt(int vec[],int TAM ,int orden)
{
    int i,j,aux;

    if(orden==1)
    {
    for (i=0;i<TAM-1;i++)
    {
        for(j=i+1;j<TAM;j++)
        {
            if(vec[i]>vec[j])
                {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
                }
        }
    }
    }
        if(orden==2)
            for (i=0;i<TAM-1;i++)
        {
            for(j=i+1;j<TAM;j++)
            {
                if(vec[i]<vec[j])
                    {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                    }
            }
        }
    }

