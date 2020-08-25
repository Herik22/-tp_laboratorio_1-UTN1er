#ifndef VUELOS_H_INCLUDED
#define VUELOS_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int Id_Vuelo;
    int Id_Avion;
    int Id_Piloto;
    char fecha[100];
    char destino[100];
    int cant_Pasajeros;
    int hr_Salida;
    int hr_Llegada;
    int importe_total;

}eVuelo;

eVuelo* new_flightwithparameters(char* Id_Vuelo,char* Id_Avion,char* Id_Piloto,char* fecha,char* destino,char* cant_Pasajeros,char* hr_Salida,char* hr_Llegada);
eVuelo* new_flight ();
int flight_setIdVuelo(eVuelo* pListflight , int id_vuelo);
int flight_getIdVuelo(eVuelo* pListflight , int* id_vuelo);
int flight_setIdAvion(eVuelo* pListflight , int id_avion);
int flight_getIdAvion(eVuelo* pListflight , int* id_avion);
int flight_setIdPiloto(eVuelo* pListflight , int id_piloto);
int flight_getIdPiloto(eVuelo* pListflight , int* id_piloto);
int flight_setFecha(eVuelo* pListflight , char* fecha);
int flight_getFecha(eVuelo* pListflight , char* fecha);
int flight_setDestino(eVuelo* pListflight , char* Destino);
int flight_getDestino(eVuelo* pListflight , char* Destino);
int flight_setCantPasajeros(eVuelo* pListflight , int CantPasajeros);
int flight_getCantPasajeros(eVuelo* pListflight , int* CantPasajeros);
int flight_setHrSalida(eVuelo* pListflight , int hr_salida);
int flight_getHrSalida(eVuelo* pListflight , int* hr_salida);
int flight_setHrLlegada(eVuelo* pListflight , int hr_llegada);
int flight_getHrLlegada(eVuelo* pListflight , int* hr_llegada);

void flight_show_flight(eVuelo* pflight,char nombre_piloto[]);



eVuelo* flight_getbyDestination(LinkedList* pList, char destination[]);

int flight_CuontPassenger(void* pElement);
int flight_CuontPassengerToIrland(void* pElement);

int flight_FilterShort(void* pElement);
int flight_FilterPortugal(void* pElement);
int flight_FilterAlexLifeson(void* pElement);
int flight_FilterByIDPilot(void* pElement,int criterio);
void* flight_Pricetotal(void* pElement );
int flight_show_flight2(eVuelo* pflight,char nombre_piloto[]);

#endif // VUELOS_H_INCLUDED
