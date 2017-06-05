#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';

    FILE* path;
    EMovie* movies;

    path = fopen("peliculas.dat","rb");
    if(path == NULL)
    {
        path = fopen("peliculas.dat", "wb");
    }

    if(path!=NULL)
    {
        movies = newMovie();
        if(movies!=NULL)
        {
            while(!feof(path))
            {
                fread(movies, sizeof(EMovie), 1, path);
            }

        }
    }

    while(seguir=='s')
    {

    switch(menu(1,4))
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
