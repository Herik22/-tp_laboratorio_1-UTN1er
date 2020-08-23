#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 1
#define OCUPADO 0

#include "ChoferCamion.h"
// mostrar choferes con camion
int choferCamion_mostrarCHconCamion(eChofer listaChofer[],int tamcho,eNacionalidad listaNaciones[],int tamna,eCamion listaCamion[],int tamca,eMarca listaMarca[],int tamMa)
{
    int retorno=-1;
    int flag_camion=-1;
    if(listaChofer!=NULL&&tamcho>0&&listaNaciones!=NULL&&tamna>0&&listaCamion!=NULL&&tamca>0&&listaMarca!=NULL&&tamMa>0)
    {
        for(int i=0;i<tamcho;i++)
        {
            retorno=0;
            if(listaChofer[i].estado==OCUPADO)
            {
                printf("Nombre:    Apellido:  DNI:  Legajo:  Nacionalidad:  Telefono:    Edad:  Sexo:\n\n");
                chofer_show(listaChofer[i],tamcho,listaNaciones,tamna);
                flag_camion=0;
            }

            for(int j=0;j<tamca;j++)
            {
                if(listaCamion[j].estado==OCUPADO && listaChofer[i].id == listaCamion[j].id_Chofer)
                {
                    printf("Patente:      Marca:    Anio:    Peso:       Cant/Ruedas:  Tipo:\n\n");
                    camion_mostrarUnCamion(listaCamion[j],listaMarca,tamMa);
                    flag_camion=1;
                }
            }
            if (listaChofer[i].estado==OCUPADO && flag_camion == 0)
            {
                printf("\n NO TIENE CAMION ");
            }

        }
    }
    return retorno;
}

//Mostrar un camion
void choferCamion_MostrarUnCamionConChofer(eCamion Camion,eChofer listaChofer[],int tamcho,eMarca listaMarca[], int tamMa)
{
    char nombreChofer[30];
    char marca[20];
        if (!chofer_getNameById(listaChofer,tamcho,nombreChofer,Camion.id_Chofer) && !marca_obtenerMarcaById(listaMarca,tamMa,marca,Camion.id_Marca))
        {
            printf("%s %10s %10s %10d %10d %10d %20s\n",nombreChofer,
                                                    Camion.patente,
                                                    marca,
                                                    Camion.anio,
                                                    Camion.peso,
                                                    Camion.cant_ruedas,
                                                    Camion.tipo);
        }else{printf("Error MOSTRAR UN CAMION!!\n");}
}

//Mostrar todos los camiones con chofer y marca
int choferCamion_MostrarAllCamionesConCh(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eMarca listaMarca[], int tamMa)
{

    int retorno=-1;
    if(listaCamion!=NULL&&tamCa>0&&listaChofer!=NULL&&tamcho>0&&listaMarca!=NULL&&tamMa>0)
    {
        printf("******* LISTA CAMIONES *******\n\n");
        printf("Chofer:     Patente:      Marca:    Anio:    Peso:       Cant/Ruedas:  Tipo:\n\n");
        for(int i=0;i<tamCa;i++)
        {
            if(listaCamion[i].estado==OCUPADO)
            {

                choferCamion_MostrarUnCamionConChofer(listaCamion[i],listaChofer,tamcho,listaMarca,tamMa);
                retorno=0;
            }
        }
    }
    return retorno;
}

