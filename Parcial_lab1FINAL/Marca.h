#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
  int id;
  char marca[20];
  char pais[50];
}eMarca;

#endif // MARCA_H_INCLUDED
/** \brief Hardcodea los campos de la lista Marca
 *
 * \param Lista de Marca.
 * \param Tamaño lista de Marca.
 * \return VOID
 *
 */
void marca_hardcodeo(eMarca listaMarca[],int tamMar);

/** \brief obtiene el nombre de la marca  por su ID
 *
 * \param lista marca
 * \param  tamaño lista marca
  * \param  id por el cual se ubicara al chofer
 * \return -1: error de parametros.
            0:OK.
 *
 */
int marca_obtenerMarcaById(eMarca listaMarca[],int tamMar,char* buffer,int idMarca);

/** \brief Imprime por pantalla LAS MARCAS lidad
 *
 * \param Lista de Marca
 * \param Tamaño de la lista Marca
 * \return VOID
 *
 */
void mostrar_marca(eMarca listaMarca[],int tamMar);

/** \brief obtiene el ID de la  marca  por su Nombre
 *
 * \param lista marca
 * \param  tamaño lista marca
 * \param  id por el cual se ubicara al chofer
 * \return -1: error de parametros.
            0:OK.
 *
 */
int marca_obtenerIdbyname(eMarca listaMarca[],int tamMar);
