#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define SIZE_ARRAY 5
int main()
{
    int i;
    int array[SIZE_ARRAY]={1,4,2,5,7};

    printf("DE mayor a menor\n");
    sort_ordenarArrayEnteros(array,SIZE_ARRAY,0);
    if(sort_ordenarArrayEnteros(array,SIZE_ARRAY,0)==0)
    {
        for(i=0;i<SIZE_ARRAY;i++)
        {
            printf("%d",array[i]);
        }
    }
    printf("\n\n");
    printf("DE menor a mayor\n");
    sort_ordenarArrayEnteros(array,SIZE_ARRAY,1);
    if(sort_ordenarArrayEnteros(array,SIZE_ARRAY,1)==0)
    {
        for(i=0;i<SIZE_ARRAY;i++)
        {
            printf("%d",array[i]);
        }
    }

    return 0;
}

