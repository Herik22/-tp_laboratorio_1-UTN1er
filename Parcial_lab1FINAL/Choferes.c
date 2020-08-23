#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 1
#define OCUPADO 0

#include "Choferes.h"


// Inicializar
int chofer_inicializar(eChofer listaChofer[],int tamCh)
{
    int retorno=-1;
    int i;
    if(listaChofer!=NULL && tamCh>0)
    {
        for(i=0;i<tamCh;i++)
        {
            listaChofer[i].estado=LIBRE;
            retorno=0;
        }
    }
    return retorno;
}

// generar  id
int chofer_generarId(eChofer listaChofer[],int tamCh)
{
   int id_aux = 0;
   int i;
   if(listaChofer!=NULL && tamCh>0)
   {
       for (i=0;i<tamCh;i++)
        {
            if (listaChofer[i].estado == OCUPADO)
            {
                if (listaChofer[i].id>id_aux)
                {
                    id_aux = listaChofer[i].id;
                }
            }
        }
    }
    return id_aux +1;
}

// hardcodear datos
void chofer_hardcodeo(eChofer listachofer[], int tamch)
{
    if(listachofer!=NULL && tamch>0)
    {
        int id_ = chofer_generarId (listachofer,tamch);
        char nombre[6][30]= {"lucrecia","jorge   ","natalia  ","matias  ","jeremias","santiago  "};
        char apellido[6][30]= {"perez","davila","ramirez","peon","arias","bolounes"};
        int dni[6] = {958893,956578,957592,959463,957693,956593};
        int legajo[6]= {1234,1237,1236,1238,1239,1235};
        int nacionalidad[6]= {1000,1001,1002,1000,1001,1002};
        int telefono[6]= {111111,112222,1155555,1166666,1133333,1144444};
        int edad[6]={45,23,45,14,41,25};
        char sexo [6][10]= {"femenino","masculino","femenino","masculino","masculino","masculino"};
        //int idCamion[6]={1000,1001,1002,1000,1000,10};
        int estado_ [6]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

        int i;

        for (i=0; i<6; i++)
        {
             listachofer[i].id =id_++;
             strcpy(listachofer[i].nombre,nombre[i]);
             strcpy(listachofer[i].apellido,apellido[i]);
             listachofer[i].dni = dni[i];
             listachofer[i].legajo = legajo[i];
             listachofer[i].id_nacionalidad = nacionalidad[i];//strcpy(listachofer[i].nacionalidad,nacionalidad[i]);
             listachofer[i].telefono = telefono[i];
             listachofer[i].edad = edad[i];
             strcpy(listachofer[i].sexo,sexo[i]);
             //listachofer[i].id_camion=idCamion[i];
             listachofer[i].estado = estado_[i];
        }
    }
}

//Buscar libre
int chofer_buscarlibre(eChofer listachofer[], int tamch)
{
    int retorno=-1;
    if(listachofer!=NULL&&tamch>0)
    {
         for(int i=0;i<tamch;i++)
         {
             if(listachofer[i].estado==LIBRE)
             {
                 retorno=i;
                 break;
             }
         }
    }
    return retorno;
}

//Mostrar UN chofer con nacionalidad
void chofer_show(eChofer listachofer, int tamch,eNacionalidad listaNacionalidad[], int tamNa)
{

    char nacionalidad[50];

    if(!nacionalidad_obtenerDescripByID(listaNacionalidad,tamNa,nacionalidad,listachofer.id_nacionalidad))
    {
        printf("\n\n%d %10s %10s %10d %10d %10s %10d %10d %10s\n",listachofer.id,
                                                        listachofer.nombre,
                                                        listachofer.apellido,
                                                        listachofer.dni,
                                                        listachofer.legajo,
                                                        nacionalidad,
                                                        listachofer.telefono,
                                                        listachofer.edad,
                                                        listachofer.sexo);
    }
}

