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
#include "informes.h"

#define TAM_BICLETAS 100
#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_TIPO 4
#define TAM_SERVICIOS 4
#define TAM_TRABAJOS 100
#define TAM_CLIENTES 10



int main()
{
    eTipo tipoBicicleta[TAM_TIPO];
    eColor colorBicicleta[TAM_COLOR];
    eServicio servicioBicicleta[TAM_SERVICIOS];
    eBicicleta bicicletas[TAM_BICLETAS];
    eTrabajo trabajos[TAM_TRABAJOS];
    eCliente clientes[TAM_CLIENTES];
    char flagExit=0;//Bandera de fin del programa
    char option;
    int idBicicletas=1;
    int idTrabajos=1;
    char exitConfirm;
    char opcionInformes;

    if(harcodearTipos(tipoBicicleta,TAM_TIPO,4)==1)//REALIZO EL HARCODEO DE LOS TIPOS DE BICICLETAS
    {
        printf("No se pudo harcodear tipo bicicletas");//VERIFICO ERROR
        flagExit=1;
        system("pause");
    }
    if(harcodearColores(colorBicicleta,TAM_COLOR,5)==1)//REALIZO EL HARCODEO DE LOS COLORES DE BICICLETAS
    {
        printf("No se pudo harcodear colores bicicletas");//VERIFICO ERROR
        flagExit=1;
        system("pause");
    }
    if(harcodearServicios(servicioBicicleta,TAM_SERVICIOS,4)==1)//REALIZO EL HARCODEO DE LOS SERVICIOS
    {
        printf("No se pudo harcodear servicios bicicletas");//VERIFICO ERROR
        flagExit=1;
        system("pause");
    }
    if(harcodearClientes(clientes,TAM_CLIENTES)==1)//REALIZO EL HARCODEO DE LOS SERVICIOS
    {
        printf("No se pudo harcodear clientes");//VERIFICO ERROR
        flagExit=1;
        system("pause");
    }

    if(initIsEmptyBicicleta(bicicletas,TAM_BICLETAS)==1)//INICIALIZO isEmpty (BICICLETAS) EN 1
    {
        printf("No se pudo inicializar bicicletas");//VERIFICO ERROR
        flagExit=1;
        system("pause");
    }
    if(initIsEmptyTrabajos(trabajos,TAM_TRABAJOS)==1)//INICIALIZO isEmpty (TRABAJOS) EN 1
    {
        printf("No se pudo inicializar bicicletas");//VERIFICO ERROR
        flagExit=1;
        system("pause");
    }


    while(!flagExit)//INICIO ITERACION DE MENÚ
    {
        //IMPRIMO EL MENU PRINCIPAL
        printf("----------------------\n----MENU PRINCIPAL----\n----------------------\nA_Alta Bicicleta\nB_Modificar Bicicleta\nC_Baja Bicicleta\nD_Listar Bicicletas\nE_Listar Tipos\nF_Listar Colores\nG_Listar Servicios\nH_Alta Trabajo\nI_Listar Trabajos\nJ_Informes\nK_Salir\n----------------------\n");
        fflush(stdin);
        option=getchar();//Escaneo la opcion elegida por el usuario del menu principal
        option=tolower(option);//CASTEO LA OPCION EN MINUSCULA
        switch(option)//Ingreso en el modulo de la funcion elegida
        {
        case 'a'://ALTA BICICLETA
            if(findEmptyBicicleta(bicicletas,TAM_BICLETAS)==(-1))//VERIFICO QUE EL ARRAY NO ESTÉ COMPLETO
            {
                printf("La lista de bicicletas está completa\n");
            }
            else
            {
                if(altaBicicleta(bicicletas,TAM_BICLETAS,idBicicletas,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR,clientes,TAM_CLIENTES)==1)//LLAMO A LA FUNCION DE ALTA DE BICICLETA
                {
                    printf("No se pudo realizar el alta\n");//VERIFICO ERROR
                }
                else
                {
                    printf("Alta exitosa\n");
                    idBicicletas++;//INCREMENTO EL ID BICICLETAS POR CADA ALTA REALIZADA
                }
            }
            break;

        case 'b'://MODIFICAR BICICLETA
            if(isEmptyBicicletas(bicicletas,TAM_BICLETAS)==0)//VERIFICO QUE EL ARRAY NO ESTE VACIO
            {
                if(modificarBicicleta(bicicletas,TAM_BICLETAS,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR,clientes,TAM_CLIENTES)==1)//LLAMO A LA FUNCION PARA MODIFICAR BICICLETAS
                {
                    printf("No se pudo realizar la modificacion\n");//VERIFICO ERROR

                }
                else
                {
                    printf("Modificacion exitosa\n");
                }
            }
            else
            {
                printf("No hay bicicletas ingresadas\n");//VERIFICO ERROR
            }
            break;

        case 'c'://BAJA BICICLETA
            if(isEmptyBicicletas(bicicletas,TAM_BICLETAS)==0)//VERIFICO QUE EL ARRAY NO ESTE VACIO
            {
                if(bajarBicicleta(bicicletas,TAM_BICLETAS,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR,clientes,TAM_CLIENTES)==1)//LLAMO A LA FUNCION DE BAJA DE BICICLETAS
                {
                    printf("No se pudo realizar la baja\n");//VERIFICO ERROR
                }
                else
                {
                    printf("Modificacion exitosa\n");
                }
            }
            else
            {
                printf("No hay bicicletas ingresadas\n");//VERIFICO ERROR
            }
            break;

        case 'd'://LISTAR BICICLETAS
            if(isEmptyBicicletas(bicicletas,TAM_BICLETAS)==0)//VERIFICO QUE EL ARRAY NO ESTE VACIO
            {
                mostrarBicicletas(bicicletas,TAM_BICLETAS,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR,clientes,TAM_CLIENTES);//LLAMO A LA FUNCION QUE IMPRIME LA LISTA DE BICICLETAS
            }
            else
            {
                printf("No hay bicicletas ingresadas\n");//VERIFICO ERROR
            }
            break;

        case 'e'://LISTAR TIPOS
            listarTipos(tipoBicicleta,TAM_TIPO);//LAMO A LA FUNCION QUE IMPRIME LA LISTA DE TIPOS DE BICICLETAS
            break;
        case 'f'://LISTAR COLORES
            listarColores(colorBicicleta,TAM_COLOR);//LAMO A LA FUNCION QUE IMPRIME LA LISTA DE COLORES DE BICICLETAS
            break;
        case 'g'://LISTAR SERVICIOS
            listarServicios(servicioBicicleta,TAM_SERVICIOS);//LAMO A LA FUNCION QUE IMPRIME LA LISTA DE SERVICIOS
            break;
        case 'h'://ALTA TRABAJO
            if(isEmptyBicicletas(bicicletas,TAM_BICLETAS)==0)//VERIFICO QUE EL ARRAY DE BICICLETAS NO ESTE VACIO
            {
                altaTrabajo(trabajos,TAM_TRABAJOS,idTrabajos,bicicletas,TAM_BICLETAS,servicioBicicleta,TAM_SERVICIOS,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR,clientes,TAM_CLIENTES);//LLAMO A LA FUNCION QUE REALIZA EL ALTA
                idTrabajos++;//INCREMENTO EL ID DE TRABAJOS POR CADA ALTA REALIZADA
            }
            else
            {
                printf("No hay bicicletas ingresadas\n");//VERIFICO ERROR
            }
            break;
        case 'i'://LISTAR TRABAJOS
            if(isEmptyTrabajos(trabajos,TAM_TRABAJOS)==0)//VERIFICO QUE EL ARRAY DE TRABAJOS NO ESTE VACIO
            {
                listarTrabajos(trabajos,TAM_TRABAJOS,bicicletas,tipoBicicleta,colorBicicleta,servicioBicicleta);//LLAMO A LA FUNCION QUE EJECUTA EL ALTA DE TRABAJOS
            }
            else
            {
                printf("No hay trabajos ingresados\n");//VERIFICO ERROR
            }
            break;
        case 'j'://INFORMES
            if(isEmptyBicicletas(bicicletas,TAM_BICLETAS)==0)//VERIFICO QUE EL ARRAY NO ESTE VACIO
            {
                printf("Informes:\na.Mostrar bicicletas del color seleccionado\nb.Mostrar bicicletas del tipo seleccionado\nc.Informar bicicletas de menor rodado\nd.Mostrar bicicletas por tipo\ne.Cantidad de bicicletas por color y tipo seleccionado\n");
                fflush(stdin);
                opcionInformes=getchar();//Escaneo la opcion elegida por el usuario del menu principal
                opcionInformes=tolower(opcionInformes);//CASTEO LA OPCION EN MINUSCULA
                switch(opcionInformes)
                {
                case 'a':
                    mostrarBicicletasPorColorSeleccionado(bicicletas,TAM_BICLETAS,colorBicicleta,TAM_COLOR,tipoBicicleta,TAM_TIPO,clientes,TAM_CLIENTES);
                    break;
                case 'b':
                    mostrarBicicletasPorTipoSeleccionado(bicicletas,TAM_BICLETAS,colorBicicleta,TAM_COLOR,tipoBicicleta,TAM_TIPO,clientes,TAM_CLIENTES);
                    break;
                case 'c':
                    informarBicicletasMenorRodado(bicicletas,TAM_BICLETAS,colorBicicleta,TAM_COLOR,tipoBicicleta,TAM_TIPO,clientes,TAM_CLIENTES);
                    break;
                case 'd':
                    mostrarBicicletasPorTipo(bicicletas,TAM_BICLETAS,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR,clientes,TAM_CLIENTES);
                    break;
                case 'e':
                    contarBicicletasPorColorYTipo(bicicletas,TAM_BICLETAS,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR,clientes,TAM_CLIENTES);
                    break;
                }

            }
            else
            {
                printf("No hay bicicletas ingresadas\n");//VERIFICO ERROR
            }
            break;

        case 'k'://SALIDA
            printf("Confirma que desea salir?(y/n)\n");//Pido confirmacion de salida
            fflush(stdin);
            exitConfirm=getchar();
            exitConfirm=tolower(exitConfirm);
            if(exitConfirm=='y')
            {
                flagExit=1;
            }
            break;
        default://VALIDO CUALQUIER INGRESO QUE NO CORRESPONDA AL MENU PRINCIPAL
            printf("Parametro invalido. Reingrese\n");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}




