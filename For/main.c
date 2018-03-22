#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CANTIDAD_NUMEROS 4

int main()
{
    int numero;
    float acumulador=0;
    float promedio;
    int max=INT_MIN;
    int min=INT_MAX;
    int i;

    for (i=0; i< CANTIDAD_NUMEROS; i++)
    {
        printf("Ingrese numero ");
        scanf("%d", &numero);
        acumulador = acumulador + numero;
    if(min>numero)
    {
        min = numero;
    }
    if(max<numero)
    {
        max = numero;
    }
    }


    promedio = acumulador / CANTIDAD_NUMEROS;
    printf("\nEl promedio de los numeros ingresados es: %.2f\n", promedio);
    printf("\nEl numero maximo es: %d", max);
    printf("\nEl numero minimo es: %d", min);
    return 0;
}