//Alta Camion
int choferCamion_camionAlta(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamCh,eNacionalidad listaNacion[],int tamna,eMarca listaMarca[], int tamma)
{

    int posicionLibre,id_chofer,aux_int;
    int retorno=-1;
    int flag=0;
    char aux_char[100];
    char respuesta='n';
    eCamion new_camion;


    if(listaCamion!=NULL&&tamCa>0&&listaChofer!=NULL&&tamCh>0&&listaMarca!=NULL&&tamma>0&&listaNacion!=NULL&&tamna>0)
    {
        printf  ("                                 *********ALTA CAMION*********\n\n");
        //ID_CHOFER
        id_chofer=chofer_getID(listaChofer,tamCh,listaNacion,tamna);
        if(id_chofer!=-1)
        {
            new_camion.id_Chofer=id_chofer;
        }//verificar
        posicionLibre=camion_buscarLibre(listaCamion,tamCa);
        if(posicionLibre!=-1)
        {
            do
            {
                    //ID
                    new_camion.id=camion_generarId(listaCamion,tamCa);
                   //PATENTE
                    printf ("\n INGRESE PATENTE: \n");
                    fflush (stdin);
                    scanf("%s",aux_char);
                    if(aux_char!=NULL)
                    {
                        strcpy(new_camion.patente,aux_char);
                    }
                    //MARCA
                    aux_int=marca_obtenerIdbyname(listaMarca,tamma);
                    if(aux_int!=-1)
                    {
                        new_camion.id_Marca=aux_int;

                    }
                    //ANIO
                    if(!utn_getEntero(&aux_int,3,"INGRESE ANIO:\n","Error: ingrese un anio valido.\n",1900,2021))
                    {
                        new_camion.anio=aux_int;
                    }
                    //PESO
                    if(!utn_getEntero(&aux_int,3,"INGRESE PESO:\n","Error: ingrese un PESO valido.\n",1000,10000))
                    {
                        new_camion.peso=aux_int;
                    }
                    //CANT RUEDAS
                    if(!utn_getEntero(&aux_int,3,"INGRESE CANTIDAD DE RUEDAS:\n","Error: ingrese un cantidad valida.\n",4,16))
                    {
                        new_camion.cant_ruedas=aux_int;
                    }
                    //TIPO
                    printf("SELECCIONE EL TIPO:\n");
                    switch (menu_tipocamion())
                    {
                        case 1:
                            strcpy(new_camion.tipo,"CortaDistancia");
                            flag=1;
                        break;
                        case 2:
                            strcpy(new_camion.tipo,"LargaDistancia");
                            flag=1;
                        break;

                        default:
                        printf("\n\nIngrese una opcion valida\n\n");
                    }
            }while(flag!=1);

            if(flag)
            {
                printf("\n Desea agregar el Camion? (s/n)\n" );
                fflush (stdin);
                scanf("%c",&respuesta);
                if (respuesta == 's')
                {
                    new_camion.estado = OCUPADO;
                    listaCamion[posicionLibre]=new_camion;
                    printf ("\n\t** CAMION CARGADO CON EXITO!!  **\n ");


                }else
                {
                    printf ("\n\t** SE HA CANCELADO LA CARGA.  **\n ");
                }
                retorno=0;
            }
        }
    }
    return retorno;
}

//Modificar Camion (anio,marca,chofer)
int choferCamion_camionModificar(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamCh,eNacionalidad listaNacion[],int tamna,eMarca listaMarca[], int tamma)
{
    int retorno=-1;
    int posicion;
    int aux_int;
    char respuesta='n';
    if(listaCamion!=NULL&&tamCa>0&&listaChofer!=NULL&&tamCh>0&&listaMarca!=NULL&&tamma>0&&listaNacion!=NULL&&tamna>0)
    {
         camion_mostrarAllCamiones2(listaCamion,tamCa,listaMarca,tamma);
         posicion=camion_obtenerbypatente(listaCamion,tamCa);
         if(posicion!=-1)
         {
             printf("CAMION ENCONTRADO \n ");
             printf("\n patente:      marca:     anio:       peso:   cant/ruedas:   tipo: \n");
             camion_mostrarUnCamion(listaCamion[posicion],listaMarca,tamma);

             switch (menu_modificar())
             {
             case 1:
                //anio
                    printf ("     ******** MODIFICAR ANIO********\n");
                    if(!utn_getEntero(&aux_int,3,"INGRESE ANIO:\n","Error: ingrese un anio valido.\n",1900,2021))
                    {

                        printf("\n Desea Modificar el Camion? (s/n)\n" );
                        fflush (stdin);
                        scanf("%c",&respuesta);
                        if (respuesta == 's')
                        {
                            listaCamion[posicion].anio=aux_int;
                            printf("Cambio efectuado !!\n");

                        printf ("\n\t** CAMION MODIFICADO CON EXITO!!  **\n ");
                        retorno=0;
                        }else
                        {
                            printf ("\n\t** SE HA CANCELADO LA CARGA.  **\n ");
                        }
                    }
                break;
             case 2:
                 //Marca
                 printf ("     ******** MODIFICAR MARCA********\n");
                 mostrar_marca(listaMarca,tamma);
                 aux_int=marca_obtenerIdbyname(listaMarca,tamma);
                 if(aux_int!=-1)
                 {
                        printf("\n Desea Modificar el Camion? (s/n)\n" );
                        fflush (stdin);
                        scanf("%c",&respuesta);
                        if (respuesta == 's')
                        {
                            listaCamion[posicion].id_Marca=aux_int;
                            printf("Cambio efectuado !!\n");

                            printf ("\n\t** CAMION MODIFICADO CON EXITO!!  **\n ");
                            retorno=0;
                        }else
                        {
                            printf ("\n\t** SE HA CANCELADO LA CARGA.  **\n ");
                        }
                 }
                break;
             case 3:
                 //chofer
                 printf ("     ******** MODIFICAR CHOFER********\n");
                 chofer_showAll(listaChofer,tamCh,listaNacion,tamna);
                 aux_int=chofer_getID(listaChofer,tamCh,listaNacion,tamna);
                 if(aux_int!=-1)
                 {
                     printf("\n Desea Modificar el Camion? (s/n)\n" );
                        fflush (stdin);
                        scanf("%c",&respuesta);
                        if (respuesta == 's')
                        {
                            listaCamion[posicion].id_Chofer=aux_int;
                            printf("Cambio efectuado !!\n");

                            printf ("\n\t** CAMION MODIFICADO CON EXITO!!  **\n ");
                            retorno=0;
                        }else
                        {
                            printf ("\n\t** SE HA CANCELADO LA CARGA.  **\n ");
                        }

                 }
                break;
              default:
                        printf("\n\nIngrese una opcion valida\n\n");
             }

         }else{printf("ERROR: CAMION NO ENCONTRADO \n ");}
    }
    return retorno;
}

