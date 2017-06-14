#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

eMovie* newMovie()
{
    return (eMovie*) malloc(sizeof(eMovie));

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
    printf("1- Agregar pelicula\n2- Borrar pelicula\n3- Generar pagina web\n4- Salir\n\nEleccion:");
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


void cargarDatosEnMovie(eMovie* vectorMovies,int* subIndice,int*largo)
{
    system("cls");
    fflush(stdin);
    char auxNombre[20];
    char auxGenero[20];
    char auxDescripcion[50];
    char auxLinkImagen[50];
    char auxDuracionString[10];
    int auxDuracion;
    char auxPuntajeString[10];
    int auxPuntaje;
    char rta;


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
    while(!esAlfaNumerico(auxDescripcion))
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
        strcpy(vectorMovies[(*subIndice)].titulo,auxNombre);
        strcpy(vectorMovies[*subIndice].genero,auxGenero);
        strcpy(vectorMovies[*subIndice].descripcion,auxDescripcion);
        strcpy(vectorMovies[*subIndice].linkImagen,auxLinkImagen);
        vectorMovies[*subIndice].puntaje=auxPuntaje;
        vectorMovies[*subIndice].duracion=auxDuracion;
        vectorMovies[*subIndice].estado=1;
        (*largo)++;
        (*subIndice)++;
        printf("\n*La pelicula se cargo correctamente.\n\n");
        system("pause");
    }else
        {
        printf("\n*Se cancelo la carga.\n\n");
        system("pause");
        }
    fflush(stdin);
}




void listarMovies(eMovie* vectorMovies,int*largo)
{
    int i;
    system("cls");
    printf("\nTITULOS:\n");
    for(i=0;i<(*largo-1);i++)
    {
        if(vectorMovies[i].estado == 1)
         {
            printf("\n\n%d--> %s\n",i,vectorMovies[i].titulo);
        }

    }
}

void guardarMoviesEnArchivo(eMovie* vectorMovies,int* largo)
{
    FILE* fArchivo;
    fArchivo=fopen("archivo.bin","wb");

    if(fArchivo!=NULL)
    {
        fwrite(largo,sizeof(int),1,fArchivo);
        fwrite(vectorMovies,sizeof(eMovie),(*largo),fArchivo);
        fclose(fArchivo);
    }

}

eMovie* cargarDatosDesdeArchivo(eMovie* vectorMovies,int* largo)
{
    FILE* fArchivo;
    int i=0;
    fArchivo=fopen("archivo.bin","rb");

    if(fArchivo!=NULL)
    {
        printf("largo vale %d",*largo);
        fread(largo,sizeof(int),1,fArchivo);
        vectorMovies=(eMovie*)realloc(vectorMovies,sizeof(eMovie)*(*largo));

        while(!feof(fArchivo))
        {
            fread((vectorMovies+i),sizeof(eMovie),1,fArchivo);
            i++;
        }
    fclose(fArchivo);
    }
    return vectorMovies;
}

