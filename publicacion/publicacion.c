#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "usuario.h"
#include "utn.h"

/** \brief
 * \param array Publicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_init(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int publicacion_mostrarDebug(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - IDPROD: %d - NOMPROD: %s - IDUS: %d - $PROD: %f - STOCK: %d - EST: %d \n",array[i].idProducto, array[i].nombreProd, array[i].idUsuario, array[i].precio, array[i].stock, array[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_listarUsuario(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==id)
            {
                retorno = 0;
                printf("\nIDPRODUCTO: %d - NOMBRE: %s - PRECIO: %f - STOCK: %d - CANTIDADVENDIDA: %d\n\n", array[i].idProducto, array[i].nombreProd, array[i].precio, array[i].stock, array[i].cantidadVentas);
            }

        }
    }
    if(retorno==-1)
    {
        printf("\nEl usuario no cuenta con productos publicados\n\n");
    }
    return retorno;
}

int publicacion_alta(Publicacion* array,int limite, int auxUsuario)
{
    int retorno = -1;
    int i;
    char nombreProd[50];
    float precioProd;
    int auxStock;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibrePublicacion(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre de producto? ","\nNo es un producto VALIDO!","El max caracteres es 40",nombreProd,40,2))
            {
                if(!getValidFloat("Precio de producto", "El precio ingresado es invalido", &precioProd, 0, 99999999,2))
                {
                    if(!getValidInt("Stock","Valor ingresado invalido",&auxStock, 0, 99999, 2))
                    {
                        retorno = 0;
                        strcpy(array[i].nombreProd,nombreProd);
                        array[i].precio = precioProd;
                        array[i].idUsuario = auxUsuario;
                        //------------------------------
                        //------------------------------
                        array[i].idProducto=proximoIdPublicacion();
                        array[i].stock = auxStock;
                        array[i].cantidadVentas = 0;
                        array[i].isEmpty = 0;
                    }


                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}

int publicacion_baja(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i, idProducto;
    char charIdProducto[3];

    if(limite > 0 && array != NULL)
    {
        retorno = -2;

        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idProducto==id)
            {
                retorno=1;
                printf("IDPRODUCTO: %d - NOMBRE: %s - PRECIO: %f - STOCK: %d - CANTIDADVENDIDA: %d", array[i].idProducto, array[i].nombreProd, array[i].precio, array[i].stock, array[i].cantidadVentas);
            }
        }
        if(retorno==1)
        {
            printf("Ingrese id producto a dar de baja");
            fflush(stdin);
            fgets(charIdProducto, 3,stdin);
            idProducto = atoi(charIdProducto);
            if(!array[idProducto].isEmpty && array[idProducto].idProducto==idProducto && array[idProducto].idUsuario==id)
            {
                array[idProducto].isEmpty=1;
            }

        }
    }
    return retorno;
}

int publicacion_modificacion(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    char auxIdproducto[3];
    int idProductoModificar;
    float precioNuevo;
    int stockNuevo;
    //char auxModProd[50];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==id)
            {
                retorno=1;
                printf("[DEBUG] - IDPROD: %d - NOMPROD: %s - $PROD: %f - IDUS: %d - STOCK: %d - EST: %d \n",array[i].idProducto, array[i].nombreProd, array[i].precio, array[i].idUsuario, array[i].stock, array[i].isEmpty);
            }
        }
        if(retorno==1)
        {
            printf("\nINGRESE NUMERO ID PRODUCTO A EDITAR: \n\n");
            fflush(stdin);
            fgets(auxIdproducto,3,stdin);
            idProductoModificar = atoi(auxIdproducto);
            if(!array[idProductoModificar].isEmpty && array[idProductoModificar].idUsuario==id && array[idProductoModificar].idProducto==idProductoModificar)
            {
                if(!getValidFloat("Ingrese nuevo precio", "Valor invalido", &precioNuevo, 0, 99999, 2))
                {
                    if(!getValidInt("Ingrese modificacion stock", "Valor invalido", &stockNuevo, 0, 9999, 2))
                    {
                        retorno = 0;
                        array[idProductoModificar].precio=precioNuevo;
                        array[idProductoModificar].stock=stockNuevo;

                    }
                }
            }

        }
    }
    else
    {
        printf("El array no esta cargado");
    }
    return retorno;
}

int publicacion_ordenar(Publicacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    ///COMPARA CARACTER CON CARACTER SI EL PRIMERO ESTA ANTES EN EL ABC DEVUELVE +
                    ///IGUALES DEVUELVE 0
                    if(( strcmp(array[i].nombreProd, array[i+1].nombreProd) > 0 && orden) || (strcmp(array[i].nombreProd,array[i+1].nombreProd) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int buscarLugarLibrePublicacion(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int proximoIdPublicacion()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


///9. LISTAR PUBLICACIONES:​ Se mostrará una lista de productos indicando: id,
///nombre, precio, cantidad vendida, stock y nombre del usuario.

int publicacion_listarPublicaciones(Publicacion* array, int limite, Usuario* arrayUsuario)
{
    int i;
    int retorno = -1;
    for(i=0;i<limite;i++)
    {
        if(!array[i].isEmpty)
        {
            retorno=0;
            printf("\nIDPRODUCTO: %d - NOMBRE: %s - PRECIO: %f - CANTIDADVENDIDA: %d - STOCK: %d - NOMBREUSER: %s\n", array[i].idProducto, array[i].nombreProd, array[i].precio, array[i].cantidadVentas, array[i].stock, arrayUsuario[i].nombre);
        }
    }
    if(retorno==-1)
    {
        printf("NO HAY PUBLICACIONES DISPONIBLES\n");
    }

    return retorno;
}

int publicacion_compra(Publicacion* array, int limite, Usuario* arrayUsuario)
{
    int auxIdProducto, auxIdUsuario, auxCalificacion, cantidadAComprar, retorno = -1;
    if(getValidInt("Ingrese ID Producto", "Valor ingresado INVALIDO", &auxIdProducto, 0, 1000, 2)==0)
    {
        if(array[auxIdProducto].idProducto==auxIdProducto)
        {
            if(!getValidInt("Ingrese cantidad a comprar", "Valor ingresado INVALIDO", &cantidadAComprar, 0, 1000, 2))
            {
                printf("STOCK DISPONIBLE %d\n", array[auxIdProducto].stock);
                if(array[auxIdProducto].stock>=cantidadAComprar)
                {
                    if(!getValidInt("Ingrese calificacion <1-10>","Valor ingresado INVALIDO", &auxCalificacion, 1, 10, 3))
                    {
                        retorno =0;
                        auxIdUsuario = array[auxIdProducto].idUsuario;
                        printf("VEIJA ACUMULADORCALIFICACION %d - CANTIDAD CALIF %d\n", arrayUsuario[auxIdUsuario].acumuladorCalificaciones, arrayUsuario[auxIdUsuario].cantidadCalificaciones);
                        array[auxIdProducto].stock = array[auxIdProducto].stock - cantidadAComprar;
                        arrayUsuario[auxIdUsuario].cantidadCalificaciones = arrayUsuario[auxIdUsuario].cantidadCalificaciones +1;
                        arrayUsuario[auxIdUsuario].acumuladorCalificaciones = arrayUsuario[auxIdUsuario].acumuladorCalificaciones + auxCalificacion;
                        array[auxIdProducto].cantidadVentas = array[auxIdProducto].cantidadVentas + cantidadAComprar;
                        printf("STOCK DISPONIBLE %d\n", array[auxIdProducto].stock);
                        printf("\nACUMULADORCALIFICACION %d - CANTIDAD CALIF %d\n", arrayUsuario[auxIdUsuario].acumuladorCalificaciones, arrayUsuario[auxIdUsuario].cantidadCalificaciones);
                    }
                }
                else
                {
                    printf("\nERROR, CANTIDAD DISPONIBLE: %d \n", array[auxIdProducto].stock);
                }
            }

        }
        else
        {
            printf("ERROR, ID INVALIDO");
        }
    }


return retorno;
}