//Baja CHOFER  cascada
int choferCamion_choferBaja (eChofer listaChofer[],int tamcho,eNacionalidad listaNaciones[],int tamna,eCamion listaCamion[],int tamca)
{
    int posicion;
     int retorno=-1;
     char respuesta='n';
     if(listaChofer!=NULL&&tamcho>0&&listaCamion!=NULL&&tamca>0&&listaNaciones!=NULL&&tamna>0)
     {
         chofer_showAll(listaChofer,tamcho,listaNaciones,tamna);
        // ID_aux=chofer_getID(listaChofer,tamcho,listaNaciones,tamna);
         posicion=chofer_obtenerbyID(listaChofer,tamcho);

         if(posicion!=-1)
         {
             printf("CHOFER ENCONTRADO \n ");
             printf("id:    Nombre:    Apellido:  DNI:    Legajo:  Nacionalidad:  Telefono:    Edad:  Sexo:\n");
             chofer_show(listaChofer[posicion],tamcho,listaNaciones,tamna);

             printf("\n Desea eliminar de forma permanente el Chofer? (s/n) \n");
             scanf("%s",&respuesta);
             if (respuesta == 's')
             {
                 listaChofer[posicion].estado = LIBRE;

                 for(int i=0;i<tamca;i++)
                 {
                     if(listaCamion[i].id_Chofer==listaChofer[posicion].id)
                     {
                         listaCamion[i].estado=LIBRE;
                     }
                 }
                  printf("\n\t*** CHOFER ELIMINADO! ***\n");
             }
            }else{printf("ERROR: CHOFER NO ENCONTRADO \n ");}

            retorno=0;
      }
      return retorno;
}

//ORDENAR CAMIONES POR TIPO Y MOSTRAR CON CHOFER
int choferCamion_camionOrdenarByTipo(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eMarca listaMarca[], int tamMa)
{
    int flag=0;
    int retorno=-1;
    eCamion aux;
    if(listaCamion!=NULL && tamCa>0 && listaChofer!=NULL && tamcho>0 &&listaMarca!=NULL && tamMa>0)
    {
        for(int i=0;i<tamCa-1;i++)
        {
            for(int j=i+1;j<tamCa;j++)
            {
                if(strcmp(listaCamion[i].tipo,listaCamion[j].tipo)>0)// de  a -> z
                {
                    aux=listaCamion[i];
                    listaCamion[i]=listaCamion[j];
                    listaCamion[j]=aux;
                    flag=1;
                    retorno=0;

                }
            }
        }
        if(flag)
        {
            choferCamion_MostrarAllCamionesConCh(listaCamion,tamCa,listaChofer,tamcho,listaMarca,tamMa);
        }
    }
    return retorno;
}

//listar choferes con mas de un camion
int choferCamion_ChoferconMasdeunCa(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eNacionalidad listaNacionalidad[], int tamNa)
{
    int retorno=-1;
    int cont_Camion[tamcho];
    if (listaCamion!=NULL&&tamCa>0&&listaChofer!=NULL&&tamcho>0&&listaNacionalidad!=NULL&&tamNa>0)
    {
        for (int k=0;k<tamcho;k++)
        {
            cont_Camion[k]=0;
        }
        for(int i=0;i<tamcho;i++)
        {
            for(int j=0;j<tamCa;j++)
            {
                if(listaChofer[i].id==listaCamion[j].id_Chofer)
                {
                    cont_Camion[i]++;
                }
            }
        }
        for(int k=0;k<tamcho;k++)
        {
            if(listaChofer[k].estado==OCUPADO && cont_Camion[k]>1)
            {
                chofer_show(listaChofer[k],tamcho,listaNacionalidad,tamNa);
                printf("CANTIDAD CAMIONES:%d",cont_Camion[k]);

            }
        }
        retorno=0;
    }
    return retorno;
}

