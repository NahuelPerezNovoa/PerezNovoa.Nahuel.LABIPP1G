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


int listarTipos(eTipo tipos[], int tam)
{
    int error=1;
    if(tipos!=NULL && tam>0)
    {
        printf("Tipos de bicicletas\nId                    Tipos\n\n");
        for(int i=0; i<tam; i++)
        {
            mostrarTipo(tipos[i]);
        }
        printf("\n\n");
        error=0;
    }
    return error;
}

int listarColores(eColor colores[], int tam)
{
    int error=1;
    if(colores!=NULL && tam>0)
    {
        printf("Colores de bicicletas\nId                    Colores\n\n");
        for(int i=0; i<tam; i++)
        {
            mostrarColor(colores[i]);
        }
        printf("\n\n");
        error=0;
    }
    return error;
}

int altaBicicleta(eBicicleta bicicletas[],int tamBicicletas,int id,eTipo tipos[], int tamTipos,eColor colores[],int tamColores,eCliente clientes[], int tamClientes)
{
    int error=1;
    int i;
    char auxChar[150];
    int auxId;
    int validacionTipo;
    int validacionColor;
    int validacionCliente;
    float auxRodado;

    if(bicicletas!=NULL)
    {
        i=findEmptyBicicleta(bicicletas,tamBicicletas);
        if(i!=(-1))
        {

            bicicletas[i].idBicicleta=id;

            printf("Ingrese la marca de la bicicleta: ");
            fflush(stdin);
            gets(auxChar);
            while(strlen(auxChar)>20)//Verifico que este dentro del rango del char[] de su correspondiente estructura
            {
                printf("Texto fuera de rango. Reingrese\n");
                fflush(stdin);
                gets(auxChar);
            }
            strcpy(bicicletas[i].marca,auxChar);//Copio el nombre a su correspondiente char[]

            listarTipos(tipos,tamTipos);
            printf("Ingrese el Id de su tipo de bicicleta: ");
            fflush(stdin);
            scanf("%d",&auxId);
            validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
            while(validacionTipo==1)
            {
                printf("Id invalido, reingrese:");
                fflush(stdin);
                scanf("%d",&auxId);
                validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
            }
            bicicletas[i].idTipo=auxId;

            listarColores(colores,tamColores);
            printf("Ingrese el Id de su color de bicicleta: ");
            fflush(stdin);
            scanf("%d",&auxId);
            validacionColor=validarIdColor(colores,tamColores,auxId);
            while(validacionColor==1)
            {
                printf("Id invalido, reingrese:");
                fflush(stdin);
                scanf("%d",&auxId);
                validacionColor=validarIdColor(colores,tamColores,auxId);
            }
            bicicletas[i].idColor=auxId;

            printf("Ingrese el rodado de la bicicleta (20/26/27.5/29)");
            fflush(stdin);
            scanf("%f",&auxRodado);
            while(auxRodado!=20 && auxRodado!=26 && auxRodado!=27.5 && auxRodado!=29)
            {
                printf("Rodado invalido, reingrese:");
                fflush(stdin);
                scanf("%f",&auxRodado);
            }
            bicicletas[i].rodado=auxRodado;

            listarClientes(clientes,TAM_CLIENTES);
            printf("Ingrese el id del cliente duenio de la bicicleta: ");
            fflush(stdin);
            scanf("%d",&auxId);
            validacionCliente=validarIdCliente(clientes,tamClientes,auxId);
            while(validacionCliente==1)
            {
                printf("Id invalido, reingrese:");
                fflush(stdin);
                scanf("%d",&auxId);
                validacionCliente=validarIdCliente(clientes,tamClientes,auxId);
            }
            bicicletas[i].idCliente=auxId;

            bicicletas[i].isEmpty=0;

        }
        error=0;
    }

    return error;
}

int mostrarBicicletas(eBicicleta bicicletas[], int tamBicis,eTipo tipos[], int tamTipos,eColor colores[], int tamColores,eCliente clientes[],int tamClientes)
{
    int error=1;
    if(bicicletas!=NULL && tamBicis>0)
    {
        printf("Listado de bicicletas\nId                   Marca                 Tipo                  Color   Rodado                  Cliente\n");
        for(int i=0; i<tamBicis; i++)
        {
            if(!bicicletas[i].isEmpty)
            {
                mostrarBicicleta(bicicletas[i],tipos,tamTipos,colores,tamColores,clientes,tamClientes);
                printf("\n");
            }
        }
        printf("\n\n");
        error=0;
    }
    return error;

}

