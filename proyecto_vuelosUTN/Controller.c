#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
//#include "LinkedList.h"
#include "LinkedList.h"
#include "Pilotos.h"
#include "Vuelos.h"
#include "Parser.h"
#include "Menu.h"
#include "Validaciones.h"

/** \brief controla y verifica que se pueda crear o leer un archivo de tipo texto
 *
 * \param nombre del archivo.
 * \param puntero a linkedlist de la entidad.
 * \return  -1:Error con los parametros
            0: todo ok
 *
 */

int controller_Arismendy_loadPilotsFromText(char* name, LinkedList* pArrayListPilots)
{
    int retorno=-1;
    FILE* pFile;
    if(name!=NULL&&pArrayListPilots!=NULL)
    {
        pFile=fopen(name,"r");// abro o en su defecto creo el archivo,especifico el uso que le dare
        retorno=parser_pilots_bytext(pFile,pArrayListPilots);
    }else
    {
        retorno=-2;
    }
    fclose(pFile);
    return retorno;
}

/** \brief controla y verifica que se pueda crear o leer un archivo de VUELOS tipo texto
 *
 * \param nombre del archivo.
 * \param puntero a linkedlist de la entidad.
 * \return  -1:Error con los parametros
            0: todo ok
 *
 */
 int controller_Arismendy_loadFlight(char* Fname,LinkedList* pListFlght)
 {
     int retorno=-1;
    FILE* pFile;
    if(Fname!=NULL&&pListFlght!=NULL)
    {
        pFile=fopen(Fname,"r");// abro o en su defecto creo el archivo,especifico el uso que le dare
        retorno=parser_flightbytext(pFile,pListFlght);
    }else
    {
        retorno=-2;
    }
    fclose(pFile);
    return retorno;
 }

int controller_Arismendy_printpilot(LinkedList* pArrayListPilots)
{
    int retorno=-1;
    int i,tam;
    ePiloto* aux_pilot;

    if(pArrayListPilots!=NULL)
    {
        tam=ll_len(pArrayListPilots);
        for(i=0;i<tam;i++)
        {
            aux_pilot=ll_get(pArrayListPilots,i);
            if(aux_pilot!=NULL)
            {
                show_pilot(aux_pilot);
                retorno=0;
            }
        }
    }
    return retorno;
}

int controller_Arismendy_printFlight(LinkedList* pArrayListFlight,LinkedList* pListPilots)
{
    int retorno=-1;
    int i,tam,id_aux;
    char nombre[128];
    eVuelo* aux_vuelo;
    ePiloto* aux_pilot;

    if( pArrayListFlight!=NULL)
    {
        tam=ll_len( pArrayListFlight);
        printf("ID_Vuelo:   ID_Avion:   Name_Piloto:      Fecha:      Destino:   Cant_Pasajeros:      Hr_Salida:      Hr_Llegada:\n");
        for(i=0;i<tam;i++)
        {
            aux_vuelo=ll_get( pArrayListFlight,i);//obtengo los vuelos de toda la lista.
            if(aux_vuelo!=NULL)
            {

                flight_getIdPiloto(aux_vuelo,&id_aux);// obtengo los id.piloto de cada vuelo
                //printf("IDs:%d\n",id_aux); verificaba si si pase el ID.
                aux_pilot=obtener_pilotbyID(pListPilots,id_aux); // obtengo los pilotos por id
                pilot_getNombre(aux_pilot,nombre);
                flight_show_flight(aux_vuelo,nombre);
                retorno=0;

            }
        }
    }
    return retorno;
}

int controller_Arismendy_TotalPassenger(LinkedList* pListFlight)
{
    int retorno=-1;
    if(pListFlight!=NULL)
    {
        retorno=ll_count(pListFlight,flight_CuontPassenger);
    }
    return retorno;
}

int controller_Arismendy_PassengerToIrlanda(LinkedList* pListFlight)
{
    int retorno=-1;
    if(pListFlight!=NULL)
    {
        retorno=ll_count(pListFlight,flight_CuontPassengerToIrland);//flight_CuontPassenger
    }
    return retorno;
}

