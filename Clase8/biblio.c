#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"


int getEdad(char *num, int edadMax, int edadMin, int *devNumero){

    int retorno=1;
    int auxiliar;
    auxiliar = atoi(num);
    while(auxiliar > edadMax || auxiliar < edadMin)
    {
        printf("\nLa edad ingresada no es valida. REINGRESE EDAD: ");
        scanf("%d", &auxiliar);
    }
    *devNumero = auxiliar;
    retorno=0;
    return retorno;
}
