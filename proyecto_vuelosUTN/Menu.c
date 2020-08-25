
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Validaciones.h"
int menu ()
{
    int opcion;
    printf("                                  ****************   BIENVENIDO  ****************\n\n\n");
    utn_getEntero(&opcion,3," 1. Cargar Archivo.\n 2. Imprimir Vuelos.\n 3. Cantidad Pasajeros.\n 4. Cantidad Pasajeros a Irlanda.\n 5. Filtrar Vuelos Cortos.\n 6. Listar Vuelos a Portugal\n 7. Filtrar  a Alex Lifeson.\n 8. Filtrar Pilotos por nombre de piloto\n 9. Filtrar Vuelos por nombre de piloto\n 10.VUELOS SETEADOS CANTPRECIO.\n11. nuevo archivo vuelos portugal.\n12. Salir\n ",
                  "ERROR:Ingrese una opcion valida\n",1,12);

    return opcion;
}

int menu_archivo()
{
    int opcion;
    printf("                                  ***********   Elija un Archivo  ***********\n\n\n");
    utn_getEntero(&opcion,3," 1. Cargar Pilotos.\n 2. Cargar  Vuelos.\n ","ERROR:Ingrese una opcion valida\n",1,2);
    return opcion;
}

int menu_Vueloscortos()
{
    int opcion;
      printf("                                  ***********   FIN DE LOS VUELOS  ***********\n\n\n");
      utn_getEntero(&opcion,3,"1.Guardar y generar lista.\n 2.Cancelar\n","ERROR:Ingrese una opcion valida\n",1,2);
        return opcion;
}