int controller_Arismendy_printFlightSHORT(LinkedList* pArrayListFlight,LinkedList* pListPilots)
{
    LinkedList* nueva;
    int retorno=-1;
    int i,tam,id_aux;
    char nombre[128];
    eVuelo* aux_vuelo;
    ePiloto* aux_pilot;

    if( pArrayListFlight!=NULL)
    {
        nueva=ll_filter(pArrayListFlight,flight_FilterShort);
        tam=ll_len( nueva);
        printf("ID_Vuelo:   ID_Avion:   Name_Piloto:      Fecha:      Destino:   Cant_Pasajeros:      Hr_Salida:      Hr_Llegada:\n");
        for(i=0;i<tam;i++)
        {
            aux_vuelo=ll_get( nueva,i);//obtengo los vuelos de toda la lista.
            if(aux_vuelo!=NULL)
            {

                flight_getIdPiloto(aux_vuelo,&id_aux);// obtengo los id.piloto de cada vuelo
                //printf("IDs:%d\n",id_aux); verificaba si si pase el ID.
                aux_pilot=obtener_pilotbyID(pListPilots,id_aux); // obtengo los pilotos por id
                pilot_getNombre(aux_pilot,nombre);
                flight_show_flight(aux_vuelo,nombre);
                retorno=0;

            }
        }
    }
    return retorno;
}
 /** \brief  Guarda en un archivo.csv los elementos de una lista pasada como parametro.
  *
  * \param Char* Puntero al nombre del archivo
  * \param Linkedlist* puntero a lista de tipo LL.
  * \return  -1=error en la func
  *
  */