int modificarBicicleta(eBicicleta bicicletas[],int tamBicis,eTipo tipos[], int tamTipos,eColor colores[], int tamColores,eCliente clientes[], int tamClientes)
{
    int error=1;
    int id;
    int validacionIdBicicleta;
    int validacionTipo;
    int auxId;
    char opcion;
    float nuevoRodado;
    int indice;

    mostrarBicicletas(bicicletas,TAM_BICLETAS,tipos,TAM_TIPO,colores,TAM_COLOR,clientes,tamClientes);
    printf("Ingrese el ID de la bicicleta que desea modificar: ");
    fflush(stdin);
    scanf("%d",&id);
    validacionIdBicicleta=validarIdBicicleta(bicicletas,TAM_BICLETAS,id);
    while(validacionIdBicicleta==1)
    {
        printf("Id invalido, reingrese:");
        fflush(stdin);
        scanf("%d",&id);
        validacionIdBicicleta=validarIdBicicleta(bicicletas,TAM_BICLETAS,id);
    }
    indice=findBiciById(bicicletas,TAM_BICLETAS,id);
    printf("Seleccione el campo a modificar:\nA_Tipo\nB_Rodado\n");
    fflush(stdin);
    opcion=getchar();
    opcion=tolower(opcion);
    while(opcion!='a' && opcion!='b')
    {
        printf("Opcion invalida. Reingrese: ");
        fflush(stdin);
        opcion=getchar();
        opcion=tolower(opcion);
    }
    switch(opcion)
    {
    case 'a':
        listarTipos(tipos,tamTipos);
        printf("\nIngrese el ID del nuevo tipo: ");
        fflush(stdin);
        scanf("%d",&auxId);
        validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
        while(validacionTipo==1)
        {
            printf("Id invalido, reingrese:");
            fflush(stdin);
            scanf("%d",&auxId);
            validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
        }
        bicicletas[indice].idTipo=auxId;
        error=0;
        break;
    case'b':
            printf("Ingrese nuevo rodado (20/26/27.5/29): ");
            fflush(stdin);
        scanf("%f",&nuevoRodado);
        while(nuevoRodado!=20 && nuevoRodado!=26 && nuevoRodado!=27.5 && nuevoRodado!=29)
        {
            printf("Rodado invalido, reingrese:");
            fflush(stdin);
            scanf("%f",&nuevoRodado);
        }
        printf("%.01f  %.01f\n",nuevoRodado,bicicletas[indice].rodado);
        bicicletas[indice].rodado=nuevoRodado;
        printf("%.01f  %.01f\n",nuevoRodado,bicicletas[indice].rodado);

        error=0;

        break;
    }

    return error;
}

int bajarBicicleta(eBicicleta bicicletas[], int tamBicis,eTipo tipos[], int tamTipos,eColor colores[], int tamColores,eCliente clientes[], int tamClientes)
{
    int error=1;
    int auxId;
    int validacionBici;
    int index;

    mostrarBicicletas(bicicletas,tamBicis,tipos,tamTipos,colores,tamColores,clientes, tamClientes);
    printf("Ingrese el ID de la bicicleta a dar de baja: ");
    fflush(stdin);
    scanf("%d",&auxId);
    validacionBici=validarIdBicicleta(bicicletas,tamBicis,auxId);
    if(validacionBici==1)
    {
        printf("id invalido. Reingrese: ");
        fflush(stdin);
        scanf("%d",&auxId);
        validacionBici=validarIdBicicleta(bicicletas,tamBicis,auxId);
    }
    index=findBiciById(bicicletas,tamBicis,auxId);
    bicicletas[index].isEmpty=1;
    error=0;

    return error;
}

int listarServicios(eServicio servicios[], int tam)
{
    int error=1;
    if(servicios!=NULL && tam>0)
    {
        printf("Servicios\nId                   Servicio      Precio\n");
        for(int i=0; i<tam; i++)
        {
            mostrarServicio(servicios[i]);
            printf("\n");
        }
        printf("\n\n");
        error=0;
    }
    return error;
}

