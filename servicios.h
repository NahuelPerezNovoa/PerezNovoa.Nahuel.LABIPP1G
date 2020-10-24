#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int precio;
    int isEmpty;
} eServicio;

#endif // SERVICIOS_H_INCLUDED


/** \brief Inicializa los valores del array de estructuras de servicios
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param cantidad int
 * \return int Devuelve (1) si hay error (servicios==NULL || tam<=0 || cantidad<0) o (0) si Ok
 *
 */
int harcodearServicios(eServicio servicios[],int tam,int cantidad);

/** \brief Imprime en pantalla una estructura de servicio
 *
 * \param servicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief Verifica la existencia de un ID en el array de estructuras de servicios
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param id int
 * \return int Devuelve (1) si hay error (servicios==NULL || tam<=0 || id<1000) o (0) si Ok
 *
 */
int validarIdServicio(eServicio servicios[], int tam, int id);

/** \brief Devuelve el indice correspondiente a la estructura que se corresponde con el id ingresado
 *
 * \param list[] eServicio
 * \param len int
 * \param id int
 * \return int Devuelve (1) si hay error (servicios==NULL || len<=0 || id>=len || id<0) o (0) si Ok
 *
 */
int findIndexServicioById(eServicio list[], int len, int id);

/** \brief Imprime en pantalla un servicio acorde al menu de trabajos
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param id int
 * \return void
 *
 */
void mostrarServicioPAraTrabajo(eServicio servicios[],int tam,int id);
