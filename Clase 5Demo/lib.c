#include <stdio.h>
#include <stdlib.h>

int getInt(int* resultado,
           char* mensaje,
           char* mensajeError,
           int minimo,
           int maximo,
           int reintentos)
{
    int retorno = -1;
    long auxiliarLong;
    do
    {
        reintentos--;
        printf("%s",mensaje);
        scanf("%ld",&auxiliarLong);
        if(auxiliarLong >= minimo && auxiliarLong <= maximo)
        {
            *resultado = (int)auxiliarLong;
            retorno = 0;
            break;
        }
        printf("%s",mensajeError);
    }while(reintentos >= 0);
    return retorno;
}


//10*9*8*7*6*5*4*3*2*1

int factorial(int numero, long* resultado)
{
    long auxiliarResultado;
    auxiliarResultado = (long)numero;
    while(numero > 1)
    {
        numero--;
        auxiliarResultado = auxiliarResultado * numero;
    }
    *resultado = auxiliarResultado;
    return 0;
}



long factorial2(int numero)
{
    if(numero == 1) return 1;
    return numero * factorial2(numero-1);
}