//Mostrar todos los choferes
int chofer_showAll(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa)
{
    int retorno=-1;
    int i;
    if(listachofer!=NULL&&tamch>0 && listaNacionalidad!=NULL&&tamNa>0)
    {
        printf("******* LISTA CHOFERES *******\n\n");
        printf("id:    Nombre:    Apellido:  DNI:    Legajo:  Nacionalidad:  Telefono:    Edad:  Sexo:\n");
        for(i=0;i<tamch;i++)
        {
           if(listachofer[i].estado==OCUPADO)
           {
               chofer_show(listachofer[i],tamch,listaNacionalidad,tamNa);
               retorno=0;
           }
        }
    }
    return retorno;
}

//obtener chofer por id
int chofer_getNameById(eChofer listachofer[], int tamch,char* buffer, int id_chofer)
{
    int retorno=-1;
    if(listachofer!=NULL && tamch>0)
    {
        for(int i=0;i<tamch;i++)
        {
            if(listachofer[i].id==id_chofer)
            {
                strcpy(buffer,listachofer[i].nombre);
                retorno=0;
            }
        }
    }
    return retorno;
}

//obtener posicion de chofer por id
int chofer_obtenerbyID(eChofer listachofer[], int tamch)
{
    int aux_int;
    int retorno=-1;
    if(listachofer!=NULL && tamch>0 )
    {
        printf("Ingrese ID del chofer: \n");
        fflush(stdin);
        scanf("%d",&aux_int);
        for(int i=0;i<tamch;i++)
        {
            if(listachofer[i].id==aux_int)
            {
                retorno=i;
            }
        }
    }
    return retorno;
}

//Obtener  id chofer por dni
int chofer_getIDbyDNI(eChofer listachofer[], int tamch, int dniChofer)
{
    int i;
    int aux_id=-1;
    if(listachofer!=NULL && aux_id!=0 && dniChofer!=0)
    {
        for(i=0;i<tamch;i++)
        {
           if(listachofer[i].dni==dniChofer)
           {
               aux_id=listachofer[i].id;
               break;
           }
        }
    }
    return aux_id;
}

//OBTIENE EL ID DEL CHOFER POR SU DNI
int chofer_getID(eChofer listachofer[], int tamch,eNacionalidad listaNacion[], int tamna)
{
    int aux_dni;
    int id_;
    if(listachofer!=NULL && tamch>0 && listaNacion!=NULL && tamna>0 )
    {

        chofer_showAll(listachofer,tamch,listaNacion,tamna);
        printf("Ingrese  DNI del chofer : \n");
        fflush(stdin);
        scanf("%d",&aux_dni);
        id_=chofer_getIDbyDNI(listachofer,tamch,aux_dni);
        if(id_!=-1)
        {
            printf("\n Chofer encontrado con exito !! \n");

        }else{printf("Error: dni incorrecto!");}
    }
    return id_;
}

