#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fIngreso;
    int isEmpty;
} eTrabajo;

#endif // TRABAJOS_H_INCLUDED


/** \brief Inicializa en (1) la variable isEmpty de todas las estructuras del array de trabajos
 *
 * \param list[] eTrabajo
 * \param len int
 * \return int Devuelve (1) si hay error (list==NULL || len<=0) o (0) si Ok.
 *
 */
int initIsEmptyTrabajos(eTrabajo list[], int len);

/** \brief Busca dentro del array de trabajos list, la primer estructura que se encuentre inactiva (isEmpty==1)
 *
 * \param list[] eTrabajo
 * \param len int
 * \return int Devuelve el indice de la primer estructura inactiva o (-1) si hay error (list==NULL) o si no encuentra una estructura inactiva
 *
 */
int findEmptyTrabajo(eTrabajo list[], int len);

/** \brief Verifica si el array de estructuras trabajos tiene alguna estructura activa (isEmpty==0)
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return int Devuelve (1) si el array esta vacio o (0) si hay alguna estructura activa
 *
 */
int isEmptyTrabajos(eTrabajo trabajos[], int tam);