int controller_Arismendy_SaveText(char* path,LinkedList* pListFlight)
{
  int* id_vuelo;
    int*id_avion;
    int*id_piloto;
    int*cantPasajeros;
    int*hr_salida;
    int*hr_llegada;
    int* totalprecio;
    int i,tam;
    int retorno=-1;
    char* fecha;
    char*destino;
    FILE* pFile;
    eVuelo* aux_flight=NULL;
    if(path!=NULL&&pListFlight!=NULL)
    {
        // genero espacio en memoria para poder recibir los datos de la estructura.
        id_vuelo=malloc(sizeof(int));
        id_avion=malloc(sizeof(int));
        id_piloto=malloc(sizeof(int));
        fecha=malloc(sizeof(char)*100);
        destino=malloc(sizeof(char)*100);
        cantPasajeros=malloc(sizeof(int));
        hr_salida=malloc(sizeof(int));
        hr_llegada=malloc(sizeof(int));
        totalprecio=malloc(sizeof(int));

        pFile=fopen(path,"w"); // abro el archivo en modo escritura
        if(pFile!=NULL)
        {
           fprintf(pFile,"ID_Vuelo,ID_Avion,ID_Piloto,Fecha,Destino,Cant_Pasajeros,Hr_Salida,Hr_Llegada,TOTAL_PRECIO\n"); // escribo la cabecera en el archivo
           tam=ll_len(pListFlight);
           for(i=0;i<tam;i++)
           {
               aux_flight=ll_get(pListFlight,i);
               if(aux_flight!=NULL)
               {
                   // obtengo todos los datos de la lista en las variables ya definidas
                   if(flight_getIdVuelo(aux_flight,id_vuelo)==0&&
                   flight_getIdAvion(aux_flight,id_avion)==0&&
                   flight_getIdVuelo(aux_flight,id_piloto)==0&&
                   flight_getFecha(aux_flight,fecha)==0&&
                   flight_getDestino(aux_flight,destino)==0&&
                   flight_getCantPasajeros(aux_flight,cantPasajeros)==0&&
                   flight_getHrSalida(aux_flight,hr_salida)==0&&
                   flight_getHrLlegada(aux_flight,hr_llegada)==0)
                   *totalprecio=aux_flight->importe_total;
                   {
                       fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d,%d\n",*id_vuelo,*id_avion,*id_piloto,fecha,destino,*cantPasajeros,*hr_llegada,*hr_salida,*totalprecio); // escribo en el archivo los valores de cada elemento.
                   }
               }
           }//Libero el espacio creado para poder utilizarlo de vuelta.
            free(id_vuelo);
            free(id_avion);
            free(id_piloto);
            free(fecha);
            free(destino);
            free(cantPasajeros);
            free(hr_salida);
            free(hr_llegada);
            free(totalprecio);
            fclose(pFile); // cierro archivo
            printf("Datos guardados con Exito!!!\n ");
            retorno=0;
        }else{printf("Error: No se han podido guardar los datos!\n "); retorno=-2;}
    }
    return retorno;
}
int controller_Arismendy_SaveText2(char* path,LinkedList* pListFlight)
{
  int* id_vuelo;
    int*id_avion;
    int*id_piloto;
    int*cantPasajeros;
    int*hr_salida;
    int*hr_llegada;
    int* totalprecio;
    int i,tam;
    int retorno=-1;
    char* fecha;
    char*destino;
    FILE* pFile;
    eVuelo* aux_flight=NULL;
    if(path!=NULL&&pListFlight!=NULL)
    {
        // genero espacio en memoria para poder recibir los datos de la estructura.
        id_vuelo=malloc(sizeof(int));
        id_avion=malloc(sizeof(int));
        id_piloto=malloc(sizeof(int));
        fecha=malloc(sizeof(char)*100);
        destino=malloc(sizeof(char)*100);
        cantPasajeros=malloc(sizeof(int));
        hr_salida=malloc(sizeof(int));
        hr_llegada=malloc(sizeof(int));
        totalprecio=malloc(sizeof(int));

        pFile=fopen(path,"w"); // abro el archivo en modo escritura
        if(pFile!=NULL)
        {
           fprintf(pFile,"ID_Vuelo,ID_Avion,ID_Piloto,Fecha,Destino,Cant_Pasajeros,Hr_Salida,Hr_Llegada,TOTAL_PRECIO\n"); // escribo la cabecera en el archivo
           tam=ll_len(pListFlight);
           for(i=0;i<tam;i++)
           {
               aux_flight=ll_get(pListFlight,i);
               if(aux_flight!=NULL)
               {
                   // obtengo todos los datos de la lista en las variables ya definidas
                   if(flight_getIdVuelo(aux_flight,id_vuelo)==0&&
                   flight_getIdAvion(aux_flight,id_avion)==0&&
                   flight_getIdVuelo(aux_flight,id_piloto)==0&&
                   flight_getFecha(aux_flight,fecha)==0&&
                   flight_getDestino(aux_flight,destino)==0&&
                   flight_getCantPasajeros(aux_flight,cantPasajeros)==0&&
                   flight_getHrSalida(aux_flight,hr_salida)==0&&
                   flight_getHrLlegada(aux_flight,hr_llegada)==0)
                   *totalprecio=aux_flight->importe_total;
                   {
                       fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d,%d\n",*id_vuelo,*id_avion,*id_piloto,fecha,destino,*cantPasajeros,*hr_llegada,*hr_salida,*totalprecio); // escribo en el archivo los valores de cada elemento.
                   }
               }
           }//Libero el espacio creado para poder utilizarlo de vuelta.
            free(id_vuelo);
            free(id_avion);
            free(id_piloto);
            free(fecha);
            free(destino);
            free(cantPasajeros);
            free(hr_salida);
            free(hr_llegada);
            free(totalprecio);
            fclose(pFile); // cierro archivo
            printf("Datos guardados con Exito!!!\n ");
            retorno=0;
        }else{printf("Error: No se han podido guardar los datos!\n "); retorno=-2;}
    }
    return retorno;
}

    /** \brief Filtra de la lista original los vuelos cortos y genera un archivo con los mismos.
     *
     * \param Char* puntero a nombre del archivo
     * \param Linkedlist* puntero a listas LL
     * \return -1=Error.
               0= Todo OK.
     *
     */
