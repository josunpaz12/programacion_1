#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int main()
{
    int i,j;
    int vec[TAM]={5,8,1,3,7};
    int aux;
    for (i=0;i<TAM-1;i++)
    {
        for(j=i+1;j<TAM;j++)
        {
            if(vec[j]<vec[i])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }

        }



    }

    printf("Vector ordenado de forma ascendente:\n\n");

    for(i=0;i<TAM;i++)
    {
        printf("El vector en la posicion %d tiene valor: %d\n",i,vec[i]);
    }


    return 0;
}
