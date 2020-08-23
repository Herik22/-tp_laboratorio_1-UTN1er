#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 1
#define OCUPADO 0

#include "Camiones.h"
// inicializar
int camion_inicializar(eCamion listaCamion[],int tamCa)
{
    int retorno=-1;
    int i;
    if(listaCamion!=NULL && tamCa>0)
    {
        for(i=0;i<tamCa;i++)
        {
            listaCamion[i].estado=LIBRE;
            retorno=0;
        }
    }
    return retorno;
}

// generar id
int camion_generarId (eCamion listaCamion[],int tamCa)
{
    int id_aux = 99;
   int i;
   if(listaCamion!=NULL && tamCa>0)
   {
       for (i=0;i<tamCa;i++)
        {
            if (listaCamion[i].estado == OCUPADO)
            {
                if (listaCamion[i].id>id_aux)
                {
                    id_aux = listaCamion[i].id;
                }
            }
        }
   }

    return id_aux +1;
}
//HARDCODEO
void camion_hardcodeo(eCamion listaCamion[],int tamCa)
{
    int id_ = camion_generarId ( listaCamion, tamCa);
    int idchofer[10]= {1,1,2,2,3,4,4,5,5,5};
    char patente[10][10]= {"027lpe","039nri","456lia","123ias","853ias","567ago","103mvt","451tbe","172rty","547aoq"};
    int id_marca[10]= {10000,10000,10001,10001,10002,10000,10000,10000,10000,10000};
    int anio[10] = {2000,2000,2001,2001,2010,2005,2015,2011,2020,2020};
    int peso[10]= {1239,2345,3456,4567,5678,6789,7235,2643,1287,9672};
    int cantidadruedas[10]= {4,6,4,4,8,4,4,6,4,10};
    char tipo [10][20]= {"cortaDistancia","largaDistancia","largaDistancia","cortaDistancia","largaDistancia","cortaDistancia","cortaDistancia","largaDistancia","largaDistancia","largaDistancia"};
    int estados [10] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;

    for (i=0; i<10; i++)
    {
         listaCamion[i].id = id_++;
         listaCamion[i].id_Chofer= idchofer[i];
         strcpy(listaCamion[i].patente,patente[i]);
         listaCamion[i].id_Marca = id_marca[i];
         listaCamion[i].anio = anio[i];
         listaCamion[i].peso = peso[i];
         listaCamion[i].cant_ruedas = cantidadruedas[i];
         strcpy(listaCamion[i].tipo,tipo[i]);
         listaCamion[i].estado = estados[i];
    }
}

//Buscar libre
int camion_buscarLibre(eCamion listaCamion[],int tamCa)
{
    int index=-1;
    if(listaCamion!=NULL && tamCa>0)
    {
        for(int i=0;i<tamCa;i++)
        {
            if(listaCamion[i].estado==LIBRE)
            {
                index=i;
            }
        }
    }
    return index;
}

