#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int largo=0;
    int flag=0;

    eMovie* vectorMovies;
    vectorMovies=newMovie();

    if(vectorMovies!=NULL)
       {
           cargarDatosDesdeArchivo(vectorMovies,&largo);
           flag=1;
       }


    while(seguir=='s' && flag==1)
    {

    switch(menu(1,5))
        {
            case 1:
                cargarDatosEnMovie(vectorMovies,&largo);
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                listarMovies(vectorMovies,&largo);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    if(flag==0)
        printf("*Error:No se puedo reservar espacio en memoria para estructura eMovie\nSe cierra aplicativo\n\n");

    return 0;
}
