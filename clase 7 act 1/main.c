#include <stdio.h>
#include <stdlib.h>
#define SIZE_ARRAY 10
int main()
{
    int i;
    int j;
    int temporal;
    int lista[SIZE_ARRAY];

    for(i=0;i<SIZE_ARRAY;i++)
    {
        printf("Ingrese valores para la lista y se acomodaran ");
        scanf("%d",&lista[i]);

    }
    for(i=1;i<SIZE_ARRAY;i++)
    {
        temporal = lista[i];
        j = i-1;
        while(j>=0 && temporal<lista[j])/// el signo(<) son de menor a mayor y el signo (>) de mayor a menor
        {
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1]= temporal;
    }
    printf("ordenado queda asi :\n");
    for(i=0;i<SIZE_ARRAY;i++)
    {
        printf("%d\n",lista[i]);
    }

    return 0;
}
