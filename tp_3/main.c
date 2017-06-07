#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int largo[2]={1,1};

    eMovie* vectorMovies;
    vectorMovies=newMovie();

    while(seguir=='s')
    {

    switch(menu(1,5))
        {
            case 1:
                cargarDatosEnMovie(vectorMovies,largo);
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                listarMovies(vectorMovies,largo);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