int controller_Arismendy_Saveflightshort(char* path,LinkedList* pListFlight,LinkedList* pListPilots)
{
    int retorno=-1;
    LinkedList*  vueloscortos;
    if(path!=NULL&&pListFlight!=NULL&&pListPilots!=NULL)
    {
        if(!controller_Arismendy_printFlightSHORT(pListFlight,pListPilots))
        {

            switch(menu_Vueloscortos())
            {
            case 1:
                vueloscortos=ll_filter(pListFlight,flight_FilterShort);
                if(vueloscortos!=NULL)
                {
                    controller_Arismendy_SaveText(path,vueloscortos);
                    retorno=0;
                }
                break;
            case 2:
                printf("CANCELADO!!\n");
                break;
            }
        }
    }
    return retorno;
}

/** \brief Lista los vuelos con destino a Portugal
 *
 * \param Linkedlist* Puntero a Linkedlist de vuelos
 * \param Linkedlist* puntero a linkedlist de piloto
 * \return -1= error de parametros
            0= Todo OK.
 *
 */

int controller_Arismendy_printFlighttoPortugal(LinkedList* pListFlight,LinkedList* pListPilots)
{
    int retorno=-1;
    LinkedList* list_filter=NULL;
    {
        if(pListPilots!=NULL&&pListFlight!=NULL)
        {
            list_filter=ll_filter(pListFlight,flight_FilterPortugal);
            if(list_filter!=NULL)
            {
                controller_Arismendy_printFlight(list_filter,pListPilots);
                retorno=0;
            }
        }
    }
    return retorno;
}
/** \brief Lista los vuelos Siempre y cuando no este Alex Lifeson de piloto
 *
 * \param Linkedlist* Puntero a Linkedlist de vuelos
 * \param Linkedlist* puntero a linkedlist de piloto
 * \return -1= error de parametros
            0= Todo OK.
 *
 */

int controller_Arismendy_printFlighwithoutAlex(LinkedList* pListFlight,LinkedList* pListPilots)
{
    int retorno=-1;
    LinkedList* list_filter=NULL;
    {
        if(pListPilots!=NULL&&pListFlight!=NULL)
        {
            list_filter=ll_filter(pListFlight,flight_FilterAlexLifeson);
            if(list_filter!=NULL)
            {
                controller_Arismendy_printFlight(list_filter,pListPilots);
                retorno=0;
            }
        }
    }
    return retorno;
}

