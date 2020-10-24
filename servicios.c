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


int harcodearServicios(eServicio servicios[],int tam,int cantidad)
{
    int error=1;
    int id=20000;
    char descripcionHarcod[][20]= {"Limpieza","Parche","Centrado","Cadena"};
    int precios[]= {250,300,400,350};
    if(servicios!=NULL && tam>0 && cantidad>=0)
    {
        for(int i=0; i<tam; i++)
        {
            strcpy(servicios[i].descripcion,descripcionHarcod[i]);
            servicios[i].precio=precios[i];
            servicios[i].id=id;
            id++;
        }
        error=0;
    }
    return error;
}

void mostrarServicio(eServicio servicio)
{
    printf("%d    %20s        $%d",servicio.id,servicio.descripcion,servicio.precio);
}

int validarIdServicio(eServicio servicios[], int tam, int id)
{
    int esValido=1;
    if(servicios!=NULL && tam>0 && id>=1000)
    {
        for (int i=0; i<tam; i++)
        {
            if(servicios[i].id==id)
            {
                esValido=0;
                break;
            }
        }
    }
    return esValido;
}

int findIndexServicioById(eServicio list[], int len, int id)
{
    int index=(-1);
    if(list!=NULL && len>0 && id<len && id>=0)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array de estructura
        {
            if((list[i].id==id) && (list[i].isEmpty==0))//Busco aquel empleado activo cuyo Id coincide con el ingresado en la funcion
            {
                index=i;//Guardo el indice del empleado encontrado
                break;
            }
        }
    }
    return index;
}

void mostrarServicioPAraTrabajo(eServicio servicios[],int tam,int id)
{
    int index;

    for(int i=0; i<tam; i++)
    {
        if(servicios[i].id==id)
        {
            index=i;
            break;
        }
    }

    printf("   %15s     ",servicios[index].descripcion);
}
