#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
typedef struct
{
    char nombre[50];
    //------------
    char password[50];
    int acumuladorCalificaciones;
    int cantidadCalificaciones;
    int idUsuario;
    int isEmpty;
}Usuario;


int usuario_init(Usuario* array,int limite);
int usuario_mostrar(Usuario* array,int limite);
int usuario_mostrarDebug(Usuario* array,int limite);
int usuario_alta(Usuario* array,int limite);
int usuario_baja(Usuario* array,int limite, int id);
int usuario_modificacion(Usuario* array,int limite, int id);
int usuario_ordenar(Usuario* array,int limite, int orden);
int buscarLugarLibreUsuario(Usuario* array,int limite);
int proximoIdUsuario();

#endif // FANTASMA_H_INCLUDED

