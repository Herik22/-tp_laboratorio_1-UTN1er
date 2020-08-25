#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vuelos.h"
#include "Validaciones.h"
#include "LinkedList.h"
#include"Pilotos.h"
/** \brief  Constructor parametrizado, reserva espacio en memoria y setea en cada campo de la entidad
 *
 * \param IDs del vuelo, el avion y pilotos
 * \param  demas parametros de la estructura...
 * \return  NULL= si no hay espacio.
            eVuelo = si el elemento es construido en memoria.
 *
 */

eVuelo* new_flightwithparameters(char* Id_Vuelo,char* Id_Avion,char* Id_Piloto,char* fecha,char* destino,char* cant_Pasajeros,char* hr_Salida,char* hr_Llegada)
{

    eVuelo* aux_flight=NULL;
    aux_flight=new_flight();

    if(Id_Vuelo!=NULL&&Id_Avion!=NULL&&Id_Piloto!=NULL&&fecha!=NULL&&
       destino!=NULL&&cant_Pasajeros!=NULL&&hr_Salida!=NULL&&hr_Llegada!=NULL)
    {
        if(aux_flight!=NULL)
            {
                flight_setIdVuelo(aux_flight,atoi(Id_Vuelo));
                flight_setIdAvion(aux_flight,atoi(Id_Avion));
                flight_setIdPiloto(aux_flight,atoi(Id_Piloto));
                flight_setFecha(aux_flight,fecha);
                flight_setDestino(aux_flight,destino);
                flight_setCantPasajeros(aux_flight,atoi(cant_Pasajeros));
                flight_setHrSalida(aux_flight,atoi(hr_Salida));
                flight_setHrLlegada(aux_flight,atoi(hr_Llegada));

            }else
            {
                printf("Error: la memoria  esta llena \n");
            }
    }
    return aux_flight;
}

/** \brief Constructor dinamico de la  entidad "vuelos"
 *
 * \return  NULL= si no hay espacio.
            eVuelo = si el elemento es construido en memoria.
 *
 */

eVuelo* new_flight ()
{
    eVuelo* aux_flight=NULL;
    aux_flight=(eVuelo*)malloc(sizeof(eVuelo));
    return aux_flight;
}
// ID VUELO
/** \brief posiciona o setea el ID  del vuelo.
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1: Error en los parametros:
            0: Todo OK.
 *
 */

int flight_setIdVuelo(eVuelo* pListflight , int id_vuelo)
{
    int retorno=-1;
    if(pListflight!=NULL&&id_vuelo>=0)
    {
        pListflight->Id_Vuelo=id_vuelo;
        retorno=0;
    }
        return retorno;
}
/** \brief obtiene el ID del piloto y lo guarda en la variable deseada
 *
 * \param Puntero a estructura.
 * \param Puntero a la variable donde guardar el dato
 * \return -1 Error en los parametros.
            0 Todo OK.
 *
 */
 int flight_getIdVuelo(eVuelo* pListflight , int* id_vuelo)
 {
     int retorno=-1;
     if(pListflight!=NULL&&id_vuelo!=NULL)
     {
         *id_vuelo=pListflight->Id_Vuelo;
         retorno=0;
     }
     return retorno;
 }

 // ID_ AVION
 /** \brief posiciona o setea el ID  del Avion.
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1: Error en los parametros:
            0: Todo OK.
 *
 */

int flight_setIdAvion(eVuelo* pListflight , int id_avion)
{
    int retorno=-1;
    if(pListflight!=NULL&&id_avion>=0)
    {
        pListflight->Id_Avion=id_avion;
        retorno=0;
    }
        return retorno;
}
/** \brief obtiene el ID del avion y lo guarda en la variable deseada
 *
 * \param Puntero a estructura.
 * \param Puntero a la variable donde guardar el dato
 * \return -1 Error en los parametros.
            0 Todo OK.
 *
 */
 int flight_getIdAvion(eVuelo* pListflight , int* id_avion)
 {
     int retorno=-1;
     if(pListflight!=NULL&&id_avion!=NULL)
     {
         *id_avion=pListflight->Id_Avion;
         retorno=0;
     }
     return retorno;
 }
 // ID_PILOTO
 /** \brief posiciona o setea el ID  del Piloto.
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1: Error en los parametros:
            0: Todo OK.
 *
 */

