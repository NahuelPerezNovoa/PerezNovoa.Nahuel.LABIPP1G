#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define TAM_BICLETAS 100
#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_TIPO 4
#define TAM_SERVICIOS 4
#define TAM_TRABAJOS 100


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

typedef struct
{
    int idBicicleta;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
} eBicicleta;

typedef struct
{
    int id;
    char descripcion[20];
    int precio;
    int isEmpty;
} eServicio;

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fIngreso;
    int isEmpty;
} eTrabajo;

int harcodearTipos(eTipo tipos[],int tam,int cantidad);

int harcodearColores(eColor colores[],int tam,int cantidad);

int harcodearServicios(eServicio servicios[],int tam,int cantidad);

int initIsEmptyBicicleta(eBicicleta list[], int len);

int initIsEmptyTrabajos(eTrabajo list[], int len);



int main()
{
    eTipo tipoBicicleta[TAM_TIPO];
    eColor colorBicicleta[TAM_COLOR];
    eServicio servicioBicicleta[TAM_SERVICIOS];
    eBicicleta bicicletas[TAM_BICLETAS];
    eTrabajo trabajos[TAM_TRABAJOS];
    char flagExit=0;//Bandera de fin del programa
    char option;
    int idBicicletas=1;
    char exitConfirm;

    if(harcodearTipos(tipoBicicleta,TAM_TIPO,4)==1)
    {
        printf("No se pudo harcodear tipo bicicletas");
        flagExit=1;
        system("pause");
    }
    if(harcodearColores(colorBicicleta,TAM_COLOR,5)==1)
    {
        printf("No se pudo harcodear colores bicicletas");
        flagExit=1;
        system("pause");
    }
    if(harcodearServicios(servicioBicicleta,TAM_SERVICIOS,4)==1)
    {
        printf("No se pudo harcodear servicios bicicletas");
        flagExit=1;
        system("pause");
    }
    if(initIsEmptyBicicleta(bicicletas,TAM_BICLETAS)==1)
    {
        printf("No se pudo inicializar bicicletas");
        flagExit=1;
        system("pause");
    }
    if(initIsEmptyTrabajos(trabajos,TAM_TRABAJOS)==1)
    {
        printf("No se pudo inicializar bicicletas");
        flagExit=1;
        system("pause");
    }


    while(!flagExit)//INICIO ITERACION DE MENÚ
    {

        printf("----------------------\n----MENU PRINCIPAL----\n----------------------\nA_Alta Bicicleta\nB_Modificar Bicicleta\nC_Baja Bicicleta\nD_Listar Bicicletas\nE_Listar Tipos\nF_Listar Colores\nG_Listar Servicios\nH_Alta Trabajo\nI_Listar Trabajos\nJ_Salir\n----------------------\n");
        fflush(stdin);
        scanf("%c",&option);//Escaneo la opcion elegida por el usuario del menu principal
        option=tolower(option);
        switch(option)//Ingreso en el modulo de la funcion elegida
        {
        case 'a'://ALTA BICICLETA
            if(findEmptyBicicleta(bicicletas,TAM_BICLETAS)==(-1))
            {
                printf("La lista de bicicletas está completa");
            }
            else
            {
                if(altaBicicleta(bicicletas,TAM_BICLETAS,idBicicletas,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR)==1)
                {
                    printf("No se pudo realizar el alta");
                }
                else
                {
                    printf("Alta exitosa");
                }
            }
            idBicicletas++;
            break;

        case 'b'://MODIFICAR BICICLETA
            if(modificarBicicleta(bicicletas,TAM_BICLETAS,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR==1)){
                printf("No se pudo realizar la modificacion");

            }
            else{
                printf("Modificacion exitosa");
            }
            break;

        case 'c'://BAJA BICICLETA
            if(bajarBicicleta(bicicletas,TAM_BICLETAS,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR)==1){
                printf("No se pudo realizar la baja");
            }
            else{
                printf("Modificacion exitosa");
            }
            break;

        case 'd'://LISTAR BICICLETAS
                mostrarBicicletas(bicicletas,TAM_BICLETAS,tipoBicicleta,TAM_TIPO,colorBicicleta,TAM_COLOR);
            break;

        case 'e'://LISTAR TIPOS
            listarTipos(tipoBicicleta,TAM_TIPO);
            break;
        case 'f'://LISTAR COLORES
                listarColores(colorBicicleta,TAM_COLOR);
            break;
        case 'g'://LISTAR SERVICIOS


            break;
        case 'h'://ALTA TRABAJO

            break;
        case 'i'://LISTAR TRABAJOS
            break;
        case 'j'://SALIDA
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




        return 0;
    }
}



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

void mostrarTipo(eTipo tipo)
{
    printf("%d    %20s\n",tipo.id,tipo.descripcion);
}

int listarTipos(eTipo tipos[], int tam)
{
    int error=1;
    if(tipos!=NULL && tam>0)
    {
        printf("Tipos de bicicletas\nId     Tipos\n");
        for(int i=0; i<tam; i++)
        {
            mostrarTipo(tipos[i]);
        }
        printf("\n\n");
        error=0;
    }
    return error;
}

void mostrarColor(eColor color)
{
    printf("%d    %20s\n",color.id,color.nombreColor);
}

int listarColores(eColor colores[], int tam)
{
    int error=1;
    if(colores!=NULL && tam>0)
    {
        printf("Colores de bicicletas\nId     Colores\n");
        for(int i=0; i<tam; i++)
        {
            mostrarColor(colores[i]);
        }
        printf("\n\n");
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



int altaBicicleta(eBicicleta bicicletas[],int tamBicicletas,int id,eTipo tipos[], int tamTipos,eColor colores[],int tamColores)
{
    int error=1;
    int i;
    char auxChar[150];
    int auxId;
    int validacionTipo;
    int validacionColor;
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
            scanf("%d",&auxId);
            validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
            while(validacionTipo==1)
            {
                printf("Id invalido, reingrese:");
                scanf("%d",&auxId);
                validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
            }
            bicicletas[i].idTipo=auxId;

            listarColores(colores,tamColores);
            printf("Ingrese el Id de su color de bicicleta: ");
            scanf("%d",&auxId);
            validacionColor=validarIdColor(colores,tamColores,auxId);
            while(validacionColor==1)
            {
                printf("Id invalido, reingrese:");
                scanf("%d",&auxId);
                validacionColor=validarIdColor(colores,tamColores,auxId);
            }
            bicicletas[i].idColor=auxId;

            printf("Ingrese el rodado de la bicicleta (20/26/27.5/29)");
            scanf("%f",&auxRodado);
            while(auxRodado!=20 && auxRodado!=26 && auxRodado!=27.5 && auxRodado!=29)
            {
                printf("Rodado invalido, reingrese:");
                scanf("%f",&auxRodado);
            }
            bicicletas[i].rodado=auxRodado;

        }
        error=0;
    }

    return error;
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

void mostrarBicicleta(eBicicleta bicicleta,eTipo tipos[],int tamTipo,eColor colores[],int tamColor)
{
    char descripcionTipo[20];
    char descripcionColor[20];
    obtenerDescripcionTipo(tipos,tamTipo,bicicleta.idBicicleta,descripcionTipo);
    obtenerDescripcionColor(colores,tamColor,bicicleta.idBicicleta,descripcionColor);
    printf("%d    %20s  %20s   %20s    %1f\n",bicicleta.idBicicleta,bicicleta.marca,descripcionTipo,descripcionColor,bicicleta.rodado);
}

int mostrarBicicletas(eBicicleta bicicletas[], int tamBicis,eTipo tipos[], int tamTipos,eColor colores[], int tamColores)
{
    int error=1;
    if(bicicletas!=NULL && tamBicis>0)
    {
        printf("Listado de bicicletas\n");
        for(int i=0; i<tamBicis; i++)
        {
            mostrarBicicleta(bicicletas[i],tipos,tamTipos,colores,tamColores);
        }
        printf("\n\n");
        error=0;
    }
    return error;

}

int modificarBicicleta(eBicicleta bicicletas[],int tamBicis,eTipo tipos[], int tamTipos,eColor colores[], int tamColores)
{
    int error=1;
    int index;
    int validacionIdBicicleta;
    int validacionTipo;
    int auxId;
    char opcion;
    float nuevoRodado;

    mostrarBicicletas(bicicletas,TAM_BICLETAS,tipos,TAM_TIPO,colores,TAM_COLOR);
    printf("Ingrese el ID de la bicicleta que desea modificar: ");
    scanf("%d",&index);
    validacionIdBicicleta=validarIdBicicleta(bicicletas,TAM_BICLETAS,index);
    while(validacionIdBicicleta==1)
    {
        printf("Id invalido, reingrese:");
        scanf("%d",&index);
        validacionIdBicicleta=validarIdBicicleta(bicicletas,TAM_BICLETAS,index);
    }
    printf("Seleccione el campo a modificar:\nA_Tipo\nB_Rodado");
    fflush(stdin);
    scanf("%c",opcion);
    opcion=tolower(opcion);
    while(opcion!='a' && opcion!='b'){
        printf("Opcion invalida. Reingrese: ");
        scanf("%c",opcion);
    opcion=tolower(opcion);
    }
    switch(opcion){
case 'a':
    listarTipos(tipos,tamTipos);
    printf("\nIngrese el ID del nuevo tipo: ");
    scanf("%d",&auxId);
            validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
            while(validacionTipo==1)
            {
                printf("Id invalido, reingrese:");
                scanf("%d",&auxId);
                validacionTipo=validarIdTipo(tipos,tamTipos,auxId);
            }
            bicicletas[index].idTipo=auxId;
            error=0;
    break;
case'b':
    printf("Ingrese nuevo rodado: ");
    scanf("%f",&nuevoRodado);
    while(nuevoRodado!=20 && nuevoRodado!=26 && nuevoRodado!=27.5 && nuevoRodado!=29)
            {
                printf("Rodado invalido, reingrese:");
                scanf("%f",&nuevoRodado);
            }
    bicicletas[index].rodado=nuevoRodado;

    break;
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
            if((bicicletas[i].idBicicleta==id) && (bicicletas[i].isEmpty==0))//Busco aquel empleado activo cuyo Id coincide con el ingresado en la funcion
            {
                index=i;//Guardo el indice del empleado encontrado
                break;
            }
        }
    }
    return index;
}

int bajarBicicleta(eBicicleta bicicletas[], int tamBicis,eTipo tipos[], int tamTipos,eColor colores[], int tamColores)
{
    int error=1;
    int auxId;
    int validacionBici;
    int index;

    mostrarBicicletas(bicicletas,tamBicis,tipos,tamTipos,colores,tamColores);
    printf("Ingrese el ID de la bicicleta a dar de baja: ");
    scanf("%d",&auxId);
    validacionBici=validarIdBicicleta(bicicletas,tamBicis,auxId);
    if(validacionBici==1){
        printf("id invalido. Reingrese: ");
        scanf("%d",&auxId);
        validacionBici=validarIdBicicleta(bicicletas,tamBicis,auxId);
    }
    index=findBiciById(bicicletas,tamBicis,index);
    bicicletas[index].isEmpty=1;

 return error;
}

void mostrarServicio(eServicio servicio)
{
    printf("%d    %20s\n        $%d",servicio.id,servicio.descripcion,servicio.precio);
}

int listarServicios(eServicio servicios[], int tam)
{
    int error=1;
    if(servicios!=NULL && tam>0)
    {
        printf("Servicios\nId     Servicio          Precio\n");
        for(int i=0; i<tam; i++)
        {
            mostrarServicio(servicios[i]);
        }
        printf("\n\n");
        error=0;
    }
    return error;
}
