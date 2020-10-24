#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

#endif // COLORES_H_INCLUDED


/** \brief Inicializa los valores del array de estructuras de colores de bicicletas
 *
 * \param colores[] eColor
 * \param tam int
 * \param cantidad int
 * \return int Devuelve (1) si hay error (colores==NULL || tam<=0 || cantidad<0) o (1) si Ok
 *
 */
int harcodearColores(eColor colores[],int tam,int cantidad);

/** \brief  Imprimme una estructura eColor
 *
 * \param color eColor
 * \return void
 *
 */
void mostrarColor(eColor color);

/** \brief  Verifica la existencia de un ID dentro del array de estructuras de colores de bicicletas
 *
 * \param colores[] eColor
 * \param tam int
 * \param id int
 * \return int Devuelve (1) si hay error (colores==NULL || tam<=0 || id<5000) o (0) si Ok
 *
 */
int validarIdColor(eColor colores[], int tam, int id);

/** \brief  Muestra la descripcion del color correspondiente al ID ingresado
 *
 * \param colores[] eColor
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int Devuelve (1) si hay error (colores==NULL || tam<=0 || id<1000 || descripcion==NULL) o (0) si Ok
 *
 */
int obtenerDescripcionColor(eColor colores[], int tam, int id, char descripcion[]);
