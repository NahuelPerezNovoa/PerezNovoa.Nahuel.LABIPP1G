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


int harcodearTipos(eTipo tipos[],int tam,int cantidad)
{
    int error=1;
    int id=1000;
    char tiposHarcod[][20]= {"Rutera","Carrera","Mountain","BMX"};
    if(tipos!=NULL && tam>0 && cantidad>=0)
    {
        for(int i=0; i<tam; i++)
        {
            strcpy(tipos[i].descripcion,tiposHarcod[i]);
            tipos[i].id=id;
            id++;
        }
        error=0;
    }
    return error;
}

void mostrarTipo(eTipo tipo)
{
    printf("%d    %20s\n",tipo.id,tipo.descripcion);
}

int validarIdTipo(eTipo tipos[], int tam, int id)
{
    int esValido=1;
    if(tipos!=NULL && tam>0 && id>=1000)
    {
        for (int i=0; i<tam; i++)
        {
            if(tipos[i].id==id)
            {
                esValido=0;
                break;
            }
        }
    }
    return esValido;
}

int obtenerDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
    int error=1;

    if(tipos!=NULL && tam>0 && id>=1000 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id==id)
            {
                strcpy(descripcion,tipos[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}
