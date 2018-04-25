#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
///---Primero defino la estructura
typedef struct {
    int edad;
    char nombre[50];
    char apellido[50];
}Personas; ///LLEVA ;
*/


typedef struct {
    char nombre[50];
    char descripcion[50];
    float precio;
    int carga;
}Producto;

int cargaProducto(Producto articulo[], int indice, int tamanio, int productoCargado);
int imprimeProducto(Producto articulo[], int indice, int tamanio, int productoCargado);
int devolverIndice(Producto articulo[], int indice);

int main()
{
    int validacion = -1;
    int indiceVacio;
    Producto productos[200];

    cargaProducto(productos, 2, 2, validacion);
    imprimeProducto(productos, 2, 2, validacion);
    indiceVacio = devolverIndice(productos , 2);
    if(indiceVacio != -1)
    {
        printf("El lugar vacio es %d", indiceVacio);
    }
    else
    {
        printf("NO HAY LUGAR VACIO");
    }

    //printf("Ingrese nombre producto");
    //fgets(productos[0].nombre, 50, stdin);

   /* for(i=0; i < 0; i++)
    {
        strcpy(productos[0].nombre);
        strcpy(productos[0].descripcion, "Bebida de cola");
        productos[0].precio = 10;
    }*/


    ///printf(productos[0].nombre);
    //printf(productos[0].descripcion);
    //printf("%f",productos[0].precio);

    /*
    Persona persona[50];
    int lista[50];

    /// personas es el nombre de la variable

    strcpy(personas[0].nombre, "toto");
    */


    return 0;
}

int cargaProducto(Producto articulo[], int indice, int tamanio, int productoCargado)
{

    int i=indice;
    char auxiliar[50];

    /*for(i=0; i < indice; i++)
    {*/
        articulo[i].carga = productoCargado;
        printf("\nIngrese nombre producto\n");
        fflush(stdin);
        fgets(articulo[i].nombre, 50, stdin);
        printf("\nIngrese descripcion\n");
        fflush(stdin);
        fgets(articulo[i].descripcion, 50, stdin);
        printf("\nIngrese precio producto\n");
        fflush(stdin);
        fgets(auxiliar, 50, stdin);
        articulo[i].precio = atof(auxiliar);
        articulo[i].carga = 0;
        //strcpy(articulo[i].precio, auxiliar);
        //scanf("%f",&articulo[i].precio);
    ///}
    /*if (strlen(articulo[i].nombre) != 0 && articulo[i].nombre != "\n")
    {
        articulo[i].carga = 0;
    }*/

      // else
        //{

       // }

    return 0;
}
int imprimeProducto(Producto articulo[], int indice, int tamanio, int productoCargado)
{
    int i;
    for(i=0; i < indice; i++)

    {
            if(articulo[i].carga == 0)
            {
                printf("\n%s",articulo[i].nombre);
                printf("\n%s",articulo[i].descripcion);
                printf("\n%.2f", articulo[i].precio);
            }

    }
    return 0;
}
int devolverIndice(Producto articulo[], int indice)
{

    int i;
    for(i=0; i < indice; i++)
    {
        if(articulo[i].carga == -1)
        {
           return i;
        }

    }
    return -1;
}


