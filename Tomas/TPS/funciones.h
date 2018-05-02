#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string.h>
#include <ctype.h>


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;
    int id;

}EPersona;


///ESTATICAS
int init_personas(EPersona aCargar[],int limite);
static int buscarLugarLibre(EPersona aCargar[],int limite);
static int buscarPorId(EPersona* aCargar,int limite, int id);
///FUNCIONES DE CARGA USUARIO
int cargaPersona(EPersona aCargar[],int limite);
int getEdad(int edadMax, int edadMin, int *devNumero);
int getDni(int *devDni);
int verificacionDigito(char *auxCarga, char *mensajeError, int tamanioVector);
int getNombre(char devNombre[],int limite);
int mostrarDebug(EPersona* aCargar,int limite);
int bajaPersona(EPersona* aCargar,int limite);
int ordenarPersonas(EPersona* aCargar, int limite, int flagOrden);

static int buscarPorId(EPersona* aCargar,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && aCargar != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!aCargar[i].estado && aCargar[i].dni==dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int buscarLugarLibre(EPersona aCargar[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && aCargar != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(aCargar[i].estado==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cargaPersona(EPersona aCargar[],int limite)
{
    int devEdad;
    int devDni;
    char devNombre[50];
    int i;
    i = buscarLugarLibre(aCargar,limite);
    if(i>=0)
    {
        if(getNombre(devNombre, limite)==0)
        {
            if(getEdad(150, 1,&devEdad)==0)
            {
                if(getDni(&devDni)==0)
                {
                    strcpy(aCargar[i].nombre, devNombre);
                    aCargar[i].edad = devEdad;
                    aCargar[i].dni = devDni;
                    aCargar[i].estado = 0;
                    aCargar[i].id = i;

                }
            }
        }
    }
     return 0;
}

int getNombre(char devNombre[],int limite)
{
    int retorno=1;
    char auxNombre[50];
    printf("\nIngrese Nombre: ");
    fflush(stdin);
    fgets(auxNombre, 50, stdin);
    strcpy(devNombre, auxNombre);
    retorno=0;
    return retorno;
}
int getEdad(int edadMax, int edadMin, int *devNumero){
    char auxCharEdad[3];
    int retorno=1;
    int auxEdad;
    printf("\nIngrese Edad: ");
    fflush(stdin);
    fgets(auxCharEdad, 50, stdin);
    auxEdad = atoi(auxCharEdad);
    while(auxEdad > edadMax || auxEdad < edadMin)
    {
        printf("\nLa edad ingresada no es valida. REINGRESE EDAD: ");
        scanf("%d", &auxEdad);
    }
    *devNumero = auxEdad;
    retorno=0;
    return retorno;
}
int getDni(int *devDni){

    char auxDni[9];
    int retorno=1;
    int longitudDni=0;
    printf("\nIngrese DNI: ");
    fflush(stdin);
    fgets(auxDni, 9, stdin);
    verificacionDigito(auxDni,"EL DNI NO CONTIENE LETRAS, REINGRESE DNI VALIDO: ", 9);
    longitudDni = strlen(auxDni);
    while(!(longitudDni == 7 || longitudDni == 8))
    {
        printf("\nEl DNI ingresado no es valido. REINGRESE DNI: ");
        fflush(stdin);
        fgets(auxDni, 9, stdin);
        longitudDni = strlen(auxDni);

    }
        *devDni = atoi(auxDni);
        retorno=0;
    return retorno;
}
int verificacionDigito(char *auxCarga, char *mensajeError, int tamanioVector)
{
    int i=0;
    int j=strlen(auxCarga);
    int retorno =1;
    while(i<j-1)
    {
        if(isdigit(auxCarga[i])!=0) ///VUELVE A ITERAR SI ES DIGITO EL CHAR
        {
            i++;
        }
        else
        {
            printf("%s", mensajeError);
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
        }
    }
        retorno =0;
    return retorno;
}

int init_personas(EPersona aCargar[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && aCargar != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            aCargar[i].estado=1;
        }
    }
    return retorno;
}



int mostrarDebug(EPersona* aCargar,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && aCargar != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - NOMBRE :%s - EDAD :%d - DNI :%d - ID :%d  - ESTADO: %d \n", aCargar[i].nombre, aCargar[i].edad, aCargar[i].dni, aCargar[i].id, aCargar[i].estado);
        }
    }
    return retorno;


}

int bajaPersona(EPersona* aCargar,int limite)
{
    int indiceABorrar, retorno;
    int dni=0;
    getDni(&dni);
    indiceABorrar = buscarPorId(aCargar, 20, dni);
    if(indiceABorrar < limite && indiceABorrar != NULL)
    {
        aCargar[indiceABorrar].estado = 1;
    }
    retorno = 0;
    return retorno;
}

int ordenarPersonas(EPersona* aCargar, int limite, int flagOrden)
{
	int i=0, ordenar=0;
	EPersona aux;
    int retorno = 1;

    if(limite > 0 && aCargar != NULL)
    {
            do
            {
                ordenar = 0;
                for(i=0;i<limite-1;i++)
                {
                    if(!aCargar[i].estado && !aCargar[i+1].estado)
                    {
                        /// DE MENOR A MAYOR                                                        DE MAYOR A MENOR
                        if((strcmp(aCargar[i].nombre,aCargar[i+1].nombre) > 0 && flagOrden ==0) || (strcmp(aCargar[i].nombre,aCargar[i+1].nombre) < 0 && flagOrden ==1))
                        //if((aCargar[i].edad > aCargar[i+1].edad && flagOrden ==0) || (aCargar[i].edad < aCargar[i+1].edad && flagOrden ==1))
                        {
                            aux = aCargar[i];
                            aCargar[i] = aCargar[i+1];
                            aCargar[i+1] = aux;
                            ordenar =1;
                        }

                    }
                }



            }while(ordenar==1);

	}


    if(ordenar ==0)
    {
        if(limite > 0 && aCargar != NULL)
        {
            for(i=0;i<limite;i++)
            {
                if(!aCargar[i].estado)
                     printf("[DEBUG] - NOMBRE :%s - EDAD :%d - DNI :%d - ID :%d  - ESTADO: %d \n", aCargar[i].nombre, aCargar[i].edad, aCargar[i].dni, aCargar[i].id, aCargar[i].estado);
            }
        }
    }

	return retorno;
}

#endif // FUNCIONES_H_INCLUDED
