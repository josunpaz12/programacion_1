
typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
    int visto;
}eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;
//    int idSerie;
}eCliente;

typedef struct
{
    int idCliente;
    int idSerie;
    int marca;

}eClienteSerie;


typedef struct
{
    int idSerie;
    int cont;
} eLoser;

void cargarSeries(eSerie[]);
void cargarClientes(eCliente[]);

void mostrarSeries(eSerie[],int);
void mostrarClientes(eCliente[], int);

char getNumeroAleatorio(int, int, int );
void cargarClienteSerie(eCliente [], eSerie [],eClienteSerie [], int );
//void machearNombreSolicitado(eCliente [], eClienteSerie [],int , char [])
/*void mostrarClientesConSerie(eCliente[], eSerie[], int, int);
void mostrarSeriesConClientes(eCliente[], eSerie[],eLoser[], int, int);
void mostrarSerieLoser(eLoser[],eSerie serie[], int);
void mostrarClientesTBBT(eCliente[], eSerie[], int, int);
*/


