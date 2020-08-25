#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Validaciones.h"
int menu_sort()
{
    int decision;
    utn_getEntero(&decision,3,"\n1.ORDENAR POR ID\n2.ORDENAR POR NOMBRE\n3.ORDENAR POR HORAS TRABAJADAS\n4.ORDENAR POR SUELDO\n5.SALIR\n","\nError: Ingrese una opcion validad\n",1,5);
    return decision;
}
// debo realizar las funciones del emmployee para poder listar .
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
int retorno=-1;
FILE* pFile;


if (pArrayListEmployee!=NULL&&path!=NULL)
{
    pFile = fopen(path,"r");
    retorno=parser_EmployeeFromText(pFile,pArrayListEmployee);
}else
{
     printf("\nError: El archivo puede estar vacio. \n");

}
fclose(pFile);
return retorno
;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(pArrayListEmployee!=NULL&&path!=NULL)
    {
        pFile=fopen(path,"rb");
        retorno=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        //retorno = 0;
    }
    fclose(pFile);
return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
int retorno = -1;
int aux_int;
char aux_nombre[128];
Employee* new_employee=NULL;
new_employee = employee_new();
if ( pArrayListEmployee!=NULL)
{

    while (retorno==-1)
    {
     /* ID.
      if(utn_getEntero(&aux_int,3,"\nIngrese un ID:\n","Error: Ingresa un ID valido.\n",0,1000)==0)
      {
          employee_setId(new_employee,aux_int);
          printf("\nid=%d\n",aux_int);
      }else
      {
          retorno = -2;
      }*/
     // NOMBRE
     if(utn_getCadena(aux_nombre,128,3,"\nIngrese su nombre:\n","Error: Ingrese un nombre valido.\n")==0)
     {
         employee_setNombre(new_employee,aux_nombre);
         printf("\nnombre=%s\n",aux_nombre);
     }else
      {
          retorno = -2;
      }
     // HORAS TRABAJADAS
     if(utn_getEntero(&aux_int,3,"\n Ingrese horas trabajadas:\n","Error: Ingrese solo numeros.\n",0,10000)==0)
     {
         employee_setHorasTrabajadas(new_employee,aux_int);
         printf("\nhoras=%d\n",aux_int);
     }else
      {
          retorno = -2;
      }
     // SUELDO
     if(utn_getEntero(&aux_int,3,"\n Ingrese su sueldo:\n","Error: ingrese solo numeros.\n",0,1000000)==0)
     {
         employee_setSueldo(new_employee,aux_int);
         printf("\nsueldo=%d\n",aux_int);
         retorno=0;
     }else
      {
          retorno = -2;
      }
//fin del while
    }

    if(retorno==0)
    {
        if(new_employee!=NULL)
        {
            obtener_ID(&aux_int);
            employee_setId(new_employee,aux_int);
            actualizar_ID(aux_int);

            if(ll_add(pArrayListEmployee,new_employee)==0)
            {
                printf("\n Su ID es: %d   \n",aux_int);
                printf("\n ** ALTA EXITOSO!!  ** \n");
                //Employee* aux =employee_newParametros("546","prueba","56","67");
                employee_show_employee(new_employee);
                //show_employee(aux);

            }else
            {
                free(new_employee);
                printf("\n*** HA OCURRIDO UN ERROR!! ***");
            }
        }
    }
  }

return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
 Employee* aux_employee=NULL;
 int retorno = -1;
 int id_aux;
 int index;
 char aux_nombre[128];
 int aux_horas;
 int aux_sueldo;
 char decision;
 if(pArrayListEmployee!=NULL)
 {
     while(retorno==-1)
     {
        if(utn_getEntero(&id_aux,3,"\n Ingrese el ID del empleado.\n","\nError: ingrese un ID valido.\n",0,1000)==0)
        {
            index=employee_buscarpor_ID(pArrayListEmployee,id_aux);

            if(index>=0)
            {
                aux_employee=ll_get(pArrayListEmployee,index);
                if(aux_employee!=NULL)
                {
                    printf("\n*** EMPLEADO ENCONTRADO! ***\n");
                    employee_show_employee(aux_employee);
                //nombre
                    utn_getCadena(aux_nombre,128,3,"\nIngrese nuevo nombre:\n","\n Error: Ingrese un nombre valido.\n");
                // HORAS
                    utn_getEntero(&aux_horas,3,"\nRe-ingrese horas trabajadas: \n","\nError: Ingrese cantidad de horas validas.\n",0,10000);
                //SUELDO
                    utn_getEntero(&aux_sueldo,3,"\nRe-ingrese sueldo:\n","\nError: ingrese un sueldo valido\n",0,10000000);
                    retorno=0;
                }
            }
        }
     }
 }
    if(retorno==0)
    {
        printf("\nDesea efectuar los cambios? (s/n) \n");
        fflush(stdin);
        scanf("%c",&decision);
        if(decision=='s')
        {
            printf ("\n\t** SE HAN EFECTUADO LOS CAMBIOS.  **\n ");
            employee_setNombre(aux_employee,aux_nombre);
            employee_setHorasTrabajadas(aux_employee,aux_horas);
            employee_setSueldo(aux_employee,aux_sueldo);
            employee_show_employee(aux_employee);

        }else
        {
            printf ("\n\t** SE HAN CANCELADO LOS CAMBIOS.  **\n ");
        }
    }

