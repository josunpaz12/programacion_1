#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char apellido[30];
    char nomape[51]={""};
    char buffer[100];
    int i;

    printf("Ingrese nombre:");
    gets(buffer);
    while(strlen(buffer)>19)
    {
        printf("El nombre excede el el maximo de caracteres permitidos, ingrese un nombre valido:");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(nombre,buffer);

    printf("Ingrese apellido:");
    gets(buffer);
    while(strlen(buffer)>29)
    {
        printf("El apellido excede el maximo de caracteres permitidos, por favor reingrese apellido:");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(apellido,buffer);

strcat(nomape,apellido);
strcat(nomape,", ");
strcat(nomape,nombre);
strlwr(nomape);
nomape[0]=toupper(nomape[0]);

for(i=0;nomape[i]!='\0';i++)
{
    if (nomape[i]==' ')
    {
        nomape[i+1]=toupper(nomape[i+1]);
    }
}

printf("%s",nomape);





    return 0;
}
