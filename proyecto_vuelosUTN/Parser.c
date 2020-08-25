#include <stdio.h>
#include <stdlib.h>
#include "Pilotos.h"
#include "Vuelos.h"
#include "LinkedList.h"
#include "Validaciones.h"

/** \brief  leo datos desde un archivo y los agrego a una entidad deseada.
 *
 * \param Puntero de tipo archivo al que se hara referencia.
 * \param Puntero a la LinkedList que contiene la entidad.
 * \return  -1: Si el archivo esta vacio, si la lista esta vac{ia
             1: Todo OK
 *
 */

int parser_pilots_bytext(FILE* pFile,LinkedList* pLista)
{
    int retorno=-1;
    ePiloto* aux_piloto;
    int cont_datos=0;
    //int band=1;
    char Id_[28];
    char nombre[128];

    if(pFile!=NULL && pLista!=NULL)
    {
        ll_clear(pLista);

        // leo la cantidad de datos
        fscanf(pFile,"%[^,],%[^\n]\n",Id_,nombre);
        while(!feof(pFile))
        {

            cont_datos=fscanf(pFile,"%[^,],%[^\n]\n",Id_,nombre);
            if(cont_datos==2)
            {
                printf("lei: %s--%s\n",Id_,nombre);
                aux_piloto=new_pilotwithparameters(Id_,nombre);
                if(aux_piloto!=NULL)
                {
                    if(!ll_add(pLista,aux_piloto))
                    {
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief  leo datos desde un archivo y los agrego a una entidad deseada.
 *
 * \param Puntero de tipo archivo al que se hara referencia.
 * \param Puntero a la LinkedList que contiene la entidad.
 * \return  -1: Si el archivo esta vacio, si la lista esta vac{ia
            -2: si hay problema con los parametros pasados.
             1: Todo OK
 *
 */
int parser_flightbytext(FILE* pFile,LinkedList* pListFlight)
{
    int retorno=-1;
    eVuelo* aux_Flight=NULL;
    char id_vuelo[28];
    char id_avion[28];
    char id_piloto[28];
    char fecha[100];
    char destino[100];
    char cant_pasajeros[28];
    char hr_salida[4];
    char hr_llegada[4];

    if(pFile!=NULL&&pListFlight!=NULL)
    {
        int cont_datos=0;
        ll_clear(pListFlight);
        // hago una primer lectura para verificar que haya algo escrito posteriormente
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_vuelo,
                                                                                    id_avion,
                                                                                    id_piloto,
                                                                                    fecha,
                                                                                    destino,
                                                                                    cant_pasajeros,
                                                                                    hr_salida,
                                                                                    hr_llegada);
        while(!feof(pFile))// hago la lectura hasta que sea el final del archivo
        {
            cont_datos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_vuelo,
                                                                                    id_avion,
                                                                                    id_piloto,
                                                                                    fecha,
                                                                                    destino,
                                                                                    cant_pasajeros,
                                                                                    hr_salida,
                                                                                    hr_llegada);
             if(cont_datos==8)// verifico datos obtenidos
             {
              /*  printf("lei: %s--%s--%s--%s--%s--%s--%s--%s\n",id_vuelo,
                                                               id_avion,
                                                               id_piloto,
                                                               fecha,
                                                               destino,
                                                               cant_pasajeros,
                                                               hr_salida,
                                                               hr_llegada);*/ //MUESTRO LO QUE LEI
                aux_Flight=(eVuelo*)new_flightwithparameters(id_vuelo,id_avion,id_piloto,fecha,destino,cant_pasajeros,hr_salida,hr_llegada);
                if(aux_Flight!=NULL)
                {
                    if(!ll_add(pListFlight,aux_Flight))
                    {
                        retorno=0;
                    }
                }
             }

        }

    }else
    {
        printf("ERROR: in Parser_flight\n");
        retorno=-2;
    }
    return retorno;

}
