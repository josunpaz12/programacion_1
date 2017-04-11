#include <stdio.h>
#include <stdlib.h>
#define A 3



int main()
{

    //tipo_dato identificador[A];

    int edades[A]= {0}, legajos[A], auxEdad, pos, flagMaximo = 0, maxProm, auxLeg,  flagEncontro=0, opcion;
    float promedios[A], promedio, suma=0;
    int i;
    char seguir='s';

    /*for(i=0; i<8; i++)
    {
        edades[i] = 0;
    }*/

    do
    {
        printf("1. Ingreso de datos\n2.Busqueda por legajo\n3.maximo\n4.listar por promedio\n5. Listar todos\n6.salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            for(i=0; i<A; i++)
            {
                printf("Ingrese legajo: ");
                scanf("%d", &legajos[i]);
                printf("Ingrese una edad: ");
                scanf("%d", &edades[i]);
                printf("Ingrese promedio: ");
                scanf("%f", &promedios[i]);
            }
            break;
        case 2:
            printf("Ingrese legajo a buscar: ");
            scanf("%d", &auxLeg);


            for(i=0; i<A; i++)
            {
                if(legajos[i]==auxLeg)
                {
                    printf("%d\t%d\t%f\n",legajos[i], edades[i], promedios[i]);
                    flagEncontro=1;
                    break;
                }


            }
            if(flagEncontro==0)
            {
                printf("Legajo inexistente");
            }
            flagEncontro=0;
            break;
        case 3:
            for(i=0; i<A; i++)
            {
                if(flagMaximo ==0 || promedios[i]>maxProm)
                {
                    maxProm = promedios[i];
                    flagMaximo = 1;
                }
            }
            for(i=0; i<A; i++)
            {
                if(promedios[i]==maxProm)
                {
                    printf("%d\t%d\t%f\n",legajos[i], edades[i], promedios[i]);
                }
            }
            break;

        case 4:

            for(i=0; i<A; i++)
            {
                suma+=promedios[i];
            }
            promedio = suma/A;
            printf("Promedio superior al promedio general\n");
            for(i=0; i<A; i++)
            {
                if(promedios[i]>promedio)
                {
                    printf("%d\t%d\t%f\n",legajos[i], edades[i], promedios[i]);
                }
            }
             //suma=0;
            break;
        case 5:
            for(i=0; i<A; i++)
            {

                printf("%d\t%d\t%f\n",legajos[i], edades[i], promedios[i]);

            }
            break;
        case 6:
            seguir='n';
            break;




        }
    system("pause");
    system("cls");

    }
    while(seguir=='s');





    //Carga Secuencial








    /*





    printf("\n alumnos con el maximo");


    */


    return 0;
}


/*do
    {
        printf("Ingrese la posicion: 1-8");
        scanf("%d", &pos);
        while(pos>8 || pos<1)
        {
            printf("reingrese la posicion: 1-8");
            scanf("%d", &pos);
        }
        printf("Ingrese edad: ");
        scanf("%d", &edades[pos-1]);


        /*printf("Ingrese edad: ");
         scanf("%d", &auxEdad);
         printf("Ingrese la posicion: 1-8");
         scanf("%d", &pos);
         edades[pos-1] = auxEdad;

        printf("Desea continuar? s/n");
        seguir = getche();

    }
    while(seguir=='s');
*/





/* edades[4]=8;
    edades[7]=10;
    edades[0]=5;
    printf("0 - %d\n", edades[0]);
    printf("4 - %d\n", edades[4]);
    printf("7 - %d\n", edades[7]);*/
