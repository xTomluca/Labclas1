#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"
#include "publicacion.h"
#include "utn.h"
#define QTY 10

int main()
{
    Usuario array[QTY];
    Publicacion arrayProducto[QTY];
    //int i;
    int menu;
    int auxiliarId;

    usuario_init(array,QTY);
    publicacion_init(arrayProducto,QTY);

    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,14,1);
        switch(menu)
        {
            case 1:
                usuario_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                usuario_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                usuario_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                usuario_mostrar(array,QTY);
                break;
            case 5:
                usuario_ordenar(array,QTY,0);
                break;
            case 6:
                usuario_mostrarDebug(array,QTY);
                break;
            case 7:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                if(array[auxiliarId].idUsuario==auxiliarId)
                {
                    publicacion_alta(arrayProducto,QTY, auxiliarId);
                }
                else
                {
                    printf("EL ID INGRESADO ES INVALIDO");
                }

                break;
            case 8:
                publicacion_mostrarDebug(arrayProducto, QTY);
                break;
            case 10:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                if(!array[auxiliarId].isEmpty && array[auxiliarId].idUsuario==auxiliarId)
                {
                    if(publicacion_modificacion(arrayProducto, QTY, auxiliarId)==0)
                    {
                        printf("\nVALOR MODIFICADO CON EXITO!!\n\n");
                    }
                }
                else
                {
                    printf("EL ID INGRESADO ES INVALIDO");
                }
                break;
            case 11:

                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                if(!array[auxiliarId].isEmpty && array[auxiliarId].idUsuario==auxiliarId)
                {
                    if(publicacion_baja(arrayProducto, QTY, auxiliarId)==0)
                    {
                        printf("\nVALOR MODIFICADO CON EXITO!!\n\n");
                    }

                }
                else
                {
                    printf("EL ID INGRESADO ES INVALIDO");
                }
                break;
            case 12:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                if(!array[auxiliarId].isEmpty && array[auxiliarId].idUsuario==auxiliarId)
                {
                    publicacion_listarUsuario(arrayProducto, QTY ,auxiliarId);
                }
                else
                {
                    printf("EL ID INGRESADO ES INVALIDO");
                }
                break;
            case 13:
                publicacion_listarPublicaciones(arrayProducto,QTY,array);
                break;
            case 14:
                publicacion_compra(arrayProducto, QTY, array);
                break;
        }


    }while(menu != 9);

    return 0;
}
