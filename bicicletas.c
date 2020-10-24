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
#define TAM_CLIENTES 10


int initIsEmptyBicicleta(eBicicleta list[], int len)
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

int findEmptyBicicleta(eBicicleta list[], int len)
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

int validarIdBicicleta(eBicicleta bicicletas[], int tam, int id)
{
    int esValido=1;
    if(bicicletas!=NULL && tam>0)
    {
        for (int i=0; i<tam; i++)
        {
            if(bicicletas[i].idBicicleta==id)
            {
                esValido=0;
                break;
            }
        }
    }
    return esValido;
}

int isEmptyBicicletas(eBicicleta bicicletas[], int tam)
{
    int error=1;

    for(int i=0; i<tam; i++)
    {
        if(bicicletas[i].isEmpty==0)
        {
            error=0;
            break;
        }
    }
    return error;
}



int findBiciById(eBicicleta bicicletas[], int len, int id)
{
    int index=(-1);
    if(bicicletas!=NULL && len>0 && id<len && id>=0)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array de estructura
        {
            if((bicicletas[i].idBicicleta==id) && (bicicletas[i].isEmpty==0))
            {
                index=i;
                break;
            }
        }
    }
    return index;
}
void mostrarBicicleta(eBicicleta bicicleta,eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamClientes)
{
    char descripcionTipo[20];
    char descripcionColor[20];
    char descripcionCliente[20];
    obtenerDescripcionTipo(tipos,tamTipo,bicicleta.idTipo,descripcionTipo);
    obtenerDescripcionColor(colores,tamColor,bicicleta.idColor,descripcionColor);
    obtenerDescripcionCliente(clientes,tamClientes,bicicleta.idCliente,descripcionCliente);
    printf("%d    %20s  %20s   %20s    %.01f    %20s",bicicleta.idBicicleta,bicicleta.marca,descripcionTipo,descripcionColor,bicicleta.rodado,descripcionCliente);
}

int findIndexBicicletaById(eBicicleta list[], int len, int id)
{
    int index=(-1);
    if(list!=NULL && len>0 && id<len && id>=0)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array de estructura
        {
            if((list[i].idBicicleta==id) && (list[i].isEmpty==0))
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

void mostrarBicicletaParaTrabajo(eBicicleta bicicletas[],int id,int tamBici, eTipo tipos[],int tamTipo,eColor colores[],int tamColor)
{
    int index;

    for(int i=0; i<tamBici; i++)
    {
        if(bicicletas[i].idBicicleta==id)
        {
            index=i;
            break;
        }
    }

    char descripcionTipo[20];
    char descripcionColor[20];
    obtenerDescripcionTipo(tipos,tamTipo,bicicletas[index].idTipo,descripcionTipo);
    obtenerDescripcionColor(colores,tamColor,bicicletas[index].idColor,descripcionColor);
    printf("        %d  -%15s-%15s-%15s-   %.01f  ",bicicletas[index].idBicicleta,bicicletas[index].marca,descripcionTipo,descripcionColor,bicicletas[index].rodado);
}

int obtenerDescripcionCliente(eCliente clientes[], int tamClientes, int idCliente, char descripcion[])
{
    int error=1;

    if(clientes!=NULL && tamClientes>0 && idCliente>=0 && descripcion!=NULL)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].idCliente==idCliente)
            {
                strcpy(descripcion,clientes[i].nombre);
                error=0;
                break;
            }
        }
    }
    return error;
}

void mostrarCliente(eCliente clientes[], int i)
{
    printf("%d    %20s        %c",clientes[i].idCliente,clientes[i].nombre,clientes[i].sexo);
}

int harcodearClientes(eCliente clientes[],int tam)
{
    int error=1;
    int id=10;
    char nombreCliente[][20]= {"Juan","Carlos","Hector","Diana","Lorena","Manuel","Carla","Sebastian","Sofia","Diego"};
    char sexo[]= {'m','m','m','f','f','m','f','m','f','m'};
    if(clientes!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            strcpy(clientes[i].nombre,nombreCliente[i]);
            clientes[i].sexo=sexo[i];
            clientes[i].idCliente=id;
            id++;
        }
        error=0;
    }
    return error;
}

int validarIdCliente(eCliente clientes[], int tam, int id)
{
    int esValido=1;
    if(clientes!=NULL && tam>0)
    {
        for (int i=0; i<tam; i++)
        {
            if(clientes[i].idCliente==id)
            {
                esValido=0;
                break;
            }
        }
    }
    return esValido;
}
