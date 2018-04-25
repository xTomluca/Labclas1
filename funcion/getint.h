#include <stdio.h>
#include <stdlib.h>

int getInt(int* resultado, char *mensaje, char *mensajeError, int maximo, int minimo, int reintento);
int getFloat(float* resultado, char *mensaje, char *mensajeError, int maximo, int minimo, int reintento);
int getChar(char* resultado, char *mensaje, char *mensajeError, int maximo, int minimo, int reintento);

int getInt( int* resultado, char* mensaje, char* mensajeError, int maximo, int minimo, int reintento)
{
    long resultadoAuxiliar;
    int retorno = -1;
    do
    {
        fflush(stdin);
        printf("%s", mensaje);
        scanf("%ld", &resultadoAuxiliar);
        if (resultadoAuxiliar < maximo && resultadoAuxiliar > minimo)
        {
            *resultado = (int)resultadoAuxiliar;
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
int getFloat( float* resultado, char* mensaje, char* mensajeError, int maximo, int minimo, int reintento)
{
    float resultadoAuxiliar;
    int retorno = -1;
    do
    {
        fflush(stdin);
        printf("%s", mensaje);
        scanf("%f", &resultadoAuxiliar);
        if (resultadoAuxiliar < maximo && resultadoAuxiliar > minimo)
        {
            *resultado = (float)resultadoAuxiliar;
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

int getChar( char* resultado, char* mensaje, char* mensajeError, int maximo, int minimo, int reintento)
{
    char resultadoAuxiliar;
    int retorno = -1;
    do
    {
        fflush(stdin);
        printf("%s", mensaje);
        scanf("%s", &resultadoAuxiliar);
        if (resultadoAuxiliar < maximo && resultadoAuxiliar > minimo)
        {
            *resultado = (char)resultadoAuxiliar;
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