//Ordenar y listar choferes por cantidad de camiones
int choferCamion_ordernarCHByCantCamiones(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eNacionalidad listaNacionalidad[], int tamNa)
{
    int retorno=-1;
    int cont_Camion[tamcho];
    int flag=0;
    eChofer aux;
    if (listaCamion!=NULL&&tamCa>0&&listaChofer!=NULL&&tamcho>0&&listaNacionalidad!=NULL&&tamNa>0)
    {
        for (int k=0;k<tamcho;k++)
        {
            cont_Camion[k]=0;
        }
        for(int i=0;i<tamcho;i++)
        {
            for(int j=0;j<tamCa;j++)
            {
                if(listaChofer[i].id==listaCamion[j].id_Chofer)
                {
                    cont_Camion[i]++;
                }
            }
        }
        for(int h=0;h<tamcho-1;h++)
        {
            for(int p=h+1;p<tamcho;p++)
            {
                if(cont_Camion[h]<cont_Camion[p])
                {
                    aux=listaChofer[h];
                    listaChofer[h]=listaChofer[p];
                    listaChofer[p]=aux;
                    flag=1;
                    retorno=0;
                }
            }
        }
        if(flag)
        {
            chofer_showAll(listaChofer,tamcho,listaNacionalidad,tamNa);

        }
    }
    return retorno;
}

//Ordenar y listar choferes por cantidad de camiones y nombre
int choferCamion_ordernarCHByCantCamionesAndName(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eNacionalidad listaNacionalidad[], int tamNa)
{
    int retorno=-1;
    int cont_Camion[tamcho];
    int flag=0;
    eChofer aux;
    if (listaCamion!=NULL&&tamCa>0&&listaChofer!=NULL&&tamcho>0&&listaNacionalidad!=NULL&&tamNa>0)
    {
        for (int k=0;k<tamcho;k++)
        {
            cont_Camion[k]=0;
        }
        for(int i=0;i<tamcho;i++)
        {
            for(int j=0;j<tamCa;j++)
            {
                if(listaChofer[i].id==listaCamion[j].id_Chofer)
                {
                    cont_Camion[i]++;
                }
            }
        }
        for(int h=0;h<tamcho-1;h++)
        {
            for(int p=h+1;p<tamcho;p++)
            {
                if(cont_Camion[h]<cont_Camion[p])
                {
                    aux=listaChofer[h];
                    listaChofer[h]=listaChofer[p];
                    listaChofer[p]=aux;
                    flag=1;
                    retorno=0;
                }else if(cont_Camion[h]==cont_Camion[p])
                {
                    if(strcmp(listaChofer[h].nombre,listaChofer[p].nombre)<0)// de la Z a la A
                    {
                       aux=listaChofer[h];
                        listaChofer[h]=listaChofer[p];
                        listaChofer[p]=aux;
                        flag=1;
                        retorno=0;
                    }
                }
            }
        }
        if(flag)
        {
            chofer_showAll(listaChofer,tamcho,listaNacionalidad,tamNa);
        }
    }
    return retorno;
}

//Mostrar todos los camiones con chofer ýmarca
int choferCamion_MostrarAllCamionesByMarca(eCamion listaCamion[],int tamCa,eChofer listaChofer[],int tamcho,eMarca listaMarca[], int tamMa)
{
    int retorno=-1;
    int aux_idmarca;
    if(listaCamion!=NULL && tamCa>0 && listaChofer!=NULL && tamcho>0 && listaMarca!=NULL && tamMa>0)
    {
        aux_idmarca=marca_obtenerIdbyname(listaMarca,tamMa);
        printf("******* LISTA CAMIONES *******\n\n");
        printf("Chofer:     Patente:      Marca:    Anio:    Peso:       Cant/Ruedas:  Tipo:\n\n");
        for(int i=0;i<tamCa;i++)
        {
            if(listaCamion[i].estado==OCUPADO && listaCamion[i].id_Marca==aux_idmarca)
            {

                choferCamion_MostrarUnCamionConChofer(listaCamion[i],listaChofer,tamcho,listaMarca,tamMa);
                retorno=0;
            }
        }
    }
       return retorno;
}