int flight_setIdPiloto(eVuelo* pListflight , int id_piloto)
{
    int retorno=-1;
    if(pListflight!=NULL&&id_piloto>=0)
    {
        pListflight->Id_Piloto=id_piloto;
        retorno=0;
    }
        return retorno;
}
/** \brief obtiene el ID del piloto y lo guarda en la variable deseada
 *
 * \param Puntero a estructura.
 * \param Puntero a la variable donde guardar el dato
 * \return -1 Error en los parametros.
            0 Todo OK.
 *
 */
 int flight_getIdPiloto(eVuelo* pListflight , int* id_piloto)
 {
     int retorno=-1;
     if(pListflight!=NULL&&id_piloto!=NULL)
     {
         *id_piloto=pListflight->Id_Piloto;
         retorno=0;
     }
     return retorno;
 }

 // FECHA
 /** \brief posiciona o setea la Fecha  del vuelo.
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1: Error en los parametros:
            0: Todo OK.
 *
 */

int flight_setFecha(eVuelo* pListflight , char* fecha)
{
    int retorno=-1;
    if(pListflight!=NULL)
     {
         strcpy(pListflight->fecha,fecha);
         retorno=0;
     }
        return retorno;
}
/** \brief obtiene la fehca y la guarda en la variable deseada
 *
 * \param Puntero a estructura.
 * \param Puntero a la variable donde guardar el dato
 * \return -1 Error en los parametros.
            0 Todo OK.
 *
 */
 int flight_getFecha(eVuelo* pListflight , char* fecha)
 {
     int retorno=-1;
     if(pListflight!=NULL&&fecha!=NULL)
     {
         strcpy(fecha,pListflight->fecha);
         retorno=0;
     }
     return retorno;
 }

 //DESTINO
 /** \brief posiciona o setea el Destino  del vuelo.
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1: Error en los parametros:
            0: Todo OK.
 *
 */

int flight_setDestino(eVuelo* pListflight , char* Destino)
{
    int retorno=-1;
    if(pListflight!=NULL&&Destino!=NULL)
     {
        strcpy(pListflight->destino,Destino);
        retorno=0;
     }
        return retorno;
}
/** \brief obtiene el Destino y lo guarda en la variable deseada
 *
 * \param Puntero a estructura.
 * \param Puntero a la variable donde guardar el dato
 * \return -1 Error en los parametros.
            0 Todo OK.
 *
 */
 int flight_getDestino(eVuelo* pListflight , char* Destino)
 {
     int retorno=-1;
     if(pListflight!=NULL&&Destino!=NULL)
     {
        strcpy(Destino,pListflight->destino);
        retorno=0;
     }
     return retorno;
 }

 // CANTIDAD  PASAJEROS
 /** \brief posiciona o setea la cantidad de pasajeros  del vuelo.
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1: Error en los parametros:
            0: Todo OK.
 *
 */

int flight_setCantPasajeros(eVuelo* pListflight , int CantPasajeros)
{
    int retorno=-1;
    if (pListflight!=NULL&& CantPasajeros>1)
     {
         pListflight->cant_Pasajeros=CantPasajeros;
         retorno=0;
     }
        return retorno;
}
/** \brief obtiene la  CantPasajeros y lo guarda en la variable deseada
 *
 * \param Puntero a estructura.
 * \param Puntero a la variable donde guardar el dato
 * \return -1 Error en los parametros.
            0 Todo OK.
 *
 */
 int flight_getCantPasajeros(eVuelo* pListflight , int* CantPasajeros)
 {
     int retorno=-1;
     if (pListflight!=NULL&& CantPasajeros!=NULL)
     {
         *CantPasajeros=pListflight->cant_Pasajeros;
         retorno=0;
     }
     return retorno;
 }

 // HORA SALIDA
 /** \brief posiciona o setea la hora de salida  del vuelo.
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1: Error en los parametros:
            0: Todo OK.
 *
 */

