#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Nacionalidad.h"

void nacionalidad_hardcodear(eNacionalidad listaNacion[],int tamNa)
{
    int id_[3]={1000,1001,1002};
    char pais_[3][50]={"italia","argentina","uruguay"}; //italiano   argento  uruguayo
    char idioma_[3][50]={"italiano","espaniol","espaniol"};
    char descripcion_[3][50]={"italiano","argentino","uruguayo"};

    for(int i=0;i<3;i++)
    {
        listaNacion[i].id=id_[i];
        strcpy(listaNacion[i].pais,pais_[i]);
        strcpy(listaNacion[i].idioma,idioma_[i]);
        strcpy(listaNacion[i].descripcion,descripcion_[i]);
    }
}

int nacionalidad_obtenerDescripByID(eNacionalidad listaNacion[],int tamNa,char* buffer,int idNacionalidad)
{
    int retorno=-1;
    if(listaNacion!=NULL && tamNa>=0 && idNacionalidad!=0)
    {
        for(int i=0;i<tamNa;i++)
        {
            if(listaNacion[i].id==idNacionalidad)
            {
                strcpy(buffer,listaNacion[i].descripcion);
                retorno=0;
            }
        }
    }
    return retorno;
}

void nacionalidad_mostrar(eNacionalidad listaNacion[],int tamNa)
{
    if(listaNacion!=NULL && tamNa>0)
    {
        printf("Pais:    Idioma:   Gentilicio:\n");
        for(int i=0;i<tamNa;i++)
        {
            printf("%s %10s %10s\n",listaNacion[i].pais,listaNacion[i].idioma,listaNacion[i].descripcion);
        }
    }
}

int nacionalidad_obteneridbypais(eNacionalidad listaNacion[],int tamNa)
{
    int retorno=-1;
    char aux_char[50];
        if(listaNacion!=NULL && tamNa>0)
        {
            printf("***\n Ingrese Su Pais: \n***");
            fflush(stdin);
            scanf("%s",aux_char);
            for (int i=0;i<tamNa;i++)
            {
                if(!strcmp(listaNacion[i].pais,aux_char))
                {
                    retorno=listaNacion[i].id;
                    break;
                }
            }
        }

        return retorno;
}

