#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main()
{
    int arrayEdades[11] = {22,56,55,66,29};
    char arrayNombres[11][50] = {"Juan","Pedro","Jose","Luis","Diego"};
    char arrayApellido[11][50] = {"Juan","Pedro","Jose","Luis","Diego"};

    //scanf("%[0-9a-zA-Z -*,.]",palabra);


   // sort_mostrarArrayEnteros(arrayEdades,5);

    sort_mostrarArrayCadenaCaracteres(arrayNombres,5);
    printf("\n\n");
    printf("\n\n");
    sort_ordenarArrayCadenaCaracteres(arrayNombres,5,0);
    sort_mostrarArrayCadenaCaracteres(arrayNombres,5);

    printf("\n\n");
/*
    if(!sort_ordenarArrayEnteros(arrayEdades,5,1))
    {
        sort_mostrarArrayEnteros(arrayEdades,5);
        printf("\n\n");
    }
    else
    {
        printf("ERROR");
    }*/
    return 0;
}
