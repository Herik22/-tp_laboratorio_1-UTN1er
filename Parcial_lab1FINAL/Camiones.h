#ifndef CAMIONES_H_INCLUDED
#define CAMIONES_H_INCLUDED

#include"Marca.h"
#include "Choferes.h"
#include "Validaciones_.h"
#include "Menus.h"

typedef struct
{
    int id;
    int id_Chofer;
    char patente[10];
    int  id_Marca;//Relaciona estructura marca
    int anio;
    int peso;
    int cant_ruedas;
    char tipo[20];
    int estado;
}eCamion;


#endif // CAMIONES_H_INCLUDED
/** \brief  Inicializa el estado de los camiones.
 *
 * \param Lista Camion.
 * \param Tamaño Lista Camion.
 * \return -1=Error de parametros
 *          0= OK
 */
int camion_inicializar(eCamion listaCamion[],int tamCa);

/** \brief Genera un Id o retorna el siguiente al ultimo
 *
 * \param Lista Camion.
 * \param Tamaño Lista Camion.
 * \return -1=Error de parametros
 *          ID_new= OK
 */
int camion_generarId (eCamion listaCamion[],int tamCa);

/** \brief Hardcodea los campos de la lista camion
 *
 * \param Lista de Camiones.
 * \param Tamaño lista de camiones.
 * \return VOID
 *
 */
void camion_hardcodeo(eCamion listaCamion[],int tamCa);

/** \brief Recorre la lista de camiones y devuelve el proximo libre
 *
 * \param Lista Camiones.
 * \param Tamaño lista camiones.
 * \return -1:Error de Parametros.
 *          posicionlibre: OK
 */
int camion_buscarLibre(eCamion listaCamion[],int tamCa);

/** \brief Recorre la lista de camiones y devuelve su posicion por patente
 *
 * \param Lista Camiones.
 * \param Tamaño lista camiones.
 * \return -1= Error parametros.
 *         posicion= todoOK.
 */
int camion_obtenerbypatente(eCamion listaCamion[],int tamCa);

/** \brief Imprime por pantalla UN SOLO camion con su marca
 *
 * \param Lista de camiones
 * \param Tamaño de la lista camiones
 * \param Lista de marcas
 * \param Tamaño de la lista marcas
 * \return VOID
 *
 */
void camion_mostrarUnCamion(eCamion Camion,eMarca listaMarca[], int tamMa);

/** \brief Imprime por pantalla todos los Camiones OCUPADOS con su Marca.
 *
 * \param Lista de Camiones
 * \param Tamaño de la lista Camiones
 * \param Lista de Marcas
 * \param Tamaño de la lista  Marcas
 * \return -1: Error parametros
 *          0: Todo Ok.
 */
int camion_mostrarAllCamiones2(eCamion listaCamion[],int tamCa,eMarca listaMarca[], int tamMa);

/** \brief Ubica un camion por su ID y lo da de baja
 *
 * \param Lista de Camiones
 * \param Tamaño de lista Camiones
 * \return -1: Error de parametros.
 *          0: todo OK.
 */
int camion_baja(eCamion listaCamion[],int tamCa,eMarca listaMarca[], int tamma);

/** \brief Lista de camiones con mas de 10 anios de antiguedad
 *
 * \param Lista de camiones.
 * \param Tamaño de la lista de camiones;
 * \return -1: Error de parametros;
 *          0: todoOK.
 */
int camion_listCamiones10anios(eCamion listaCamion[],int tamCa,eMarca listaMarca[], int tamMa);

/** \brief Lista de camiones por su Marca
 *
 * \param Lista de camiones.
 * \param Tamaño de la lista de camiones;
 * \return -1: Error de parametros;
 *          0: todoOK.
 */
int camion_listarByMarca (eCamion listaCamion[],int tamCa,eMarca listaMarca[], int tamMa);

/** \brief Recorre la lista y devuelve el promedio de antiguedad de la flota de Camiones.
 *
 * \param Lista de camiones.
 * \param Tamaño de la lista de camiones;
 * \return -1: Error de parametros;
 *          0: todoOK.
 */
int camion_promedioAntiguedad(eCamion listaCamion[],int tamCa);
