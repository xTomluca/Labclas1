#include <stdio.h>
#include <stdlib.h>


int getInt(int* numero, char *mensaje, char *mensajeError, int maximo, int minimo, int reintento);
int getFloat(float* numero, char *mensaje, char *mensajeError, int maximo, int minimo, int reintento);
int getChar(char* numero, char *mensaje, char *mensajeError, int maximo, int minimo, int reintento);
float calcularPromedio(int valores[], int cantidad);
//BASICA//int calcularSuma(int numeros[], int cantidad);
int calcularPromedioPreviaSuma(float resultadoSuma, int cantidad, float* pResultado);

/** \brief
 *
 * \param numero int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param maximo int
 * \param minimo int
 * \param reintento int
 * \return int
 *
 */
int getInt( int* numero, char* mensaje, char* mensajeError, int maximo, int minimo, int reintento)
{
    long numeroAuxiliar;
    int retorno = -1;
    do
    {
        fflush(stdin);
        printf("%s", mensaje);
        scanf("%ld", &numeroAuxiliar);
        if (numeroAuxiliar < maximo && numeroAuxiliar > minimo)
        {
            *numero = (int)numeroAuxiliar;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s , le quedan %d reintentos\n",mensajeError , reintento);
            reintento--;
        }
    }while(reintento >= 0);

    return retorno;
}
//LO QUE RETORNA LA FUNCION
int getFloat( float* numero, char* mensaje, char* mensajeError, int maximo, int minimo, int reintento)
{
    float numeroAuxiliar;
    int retorno = -1;
    do
    {
        fflush(stdin);
        printf("%s", mensaje);
        scanf("%f", &numeroAuxiliar);
        if (numeroAuxiliar < maximo && numeroAuxiliar > minimo)
        {
            *numero = (float)numeroAuxiliar;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s , le quedan %d reintentos\n",mensajeError , reintento);
            reintento--;
        }
    }while(reintento >= 0);

    return retorno;
}

///////

/*float calcularPromedio(int numeros[], int cantidad)
{
    int acumulador=0;
    int i=0;
    for (i=0; i < cantidad; i++)
    {
        acumulador = acumulador + numeros[i];

    }
    return acumulador/cantidad;
}
*/
//////

/*int getChar( char* numero, char* mensaje, char* mensajeError, int maximo, int minimo, int reintento)
{
    char numeroAuxiliar;
    int retorno = -1;
    do
    {
        fflush(stdin);
        printf("%s", mensaje);
        scanf("%s", &numeroAuxiliar);
        if (numeroAuxiliar < maximo && numeroAuxiliar > minimo)
        {
            *numero = (char)numeroAuxiliar;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s , le quedan %d reintentos\n",mensajeError , reintento);
            reintento--;
        }
    }while(reintento >= 0);

    return retorno;
}*/

int calcularSuma(int numeros[], int cantidad)
{
    int acumulador=0;
    int i=0;
    for (i=0; i < cantidad; i++)
    {
        acumulador = acumulador + numeros[i];

    }
    return acumulador;
}
/*int calcularPromedioV2(int valores[], int cantidad, float* pResultado)
{
    int suma = calcularSuma(valores, cantidad);
    int retorno;
    if (cantidad == 0|| pResultado ==NULL)
    {
        retorno = -1;
    }
    else
    {
        *pResultado = (float)suma / cantidad;
        retorno = 0;
    }

    return retorno;
}*/

int calcularPromedioPreviaSuma(float resultadoSuma, int cantidad, float* pResultado)
{
    //int suma = calcularSuma(numeros, cantidad);
    int retorno;
    if (cantidad == 0|| pResultado ==NULL)
    {
        retorno = -1;
    }
    else
    {
        *pResultado = resultadoSuma / cantidad;
        retorno = 0;
    }

    return retorno;
}

