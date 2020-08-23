#ifndef CHOFERCAMION_H_INCLUDED
#define CHOFERCAMION_H_INCLUDED

#include "Choferes.h"
#include "Camiones.h"

#endif // CHOFERCAMION_H_INCLUDED
/** \brief Lista a todos los choferes que continen uno o mas camiones.
 *
 * \param lista chofer.
 * \param Tama�o Lista chofer.
 * \param lista Nacionalidad.
 * \param Tama�o Lista Nacionalidad.
 * \param lista Camion.
 * \param Tama�o Lista Camion.
 * \param lista Marca.
 * \param Tama�o Lista Marca.
 * \return -1: error de parametros
 *          0: todoOK
 */
int choferCamion_mostrarCHconCamion(eChofer listaChofer[],int tamcho,eNacionalidad listaNaciones[],int tamna,eCamion listaCamion[],int tamca,eMarca listaMarca[],int tamMa);

/** \brief Muestra un camion con el nombre de su respectivo chofer
 *
 * \param camion a listar.
 * \param Lista de Choferes.
 * \param Tama�o Lista de Choferes.
 * \param Lista de Marcas.
 * \param Tama�o Lista de Marcas.
 * \return
 *
 */
void choferCamion_MostrarUnCamionConChofer(eCamion Camion,eChofer listaChofer[],int tamcho,eMarca listaMarca[], int tamMa);

/** \brief Muestra una lista de camiones con el nombre de su respectivo chofer
 *
 * \param camion a listar.
 * \param Lista de Choferes.
 * \param Tama�o Lista de Choferes.
 * \param Lista de Marcas.
 * \param Tama�o Lista de Marcas.
 * \return
 *
 */
int choferCamion_MostrarAllCamionesConCh(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eMarca listaMarca[], int tamMa);

/** \brief Da de alta un Camion preguntnado por todos sus campos y posicionandolo en un ligar libre
  *
  * \param lista Camion
  * \param  taama�o de lista Camion
   * \param lista Marcas
  * \param  taama�o de lista Marcas
  * \return  -1=error en parametros.
             0= todo OK
  *
  */
int choferCamion_camionAlta(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamCh,eNacionalidad listaNacion[],int tamna,eMarca listaMarca[], int tamma);

/** \brief  Edita un Camion indicado por ID, preguntnado por todos sus campos
  *
  * \param lista Camion.
  * \param  taama�o de lista Camion.
   * \param lista Marcas.
  * \param  tama�o de lista Marcas.
  * \return -1=error en parametros.
  *         0= todo ok.
  */
int choferCamion_camionModificar(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamCh,eNacionalidad listaNacion[],int tamna,eMarca listaMarca[], int tamma);

/** \brief Ubica un Chofer por su ID y lo da de baja con todos sus autos a cargo
 *
 * \param Lista de Chofer
 * \param Tama�o de lista Chofer
 * \param Lista de Nacionalidad
 * \param Tama�o de lista Nacionalidad
 * \param Lista de Camion
 * \param Tama�o de Camion Chofer
 * \return -1: Error de parametros.
 *          0: todo OK.
 */
int choferCamion_choferBaja (eChofer listaChofer[],int tamcho,eNacionalidad listaNaciones[],int tamna,eCamion listaCamion[],int tamca);

/**\brief Ordena y muestra la lista de Camiones por Tipo
 *
 * \param Lista Camiones.
 * \param Tama�o Lista Camiones.
 * \param Lista Marcas.
 * \param Tama�o lista Marcas.
 * \return -1=Error de parametros.
 *         0= TodoOK.
 */
int choferCamion_camionOrdenarByTipo(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eMarca listaMarca[], int tamMa);

/** \brief Lista a todos los choferes que continen  mas de un camion.
 *
 * \param lista Camion.
 * \param Tama�o Lista Camion.
 * \param lista Chofer.
 * \param Tama�o Lista Chofer.
 * \param lista Nacionalidad.
 * \param Tama�o Lista Nacionalidad.
 * \return -1: error de parametros
 *          0: todoOK
 */
int choferCamion_ChoferconMasdeunCa(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eNacionalidad listaNacionalidad[], int tamNa);

/**\brief Ordena y muestra la lista de Choferes por cantidad de Camiones
 *
 * \param Lista Camiones.
 * \param Tama�o Lista Camiones.
 * \param Lista Choferes.
 * \param Tama�o lista Choferes.
 * \param Lista Nacionalidades.
 * \param Tama�o lista Nacionalidades.
 * \return -1=Error de parametros.
 *         0= TodoOK.
 */
int choferCamion_ordernarCHByCantCamiones(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eNacionalidad listaNacionalidad[], int tamNa);

/**\brief Ordena y muestra la lista de Choferes por cantidad de Camiones y Nombre
 *
 * \param Lista Camiones.
 * \param Tama�o Lista Camiones.
 * \param Lista Choferes.
 * \param Tama�o lista Choferes.
 * \param Lista Nacionalidades.
 * \param Tama�o lista Nacionalidades.
 * \return -1=Error de parametros.
 *         0= TodoOK.
 */
int choferCamion_ordernarCHByCantCamionesAndName(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eNacionalidad listaNacionalidad[], int tamNa);

/** \brief Lista todos los camiones por la marca ingresada.
 *
 * \param lista de Camiones.
 * \param Tama�o Lista de Camiones.
 * \return -1: Error de Parametros.
 *          0: TodoOK.
 */
int choferCamion_MostrarAllCamionesByMarca(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eMarca listaMarca[], int tamMa);
