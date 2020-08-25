#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"


int controller_Arismendy_loadPilotsFromText(char* name, LinkedList* pArrayListPilots);
int controller_Arismendy_loadFlight(char* Fname,LinkedList* pListFlght);
int controller_Arismendy_printpilot(LinkedList* pArrayListPilots);
int controller_Arismendy_printFlight(LinkedList* pArrayListFlight,LinkedList* pListPilots);
int controller_Arismendy_TotalPassenger(LinkedList* pListFlight);
int controller_Arismendy_PassengerToIrlanda(LinkedList* pListFlight);

int controller_Arismendy_printFlightSHORT(LinkedList* pArrayListFlight,LinkedList* pListPilots);

int controller_Arismendy_SaveText(char* path,LinkedList* pListFlight);
int controller_Arismendy_Saveflightshort(char* path,LinkedList* pListFlight,LinkedList* pListPilots);
int controller_Arismendy_printFlighttoPortugal(LinkedList* pListFlight,LinkedList* pListPilots);
int controller_Arismendy_printFlighwithoutAlex(LinkedList* pListFlight,LinkedList* pListPilots);
int controller_Arismendy_printPilotwithout(LinkedList* pListPilots);
int controller_Arismendy_printFlightthe(LinkedList* pListflight ,LinkedList* pListPilots);
int controller_Arismendy_SaveText2(char* path,LinkedList* pListFlight);
int controller_Arismendy_Parcial(LinkedList* pListvuelos,LinkedList* pListpilotos);
int controller_Arismendy_printFlighttoPortugalyGUARDAR(char* path,LinkedList* pListFlight,LinkedList* pListPilots);
#endif // CONTROLLER_H_INCLUDED