return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux_employee=NULL;
    int retorno=-1;
    int aux_id;
    int index;
    char decision;
    if(pArrayListEmployee!=NULL)
    {
        if(utn_getEntero(&aux_id,3,"\n Ingrese el ID del empleado.\n","\nError: ingrese un ID valido.\n",0,1000)==0)
        {
            index=employee_buscarpor_ID(pArrayListEmployee,aux_id);
            if(index>=0)
            {
                aux_employee=ll_get(pArrayListEmployee,index);
                if(aux_employee!=NULL)
                {
                    printf("\n*** EMPLEADO ENCONTRADO! ***\n");
                    employee_show_employee(aux_employee);
                    printf("\nDesea Eliminar el empleado? (s/n) \n");
                    fflush(stdin);
                    scanf("%c",&decision);
                    if(decision=='s')
                    {
                        free(aux_employee);
                        ll_remove(pArrayListEmployee,index);
                        printf("\n*** EMPLEADO ELIMINADO! ***\n");
                    }else
                    {
                        printf ("\n\t** SE HA CANCELADO EL DELETE.  **\n ");
                    }
                }
            }
        }else
        {
            printf("\n*** EMPLEADO NO ENCONTRADO! ***\n");
        }
    }

return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* aux_employee=NULL;
    int i;
    int tam;
    if(pArrayListEmployee!=NULL)
    {
        tam=ll_len(pArrayListEmployee);
        for (i=0;i<tam;i++)
        {
            aux_employee=ll_get(pArrayListEmployee,i);
            if(aux_employee!=NULL)
            {
                employee_show_employee(aux_employee);
                retorno=0;
            }
        }
    }
return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    char decision = 0;
    int opcion;
    do
    {
       switch (menu_sort())
       {
        case 1:
        printf("\nSort by ID !\n");
        ll_sort(pArrayListEmployee,employee_CompareById,1);
        retorno=1;
        break;
        case 2:
        printf("\nSort by NOMBRE!\n");
        ll_sort(pArrayListEmployee,employee_CompareByName,1);
        retorno=1;
        break;
        case 3:
        printf("\nSort by HORAS TRABAJADAS!\n");
        ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas,1);
        retorno=1;
        break;
        case 4:
        printf("\nSort by SUELDO!\n");
        ll_sort(pArrayListEmployee,employee_CompareBySueldo,1);
        retorno=1;
        break;
        case 5:
        printf("***\nDesea salir? (s/n)\n***");
        fflush(stdin);
        scanf("%c",&decision);
        if(decision=='s')
        {
           opcion=5;
           retorno=1;
           break;
        }
        default:
            printf("\n\nIngrese una opcion valida\n\n");
        }


    }while(opcion!=5);


return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* Pfile;
    Employee* aux_employee=NULL;
    int aux_id;
    char aux_nombre[128];
    int aux_horas;
    int aux_sueldo;

    if (pArrayListEmployee!=NULL && path!=NULL)
    {
        Pfile=fopen(path,"w");
        if(Pfile!=NULL)
        {
            retorno=0;
            fprintf(Pfile,"id,nombre,horas Trabajadas,sueldo\n");
            for (int i=0;i<ll_len(pArrayListEmployee);i++)
            {
                aux_employee=ll_get(pArrayListEmployee,i);
                if(!employee_getId(aux_employee,&aux_id)&&
                   !employee_getNombre(aux_employee,aux_nombre)&&
                   !employee_getHorasTrabajadas(aux_employee,&aux_horas)&&
                   !employee_getSueldo(aux_employee,&aux_sueldo))
                {
                    fprintf(Pfile,"%d,%s,%d,%d\n",aux_id,aux_nombre,aux_horas,aux_sueldo);
                }
            }
            fclose(Pfile);
            printf("\nSe han guardado los datos en el Archivo.csv!!\n");
        }
}else
{
    retorno=-2;
    printf("\nError:Verificar parametros .! \n");
}
return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* Pfile;
    Employee* aux_employee;
    int tam; ll_len(pArrayListEmployee);
    if (path!=NULL&&pArrayListEmployee!=NULL)
    {
        Pfile=fopen(path,"wb");
        tam=ll_len(pArrayListEmployee);
        for(int i=0;i<tam;i++)
        {
            aux_employee=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(aux_employee,sizeof(Employee),1,Pfile);
        }
        fclose(Pfile);
        retorno=0;
    }else
    {
        retorno=-2;
        printf("\nError: Verificar parametros.! \n");
    }
return retorno;
}

int menu()
{
 int opcion;
 printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).  \n");
 printf("\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).  \n");
 printf("\n3. Alta de empleado.  \n");
 printf("\n4. Modificar datos de empleado.  \n");
 printf("\n5. Baja de empleado.  \n");
 printf("\n6. Listar empleados.  \n");
 printf("\n7. Ordenar empleados.  \n");
 printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).  \n");
 printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
 printf("\n10. Salir,  \n");
 scanf("%d",&opcion);
 return opcion;

}

