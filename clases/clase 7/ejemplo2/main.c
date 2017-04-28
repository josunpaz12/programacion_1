#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombres[5][20], auxString[50];
    int legajos[5];
    int i,j;

    for(i=0;i<5;i++)
    {
     printf("Ingrese los nombres:");
     fflush(stdin);
     gets(nombres[i]);
    }

    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(strcmp(nombres[i],nombres[j])<0)
            {
                strcpy(auxString,nombres[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j],auxString);

            }//else acomodamiento doble

        }
    }

    for(i=0;i<5;i++)
    {
        printf("%s\n",nombres[i]);
    }

    return 0;
}
