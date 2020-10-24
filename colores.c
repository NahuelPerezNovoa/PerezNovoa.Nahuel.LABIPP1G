#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "tipos.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "trabajos.h"
#include "menu.h"

#define TAM_BICLETAS 100
#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_TIPO 4
#define TAM_SERVICIOS 4
#define TAM_TRABAJOS 100

int harcodearColores(eColor colores[],int tam,int cantidad)
{
    int error=1;
    int id=5000;
    char coloresHarcod[][20]= {"Gris","Negro","Blanco","Azul","Rojo"};
    if(colores!=NULL && tam>0 && cantidad>=0)
    {
        for(int i=0; i<tam; i++)
        {
            strcpy(colores[i].nombreColor,coloresHarcod[i]);
            colores[i].id=id;
            id++;
        }
        error=0;
    }
    return error;
}

void mostrarColor(eColor color)
{
    printf("%d    %20s\n",color.id,color.nombreColor);
}

int validarIdColor(eColor colores[], int tam, int id)
{
    int esValido=1;
    if(colores!=NULL && tam>0 && id>=5000)
    {
        for (int i=0; i<tam; i++)
        {
            if(colores[i].id==id)
            {
                esValido=0;
                break;
            }
        }
    }
    return esValido;
}

int obtenerDescripcionColor(eColor colores[], int tam, int id, char descripcion[])
{
    int error=1;

    if(colores!=NULL && tam>0 && id>=1000 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(colores[i].id==id)
            {
                strcpy(descripcion,colores[i].nombreColor);
                error=0;
                break;
            }
        }
    }
    return error;
}
