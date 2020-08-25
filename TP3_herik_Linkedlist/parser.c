#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"
#include "Validaciones.h"
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
     Employee* aux_employee=NULL;
     int cont_datos=0;
     char id_ [20];
     char nombre_[128];
     char horasTrabajadas_[50];
     char sueldo_[20];
     int retorno_ok= -1;

 if (pFile!=NULL && pArrayListEmployee != NULL)
 {
     ll_clear(pArrayListEmployee);
       // leo la cantidad de datos y los guardo en el contador.
   fscanf(pFile,"%*[^,],%*[^,],%*[^,],%*[^\n]");

   while(!feof(pFile))
    {
        cont_datos =  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id_,nombre_,horasTrabajadas_,sueldo_);

        if(cont_datos == 4 )
        {
            aux_employee=employee_newParametros(id_,nombre_,horasTrabajadas_,sueldo_); // inicializo el empleado
            if(aux_employee!=NULL)
            {
                if (ll_add(pArrayListEmployee,aux_employee)==0)//( 0) Si funciono correctamente
                {
                    retorno_ok =1;
                }else // (-1) Error: si el puntero a la lista es NULL
                {
                    retorno_ok=-1;
                    printf("\nError: el puntero a la lista es NULL\n");
                }

            }

        }
    }

 }
    fclose(pFile);
    return retorno_ok ;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* aux_employee;
    int retorno =-1;

        if(pFile!=NULL&&pArrayListEmployee!=NULL)
        {
            while(!feof(pFile))
            {
                aux_employee=employee_new();
                fread(aux_employee,sizeof(Employee),1,pFile);
                ll_add(pArrayListEmployee,aux_employee);
                retorno=0;
            }
        }
     fclose(pFile);
    return retorno;
}