//Alta chofer
int chofer_alta(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa)
{
    eChofer aux_chofer;
    char aux_char[50];
    char respuesta='n';

    int aux_int;
    int retorno=-1;
    int posicion_libre;
    if(listachofer!=NULL && tamch>0 && listaNacionalidad!=NULL && tamNa>0)
    {
        posicion_libre=chofer_buscarlibre(listachofer,tamch);
        if(posicion_libre!=-1)
        {
           //dni
            aux_chofer.id=chofer_generarId(listachofer,tamch);
           //nombre
           if(!utn_getCadena(aux_char,50,3,"Ingrese Nombre: \n","Error: Nombre invalido."))
           {
               strcpy(aux_chofer.nombre,aux_char);
           }
           //apellido
            if(!utn_getCadena(aux_char,50,3,"Ingrese Apellido: \n","Error: Apellido invalido."))
           {
               strcpy(aux_chofer.apellido,aux_char);
           }
           // dni
           if(!utn_getEntero(&aux_int,3,"Ingrese DNI:\n","Error: Dni invalido!\n",100000,999999))
           {
               aux_chofer.dni=aux_int;
           }
           //legajo
           if(!utn_getEntero(&aux_int,3,"Ingrese legajo:\n","Error: legajo invalido!\n",1000,9999))
           {
               aux_chofer.legajo=aux_int;
           }
           //nacionalidad
            nacionalidad_mostrar(listaNacionalidad,tamNa);
            aux_int=nacionalidad_obteneridbypais(listaNacionalidad,tamNa);
            if (aux_int!=-1)
            {
                aux_chofer.id_nacionalidad=aux_int;
            }
            //tel
            if(!utn_getEntero(&aux_int,3,"Ingrese su Telefono:\n","Error: telefono invalido!\n",100000,999999))
           {
               aux_chofer.telefono=aux_int;
           }
           //edad
           if(!utn_getEntero(&aux_int,3,"Ingrese su Edad:\n","Error: edad invalida!\n",10,99))
           {
               aux_chofer.edad=aux_int;
           }
           //sexo
           if(!utn_getCadena(aux_char,50,3,"Ingrese su sexo: \n","Error: sexo invalido."))
           {
               strcpy(aux_chofer.sexo,aux_char);
           }
            printf("\n Desea agregar el Chofer? (s/n)\n" );
            fflush (stdin);
            scanf("%c",&respuesta);
            if (respuesta == 's')
            {
                aux_chofer.estado = OCUPADO;
                listachofer[posicion_libre]=aux_chofer;
                printf ("\n\t** CHOFER CARGADO CON EXITO!!  **\n ");
            }else
            {
                printf ("\n\t** SE HA CANCELADO LA CARGA.  **\n ");
            }
            retorno=0;
        }
    }
    return retorno;
}

