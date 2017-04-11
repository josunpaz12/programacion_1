#include <stdio.h>
#include <stdlib.h>
#define TAM 3
int main()
{
    char seguir='s';
    int leg[TAM], edad[TAM], nota[TAM];
    int opc, i, auxLeg, maxNot, prom, promAux=0;
    int flag=0;

 do
    {
        printf("1. Ingreso de datos\n2.Busqueda por legajo\n3.maximo\n4.listar por promedio\n5. Listar todos\n6.salir\n");
        scanf("%d", &opc);
        switch(opc)
        {
        case 1:
            for(i=0;i<TAM;i++)
            {
            printf("Inbrese numero de legajo:");
            scanf("%d",&leg[i]);
            printf("Inbrese edad:");
            scanf("%d",&edad[i]);
            printf("Inbrese nota:");
            scanf("%d",&nota[i]);
            }
            break;
        case 2:
            printf("Ingrese numero de legajo:");
            scanf("%d",&auxLeg);
            for(i=0;i<TAM;i++)
            {
                if(auxLeg==leg[i])
                {
                    printf("Para numero de legajo:%d",leg[i]);
                    printf("\nedad:%d",edad[i]);
                    printf("\nnota:%d\n",nota[i]);
                    break;
                }
            }
            break;
        case 3:
            for(i=0;i<TAM;i++)
            {
                if(flag==0)
                {
                  maxNot=nota[i];
                  flag=1;
                }
                if(nota[i]>maxNot)
                {
                    maxNot=nota[i];
                }

            }

            for(i=0;i<TAM;i++)
            {
                if(maxNot==nota[i])
                    {
                        printf("Legajo:%d\n",leg[i]);
                        printf("edad:%d\n",edad[i]);
                        printf("nota:%d\n\n\n",nota[i]);
                    }


            }


            break;
        case 4:
            for(i=0;i<TAM;i++)
            {
                promAux=nota[i]+promAux;
            }
            prom=promAux/TAM;
            printf("\nPROMEDIO:%d\n\n",prom);
            for(i=0;i<TAM;i++)
            {
                if(nota[i]>=prom)
                {
                    printf("Legajo:%d\n",leg[i]);
                    printf("edad:%d\n",edad[i]);
                    printf("nota:%d\n\n\n",nota[i]);
                }
            }
            break;
        case 5:
            for(i=0;i<TAM;i++)
            {
                    printf("Legajo:%d\n",leg[i]);
                    printf("edad:%d\n",edad[i]);
                    printf("nota:%d\n\n\n",nota[i]);

            }
            break;
        case 6:
            seguir='n';
            break;




        }
    system("pause");
    system("cls");

    }while(seguir=='s');

    return 0;
}
