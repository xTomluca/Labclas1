#include <stdio.h>
#include <stdlib.h>
#include "getint.h"

int main()
{
    int edad=0;
    float edadFloat=0;
    char chart=0;
    int resultadoInt = getInt(&edad, "Ingrese su edad: ", "El numero ingresado no es valido", 100, 0, 5);
    int resultadoFloat = getFloat(&edadFloat, "Ingrese su edad: ", "El numero ingresado no es valido", 100, 0, 5);
    int resultadoChar = getChar(&chart, "Ingrese su edad: ", "El numero ingresado no es valido", 'a', 'Z', 5);

    if (resultadoInt == 0)
    {
        printf("\nSu edad es  : %d", edad);
    }
    else
    {
        printf("\nLa edad ese invalida!!!!!");
    }

    if (resultadoFloat == 0)
    {
        printf("\nSu edad es  : %f", edadFloat);
    }
    else
    {
        printf("\nLa edad ese invalida!!!!!");
    }
    if (resultadoChar == 0)
    {
        printf("\nSu edad es  : %c", chart);
    }
    else
    {
        printf("\nLa edad ese invalida!!!!!");
    }


    return 0;
}

