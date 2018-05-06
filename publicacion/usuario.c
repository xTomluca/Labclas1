#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"
#include "utn.h"

/** \brief
 * \param array Usuario*
 * \param limite int
 * \return int
 *
 */
int usuario_init(Usuario* array,int limite)
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

int usuario_mostrarDebug(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %d\n",array[i].idUsuario, array[i].nombre, array[i].password, array[i].isEmpty);
        }
    }
    return retorno;
}

int usuario_mostrar(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %d\n",array[i].idUsuario, array[i].nombre, array[i].password, array[i].isEmpty);
        }
    }

    return retorno;
}

int usuario_alta(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    char usuario[50];
    char password[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibreUsuario(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",usuario,40,2))
            {
                printf("Ingrese password: ");
                fflush(stdin);
                fgets(password, 20, stdin);
                if(!esAlfaNumerico(password))
                {
                    retorno = 0;
                    strcpy(array[i].nombre,usuario);
                    strcpy(array[i].password,password);
                    //------------------------------
                    //------------------------------
                    array[i].acumuladorCalificaciones=0;
                    array[i].cantidadCalificaciones=0;
                    array[i].idUsuario = proximoIdUsuario();
                    array[i].isEmpty = 0;
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


int usuario_baja(Usuario* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==id)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}




int usuario_modificacion(Usuario* array,int limite, int id)
{
    int retorno = -1;
    int i;
    char usuario[50];
    char password[50];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==id)
            {
                if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",usuario,40,2))
                {
                    printf("Ingrese password: ");
                    fflush(stdin);
                    fgets(password, 20, stdin);
                    if(!esAlfaNumerico(password))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,usuario);
                        strcpy(array[i].password,password);
                        //------------------------------
                        //------------------------------
                    }
                }
                else
                {
                    retorno = -3;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int usuario_ordenar(Usuario* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Usuario auxiliarEstructura;

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
                    if(( strcmp(array[i].nombre, array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
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

int buscarLugarLibreUsuario(Usuario* array,int limite)
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


int proximoIdUsuario()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
