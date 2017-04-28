#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Inicializa un campo de un array.
 * @param se pasa el array de estructuras del tipo ePersona.
 * @param se pasa la cantidad por parametro.
 *
 */
void inicializarArray(ePersona[],int);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[]);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[]);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]) ;

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * Obtiene el primer indice libre del array.
 * @param persona, el array se pasa como parametro.
 * @return el primer indice disponible, de forma contraria -1 dato no encontrado.
 *
 */
int buscarPrimeraOcurrencia(ePersona [],int);

/**
 * Carga un estructura validando los campos solicitados.
 * @param Devuelve solo letras en esta cadena de caracteres.
 * @return
 *
 */
void cargarDatosPersona (ePersona [],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 *
 */
int buscarPorDni(ePersona[], int,int);

void borrarPersona(ePersona [], int,int);

#endif // FUNCIONES_H_INCLUDED
