#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int subIndice=0;
    int largo=1;
    eMovie* vectorMovies;
    vectorMovies=newMovie();

    vectorMovies=cargarDatosDesdeArchivo(vectorMovies,&largo);
    subIndice=largo-1;

    while(seguir=='s')
    {
    switch(menu(1,4))
        {
            case 1:
                if(largo>1)
                vectorMovies=(eMovie*)realloc(vectorMovies,sizeof(eMovie)*largo);
                cargarDatosEnMovie(vectorMovies,&subIndice,&largo);
                break;
            case 2:
                listarMovies(vectorMovies,&largo);
                borrarPeli(vectorMovies,&largo);
                break;
            case 3:
                generarWeb(vectorMovies,&largo);
               break;
            case 4:
                guardarMoviesEnArchivo(vectorMovies,&largo);
                free(vectorMovies);
                seguir = 'n';
                break;
        }
    }

    return 0;
}
