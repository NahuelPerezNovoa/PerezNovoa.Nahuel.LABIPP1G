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


int initIsEmptyTrabajos(eTrabajo list[], int len)
{
    int error=1;
    if(list!=NULL && len>0)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array
        {
            list[i].isEmpty=1;//Inicializo todos los isEmpty en 1
        }
        error=0;
    }
    return error;
}

int findEmptyTrabajo(eTrabajo list[], int len)
{
    int index = (-1);

    if(list!=NULL)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array de estructura
        {
            if(list[i].isEmpty==1)//Busco la primer estructura que figure vacia
            {
                index=i;//Guardo el indice de dicha estructura
                break;
            }
        }
    }
    return index;//Retorno el indice de la primer estructura vacia
}

int isEmptyTrabajos(eTrabajo trabajos[], int tam)
{
    int error=1;

    for(int i=0; i<tam; i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            error=0;
            break;
        }
    }
    return error;
}
