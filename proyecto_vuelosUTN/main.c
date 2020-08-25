#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "LinkedList.h"
#include "Vuelos.h"
#include "Pilotos.h"
#include "Menu.h"
#include "Parser.h"
#include "Controller.h"

int main()
{
    LinkedList* list_pilotos= ll_newLinkedList(); // creo la cabeza del linkedlist.
    LinkedList* list_flight = ll_newLinkedList();

    int opcion;
    int pasajeros,pasajeros_irlanda;
    int carga_pilots=0;
    int carga_flight=0;
    int carga_flightshort=0;
    char decision='n';



    do{
        switch(menu())
        {

            case 1:// carga archivos
                switch(menu_archivo())
                {
                case 1:
                    //FILE pilotos
                    if(!carga_pilots)
                        {
                            controller_Arismendy_loadPilotsFromText("pilotos2.csv",list_pilotos);
                            carga_pilots=1;

                            break;
                            printf("OK.!\n");

                        }else
                        {
                            printf("ERROR:El archivo ya esta cargado! \n");
                        }
                case 2:
                    // FILE vuelos
                    if(!carga_flight)
                        {
                            controller_Arismendy_loadFlight("vuelos2.csv",list_flight);
                            carga_flight=1;
                            printf("**********  VUELOS CARGADOS !! **********\n");
                            break;
                            printf("OK.!\n");

                        }else
                        {
                            printf("ERROR:El archivo ya esta cargado! \n");
                        }
                  break;
                }
            break;

            case 2://imprimir vuelos
                if(carga_flight&&carga_pilots)
                {
                    if(!controller_Arismendy_printFlight(list_flight,list_pilotos))
                    {
                        printf("OK!\n");
                    }else{ printf("Error: Algo salio mal!\n");}
                }else{printf("Error: Cargue primero la lista de vuelos y pilotos!\n");}
            break;

            case 3://cantidad pasajeros
                if(carga_flight)
                {

                    pasajeros=controller_Arismendy_TotalPassenger(list_flight);
                    if(pasajeros!=0)
                    {
                      printf("TOTAL PASAJEROS= %d\n",pasajeros);
                      break;
                    }else{printf("Error: Controller devuelve 0 !\n");}
                }else{printf("Error: Cargue primero la lista de vuelos!\n");}

            case 4:// cantidad pasajeros a irlanda
                if(carga_flight)
                {
                    pasajeros_irlanda=controller_Arismendy_PassengerToIrlanda(list_flight);
                    if(pasajeros_irlanda!=0)
                    {
                        printf("TOTAL PASAJEROS= %d\n",pasajeros_irlanda);
                        break;
                    }else{printf("Error: Controller devuelve 0 !\n");}
                }else{printf("Error: Cargue primero la lista de vuelos!\n");}
            break;

            case 5://filtrar vuelos cortos
                if(!carga_flightshort)
                {
                    if(carga_flight&&carga_pilots)
                    {
                        if(!controller_Arismendy_Saveflightshort("Vueloscortos.csv",list_flight,list_pilotos))
                        {
                            carga_flightshort=1;
                            printf("OK!\n");
                        }else{ printf("Error: case 5!\n");}
                    }else{printf("Error: Cargue primero la lista de vuelos y pilotos!\n");}
                }else{printf("Error: El Archivo ya existe!\n");}

            break;

            case 6:// listar vuelos a portugal
                if(carga_flight&&carga_pilots)
                {
                    if(!controller_Arismendy_printFlighttoPortugal(list_flight,list_pilotos))
                    {
                        printf("OK!\n");
                    }else{ printf("Error: Algo salio mal!\n");}
                }else{printf("Error: Cargue primero la lista de vuelos y pilotos!\n");}
            break;

            case 7://filtrar a alex lifeson (VUELOS SIN ALEX)
            if(carga_flight&&carga_pilots)
                {
                    if(!controller_Arismendy_printFlighwithoutAlex(list_flight,list_pilotos))
                    {
                        printf("OK!\n");
                    }else{ printf("Error: Algo salio mal!\n");}
                }else{printf("Error: Cargue primero la lista de vuelos y pilotos!\n");}
            break;

            case 8:// filtrar por nombre de piloto (LISTA PILOTOS SIN X )
            if(carga_flight&&carga_pilots)
                {
                    if(!controller_Arismendy_printPilotwithout(list_pilotos))
                    {
                        printf("OK!\n");
                    }else{ printf("Error: Algo salio mal!\n");}
                }else{printf("Error: Cargue primero la lista de vuelos y pilotos!\n");}
            break;
            case 9:// filtrar por nombre dle piloto (VUELOS DE PILOTO X )
            if(carga_flight&&carga_pilots)
                {
                    if(!controller_Arismendy_printFlightthe(list_flight,list_pilotos))
                    {
                        printf("OK!\n");
                    }else{ printf("Error: Algo salio mal!\n");}
                }else{printf("Error: Cargue primero la lista de vuelos y pilotos!\n");}
            break;
            case 10:
            if(carga_flight&&carga_pilots)
                {
                    if(!controller_Arismendy_Parcial(list_flight,list_pilotos))
                    {
                        printf("OK!\n");
                    }else{ printf("Error: Algo salio mal!\n");}
                }else{printf("Error: Cargue primero la lista de vuelos y pilotos!\n");}
            break;
           case 11:
                    if(carga_flight&&carga_pilots)
                    {
                        if(!controller_Arismendy_printFlighttoPortugalyGUARDAR("Vuelosparcial.csv",list_flight,list_pilotos))
                        {
                            printf("OK!\n");
                        }else{ printf("Error: case 5!\n");}
                    }else{printf("Error: Cargue primero la lista de vuelos y pilotos!\n");}
            break;
            case 12://SALIR
            printf("***\nDesea salir? (s/n)\n***");
            fflush(stdin);
            scanf("%c",&decision);
            if(decision=='s')
            {
                opcion=10;
                break;
            }
            default:
            printf("\n\nIngrese una opcion valida\n\n");
        }
        system("pause");

    }while(opcion!=12);

    //printf("Hello world!\n");
    return 0;
}
