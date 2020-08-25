#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir

    exit(EXIT_FAILURE); --> Para especificar que algo salio mal
    exit(EXIT_SUCCESS);
*****************************************************/


int main()
{
    LinkedList* lista_employee = ll_newLinkedList(); // creo la locomotora o cabeza del linkedlist
    char decision;
    int opcion=0;
    int flag_carga=-1;
    do{
        switch(menu())
        {
        case 1:
        printf("\n Cargando datos ...  \n");
        if(controller_loadFromText("data.csv",lista_employee)!=-1)
        {
           printf("\n Datos cargados ! \n");
           flag_carga=0;
        }else
        {
            printf("\n ALGO SALIO MAL ! \n");
        }
        break;
        case 2:
        printf("\n Cargando datos binarios ...  \n");
        if(controller_loadFromBinary("data.bin",lista_employee)!=-1)
        {
           printf("\n Datos cargados ! \n");
           flag_carga=0;
        }else
        {
            printf("\n ALGO SALIO MAL ! \n");
        }
        break;
        case 3:
            if( !flag_carga &&controller_addEmployee(lista_employee)==0 )
            {
               printf("\n TODO CORRECTO ! \n");
            }else
            {
                printf("\nError:Carga algun archivo primero.! \n");
            }
            break;
        case 4:
            if(ll_isEmpty(lista_employee)==0)
            {
               printf("\n Editar datos ...  \n");
               if(!controller_editEmployee(lista_employee))
               {
                   printf("\n OK. \n");
               }
            }else
            {
                 printf("\n Error: la lista esta vacia,cargue un empleado primero\n");
            }

            break;
        case 5:
            if(ll_isEmpty(lista_employee)==0)
            {
               printf("\n*** Eliminar ***\n");
               if(!controller_removeEmployee(lista_employee))
               {
                   printf("\n OK. \n");
               }
            }else
            {
                 printf("\n Error: la lista esta vacia,cargue un empleado primero \n");
            }

            break;
        case 6:
            if(ll_isEmpty(lista_employee)==0)
            {
               if (controller_ListEmployee(lista_employee)!=-1)
                {
                    printf("\n Datos Listados ! \n");
                }else
                {
                    printf("\nError: algo salio mal.\n");
                }
            }else
            {
                printf("\n Error: la lista esta vacia,cargue un empleado primero \n ");
            }
            break;
        case 7:
            if(!ll_isEmpty(lista_employee))
            {
               if(!controller_sortEmployee(lista_employee))
               {
                   printf("\n OK \n");
               }else
               {
                   printf("\n Error: Algo salio mal. \n");
               }
            }else
            {
                 printf("\n Error: la lista esta vacia,cargue un empleado primero \n");
            }

            break;
        case 8:

            if(ll_isEmpty(lista_employee)==0)
            {
               printf("\n Guarndo datos csv ...  \n");
               if(!controller_saveAsText("data.csv",lista_employee))
               {
                   printf("\n OK. \n");
               }
            }else
            {
                 printf("\n Error: la lista esta vacia,cargue un empleado primero\n");
            }

            break;
        case 9:
            if(ll_isEmpty(lista_employee)==0)
            {
               printf("\n Guarndo datos bin ...  \n");
               if(!controller_saveAsBinary("data.bin",lista_employee))
               {
                   printf("\n OK. \n");
               }
            }else
            {
                 printf("\n Error: la lista esta vacia,cargue un empleado primero\n");
            }

            break;
        case 10:
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

    }while(opcion!=10);

    return 0;
}