int controller_Arismendy_printPilotwithout(LinkedList* pListPilots)
{
    int retorno=-1;
    char name_aux[100];
    LinkedList* listfilter=NULL;
    if(pListPilots!=NULL)
    {
        controller_Arismendy_printpilot(pListPilots);
        printf("Ingrese el nombre del Piloto a filtrar:\n");
        fflush(stdin);
        gets(name_aux);
        if(name_aux!=NULL)
        {
            listfilter=ll_filterwithParameters(pListPilots,pilot_FilterBynamePilot,name_aux);
            if(listfilter!=NULL && ll_len(pListPilots)==ll_len(listfilter))
            {
                printf("            *******Error: Nombre inexistente. \n*******");
            }else
            {
                controller_Arismendy_printpilot(listfilter);
                retorno=0;
            }
        }
    }
return retorno;
}
int controller_Arismendy_printFlightthe(LinkedList* pListflight ,LinkedList* pListPilots)
{
    int retorno=-1;
    char name_aux[100];
    int id_aux;
    LinkedList* listfilter=NULL;
    if(pListflight!=NULL && pListPilots!=NULL)
    {
        controller_Arismendy_printpilot(pListPilots);
        printf("\n\n\nIngrese el nombre del Piloto a filtrar:\n\n");
        fflush(stdin);
        gets(name_aux);
        if(name_aux!=NULL)
        {
            id_aux=pilot_obtener_IDpilotbyName(pListPilots,name_aux);
            if(id_aux!=-1)
            {
                listfilter=ll_filterwithParameters2(pListflight,flight_FilterByIDPilot,id_aux);
                if(listfilter!=NULL && ll_len(pListflight)==ll_len(listfilter))
            {
                printf("            *******Error: Nombre inexistente. \n*******");
            }else
            {
                controller_Arismendy_printFlight(listfilter,pListPilots);
                retorno=0;
            }
            }else{printf("            *******Error: Nombre inexistente. \n*******");}
        }
    }
    return retorno;
}
int controller_Arismendy_Parcial(LinkedList* pListvuelos,LinkedList* pListpilotos)
{
    int retorno=-1;
    LinkedList* nueva_lista=NULL;
    int i,tam,id_aux;
    char nombre[128];
    eVuelo* aux_vuelo;
    ePiloto* aux_pilot;

    if( pListvuelos!=NULL)
    {
        nueva_lista=ll_map(pListvuelos,flight_Pricetotal);
        if(nueva_lista!=NULL)
        {
            tam=ll_len( nueva_lista);
            printf("ID_Vuelo:   ID_Avion:   Name_Piloto:      Fecha:      Destino:   Cant_Pasajeros:      Hr_Salida:      Hr_Llegada:\n");
            for(i=0;i<tam;i++)
            {
                aux_vuelo=ll_get(nueva_lista,i);//obtengo los vuelos de toda la lista.
                if(aux_vuelo!=NULL)
                {

                    flight_getIdPiloto(aux_vuelo,&id_aux);// obtengo los id.piloto de cada vuelo
                    //printf("IDs:%d\n",id_aux); verificaba si si pase el ID.
                    aux_pilot=obtener_pilotbyID(pListpilotos,id_aux); // obtengo los pilotos por id
                    pilot_getNombre(aux_pilot,nombre);
                    flight_show_flight2(aux_vuelo,nombre);
                    retorno=0;

                }
            }
        }

    }
    return retorno;
}
int controller_Arismendy_printFlighttoPortugalyGUARDAR(char* path,LinkedList* pListFlight,LinkedList* pListPilots)
{
    int retorno=-1;
    LinkedList* new_ll= NULL;
    LinkedList* list_filter=NULL;
    int i,tam,id_aux;
    char nombre[128];
    char decision='n';
    eVuelo* aux_vuelo;
    ePiloto* aux_pilot;
    {
        if(pListPilots!=NULL&&pListFlight!=NULL)
        {
            new_ll=ll_map(pListFlight,flight_Pricetotal); // OBTENGO LA NUEVA LINKEDLIST SETEADA
            list_filter=ll_filter(new_ll,flight_FilterPortugal); //filtro la linkedlist por el pais
            if(list_filter!=NULL)
            {
                tam=ll_len( list_filter);
                printf("ID_Vuelo:  ID_Avion:  Name_Piloto:     Fecha:     Destino:  Cant_Pasajeros:    Hr_Salida:    Hr_Llegada:   Total:\n");
                for(i=0;i<tam;i++)
                {
                    aux_vuelo=ll_get(list_filter,i);//obtengo los vuelos de toda la lista.
                    if(aux_vuelo!=NULL)
                    {

                        flight_getIdPiloto(aux_vuelo,&id_aux);// obtengo los id.piloto de cada vuelo
                        //printf("IDs:%d\n",id_aux); verificaba si si pase el ID.
                        aux_pilot=obtener_pilotbyID(pListPilots,id_aux); // obtengo los pilotos por id
                        pilot_getNombre(aux_pilot,nombre);
                        if(!flight_show_flight2(aux_vuelo,nombre))
                        {
                            printf("OK\n");

                        }
                    }
                }
                        printf("DESEA GUARDAR? (s/n )\n");
                        fflush(stdin);
                        scanf("%c",&decision);
                        if(decision=='s')
                        {
                            controller_Arismendy_SaveText2(path,list_filter);
                        }
                        retorno=0;
            }
        }
    }
    return retorno;
}