// Editar chofer
int chofer_editar(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa)
{

     char respuesta='n';
    char aux_char[100];
    int aux_int,posicion;
    int retorno=-1;
    if(listachofer!=NULL && tamch>0 && listaNacionalidad!=NULL && tamNa>0)
    {
        chofer_showAll(listachofer,tamch,listaNacionalidad,tamNa);
        posicion=chofer_obtenerbyID(listachofer,tamch);
        if(posicion!=-1)
        {
             printf("CHOFER ENCONTRADO \n ");
             printf("id:    Nombre:    Apellido:  DNI:    Legajo:  Nacionalidad:  Telefono:    Edad:  Sexo:\n");
             chofer_show(listachofer[posicion],tamch,listaNacionalidad,tamNa);
                 printf("\n\n******MODIFICAR CHOFER******\n\n");
                 switch(menu_modificarChofer())
                 {
                 case 1:// nombre
                     if(!utn_getCadena(aux_char,100,3,"Ingrese su Nombre: \n","Error: Nombre invalido!! \n"))
                     {
                        printf("\n Desea Modificar el Chofer? (s/n)\n" );
                         fflush (stdin);
                         scanf("%c",&respuesta);
                         if (respuesta == 's')
                         {
                             strcpy(listachofer[posicion].nombre,aux_char);
                            printf ("\n\t** CHOFER MODIFICADO CON EXITO!!  **\n ");
                            retorno=0;
                         }else
                         {
                            printf ("\n\t** SE HA CANCELADO LOS CAMBIOS.  **\n ");
                         }
                     }
                     break;
                 case 2://apellido
                     if(!utn_getCadena(aux_char,100,3,"Ingrese su Apellido: \n","Error: Apellido invalido!! \n"))
                     {
                         printf("\n Desea Modificar el Chofer? (s/n)\n" );
                         fflush (stdin);
                         scanf("%c",&respuesta);
                         if (respuesta == 's')
                         {
                             strcpy(listachofer[posicion].apellido,aux_char);
                            printf ("\n\t** CHOFER MODIFICADO CON EXITO!!  **\n ");
                            retorno=0;
                         }else
                         {
                            printf ("\n\t** SE HA CANCELADO LOS CAMBIOS.  **\n ");
                         }
                     }
                     break;
                 case 3://dni
                     if(!utn_getEntero(&aux_int,3,"Ingrese su DNI: \n","Error: DNI invalido!! \n",100000,999999))
                     {
                         printf("\n Desea Modificar el Chofer? (s/n)\n" );
                             fflush (stdin);
                             scanf("%c",&respuesta);
                             if (respuesta == 's')
                             {
                                listachofer[posicion].dni=aux_int;
                                printf ("\n\t** CHOFER MODIFICADO CON EXITO!!  **\n ");
                                retorno=0;
                             }else
                             {
                                printf ("\n\t** SE HA CANCELADO LOS CAMBIOS.  **\n ");
                             }
                     }
                     break;
                 case 4://legajo
                      if(!utn_getEntero(&aux_int,3,"Ingrese su Legajo: \n","Error: Legajo invalido!! \n",100000,999999))
                     {
                         printf("\n Desea Modificar el Chofer? (s/n)\n" );
                             fflush (stdin);
                             scanf("%c",&respuesta);
                             if (respuesta == 's')
                             {
                                listachofer[posicion].legajo=aux_int;
                                printf ("\n\t** CHOFER MODIFICADO CON EXITO!!  **\n ");
                                retorno=0;
                             }else
                             {
                                printf ("\n\t** SE HA CANCELADO LOS CAMBIOS.  **\n ");
                             }
                     }
                     break;
                 case 5://nacionalidad
                      nacionalidad_mostrar(listaNacionalidad,tamNa);
                      aux_int=nacionalidad_obteneridbypais(listaNacionalidad,tamNa);
                      if (aux_int!=-1)
                      {
                            printf("\n Desea Modificar el Chofer? (s/n)\n" );
                             fflush (stdin);
                             scanf("%c",&respuesta);
                             if (respuesta == 's')
                             {
                                listachofer[posicion].id_nacionalidad=aux_int;
                                printf ("\n\t** CHOFER MODIFICADO CON EXITO!!  **\n ");
                                retorno=0;
                             }else
                             {
                                printf ("\n\t** SE HA CANCELADO LOS CAMBIOS.  **\n ");
                             }
                      }
                     break;
                 case 6://telefono
                       if(!utn_getEntero(&aux_int,3,"Ingrese su Telefono: \n","Error: Telefono invalido!! \n",100000,999999))
                        {
                            printf("\n Desea Modificar el Chofer? (s/n)\n" );
                             fflush (stdin);
                             scanf("%c",&respuesta);
                             if (respuesta == 's')
                             {
                                listachofer[posicion].telefono=aux_int;
                                printf ("\n\t** CHOFER MODIFICADO CON EXITO!!  **\n ");
                                retorno=0;
                             }else
                             {
                                printf ("\n\t** SE HA CANCELADO LOS CAMBIOS.  **\n ");
                             }
                        }
                     break;
                 case 7://edad
                     if(!utn_getEntero(&aux_int,3,"Ingrese su Edad: \n","Error: Edad invalido!! \n",10,100))
                        {
                             printf("\n Desea Modificar el Chofer? (s/n)\n" );
                             fflush (stdin);
                             scanf("%c",&respuesta);
                             if (respuesta == 's')
                             {
                                listachofer[posicion].edad=aux_int;
                                printf ("\n\t** CHOFER MODIFICADO CON EXITO!!  **\n ");
                                retorno=0;
                             }else
                             {
                                printf ("\n\t** SE HA CANCELADO LOS CAMBIOS.  **\n ");
                             }
                        }
                     break;
                 case 8:     //sexo
                     if(!utn_getCadena(aux_char,100,3,"Ingrese su Sexo: \n","Error: Sexo invalido!! \n"))
                     {

                         printf("\n Desea Modificar el Chofer? (s/n)\n" );
                         fflush (stdin);
                         scanf("%c",&respuesta);
                         if (respuesta == 's')
                         {
                             strcpy(listachofer[posicion].sexo,aux_char);
                            printf ("\n\t** CHOFER MODIFICADO CON EXITO!!  **\n ");
                            retorno=0;
                         }else
                         {
                            printf ("\n\t** SE HA CANCELADO LOS CAMBIOS.  **\n ");
                         }
                        break;
                     }
                        default:
                        printf("\n\nIngrese una opcion valida\n\n");
                 }
        }
        retorno=0;
    }
    return retorno;
}