int flight_setHrSalida(eVuelo* pListflight , int hr_salida)
{
    int retorno=-1;
    if(pListflight!=NULL&&hr_salida>0&&hr_salida<=24)
    {
        pListflight->hr_Salida=hr_salida;
        retorno=0;
    }
        return retorno;
}
/** \brief obtiene el ID del piloto y lo guarda en la variable deseada
 *
 * \param Puntero a estructura.
 * \param Puntero a la variable donde guardar el dato
 * \return -1 Error en los parametros.
            0 Todo OK.
 *
 */
 int flight_getHrSalida(eVuelo* pListflight , int* hr_salida)
 {
     int retorno=-1;
     if(pListflight!=NULL&&hr_salida!=NULL)
    {
       *hr_salida=pListflight->hr_Salida;
        retorno=0;
    }
     return retorno;
 }

 // HORA LLEGADA

 /** \brief posiciona o setea la hora de llegada  del vuelo.
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1: Error en los parametros:
            0: Todo OK.
 *
 */

int flight_setHrLlegada(eVuelo* pListflight , int hr_llegada)
{
    int retorno=-1;
    if(pListflight!=NULL&&hr_llegada>0&&hr_llegada<=24)
    {
        pListflight->hr_Llegada=hr_llegada;
        retorno=0;
    }
    return retorno;
}
/** \brief obtiene el ID del piloto y lo guarda en la variable deseada
 *
 * \param Puntero a estructura.
 * \param Puntero a la variable donde guardar el dato
 * \return -1 Error en los parametros.
            0 Todo OK.
 *
 */
 int flight_getHrLlegada(eVuelo* pListflight , int* hr_llegada)
 {
     int retorno=-1;
     if(pListflight!=NULL&&hr_llegada!=NULL)
     {
         *hr_llegada=pListflight->hr_Llegada;
         retorno=0;
     }
     return retorno;
 }
// MOSTRAR VUELOS

/** \brief Muestra un piloto.
 *
 * \param Entidad de tipo piloto a mostrar.
 * \return VOID.
 *
 */
void flight_show_flight(eVuelo* pflight,char nombre_piloto[])
{
    //char nombre[128];
    //ePiloto* aux;
    if(pflight!=NULL)
    {
            //printf("%s\n",nombre);
            printf(" %d %10d %20s  %10s - %10s %10d %20d %10d\n",pflight->Id_Vuelo,
                                                              pflight->Id_Avion,
                                                              nombre_piloto,
                                                              pflight->fecha,
                                                              pflight->destino,
                                                              pflight->cant_Pasajeros,
                                                              pflight->hr_Salida,
                                                              pflight->hr_Llegada);
    }else{printf("ERROR EN EL MOSTRAR CRACK ");}
}
// OBTENER VUELO POR DESTINO.
eVuelo* flight_getbyDestination(LinkedList* pList, char destination[])
{
    eVuelo* aux_flight=NULL;
    int i,tam;
    char aux_destino[100];
    if(pList!=NULL && utn_solocaracter(destination))
    {
        tam=ll_len(pList);
        for(i=0;i<tam;i++)
        { // recorro la lista y obtengo cada vuelo
            aux_flight= ll_get(pList,i);
            if(aux_flight!=NULL)
            {
                flight_getDestino(aux_flight,aux_destino); // obtengo el DESTINO de cada VUELO para poder comparar.
                if(strcmp(aux_destino,destination)==0)
                   {
                       break;
                   }else{continue;}
            }
        }
    }
    return aux_flight;

}

// CONTADOR PASAJEROS

/** \brief Recibe un elemento, obtiene el campo a contar y retorna su valor
     *
     * \param
     * \param
     * \return  0= La listaesta vacia.
                Cant_pasajeros = Todo ok
     *
     */

int flight_CuontPassenger(void* pElement)
{

    eVuelo* aux;
    int retorno=0;

    if (pElement!=NULL)
    {
        aux=(eVuelo*)pElement;
        flight_getCantPasajeros(aux,&retorno);
    }
    return retorno;
}

/** \brief Recibe un elemento, obtiene el campo a contar y retorna su valor
     *
     * \param pElemen= puntero a elemento libre.
     * \param
     * \return  0= La listaesta vacia.
                Cant_pasajeros = Todo ok
     *
     */
int flight_CuontPassengerToIrland(void* pElement)
{
    eVuelo* aux;// defino aux del vuelo  al cual pertenece el campo a contar
    char destino[100]; // lugar donde guardare el destino caracteristico
    int retorno=0;

    if (pElement!=NULL)
    {
        aux=(eVuelo*)pElement; //obtengo el vuelo con el cual trabajare
        if(aux!=NULL)
        {
            flight_getDestino(aux,destino); // obtengo el destino a filtrar
            if(strcmp(destino,"Irlanda")==0)
            {
                flight_getCantPasajeros(aux,&retorno);
            }else{retorno=-1;}
        }
    }
    return retorno;
}
//FILTROS!
/** \brief  Compara el elemento recibido y retorna segun si debe ir incluido o no.
 *
 * \param  Void* = Puntero al elemento a comparar.
 * \return  1= Debe agregarse
            0= no debe agregarse
 *
 */

