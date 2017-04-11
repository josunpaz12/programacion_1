#include <stdio.h>
#include <stdlib.h>

int main()
{
 int numeros[5];
 int i;

 for(i=0;i<5;i++)
 {
     printf("\nIngrese un valor para el numero %d:",i+1);
     scanf("%d",&numeros[i]);
 }

for(i=4;i>-1;i--)
{
    printf(" %d ",numeros[i]);
}

    return 0;
}