//obtener posicion de camion por patente
int camion_obtenerbypatente(eCamion listaCamion[],int tamCa)
{
    int retorno=-1;
    char aux_char[100];
    if(listaCamion!=NULL && tamCa>0)
    {
         printf ("\n INGRESE PATENTE: \n");
         fflush (stdin);
         scanf("%s",aux_char);

        for(int i=0;i<tamCa;i++)
        {
            if(!strcmp(listaCamion[i].patente,aux_char))
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

// mostrar un camion SIN CHOFER
void camion_mostrarUnCamion(eCamion Camion,eMarca listaMarca[], int tamMa)
{

        char marca[20];
        if (!marca_obtenerMarcaById(listaMarca,tamMa,marca,Camion.id_Marca))
        {
            printf("\n\n %10s %10s %10d %10d %10d %20s\n",Camion.patente,
                                                    marca,
                                                    Camion.anio,
                                                    Camion.peso,
                                                    Camion.cant_ruedas,
                                                    Camion.tipo);
        }
}

//Mostrar todos los camiones con  marca
int camion_mostrarAllCamiones2(eCamion listaCamion[],int tamCa,eMarca listaMarca[], int tamMa)
{

    int retorno=-1;
    if(listaCamion!=NULL && tamCa>0 && listaMarca!=NULL && tamMa>0)
    {
        printf("******* LISTA CAMIONES *******\n\n");
        printf(" Patente:      Marca:    Anio:    Peso:       Cant/Ruedas:  Tipo:\n\n");
        for(int i=0;i<tamCa;i++)
        {
            if(listaCamion[i].estado==OCUPADO)
            {

                camion_mostrarUnCamion(listaCamion[i],listaMarca,tamMa);
                retorno=0;
            }
        }
    }
    return retorno;
}

// Baja Camion
int camion_baja(eCamion listaCamion[],int tamCa,eMarca listaMarca[], int tamma)
{
     int posicion;
     int retorno=-1;
     char respuesta='n';
     if(listaCamion!=NULL && tamCa>0 &&  listaMarca!=NULL && tamma>0 )
     {
         camion_mostrarAllCamiones2(listaCamion,tamCa,listaMarca,tamma);
         posicion=camion_obtenerbypatente(listaCamion,tamCa);

         if(posicion!=-1)
         {
             printf("CAMION ENCONTRADO \n ");
             printf("\n patente:      marca:     anio:       peso:   cant/ruedas:   tipo: \n");
             camion_mostrarUnCamion(listaCamion[posicion],listaMarca,tamma);

             printf("\n Desea eliminar de forma permanente el camion? (s/n) \n");
             scanf("%s",&respuesta);
             if (respuesta == 's')
             {
                 listaCamion[posicion].estado = LIBRE;
                 printf("\n\t*** CAMION ELIMINADO! ***\n");
             }
         }else{printf("ERROR: CAMION NO ENCONTRADO \n ");}

         retorno=0;
     }
     return retorno;
}

//listar camiones con mas de 10 anios
int camion_listCamiones10anios(eCamion listaCamion[],int tamCa,eMarca listaMarca[], int tamMa)
{
    int retorno=0;
    if(listaCamion!=NULL && tamCa>0 && listaMarca!=NULL && tamMa>0)
    {
        for(int i=0;i<tamCa;i++)
        {
            if(listaCamion[i].anio<(2020-10) )
            {
                camion_mostrarUnCamion(listaCamion[i],listaMarca,tamMa);
            }
        }
        retorno=0;
    }
    return retorno;
}

// lista los camiones de la amrca ingresada
int camion_listarByMarca (eCamion listaCamion[],int tamCa,eMarca listaMarca[], int tamMa)
{

    int retorno=0;
    int id_marca;
    if(listaCamion!=NULL && tamCa>0 && listaMarca!=NULL && tamMa)
    {
        mostrar_marca(listaMarca,tamMa);
        id_marca=marca_obtenerIdbyname(listaMarca,tamMa>0);
        for(int i=0;i<tamCa;i++)
        {
            if(listaCamion[i].id_Marca==id_marca )
            {
                camion_mostrarUnCamion(listaCamion[i],listaMarca,tamMa);
            }
        }
        retorno=0;
    }
    return retorno;
}

// Promedio de antiguedad de los Camiones
int camion_promedioAntiguedad(eCamion listaCamion[],int tamCa)
{


    int retorno;
    int contAntiguedad=0,acumuladorAntiguedad=0;
    float promedio;
    if(listaCamion!=NULL && tamCa>0)
    {
        for(int i=0;i<tamCa;i++)
        {
            if(listaCamion[i].estado==OCUPADO)
            {
                acumuladorAntiguedad=acumuladorAntiguedad+(2020-listaCamion[i].anio);
                contAntiguedad++;
                retorno=0;
            }
        }
        promedio=(float)acumuladorAntiguedad/contAntiguedad;
        printf("La Antiguedad promedio es: %.2f\n",promedio);
    }
    return retorno;
}
