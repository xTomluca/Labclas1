

int sort_ordenarArrayEnteros(int *array,int cantidadElementos,int flagOrden)
{
    int i;
    int flagSwap;
    int auxiliar;
    int retorno = -1;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap=0;

            for(i=0; i < cantidadElementos -1 ;i++)
            {
               if((array[i] < array[i+1] && flagOrden == 0)||(array[i] > array[i+1] && flagOrden == 1))
               {
                   auxiliar = array[i];
                   array[i]= array[i+1];
                   array[i+1]= auxiliar;

                   flagSwap=1;
               }
            }

        }while(flagSwap);
    }return retorno;
}
