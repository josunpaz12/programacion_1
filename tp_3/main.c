#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';

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
