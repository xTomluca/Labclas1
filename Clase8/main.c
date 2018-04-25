#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

typedef struct{
    char nombre[50];
    char apellido[50];
    int edad;
    int slotCargado;
}Persona;

int cargaProducto(Persona aCargar[], int indice, int productoCargado);
int devolverIndice(Persona aCargar[], int indice);
int main()
{
    int indiceVacio, opcionUsuario=0;
    char seguirOperando = 's', auxiliarOpcion[3];
    int productoCargado = -1;
    Persona personas[200];

    while(seguirOperando=='s'){


    printf("\n\n<1> CARGAR PRODUCTO");
    printf("\n<2> IMPRIMO LISTADO");
    printf("\n<3> SALIR");
    fflush(stdin);
    fgets(auxiliarOpcion, 3, stdin);
    opcionUsuario = atoi(auxiliarOpcion);
    while(!(opcionUsuario <= 3 && opcionUsuario > 0))
        {
            printf("\nValor ingresado invalidado, intentelo nuevamente \n");
            fflush(stdin);
            fgets(auxiliarOpcion, 3, stdin);
            opcionUsuario = atoi(auxiliarOpcion);
        }

//    scanf("%d", &opcionUsuario);
    switch(opcionUsuario)
    {
        case 1:
            system("cls");
            cargaProducto(personas, 200, productoCargado);
            indiceVacio = devolverIndice(personas , 200);
            if(indiceVacio != -1)
            {
                printf("\nEl lugar vacio es %d", indiceVacio);
            }
            else
            {
                printf("\nNO HAY LUGAR VACIO");
            }

            break;
        case 3:
            seguirOperando = 'n';

    }
    }


    return 0;
}
int cargaProducto(Persona aCargar[], int indice, int productoCargado){

    char auxiliar[50];
    int devNumero;
    int validacionEdad;
        //do/// AGREGAR DO WHILE QUE REPITA HASTA QUE CAMBIE LA CONDICION DEL
        aCargar[indice].slotCargado = productoCargado;
        printf("\nIngrese NNombre: ");
        fflush(stdin);
        fgets(aCargar[indice].nombre, 50, stdin);
        fflush(stdin);
        printf("\nIngrese Apellido: ");
        fgets(aCargar[indice].apellido, 50, stdin);
        printf("\nIngrese Edad: ");
        fflush(stdin);
        fgets(auxiliar, 50, stdin);
        validacionEdad = getEdad(auxiliar, 150, 1, &devNumero);
        aCargar[indice].slotCargado = 0;
        if(validacionEdad==0)
        {
            aCargar[indice].edad = devNumero;
            printf("\nNOMBRE: %s \nAPELLIDO: %s \nEDAD: %d\n", aCargar[indice].nombre, aCargar[indice].apellido, aCargar[indice].edad);
        }
     return 0;
}
int devolverIndice(Persona aCargar[], int indice){
    int i;
    int retorno;
    retorno = -1;
    for(i=0; i < indice; i++)
    {

        if(aCargar[i].slotCargado == -1)
        {
           retorno = i;
        }

    }
    return retorno;
}
