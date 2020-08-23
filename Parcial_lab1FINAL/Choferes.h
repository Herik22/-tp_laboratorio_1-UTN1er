#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED
#include "Nacionalidad.h"
#include "Validaciones_.h"
#include "Menus.h"


typedef struct
{
    int id;
    char nombre[30]; //nombre apellido dni legajo nacionalidad teleofno edad sexo
    char apellido[30];
    int dni;
    int legajo;
    int id_nacionalidad; // RELACIONA ESTRUCTURA NACIONALIDAD
    int telefono;
    int edad;
    char sexo[10];
    int estado;

}eChofer;


#endif // CHOFERES_H_INCLUDED

/** \brief  inicializa los estado de los choferes en LIBRE .
 *
 * \param  lista chofer.
 * \param  tamaño de la lista.
 * \return  -1= Error de parametros.
            0 = Todo OK
 *
 */
int chofer_inicializar(eChofer listaChofer[],int tamCh);

/** \brief  inicializa los id de los choferes desde el que se estipule y lo incrementa.
 *
 * \param  lista chofer.
 * \param  tamaño de la lista.
 * \return  Id generado.
 *
 */
int  chofer_generarId (eChofer listaChofer[],int tamCh);

/** \brief  completa los campos de los choferes en cada posicion.
 *
 * \param  lista chofer.
 * \param  tamaño de la lista.
 * \return  NULL.
 *
 */
void chofer_hardcodeo (eChofer listachofer[], int tamch);

/** \brief Busca una posicion libre iterando la lista.
 *
 * \param Lista de choferes
 * \param  tamaño de la lista
 * \return -1: error de parametros;
            i: posicion libre;
 *
 */
int chofer_buscarlibre(eChofer listachofer[], int tamch);

/** \brief Imprime por pantalla UN SOLO chofer con su nacionalidad
 *
 * \param Lista de choferes
 * \param Tamaño de la lista chofer
 * \param Lista de nacionalidades
 * \param Tamaño de la lista  nacionalidades
 * \return VOID
 *
 */
void chofer_show(eChofer listachofer, int tamch,eNacionalidad listaNacionalidad[], int tamNa);

/** \brief Imprime por pantalla todos los choferes OCUPADOS con su nacionalidad.
 *
 * \param Lista de choferes
 * \param Tamaño de la lista chofer
 * \param Lista de nacionalidades
 * \param Tamaño de la lista  nacionalidades
 * \return VOID
 *
 */
int chofer_showAll(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa);

/** \brief Obtiene el nombre de un chofer por su ID.
 *
 * \param lista de chofer.
 * \param tamaño de la lista  chofer
 * \param lugar donde guardar el nombre
 * \param id del chofer a retornar
 * \return -1= error de parametros.
            0= OK.
 *
 */
int chofer_getNameById(eChofer listachofer[], int tamch,char* buffer, int id_chofer);

/** \brief obtiene la posicion de un chofer por su ID
 *
 * \param lista choferes
 * \param  tamaño lista choferes
  * \param  id por el cual se ubicara al chofer
 * \return -1: error de parametros.
            i:OK.
 *
 */
int chofer_obtenerbyID(eChofer listachofer[], int tamch);

/** \brief Obtiene el ID de un chofer por su DNI.
 *
 * \param lista de chofer.
 * \param tamaño de la lista  chofer
 * \param nombre del chofer a encontrar
 * \return -1= error de parametros.
            ID= OK.
 *
 */
int chofer_getIDbyDNI(eChofer listachofer[], int tamch, int dniChofer);

/** \brief Obtiene el ID de un chofer por su DNI.
 *
 * \param lista de chofer.
 * \param tamaño de la lista  chofer
 * \param nombre del chofer a encontrar
 * \return -1= error de parametros.
            ID= OK.
 *
 */
int chofer_getID(eChofer listachofer[], int tamch,eNacionalidad listaNacion[], int tamna);

 /** \brief Da de alta un chofer preguntnado por todos sus campos y posicionandolo en un ligar libre
  *
  * \param lista chofer
  * \param  taamaño de lista chofer
   * \param lista nacionalidades
  * \param  taamaño de lista nacionalidades
  * \return  -1=error en parametros.
            0= todo o
  *
  */
int chofer_alta(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa);

/** \brief  Edita un chofer indicado por ID, preguntnado por todos sus campos
  *
  * \param lista chofer.
  * \param  taamaño de lista chofer.
   * \param lista nacionalidades.
  * \param  tamaño de lista nacionalidades.
  * \return -1=error en parametros.
            0= todo ok.
  *
  */
int chofer_editar(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa);

/** \brief Obtiene la edad de todos los choferes y devuelve el promedio.
 *
 * \param   array Listachofer
 * \param  tamaño de la lista
 * \return -1=error de parametros.
            promedio= Todo OK.
 *
 */
int chofer_promedioEdad(eChofer listachofer[], int tamch);

/** \brief Recorre la lista de choferes, obtiene su sexo y devuelve el porcentaje  de varones
 *
 * \param Lista de choferes.
 * \param Tamanio lista de choferes
 * \return -1=Error de parametros
            Porcentaje=Todo OK
 *
 */
int chofer_porcentajeVarones(eChofer listachofer[], int tamch);

/** \brief Muestra la lista de choferes filtrada por Nacionalidad.
 *
 * \param Lista choferes.
 * \param Tamaño lista chofer.
 * \param Lista Nacionalidades.
 * \param Tamaño lista nacionalidades.
 * \return
 *
 */
int chofer_listarByNacionalidad(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa);

/** \brief Ordena y muestra la lista de choferes por nacionalidad y por nombre
 *
 * \param Lista Choferes.
 * \param Tamaño Lista choferes.
 * \param Lista Nacionalidades.
 * \param Tamaño lista nacionalidades.
 * \return -1=Error de parametros.
 *         0= TodoOK.
 */
int chofer_OrdenarByNacionalidadandName(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa);
