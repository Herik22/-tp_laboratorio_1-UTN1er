#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Menus.h"
#include "Choferes.h"
#include "Camiones.h"
#include "Nacionalidad.h"
#include "Marca.h"
#include "ChoferCamion.h"

#define LIBRE 1
#define OCUPADO 0

#define TAMCHO 12
#define TAMCAMI 25
#define TAMNACION 3
#define TAMMARCA 3

// INICIALIZO / HARDCODEO


int main()
{
    eChofer lista_Chofer[TAMCHO];
    eCamion lista_Camion[TAMCAMI];
    eNacionalidad lista_Nacionalidad[TAMNACION];
    eMarca lista_marca[TAMMARCA];

    nacionalidad_hardcodear(lista_Nacionalidad,TAMNACION);
    marca_hardcodeo(lista_marca,TAMMARCA);

    chofer_inicializar(lista_Chofer,TAMCHO);
    chofer_hardcodeo(lista_Chofer,TAMCHO);

    camion_inicializar(lista_Camion,TAMCAMI);
    camion_hardcodeo(lista_Camion,TAMCAMI);

    char decision='n';
    int opcion=0;

    do{
        switch(menuPrincipal())
        {
        case 1://Lista choferes.
        if(!chofer_showAll(lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION))
        {
            printf("OK.\n");
        }else{printf("Error Case1\n");}
        break;
        case 2://Listar camiones con chofer
        if(!choferCamion_MostrarAllCamionesConCh(lista_Camion,TAMCAMI,lista_Chofer,TAMCHO,lista_marca,TAMMARCA))
        {
          printf("OK.\n");
        }else{printf("Error Case2!!\n");}
        break;
        case 3://listar choferes con camion
        if(!choferCamion_mostrarCHconCamion(lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION,lista_Camion,TAMCAMI,lista_marca,TAMMARCA))
        {
          printf("OK.\n");
        }else{printf("Error Case3!!\n");}
        break;
        case 4://Alta Camion.
        if(!choferCamion_camionAlta(lista_Camion,TAMCAMI,lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION,lista_marca,TAMMARCA))
        {
          printf("OK.\n");
        }else{printf("Error Case4!!\n");}
        break;
        case 5:// Baja logica de camion.
        if(!camion_baja(lista_Camion,TAMCAMI,lista_marca,TAMMARCA))
        {
          printf("OK.\n");
        }else{printf("Error Case5!!\n");}
        break;
        case 6://Modificar Camion
        if(!choferCamion_camionModificar(lista_Camion,TAMCAMI,lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION,lista_marca,TAMMARCA))
        {
          printf("OK.\n");
        }else{printf("Error Case6!!\n");}
        break;
        case 7://Alta chofer
        if(!chofer_alta(lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION))
        {
          printf("OK.\n");
        }else{printf("Error Case7!!\n");}
        break;
        case 8://Borrado chofer en cascada
        if(!choferCamion_choferBaja(lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION,lista_Camion,TAMCAMI))
        {
          printf("OK.\n");
        }else{printf("Error Case8!!\n");}
        break;
        case 9://Ordenar camiones por TIPO
        if(!choferCamion_camionOrdenarByTipo(lista_Camion,TAMCAMI,lista_Chofer,TAMCHO,lista_marca,TAMMARCA))
        {
            printf("OK.\n");
        }else{printf("Error Case9!!\n");}
        break;
        case 10://Editar Chofer
        if(!chofer_editar(lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION))
        {
            printf("OK.\n");
        }else{printf("Error Case 10!!\n");}
            break;
        case 11://listar choferes con mas de un camion
        if(!choferCamion_ChoferconMasdeunCa(lista_Camion,TAMCAMI,lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION))
        {
            printf("OK.\n");
        }else{printf("Error Case 11!!\n");}
            break;
        case 12:// listar camiones con mas de 10 anios de antiguedad
        if(!camion_listCamiones10anios(lista_Camion,TAMCAMI,lista_marca,TAMMARCA))
        {
            printf("OK.\n");
        }else{printf("Error Case 12!!\n");}
            break;
        case 13://pedir marca y solo listar camiones de esa marca
        if(!camion_listarByMarca(lista_Camion,TAMCAMI,lista_marca,TAMMARCA))
        {
            printf("OK.\n");
        }else{printf("Error Case 13!!\n");}
            break;
        case 14:// ordenar los choferes por cant de camiones y listar
        if(!choferCamion_ordernarCHByCantCamiones(lista_Camion,TAMCAMI,lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION))
        {
            printf("OK.\n");
        }else{printf("Error Case 14!!\n");}
            break;
        case 15:// ordenar los choferes por cant de camiones y nombre, listar
        if(!choferCamion_ordernarCHByCantCamionesAndName(lista_Camion,TAMCAMI,lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION))
        {
            printf("OK.\n");
        }else{printf("Error Case 15!!\n");}
        case 16:// promedio de edad entre los choferes.
            if(!chofer_promedioEdad(lista_Chofer,TAMCHO))
            {
                printf("\nOK.\n");
            }else{printf("Error Case 16!!\n");}
            break;
        case 17://promedio antiguedad CAMIONES
            if(!camion_promedioAntiguedad(lista_Camion,TAMCAMI))
            {
                printf("\nOK.\n");
            }else{printf("Error Case 17!!\n");}
            break;
        case 18:// porcentaje de choferes hombre  sobre el total de choferes
            if(!chofer_porcentajeVarones(lista_Chofer,TAMCHO))
            {
                printf("\nOK.\n");
            }else{printf("Error Case 18 !!\n");}
            break;
        case 19:// mostrar chofer con camion por marca
            if(!choferCamion_MostrarAllCamionesByMarca(lista_Camion,TAMCAMI,lista_Chofer,TAMCHO,lista_marca,TAMMARCA))
            {
                printf("\nOK.\n");
            }else{printf("Error Case 19 !!\n");}
            break;
        case 20://listar chofer por nacionalidad
         if(!chofer_listarByNacionalidad(lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION))
            {
                printf("\nOK.\n");
            }else{printf("Error Case 20 !!\n");}
            break;
        case 21://Ordenar chofer por nacionalidad y nombre
         if(!chofer_OrdenarByNacionalidadandName(lista_Chofer,TAMCHO,lista_Nacionalidad,TAMNACION))
            {
                printf("\nOK.\n");
            }else{printf("Error Case 21 !!\n");}
            break;
        case 22:
        printf("***\nDesea salir? (s/n)\n***");
        fflush(stdin);
        scanf("%c",&decision);
        if(decision=='s')
        {
           opcion=22;
           break;
        }
        default:
            printf("\n\nIngrese una opcion valida\n\n");
        }
        system("pause");

    }while(opcion!=22);

    printf("Hello world!\n");
    return 0;
}
