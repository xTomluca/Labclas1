#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int resultado;
    char continuar;


    do
    {
        printf("Ingrese primer numero\n");
        scanf("%d", &numero1);
        printf("Ingrese segundo numero\n");
        scanf("%d",&numero2);

        if(numero1 > 0 && numero2 > 0)
        {
            resultado = numero1 + numero2;
            printf("El resultado es :%d", resultado);
        }
        else if (numero2 > 0 && numero1 <= 0)
        {
            printf("\nEl primer numero es menor/igual a 0");
        }
        else if (numero2 <= 0 && numero1 > 0)
        {
            printf("\nEl segundo numero es menor/igual a 0");
        }
        printf("Desea continuar? S para continuar");
        fflush(stdin);
        scanf("%c", &continuar);
    }while(continuar == 's');
    return 0;
}
