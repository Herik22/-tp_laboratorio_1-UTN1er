#ifndef NACIONALIDAD_H_INCLUDED
#define NACIONALIDAD_H_INCLUDED

typedef struct
{
    int id;
    char pais[50]; //italiano   argento  uruguayo
    char idioma[50];
    char descripcion[50];

}eNacionalidad;

#endif // NACIONALIDAD_H_INCLUDED
/** \brief Hardcodea los campos de la lista Nacionalidad
 *
 * \param Lista de Nacionalidad.
 * \param Tamaño lista de Nacionalidad.
 * \return VOID
 *
 */
void nacionalidad_hardcodear(eNacionalidad listaNacion[],int tamNa);

/** \brief obtiene el nombre de la Nacionalidad  por su ID
 *
 * \param lista Nacionalidad
 * \param  tamaño lista Nacionalidad
 * \param lista Nacionalidad
 * \param  Buffer donde guardar
 * \param  id por el cual se ubicara
 * \return -1: error de parametros.
            0:OK.
 *
 */
int nacionalidad_obtenerDescripByID(eNacionalidad listaNacion[],int tamNa,char* buffer,int idNacionalidad);

/** \brief Imprime por pantalla LAS Nacionalidades
 *
 * \param Lista de Nacionalidades
 * \param Tamaño de la lista Nacionalidades
 * \return VOID
 *
 */
void nacionalidad_mostrar(eNacionalidad listaNacion[],int tamNa);

/** \brief obtiene el ID de la  marca  por su Pais
 *
 * \param lista Nacionalidades
 * \param  tamaño lista Nacionalidades
 * \return -1: error de parametros.
            0:OK.
 *
 */
int nacionalidad_obteneridbypais(eNacionalidad listaNacion[],int tamNa);
