#include <stdio.h>
#include <stdlib.h>

#define SIZE_ARRAY  5

float calcularProm(int valores[],int cantidad);

int calcularPromV2(int valores[], int cantidad, float* pResultado);

int main()
{

    int lista[SIZE_ARRAY];
    int i;
    int aux=0;
    float prom;
    for(i=0; i<SIZE_ARRAY; i++)
    {
        printf("ingrese un numero:");
        scanf("%d",&lista[i]);
    }
    /*
    for(i=0; i<SIZE_ARRAY; i++)
    {
        aux = aux + lista[i];
    }
    prom = (float)aux / SIZE_ARRAY;
    printf("prom: %f",prom);
    */

    //prom = calcularProm(lista,SIZE_ARRAY);

    if(calcularPromV2(lista,SIZE_ARRAY,&prom)==0)
        printf("prom: %f",prom);
    else
        printf("error de datos en array");

    //calcularProm(otroArray,20);

    return 0;
}



float calcularProm(int valores[],int cantidad)
{
    int i;
    int suma=0;
    float promedio;
    for(i=0; i<cantidad;i++)
    {
        suma = suma + valores[i];
    }
    promedio = ((float)suma)/cantidad;
    return promedio;
}


int calcularPromV2(int valores[],
                   int cantidad,
                   float* pResultado)
{
   int i;
    int suma=0;
    float promedio;
    int retorno;

    if(cantidad<=0)
        retorno=-1;
    else
        retorno=0;

    for(i=0; i<cantidad;i++)
    {
        suma = suma + valores[i];
    }

    *pResultado = ((float)suma)/cantidad;
    return retorno;
}
