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

    cargarDatosDesdeArchivo(vectorMovies,&subIndice,&largo);

    while(seguir=='s')
    {
    switch(menu(1,5))
        {
            case 1:
                vectorMovies = (eMovie*)realloc(vectorMovies,sizeof(eMovie)*largo);
                if(vectorMovies!=NULL)
                    {
                        cargarDatosEnMovie(vectorMovies,&subIndice,&largo);
                    }
                break;
            case 2:
                guardarDatosEnArchivo(vectorMovies,&subIndice,&largo);
                break;
            case 3:
               break;
            case 4:
                listarMovies(vectorMovies,&subIndice);
                break;
            case 5:
                free(vectorMovies);
                seguir = 'n';
                break;
        }
    }

    return 0;
}