// promedio edad choferes
int chofer_promedioEdad(eChofer listachofer[], int tamch)
{
    int retorno=-1;
    float promedio;
    int acumuladorEdad=0;
    int contEdad=0;
    if(listachofer!=NULL && tamch>0)//promedio sumo y divido en el total
    {
        for(int i=0;i<tamch;i++)
        {
            if(listachofer[i].estado==OCUPADO)
            {
                acumuladorEdad=acumuladorEdad+listachofer[i].edad;
                contEdad++;
                retorno=0;
            }
        }
        promedio=(float)acumuladorEdad/contEdad;
        printf("El promedio de edad es:%.2f\n",promedio);
    }
    return retorno;
}

//porcentaje choferes hombre sobre el total
int chofer_porcentajeVarones(eChofer listachofer[], int tamch)
{
  int contVarones=0,contTotal=0,retorno=-1;
    float porcentaje;

    if(listachofer!=NULL && tamch>0)
    {
        for(int i=0;i<tamch;i++)
        {
            if(listachofer[i].estado==OCUPADO)
            {
                if(!strcmp(listachofer[i].sexo,"masculino"))
                {
                    contVarones++;
                }
                contTotal++;
                retorno=0;
            }
        }
        porcentaje=(float)contVarones/contTotal;
        printf("Porcentaje de Varones: %.2f\n",porcentaje*100);
    }
    return retorno;
}

// Listar choferes por nacionalidad
int chofer_listarByNacionalidad(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa)
{
    int retorno=-1;
    int aux_idnacionalidad;
    if(listachofer!=NULL && tamch>0 && listaNacionalidad !=NULL && tamNa>0)
    {
        aux_idnacionalidad=nacionalidad_obteneridbypais(listaNacionalidad,tamNa);
        if(aux_idnacionalidad!=-1)
        {
            printf("******* LISTA CHOFERES *******\n\n");
        printf("id:    Nombre:    Apellido:  DNI:    Legajo:  Nacionalidad:  Telefono:    Edad:  Sexo:\n");
            for (int i=0;i<tamch;i++)
            {
                if(listachofer[i].id_nacionalidad==aux_idnacionalidad)
                {
                    chofer_show(listachofer[i],tamch,listaNacionalidad,tamNa);
                    retorno=0;
                }
            }
        }
    }
return retorno;
}

//Ordenar por nacionalidad y nombre
int chofer_OrdenarByNacionalidadandName(eChofer listachofer[], int tamch,eNacionalidad listaNacionalidad[], int tamNa)
{
    int retorno=-1;
    int i,j;
    eChofer aux_chofer;
    if(listachofer!=NULL && tamch>0 && listaNacionalidad!=NULL && tamNa>0)
    {
        for(i=0;i<tamch-1;i++)
        {
            for(j=i+1;j<tamch;j++)
            {
                if(listachofer[i].id_nacionalidad>listachofer[j].id_nacionalidad)// ES agrupacion Y DEBE ORDENAR!
                {
                    aux_chofer=listachofer[i];
                    listachofer[i]=listachofer[j];
                    listachofer[j]=aux_chofer;
                    retorno=0;
                }else if(listachofer[i].id_nacionalidad==listachofer[j].id_nacionalidad && strcmp(listachofer[i].nombre,listachofer[j].nombre)>0)
                {
                    aux_chofer=listachofer[i];
                    listachofer[i]=listachofer[j];
                    listachofer[j]=aux_chofer;
                    retorno=0;
                }
            }
        }
        chofer_showAll(listachofer,tamch,listaNacionalidad,tamNa);
    }

    return retorno;
}
