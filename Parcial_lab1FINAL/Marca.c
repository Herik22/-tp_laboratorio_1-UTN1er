#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"Marca.h"

void marca_hardcodeo(eMarca listaMarca[],int tamMar)
{
    int id_[3]={10000,10001,10002};
    char marca[3][20]={"ford","fiat","vw"};
    char pais [3][50]={"eeuu","italia","alemania"};
    for(int i=0;i<tamMar;i++)
    {
        listaMarca[i].id=id_[i];
        strcpy(listaMarca[i].marca,marca[i]);
        strcpy(listaMarca[i].pais,pais[i]);
    }
}

int marca_obtenerMarcaById(eMarca listaMarca[],int tamMar,char* buffer,int idMarca)
{
    int retorno=-1;
    if(listaMarca!=NULL && tamMar>0)
    {
        for(int i=0;i<tamMar;i++)
        {
            if(listaMarca[i].id==idMarca)
            {
                strcpy(buffer,listaMarca[i].marca);
                retorno=0;
            }
        }
    }
    return retorno;
}

void mostrar_marca(eMarca listaMarca[],int tamMar)
{
    int i;
    if(listaMarca!=NULL && tamMar>0)
    {
        printf("\n NOMBRE:   PAIS:   \n");
        for(i=0;i<tamMar;i++)
        {
            printf("  %s %10s  \n ",listaMarca[i].marca,
                              listaMarca[i].pais);
        }
    }
}

int marca_obtenerIdbyname(eMarca listaMarca[],int tamMar)
{
    int retorno=-1;
    char aux_char[50];

    printf("Ingrese el nombre de la marca.\n\n");
    fflush(stdin);
    scanf("%s",aux_char);

    if(listaMarca!=NULL && tamMar>0)
    {
        for(int i=0;i<tamMar;i++)
        {
            if(!strcmp(listaMarca[i].marca,aux_char))
            {
                retorno=listaMarca[i].id;
            }
        }
    }
    return retorno;
}