int altaTrabajo(eTrabajo trabajos[],int tamTrabajo,int idTrabajo,eBicicleta bicicletas[], int tamBicicletas,eServicio servicios[],int tamServicios,eTipo tipos[], int tamTipos,eColor colores[],int tamColores,eCliente clientes[],int tamClientes)
{
    int error=1;
    int i;
    int auxId;
    int validacionBicicleta;
    int validacionServicio;


    if(trabajos!=NULL)
    {
        i=findEmptyTrabajo(trabajos,tamTrabajo);
        if(i!=(-1))
        {

            trabajos[i].id=idTrabajo;

            mostrarBicicletas(bicicletas,tamBicicletas,tipos,tamTipos,colores,tamColores,clientes,tamClientes);
            printf("Ingrese el Id de la bicicleta a trabajar: ");
            fflush(stdin);
            scanf("%d",&auxId);
            validacionBicicleta=validarIdBicicleta(bicicletas,tamBicicletas,auxId);
            while(validacionBicicleta==1)
            {
                printf("Id invalido, reingrese:");
                fflush(stdin);
                scanf("%d",&auxId);
                validacionBicicleta=validarIdBicicleta(bicicletas,tamBicicletas,auxId);
            }
            trabajos[i].idBicicleta=auxId;

            listarServicios(servicios,tamServicios);
            printf("Ingrese el Id del servicio a realizar: ");
            fflush(stdin);
            scanf("%d",&auxId);
            validacionServicio=validarIdServicio(servicios,tamServicios,auxId);
            while(validacionServicio==1)
            {
                printf("Id invalido, reingrese:");
                fflush(stdin);
                scanf("%d",&auxId);
                validacionServicio=validarIdServicio(servicios,tamServicios,auxId);
            }
            trabajos[i].idServicio=auxId;

            printf("\nIngrese fecha de ingreso (dd/mm/aaaa): ");
            fflush(stdin);
            scanf("%d/%d/%d",&trabajos[i].fIngreso.dia,&trabajos[i].fIngreso.mes, &trabajos[i].fIngreso.anio);
            while(trabajos[i].fIngreso.dia<1 || trabajos[i].fIngreso.dia>31 || trabajos[i].fIngreso.mes<1 || trabajos[i].fIngreso.mes>12 || trabajos[i].fIngreso.anio>2200)
            {
                printf("Fecha invalida, reingrese: ");
                fflush(stdin);
                scanf("%d/%d/%d",&trabajos[i].fIngreso.dia,&trabajos[i].fIngreso.mes, &trabajos[i].fIngreso.anio);
            }

            trabajos[i].isEmpty=0;

            printf("Alta exitosa");

        }
        error=0;
    }

    return error;
}

int listarTrabajos(eTrabajo trabajos[], int tamTrab,eBicicleta bicicletas[],eTipo tipos[],eColor colores[], eServicio servicios[])
{
    int error=1;
    if(trabajos!=NULL && tamTrab>0)
    {
        printf("TRABAJOS\nId Trab--Id Bicic-----------Marca-----------Tipo-----------Color--Rodado------------Servicio---Fecha de Ingreso---\n");//cambiar
        for(int i=0; i<tamTrab; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                printf("%d    ",trabajos[i].id);
                mostrarBicicletaParaTrabajo(bicicletas,trabajos[i].idBicicleta,TAM_BICLETAS,tipos,TAM_TIPO,colores,TAM_COLOR);
                mostrarServicioPAraTrabajo(servicios,TAM_SERVICIOS,trabajos[i].idServicio);
                printf("%02d/%02d/%d",trabajos[i].fIngreso.dia,trabajos[i].fIngreso.mes,trabajos[i].fIngreso.anio);
                printf("\n");
            }
        }
        printf("\n\n");
        error=0;
    }
    return error;
}

int listarClientes(eCliente clientes[], int tam)
{
    int error=1;
    if(clientes!=NULL && tam>0)
    {
        printf("Clientes\nId                   Clientes     Sexo\n");
        for(int i=0; i<tam; i++)
        {
            mostrarCliente(clientes,i);
            printf("\n");
        }
        printf("\n\n");
        error=0;
    }
    return error;
}
