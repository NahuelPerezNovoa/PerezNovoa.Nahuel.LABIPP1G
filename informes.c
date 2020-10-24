#include <stdio.h>
#include <stdlib.h>
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

void mostrarBicicletasPorColorSeleccionado(eBicicleta bicicletas[], int tamBicicletas, eColor colores[], int tamColores,eTipo tipos[], int tamTipos,eCliente clientes[], int tamClientes)
{
    int auxId;
    int validacionColor;
    int flag=1;

    listarColores(colores,tamColores);
    printf("Ingrese el id del color deseado: ");
    fflush(stdin);
    scanf("%d",&auxId);
    validacionColor=validarIdColor(colores,tamColores,auxId);
    while(validacionColor==1)
    {
        printf("Id invalido, reingrese: ");
        fflush(stdin);
        scanf("%d",&auxId);
        validacionColor=validarIdColor(colores,tamColores,auxId);
    }
    for(int i=0; i<tamBicicletas; i++)
    {
        if(bicicletas[i].idColor==auxId)
        {
            mostrarBicicleta(bicicletas[i],tipos,tamTipos,colores,tamColores,clientes,tamClientes);
            printf("\n");

            flag=0;
        }
    }
    if(flag==1)
    {
        printf("No hay bicicletas ingresadas de ese color\n");
    }
}

void mostrarBicicletasPorTipoSeleccionado(eBicicleta bicicletas[], int tamBicicletas, eColor colores[], int tamColores,eTipo tipos[], int tamTipos,eCliente clientes[], int tamClientes)
{
    int auxId;
    int validacionTipo;
    int flag=1;

    listarTipos(tipos,tamTipos);
    printf("Ingrese el id del color deseado: ");
    fflush(stdin);
    scanf("%d",&auxId);
    validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
    while(validacionTipo==1)
    {
        printf("Id invalido, reingrese: ");
        fflush(stdin);
        scanf("%d",&auxId);
        validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
    }
    for(int i=0; i<tamBicicletas; i++)
    {
        if(bicicletas[i].idTipo==auxId)
        {
            mostrarBicicleta(bicicletas[i],tipos,tamTipos,colores,tamColores,clientes,tamClientes);
            printf("\n");
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("No hay bicicletas ingresadas de ese tipo\n");
    }
}

void informarBicicletasMenorRodado(eBicicleta bicicletas[], int tamBicicletas, eColor colores[], int tamColores,eTipo tipos[], int tamTipos,eCliente clientes[], int tamClientes)
{

    float auxMenorRodado=0;

    for(int i=0; i<tamBicicletas; i++)
    {
        if(i==0)
        {
            auxMenorRodado=bicicletas[i].rodado;
        }
        else
        {
            if(bicicletas[i].rodado<auxMenorRodado)
            {
                auxMenorRodado=bicicletas[i].rodado;
            }
        }
    }
    printf("El menor rodado es %.1f y las bicicletas respectivas son las siguientes:\n",auxMenorRodado);
    for(int i=0; i<tamBicicletas; i++)
    {
        if(bicicletas[i].rodado==auxMenorRodado)
        {
            mostrarBicicleta(bicicletas[i],tipos,tamTipos,colores,tamColores,clientes,tamClientes);
            printf("\n");
        }
    }
}

void mostrarBicicletasPorTipo(eBicicleta bicicletas[],int tamBicicletas,eTipo tipos[],int tamTipos,eColor colores[],int tamColores,eCliente clientes[],int tamClientes)
{
    for(int i=0; i<tamTipos; i++)
    {
        for(int j=0; j<tamBicicletas; j++)
        {
            if(bicicletas[j].idTipo==tipos[i].id)
            {
                mostrarBicicleta(bicicletas[j],tipos,tamTipos,colores,tamColores,clientes,tamClientes);
                printf("\n");
            }


        }
    }
}

void contarBicicletasPorColorYTipo (eBicicleta bicicletas[],int tamBicicletas,eTipo tipos[],int tamTipos,eColor colores[],int tamColores,eCliente clientes[],int tamClientes)
{
    int idColor;
    int validacionColor;
    int idTipo;
    int validacionTipo;
    int contador=0;

    listarColores(colores,tamColores);
    printf("Ingrese el id del color elegido: ");
    fflush(stdin);
    scanf("%d",&idColor);
    validacionColor=validarIdColor(colores,tamColores,idColor);
    while(validacionColor==1)
    {
        printf("Id invalido, reingrese: ");
        fflush(stdin);
        scanf("%d",&idColor);
        validacionColor=validarIdColor(colores,tamColores,idColor);
    }

    listarTipos(tipos,tamTipos);
    printf("Ingrese el id del tipo elegido: ");
    fflush(stdin);
    scanf("%d",&idTipo);
    validacionTipo=validarIdTipo(tipos,tamTipos,idTipo);
    while(validacionTipo==1)
    {
        printf("Id invalido, reingrese: ");
        fflush(stdin);
        scanf("%d",&idTipo);
        validacionTipo=validarIdTipo(tipos,tamTipos,idTipo);
    }

    for(int i=0; i<tamBicicletas; i++)
    {
        if(bicicletas[i].idColor==idColor && bicicletas[i].idTipo==idTipo)
        {
            contador++;
        }
    }
    if(contador==0)
    {
        printf("No hay bicicletas que se correspondan con el color y tipo ingresado\n");
    }
    else
    {
        printf("Se encontraron %d bicicletas que se corresponden con el color y tipo seleccionado\n",contador);

    }
}
