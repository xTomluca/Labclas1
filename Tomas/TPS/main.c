#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "string.h"


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona personas[20];
    init_personas(personas, 20);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                cargaPersona(personas, 20);
                break;
            case 2:
                bajaPersona(personas, 20);
                break;
            case 3:
                ordenarPersonas(personas, 20, 0);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
            case 6:
                mostrarDebug(personas, 20);
                break;
        }
    }

    return 0;
}
