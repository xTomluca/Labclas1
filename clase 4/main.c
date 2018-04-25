#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int edad;
    long resFactorial;

    factorial(10,&resFactorial);
    printf("\n%ld",resFactorial);


    printf("\n%ld",factorial2(10));


    if(getInt(&edad,"\nEdad?","\nEl rago valido [0-199]",0,199,2)==0)
    {
        printf("\nLa edad es: %d\n",edad);
    }
    else
    {
        printf("NO SE LA EDAD");
    }

    return 0;
}



