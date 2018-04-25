#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char array1[50];
    char array2[50];



    printf("%s",array2);
    scanf("%s",array1);
    strcpy(array2,array1);///copia lo de un array a otro array de caracteres
    printf("%s",array2);


    return 0;
}
int getInt()
{
    int arrayAuxiliar[50];
    int i;
    int retorno=0;
    int numero;
    char array;

    fgets(array,sizeof(arrayAuxiliar),stdin);///es como el strlen
    for(i=0;i<strlen(arrayAuxiliar);i++)
    {
        if(array[i] < '0' || array[i] > '9')/// aca entro si esta mal/// y aca no va ni cero ni nueve va lo que vale de origen en la tabla
        {
            retorno=-1;/// con las comillas simples me muestra el valor asccic de esos valores 46 y 57
            break;
        }
    }
    if(retorno == 0)
    {
      numero = atoi(arrayAuxiliar);
      printf("ingresaste %d",numero);
    }
    else
    {
       printf("error no ingresaste un numero");
    }
    return numero;


}
