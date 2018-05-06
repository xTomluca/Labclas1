#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include "usuario.h"
typedef struct
{
    char nombreProd[50];
    float precio;
    int cantidadVentas;
    int idUsuario;
    int idProducto;
    int stock;
    int isEmpty;
}Publicacion;


int publicacion_init(Publicacion* array,int limite);
int publicacion_listarUsuario(Publicacion* array,int limite, int id);
int publicacion_mostrarDebug(Publicacion* array,int limite);
int publicacion_alta(Publicacion* array,int limite, int auxUsuario);
int publicacion_baja(Publicacion* array,int limite, int id);
int publicacion_modificacion(Publicacion* array,int limite, int id);
int publicacion_ordenar(Publicacion* array,int limite, int orden);
int buscarLugarLibrePublicacion(Publicacion* array,int limite);
int publicacion_listarPublicaciones(Publicacion* array, int limite, Usuario* arrayUsuario);
int publicacion_compra(Publicacion* array, int limite, Usuario* arrayUsuario);
int proximoIdPublicacion();

#endif // FANTASMA_H_INCLUDED

