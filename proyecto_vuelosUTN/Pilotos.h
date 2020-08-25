#ifndef PILOTOS_H_INCLUDED
#define PILOTOS_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id_Piloto;
    char nombre[128];

}ePiloto;



#endif // PILOTOS_H_INCLUDED
int pilot_setId(ePiloto* this, int Id_);
int pilot_getId(ePiloto* this, int* Id_);
int pilot_setNombre(ePiloto* this, char* nombre_);
int pilot_getNombre(ePiloto* this, char* nombre_);
ePiloto* new_pilot();
ePiloto* new_pilotwithparameters(char* id_ , char* nombre);
void show_pilot(ePiloto* pPilot);
ePiloto* obtener_pilotbyID(LinkedList* pListpilot, int id_piloto);
int pilot_FilterBynamePilot(void* pElement,char criterio[]);
int pilot_obtener_IDpilotbyName(LinkedList* pListpilot, char name[]);