void generarWeb(eMovie vectorMovies[],int* largo)
{
    int i;
    char primerBloque[]={"<!DOCTYPE html>"};
    char primerBloque2[]={"<html lang='en'>"};
    char primerBloque3[]={"<head>"};
    char primerBloque4[]={"    <meta charset='utf-8'>"};
    char primerBloque5[]={"    <meta http-equiv='X-UA-Compatible' content='IE=edge'>"};
    char primerBloque6[]={"    <meta name='viewport' content='width=device-width, initial-scale=1'>"};
    char primerBloque7[]={"    <title>Pagina WEB peliculas</title>"};
    char primerBloque8[]={"    <link href='css/bootstrap.min.css' rel='stylesheet'>"};
    char primerBloque9[]={"    <link href='css/custom.css' rel='stylesheet'>"};
    char primerBloque10[]={"</head>"};
    char primerBloque11[]={"<body>"};
    char primerBloque12[]={"    <div class='container'>"};

    char segundoBloque[]={"<div class='row'>"};
    char segundoBloque2[]={"<article class='col-md-4 article-intro'>"};
    char segundoBloque3[]={"<a href='#'>"};
    char segundoBloque4[]={"<img class='img-responsive img-rounded'  src='"};
    char segundoBloque5[]={"' alt='Sin Imagen! "};
    char segundoBloque6[]={"</a>"};
    char segundoBloque7[]={"<h3>"};
    char segundoBloque8[]={"<a href='#'>"};
    char segundoBloque9[]={"</a>"};
    char segundoBloque10[]={"</h3>"};
    char segundoBloque11[]={"<ul>"};
    char segundoBloque12[]={"<li>Genero:"};
    char segundoBloque13[]={"</li>"};
    char segundoBloque14[]={"<li>Puntaje:"};
    char segundoBloque15[]={"</li>"};
    char segundoBloque17[]={"<li>Duracion:"};
    char segundoBloque18[]={"</ul>"};
    char segundoBloque19[]={"</p>"};
    char segundoBloque20[]={"<p>"};
    char segundoBloque21[]={"</article>"};
    char segundoBloque22[]={"</div>"};

    char tercerBloque[]={"    </div>"};
    char tercerBloque2[]={"    <script src='js/jquery-1.11.3.min.js'></script>"};
    char tercerBloque3[]={"    <script src='js/bootstrap.min.js'></script>"};
    char tercerBloque4[]={"	<script src='js/ie10-viewport-bug-workaround.js'></script>"};
    char tercerBloque5[]={"	<script src='js/holder.min.js'></script>"};
    char tercerBloque6[]={"</body>"};
    char tercerBloque7[]={"</html>"};


    FILE* fArchiveHTML;
    fArchiveHTML = fopen("template/index.html","w");
    if(fArchiveHTML!=NULL)
    {

		fprintf(fArchiveHTML,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",primerBloque,primerBloque2,primerBloque3,primerBloque4,primerBloque5,primerBloque6,primerBloque7,primerBloque8,primerBloque9,primerBloque10,primerBloque11,primerBloque12);


		for(i=0;i<(*largo);i++)
        {
            if(vectorMovies[i].estado==1)
            {
				fprintf(fArchiveHTML,"%s\n%s\n%s\n%s",segundoBloque,segundoBloque2,segundoBloque3,segundoBloque4);

				fprintf(fArchiveHTML,"%s",vectorMovies[i].linkImagen);

				fprintf(fArchiveHTML,"%s\n",segundoBloque5);

				fprintf(fArchiveHTML,"%s'>",vectorMovies[i].titulo);

				fprintf(fArchiveHTML,"%s\n%s\n%s",segundoBloque6,segundoBloque7,segundoBloque8);

				fprintf(fArchiveHTML,"%s",vectorMovies[i].titulo);

				fprintf(fArchiveHTML,"%s%s\n%s\n%s",segundoBloque9,segundoBloque10,segundoBloque11,segundoBloque12);

				fprintf(fArchiveHTML,"%s",vectorMovies[i].genero);

				fprintf(fArchiveHTML,"%s\n%s",segundoBloque13,segundoBloque14);

				fprintf(fArchiveHTML,"%d",vectorMovies[i].puntaje);

				fprintf(fArchiveHTML,"%s\n%s",segundoBloque15,segundoBloque17);

				fprintf(fArchiveHTML,"%d",vectorMovies[i].duracion);

				fprintf(fArchiveHTML,"%s\n%s\n%s",segundoBloque18,segundoBloque19,segundoBloque20);


				fprintf(fArchiveHTML,"%s%s","Breve descripcion:",vectorMovies[i].descripcion);

				fprintf(fArchiveHTML,"%s\n%s\n%s\n",segundoBloque20,segundoBloque21,segundoBloque22);

            }
        }

		fprintf(fArchiveHTML,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n",tercerBloque,tercerBloque2,tercerBloque3,tercerBloque4,tercerBloque5,tercerBloque6,tercerBloque7);


        fclose(fArchiveHTML);
        printf("\n*La pagina WEB fue generada con exito\n");
        system("pause");
    }
    else
        {
        printf("\n*La pagina WEB no pudo ser generada\n");
        system("pause");
        }
}


void borrarPeli(eMovie* vectorMovies, int* largo)
{
    int i;
    int flag=0;
    char movieAux[30];
    printf("\n\nIngrese el nombre de la pelicula a borrar:");
    fflush(stdin);
    gets(movieAux);
    for(i=0;i<(*largo);i++)
    {
        if(strcmp(movieAux,vectorMovies[i].titulo)==0)
        {
            vectorMovies[i].estado=0;
            printf("\n\n*La pelicula %s se borro correctamente.",vectorMovies[i].titulo);
            system("pause");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
    printf("\n\n*La pelicula %s no existe.",movieAux);
    system("pause");
    }


}
