#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

eMovie* newMovie()
{
    eMovie* movie = NULL;
    movie = malloc(sizeof(eMovie));
    return movie;
}

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


int menu (int minimo, int maximo)
{
    char dato[10];
    int opc;
    system("cls");
    printf("1- Agregar pelicula\n2- Borrar pelicula\n3- Generar pagina web\n4- Listar pelis\n5- Salir\n\nEleccion:");
    gets(dato);
    fflush(stdin);

    while(!esNumerico(dato))
    {
        pedirNuevamente:
        printf("La opcion ingresada es incorrecta, por favor reingrese:");
        gets(dato);
        fflush(stdin);
    }
    opc = atoi(dato);
    if (opc < minimo || opc > maximo)
    {
        goto pedirNuevamente;
    }
    return opc;
}

void cargarDatosEnMovie(eMovie* movie,int largo[])
{
    system("cls");
    fflush(stdin);
    eMovie* auxMovie;
    char auxNombre[20];
    char auxGenero[20];
    char auxDescripcion[50];
    char auxLinkImagen[50];
    char auxDuracionString[10];
    int auxDuracion;
    char auxPuntajeString[10];
    int auxPuntaje;
    int auxLargo;
    auxLargo=largo[0]-1;
    char rta;


/*
    if(auxLargo>0)
    {
    auxMovie = (eMovie*)realloc(movie,sizeof(eMovie)*(auxLargo+1));
    printf("pasa por aqui");
    if(auxMovie!=NULL)
    {
        movie=auxMovie;
        printf("realoco bien");
    }

    }

*/
//ralloca solo :/


    printf("AGREGAR PELICULA.\n\n");


    printf("\nIngrese Nombre:");
    gets(auxNombre);
    fflush(stdin);
    while(!esAlfaNumerico(auxNombre))
    {
        printf("\n*El nombre ingresado no es valido, por favor reingrese:");
        gets(auxNombre);
        fflush(stdin);
    }

    printf("\nIngrese genero:");
    gets(auxGenero);
    fflush(stdin);
    while(!esSoloLetras(auxGenero))
    {
        printf("\n*El genero ingresado no es valido, por favor reingrese:");
        gets(auxGenero);
        fflush(stdin);
    }

    printf("\nIngrese breve descripcion:");
    gets(auxDescripcion);
    fflush(stdin);
    while(!esSoloLetras(auxDescripcion))
    {
        printf("\n*La descripcion ingresada no es valida, por favor reingrese(recuerde ingresar solo letras:");
        gets(auxDescripcion);
        fflush(stdin);
    }

    printf("\nIngrese link de la imagen:");
    gets(auxLinkImagen);
    fflush(stdin);


    printf("\nIngrese puntaje del 1 al 10:");
    gets(auxPuntajeString);
    fflush(stdin);

    while(!esNumerico(auxPuntajeString))
    {
        pedirPuntaje_Nuevamente:
        printf("\n*El valor ingresado no es valido, por favor reingrese recuerde que debe ser en el rango del 1 al 10:");
        gets(auxPuntajeString);
        fflush(stdin);
    }
        auxPuntaje=atoi(auxPuntajeString);
        if(auxPuntaje < 1 || auxPuntaje > 10)
        goto pedirPuntaje_Nuevamente;

    printf("\nIngrese duracion de la pelicula:");
    gets(auxDuracionString);
    fflush(stdin);

    while(!esNumerico(auxDuracionString))
    {
        pedirDato_Nuevamente:
        printf("\n*El valor ingresado no es valido(entre 1 y 240), recuerde que se ingresa en minutos, por favor reingrese:");
        gets(auxDuracionString);
        fflush(stdin);
    }
    auxDuracion=atoi(auxDuracionString);
    if(auxDuracion < 1 || auxDuracion > 240)
    goto pedirDato_Nuevamente;

    printf("Desea agregar la siguiente pelicula:(s/n)\n-Nombre:%s\n-Genero:%s\n-Descripcion:%s\n-Link de imagen:%s\n-Puntaje:%d\n-Duracion:%d\n\n",auxNombre,auxGenero,auxDescripcion,auxLinkImagen,auxPuntaje,auxDuracion);
    scanf("%c",&rta);

    if(rta=='s')
    {
        strcpy(movie[auxLargo].titulo,auxNombre);
        strcpy(movie[auxLargo].genero,auxGenero);
        strcpy(movie[auxLargo].descripcion,auxDescripcion);
        strcpy(movie[auxLargo].linkImagen,auxLinkImagen);
        movie[auxLargo].puntaje=auxPuntaje;
        movie[auxLargo].duracion=auxDuracion;
        movie[auxLargo].estado=1;
        largo[0]=largo[0]+1;

        printf("\n*La pelicula se cargo correctamente.\n\n");
        system("pause");
    }else{
    printf("\n*Se cancelo la carga.\n\n");
    system("pause");
    }
    system("cls");

}

void listarMovies(eMovie* vectorMovies,int largo[])
{
    int auxLargo;
    int i;
    auxLargo=largo[0]+1;

    printf("\nTITULOS:\n\n");
    for(i=0;i<auxLargo;i++)
    {
        //if(vectorMovies[i].estado == 1)
            printf("--> %s\n",vectorMovies[i].titulo);
    }
    system("pause");
}



