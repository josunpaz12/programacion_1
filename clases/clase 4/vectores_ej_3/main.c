#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int main()
{

    int arrayUno[TAM]={0};
    int val;
    int indice;
    int i;
for(i=0;i<TAM;i++)
{

printf("ingrese valor:");
scanf("%d",&val);

printf("ingrese indice:");
scanf("%d",&indice);

arrayUno[indice]=arrayUno[indice]+val;
}


for(i=0;i<TAM;i++)
{
    printf(" %d -",arrayUno[i]);

}
    return 0;
}
