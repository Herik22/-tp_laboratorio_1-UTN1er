#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "LinkedList.h"
#include "Pilotos.h"
#include "Validaciones.h"
#include "Vuelos.h"
//CONSTRUCTORES

/** \brief Constructor dinamico de entidad piloto
 *
 * \return NULL: No hay espacio.
           ePiloto*: Entidad creada en espacio de memoria.
 *
 */

ePiloto* new_pilot()
{
    ePiloto* aux_pilot=NULL;
    aux_pilot=(ePiloto*)malloc(sizeof(ePiloto));
    return aux_pilot;
}
/** \brief  Constructor parametrizado, reserva espacio en memoria y setea en cada campo de la entidad
 *
 * \param IDs del piloto
 * \param  Nombre del piloto
 * \return  NULL= si no hay espacio.
            eVuelo = si el elemento es construido en memoria.
 *
 */
ePiloto* new_pilotwithparameters(char* id_ , char* nombre)
{
// ID_PILOTO

    ePiloto* aux_pilot=NULL;
    aux_pilot=new_pilot();
    if(id_!=NULL&&nombre!=NULL)
    {
        if(aux_pilot!=NULL)
        {
            pilot_setId(aux_pilot,atoi(id_));
            pilot_setNombre(aux_pilot,nombre);
        }else
        {
            printf("Error: No hay mas espacio para un nuevo piloto!\n");
        }
    }
    return aux_pilot;
}
/** \brief posiciona o setea el ID  del Piloto.
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1 Error en los parametros
            0 Todo OK.
 *
 */

int pilot_setId(ePiloto* this, int Id_)
{
    int retorno =-1;
    if (this!=NULL && Id_>=0)
    {
        this->id_Piloto=Id_;
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

int pilot_getId(ePiloto* this, int* Id_)
{

   int retorno =-1;
   if(this!=NULL&&Id_!=NULL)
   {
       *Id_=this->id_Piloto;
       retorno=0;
   }
    return retorno;
}
// NOMBRE_PILOTO

/** \brief posiciona o setea el nombre  del piloto en el campo "ID"
 *
 * \param Puntero a estructura.
 * \param  variable  del dato a setear
 * \return -1 Error en los parametros
            0 Todo OK.
 *
 */
int pilot_setNombre(ePiloto* this, char* nombre_)
{
    int retorno =-1;
    if(this!=NULL && nombre_!= NULL)
    {
        strcpy(this->nombre,nombre_);
        retorno=0;
    }
    return retorno;
}

/** \brief obtiene el nombre del elemento y lo guarda en la variable deseada
 *
 * \param Puntero a estructura.
 * \param Puntero a la variable donde guardar el dato
 * \return -1 Error en los parametros.
            0 Todo OK.
 *
 */

int pilot_getNombre(ePiloto* this, char* nombre_)
{
//MOSTRAR

   int retorno =-1;
   if(this!=NULL && nombre_ !=NULL)
    {
        strcpy(nombre_,this->nombre);
        retorno=0;
    }
    return retorno;
}
/** \brief Muestra un piloto.
 *
 * \param Entidad de tipo piloto a mostrar.
 * \return VOID.
 *
 */

void show_pilot(ePiloto* pPilot)
{
   if(pPilot!=NULL)
   {
       printf("%d , %s \n",pPilot->id_Piloto,
                            pPilot->nombre);
   }
}

// OBTENER PILOTO

/** \brief  Obtiene un piloto dependiendo del id que reciba
 *
 * \param puntero a LL de pilotos.
 * \param  id del piloto a obtener.
 * \return  NULL= si la lista esta vacia o el id es menor a 0 y mayor al len (corregir)
            ePiloto = si el elemento es construido en memoria.
 *
 */
ePiloto* obtener_pilotbyID(LinkedList* pListpilot, int id_piloto)
{
    ePiloto* aux_pilot=NULL;
    int i,tam,aux_id;
    if(pListpilot!=NULL && id_piloto>=0)
    {
        tam=ll_len(pListpilot);
        for(i=0;i<tam;i++)
        { // recorro la lista y obtengo cada piloto
            aux_pilot=ll_get(pListpilot,i);
            if(aux_pilot!=NULL)
            {
                pilot_getId(aux_pilot,&aux_id); // obtengo el id de cada piloto para poder comparar.
                if(id_piloto==aux_id)
                   {
                       break;
                   }else{continue;}
            }
        }
    }
    return aux_pilot;

}

/** \brief  Compara el elemento recibido y retorna segun si debe ir incluido o no.
 *
 * \param  Void* = Puntero al elemento a comparar.
 * \param  Char = criterio a comparar
 * \return  1= Debe agregarse
            -1= Error
            0= no debe agregarse
 *
 */
int pilot_FilterBynamePilot(void* pElement,char criterio[])
{
    ePiloto* aux;
    int retorno=-1;
    char name[100];
    if(pElement!=NULL)
    {
        aux=(ePiloto*)pElement;
        if(aux!=NULL)
        {
            pilot_getNombre(aux,name);
            //printf("Piloto=%s - Piloto a fitrar=%s \n",name,criterio);
            if(!strcmp(criterio,name))
            {
                retorno=0;
              //  printf("RETORNE 0\n");
            }
            else{retorno=1;}
            //printf("RETORNE 1 \n");}
        }
    }
    return retorno;
}

int pilot_obtener_IDpilotbyName(LinkedList* pListpilot, char name[])
{
    int ID_pilot=-1;
    char name_aux[100];
    ePiloto* aux_pilot=NULL;
    int i,tam;
    if(pListpilot!=NULL && name!=NULL)
    {
        tam=ll_len(pListpilot);
        for(i=0;i<tam;i++)
        { // recorro la lista y obtengo cada piloto
            aux_pilot=ll_get(pListpilot,i);
            if(aux_pilot!=NULL)
            {
                pilot_getNombre(aux_pilot,name_aux); // obtengo el nombre de cada piloto para poder comparar.
                if(!strcmp(name_aux,name))
                   {
                       pilot_getId(aux_pilot,&ID_pilot);
                       break;
                   }else{continue;}
            }
        }
    }
    return ID_pilot;
}