int flight_FilterShort(void* pElement)
{
   eVuelo* aux_flight=NULL;
   int hr_salida,hr_llegada;
   int retorno=-1;
   if(pElement!=NULL)
   {
       aux_flight=(eVuelo*)pElement;
       if(aux_flight!=NULL)
       {
           flight_getHrSalida(aux_flight,&hr_salida);
           flight_getHrLlegada(aux_flight,&hr_llegada);
           if(hr_llegada-hr_salida<=3)
           {
               retorno=1;
           }else{retorno=0;}
       }
   }
return retorno;
}

  /** \brief  Compara el elemento recibido y retorna segun si debe ir incluido o no.
 *
 * \param  Void* = Puntero al elemento a comparar.
 * \return  1= Debe agregarse
            -1= Error
            0= no debe agregarse
 *
 */

int flight_FilterPortugal(void* pElement)
{
    eVuelo* aux;
    int retorno=-1;
    char destino[100];
    if(pElement!=NULL)
    {
        aux=(eVuelo*)pElement;
        if(aux!=NULL)
        {
            flight_getDestino(aux,destino);
            if(!strcmp(destino,"Portugal"))
            {
                retorno=1;
            }
            else{retorno=0;}
        }
    }
    return retorno;
}
 /** \brief  Compara el elemento recibido y retorna segun si debe ir incluido o no.
 *
 * \param  Void* = Puntero al elemento a comparar.
 * \return  1= Debe agregarse
            -1= Error
            0= no debe agregarse
 *
 */

int flight_FilterAlexLifeson(void* pElement)
{
    eVuelo* aux;
    int retorno=-1;
    int idAlex;
    if(pElement!=NULL)
    {
        aux=(eVuelo*)pElement;
        if(aux!=NULL)
        {
            flight_getIdPiloto(aux,&idAlex);
            if(idAlex!=1)
            {
                retorno=1;
            }
            else{retorno=0;}
        }
    }
    return retorno;
}


int flight_FilterByIDPilot(void* pElement,int criterio)
{
    eVuelo* aux;
    int retorno=-1;
    int id_aux;
    if(pElement!=NULL)
    {
        aux=(eVuelo*)pElement;
        if(aux!=NULL)
        {
            flight_getIdPiloto(aux,&id_aux);
            if(criterio==id_aux)
            {
                retorno=1;
               // printf("RETORNE 0\n");
            }
            else{retorno=0;}
            //printf("RETORNE 1 \n");}
        }
    }
    return retorno;
}
int flight_show_flight2(eVuelo* pflight,char nombre_piloto[])
{
    //char nombre[128];
    //ePiloto* aux;
    int retorno=-1;
    if(pflight!=NULL)
    {
            //printf("%s\n",nombre);
            printf(" %d %10d %20s  %10s - %10s %10d %10d  %10d  %15d $\n",pflight->Id_Vuelo,
                                                              pflight->Id_Avion,
                                                              nombre_piloto,
                                                              pflight->fecha,
                                                              pflight->destino,
                                                              pflight->cant_Pasajeros,
                                                              pflight->hr_Salida,
                                                              pflight->hr_Llegada,
                                                              pflight->importe_total);
                                                              retorno=0;
    }else{printf("ERROR EN EL MOSTRAR CRACK ");}
    return retorno;
}


void* flight_Pricetotal(void* pElement )
{
    eVuelo* aux_vuelo;
    char destino[100];
    int cant_pasajeros;
    if(pElement!=NULL)
    {
        aux_vuelo=(eVuelo*)pElement;
        if(aux_vuelo!=NULL)
        {
            flight_getDestino(aux_vuelo,destino);
            flight_getCantPasajeros(aux_vuelo,&cant_pasajeros);
            if(!strcmp(destino,"Portugal"))
            {
                aux_vuelo->importe_total=1000*cant_pasajeros;
            }else
            {
               aux_vuelo->importe_total=1500*cant_pasajeros;
            }
        }
    }
    return aux_vuelo;
}
