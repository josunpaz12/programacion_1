#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[20];
    char descripcion[500];
    char linkImagen[200];
    int puntaje;
    int duracion;
    int estado;

}eMovie;

/**
 *  Reserva espacio en memoria de una estructura movie
 *  @return retorna NULL si no pudo reservar espacio, si pudo retorna direccion de memoria
 */
eMovie* newMovie();


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);

/**
 * \brief En un menu solicita un numero para ingresar
 * \param minimo delimita numero minimo que se puede ingresar
 * \param maximo delimita numero maximo que se puede ingresar
 * \return el numero ingresado por el usuario
 *
 */
int menu (int minimo, int maximo);


void cargarDatosEnMovie(eMovie* vectorMovies,int*subIndice,int* largo);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie movie,FILE* path);

/**
 *  Borra una pelicula de un vector de estructura eMovie
 *  @param movie la estructura a ser eliminada del vector
 */
void borrarPeli(eMovie* vectorMovies, int* largo);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(eMovie lista[], char nombre[]);

void listarMovies(eMovie* vectorMovies,int* subIndice);

void guardarMoviesEnArchivo(eMovie* vectorMovies,int* largo);
eMovie* cargarDatosDesdeArchivo(eMovie* vectorMovies,int* largo);
void generarWeb(eMovie vectorMovies[], int* largo);


#endif // FUNCIONES_H_INCLUDED
