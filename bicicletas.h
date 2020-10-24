#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombre[20];
    char sexo;
} eCliente;

typedef struct
{
    int idBicicleta;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int idCliente;
    int isEmpty;
} eBicicleta;

#endif // BICICLETAS_H_INCLUDED


/** \brief Inicializa en (1) la variable isEmpty del array de estructuras bicicletas
 *
 * \param list[] eBicicleta
 * \param len int
 * \return int Devuelve (1) si hay error (list==NULL || len<=0) o (0) si Ok
 *
 */
int initIsEmptyBicicleta(eBicicleta list[], int len);

/** \brief Devuelve el indice correspondiente a la primer estructura inactiva del array de estructuras bicicletas
 *
 * \param list[] eBicicleta
 * \param len int
 * \return int Devuelve (-1) si hay error (list==NULL) o el indice de la estructura correspondiente
 *
 */
int findEmptyBicicleta(eBicicleta list[], int len);

/** \brief Verifica la existencia del id ingresado y que corresponda a una estructura activa dentro del array de estructuras bicicletas
 *
 * \param bicicletas[] eBicicleta
 * \param tam int
 * \param id int
 * \return int Devuelve (1) si hay error (bicicletas==NULL || tam<=0) o si el id no existe. Devuelve 0 si el id existe
 *
 */
int validarIdBicicleta(eBicicleta bicicletas[], int tam, int id);

/** \brief Verifica si hay alguna estructura activa en el array de estructuras bicicletas
 *
 * \param bicicletas[] eBicicleta
 * \param tam int
 * \return int Devuelve (1) si no hay estructura activa o (0) si la hay
 *
 */
int isEmptyBicicletas(eBicicleta bicicletas[], int tam);

/** \brief Imprime en pantalla una descripcion completa de una bicicleta
 *
 * \param bicicleta eBicicleta
 * \param tipos[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamColor int
 * \return void
 *
 */
void mostrarBicicleta(eBicicleta bicicleta,eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamClientes);

/** \brief Busca la estructura correspondiente al id ingresado y devuelve el indice de la misma, dentro del array de estructuras bicicletas
 *
 * \param bicicletas[] eBicicleta
 * \param len int
 * \param id int
 * \return int Devuelve (-1) si hay error (bicicletas==NULL || len<=0 || id>len || id<0). Devuelve el indice correspondiene si esta Ok
 *
 */
int findBiciById(eBicicleta bicicletas[], int len, int id);

/** \brief Busca la estructura correspondiente al id ingresado y devuelve el indice de la misma, dentro del array de estructuras bicicletas
 *
 * \param list[] eBicicleta
 * \param len int
 * \param id int
 * \return int Devuelve (-1) si hay error (bicicletas==NULL || len<=0 || id>len || id<0). Devuelve el indice correspondiene si esta Ok
 *
 */
int findIndexBicicletaById(eBicicleta list[], int len, int id);

/** \brief Imprime en pantalla una bicicleta acorde al menu de trabajos
 *
 * \param bicicletas[] eBicicleta
 * \param id int
 * \param tamBici int
 * \param tipos[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamColor int
 * \return void
 *
 */
void mostrarBicicletaParaTrabajo(eBicicleta bicicletas[],int id,int tamBici, eTipo tipos[],int tamTipo,eColor colores[],int tamColor);

int obtenerDescripcionCliente(eCliente clientes[], int tamClientes, int idCliente, char descripcion[]);

void mostrarCliente(eCliente clientes[], int i);

int harcodearClientes(eCliente clientes[],int tam);

int validarIdCliente(eCliente clientes[], int tam, int id);
