#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



#endif // MENU_H_INCLUDED


/** \brief Imprime todos los tipos de bicicletas en una lista
 *
 * \param tipos[] eTipo
 * \param tam int
 * \return int Devuelve (1) si hay error (tipos==NULL || tam<=0) o (0) si Ok
 *
 */
int listarTipos(eTipo tipos[], int tam);

/** \brief Imprime todos los colores de bicicletas en una lista
 *
 * \param colores[] eColor
 * \param tam int
 * \return int Devuelve (1) si hay error (colores==NULL || tam<=0) o (0) si Ok
 *
 */
int listarColores(eColor colores[], int tam);

/** \brief Realiza la toma de datos para realizar el alta y los guarda en su correspondiente estructura
 *
 * \param bicicletas[] eBicicleta
 * \param tamBicicletas int
 * \param id int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColores int
 * \return int Devuelve (1) si hay error (bicicletas==NULL) o (0) si Ok
 *
 */
int altaBicicleta(eBicicleta bicicletas[],int tamBicicletas,int id,eTipo tipos[], int tamTipos,eColor colores[],int tamColores,eCliente clientes[], int tamClientes);

/** \brief Muestra en una lista todas las bicicletas ingresadas activas
 *
 * \param bicicletas[] eBicicleta
 * \param tamBicis int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColores int
 * \return int Devuelve (1) si hay error (bicicletas==NULL && tambicis<=0) o (0) si Ok
 *
 */
int mostrarBicicletas(eBicicleta bicicletas[], int tamBicis,eTipo tipos[], int tamTipos,eColor colores[], int tamColores,eCliente clientes[],int tamClientes);
/** \brief Ejecuta el submenu de modificacion de bicicletas y efectua la misma
 *
 * \param bicicletas[] eBicicleta
 * \param tamBicis int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColores int
 * \return int Devuelve (1) si hay error o (0) si Ok
 *
 */
int modificarBicicleta(eBicicleta bicicletas[],int tamBicis,eTipo tipos[], int tamTipos,eColor colores[], int tamColores,eCliente clientes[], int tamClientes);

/** \brief Ejecuta el submenu de baja de bicicletas y efectua la misma (cambia el estado de isEmpty de la estructura correspondiente)
 *
 * \param bicicletas[] eBicicleta
 * \param tamBicis int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColores int
 * \return int Devuelve (1) si hay error o (0) si Ok
 *
 */
int bajarBicicleta(eBicicleta bicicletas[], int tamBicis,eTipo tipos[], int tamTipos,eColor colores[], int tamColores,eCliente clientes[], int tamClientes);

/** \brief Imprime una lista con todos los servicios
 *
 * \param servicios[] eServicio
 * \param tam int
 * \return int Devuelve (1) si hay error (servicios==NULL || tam<=0) o (0) si Ok
 *
 *
 */
int listarServicios(eServicio servicios[], int tam);

/** \brief Ejecuta el submenu de alta de trabajos y efectua el mismo
 *
 * \param trabajos[] eTrabajo
 * \param tamTrabajo int
 * \param idTrabajo int
 * \param bicicletas[] eBicicleta
 * \param tamBicicletas int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColores int
 * \return int Devuelve (1) si hay error (trabajos==NULL) o (0) si Ok
 *
 */
int altaTrabajo(eTrabajo trabajos[],int tamTrabajo,int idTrabajo,eBicicleta bicicletas[], int tamBicicletas,eServicio servicios[],int tamServicios,eTipo tipos[], int tamTipos,eColor colores[],int tamColores,eCliente clientes[],int tamClientes);

/** \brief Imprime una lista con todos los trabajos ingresados
 *
 * \param trabajos[] eTrabajo
 * \param tamTrab int
 * \param bicicletas[] eBicicleta
 * \param tipos[] eTipo
 * \param colores[] eColor
 * \param servicios[] eServicio
 * \return int Devuelve (1) si hay error (trabajos==NULL || tamTrab<=0) o (0) si Ok
 *
 */
int listarTrabajos(eTrabajo trabajos[], int tamTrab,eBicicleta bicicletas[],eTipo tipos[],eColor colores[], eServicio servicios[]);

int listarClientes(eCliente clientes[], int tam);
