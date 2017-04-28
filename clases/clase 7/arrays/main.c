#include <stdio.h>
#include <stdlib.h>
#include <string.h>//recordar incluir libreria

int main()
{
    char nombre[20]={"juan"};
    char auxCad[100];
    printf("Ingrese nombre:");
    gets(auxCad);
    while(strlen(auxCad)>19) //strlen cantidad de caracteres
    {
      printf("Nombre demasiado grande, reingrese nombre:");
      fflush(stdin);//stdin buffer del teclado
      gets(auxCad);
    }
    strcpy(nombre,auxCad);

    strcmp(cadena1,cadena2);//compara cadena 1 con cadena 2 - si 1 es mayor 1 si es menor -1 si es igual 0
    strcat(cadena2,cadena1);// contatena
    return 0;
}
