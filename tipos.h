#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;

#endif // TIPOS_H_INCLUDED

/** \brief Inicializa los valores del array de estructuras de tipos de bicicletas
 *
 * \param tipos[] eTipo
 * \param tam int
 * \param cantidad int
 * \return int Devuelve (1) si hay error (tipos==NULL || tam<=0 || cantidad<0) o (0) si Ok
 *
 */
int harcodearTipos(eTipo tipos[],int tam,int cantidad);

/** \brief Imprime en pantalla una estructura eTipo
 *
 * \param tipo eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo tipo);

/** \brief Valida la existencia de un Id dentro del array de estructuras de tipos de bicicletas
 *
 * \param tipos[] eTipo
 * \param tam int
 * \param id int
 * \return int Devuelve (1) si hay error (tipos==NULL || tam<=0 || id<1000) o (0) si Ok
 *
 */
int validarIdTipo(eTipo tipos[], int tam, int id);

/** \brief Devuelve la descripcion del tipo de bicicleta en base al id ingresado
 *
 * \param tipos[] eTipo
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int Devuelve (1) si hay error(tipos==NULL || tam<=0 || id<1000 || descripcion==NULL) o (0) si Ok
 *
 */
int obtenerDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
