#include <stdio.h>
#include <stdlib.h>
#include "getint.h"
#define SIZE_ARRAY 5

int main()
{
    int numeros[SIZE_ARRAY];
    int i=0;
    //float prom=0;
    int suma;
    float resultadoProm;

    for(i=0; i < SIZE_ARRAY; i++)

    {
        getInt(&numeros[i], "Ingrese numero: ", "Numero invalido", 32767, -32767, 5);
    }

    for(i=0; i < SIZE_ARRAY; i++)
    {
    printf("\n\nEl numero %d es: %d", i+1,numeros[i]);
    }

        suma = calcularSuma(numeros, SIZE_ARRAY);
        calcularPromedioPreviaSuma(suma, SIZE_ARRAY,&resultadoProm);
        //prom = calcularPromedio(numeros, SIZE_ARRAY);


        printf("\n\nLa sumad de todos los numeros ingresados es: %d", suma);

        printf("\n\nEl promedio de los numeros ingresados es: %f\n", resultadoProm);

    return 0;
}
