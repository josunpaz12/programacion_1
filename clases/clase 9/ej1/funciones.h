
typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
}eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;
    int idSerie;
}eCliente;

typedef struct
{
    int idSerie;
    int cont;
} eLoser;

void cargarSeries(eSerie[]);
void cargarClientes(eCliente[]);

void mostrarSeries(eSerie[],int);
void mostrarClientes(eCliente[], int);
void mostrarClientesConSerie(eCliente[], eSerie[], int, int);
void mostrarSeriesConClientes(eCliente[], eSerie[],eLoser[], int, int);
void mostrarSerieLoser(eLoser[],eSerie serie[], int);
void mostrarClientesTBBT(eCliente[], eSerie[], int, int);

