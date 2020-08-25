#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include "Validaciones.h"
Employee* employee_new()
{
    Employee* nuevo_empleado=NULL;
    nuevo_empleado = (Employee*)malloc(sizeof(Employee));
    return nuevo_empleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
   Employee* nuevo_empleado=NULL;
   nuevo_empleado=employee_new();
   if (nuevo_empleado!=NULL)
   {
       employee_setId(nuevo_empleado,atoi(idStr));
       employee_setNombre(nuevo_empleado,nombreStr);
       employee_setHorasTrabajadas(nuevo_empleado,atoi(horasTrabajadasStr));
       employee_setSueldo(nuevo_empleado,atoi(sueldoStr));
   }else
   {
       printf("Error: No hay mas espacio para un nuevo empleado\n");
   }
   return nuevo_empleado;
}

int employee_setNombre(Employee* this,char* nombre_)
{
    int retorno=-1;
    if(this!=NULL && utn_solocaracter(nombre_)==0)
    {
        strcpy(this->nombre,nombre_);
        retorno=0 ;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    //char* nombre_aux;
    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this !=NULL &&  sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL&&sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;

}

int employee_setId(Employee* this,int id_)
{
     int retorno=-1;
    if(this!=NULL&&id_>0)
    {
       this->id=id_;
        retorno=0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id_)
{
    int retorno=-1;
    if(this!=NULL&&id_!=NULL)
    {
       *id_=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL&&horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;

}
int obtener_ID(int* id_)
{
    int retorno=-1;
    *id_=1001;
    FILE* Pfile;

    Pfile=fopen("proximoId.bin","rb");
    if(Pfile!=NULL)
    {
        fread(id_,sizeof(int),1,Pfile);

        fclose(Pfile);
        retorno=0;
    }
    return retorno;
}

int actualizar_ID(int id_)
{
    int retorno=-1;
    id_++;

    FILE* Pfile;
    Pfile=fopen("proximoId.bin","wb");

    if(Pfile!=NULL)
    {
        fwrite(&id_,sizeof(int),1,Pfile);

        fclose(Pfile);
        retorno=0;
    }
    return retorno;
}

int employee_CompareByName(void* e1, void* e2)
{
    int retorno=0;
    // defino elementos del tipo EMPLEADO
    Employee* aux_1;
    Employee* aux_2;
    char nombre_1[128];
    char nombre_2[128];
    // referencio los elementos recividos por parametro a una entidad conocida.
    aux_1 = (Employee*) e1;
    aux_2 = (Employee*) e2;
    // obtengo los nombres de cada empleado por medio de los geter
    if(employee_getNombre(aux_1,nombre_1)==0&&employee_getNombre(aux_2,nombre_2)==0)
    {
       if(strcmp(nombre_1,nombre_2)>0)
       {
           retorno=1;
       }else if(strcmp(nombre_1,nombre_2)<0)
       {
           retorno=-1;
       }
    }


    return retorno;
}

int employee_CompareById(void* e1, void* e2)
{
    int retorno=0;
    Employee* aux_1;
    Employee* aux_2;
    int id_1,id_2;
    if(e1!=NULL&&e2!=NULL)
    {
        aux_1= (Employee*)e1;
        aux_2= (Employee*)e2;
        if(employee_getId(aux_1,&id_1)==0&&employee_getId(aux_2,&id_2)==0)
        {
            if(id_1>id_2)
            {
                retorno=1;
            }else
            {
                retorno=-1;
            }
        }
    }

    return retorno ;
}
int employee_CompareByHorasTrabajadas(void* e1, void* e2)
{
    int retorno=0;
    Employee* aux_1;
    Employee* aux_2;
    int horas_1,horas_2;
    if(e1!=NULL&&e2!=NULL)
    {
        aux_1= (Employee*)e1;
        aux_2= (Employee*)e2;
        if(employee_getHorasTrabajadas(aux_1,&horas_1)==0&&employee_getHorasTrabajadas(aux_2,&horas_2)==0)
        {
            if(horas_1>horas_2)
            {
                retorno=1;
            }else
            {
                retorno=-1;
            }
        }
    }

    return retorno ;
}
int employee_CompareBySueldo(void* e1, void* e2)
{
    int retorno=0;
    Employee* aux_1;
    Employee* aux_2;
    int sueldo_1,sueldo_2;
    if(e1!=NULL&&e2!=NULL)
    {
        aux_1= (Employee*)e1;
        aux_2= (Employee*)e2;
        if(employee_getSueldo(aux_1,&sueldo_1)==0&&employee_getSueldo(aux_2,&sueldo_2)==0)
        {
            if(sueldo_1>sueldo_2)
            {
                retorno=1;
            }else
            {
                retorno=-1;
            }
        }
    }

    return retorno ;
}
void employee_show_employee(Employee* Pemployee)
{
    if (Pemployee!=NULL)
    {
        printf("%d,%10s,%10d, %10d$\n",Pemployee->id,
                                    Pemployee->nombre,
                                    Pemployee->horasTrabajadas,
                                    Pemployee->sueldo);
    }
}
int  employee_buscarpor_ID (LinkedList* this,int id_ )
{
   Employee* aux_employee=NULL;
   int i;
   int retorno=-1;
   int tamanio= ll_len(this);

   if (this!=NULL&&id_>=0)
   {
        retorno=-2;
       for (i=0;i<tamanio;i++)
       {
            aux_employee =(Employee*) ll_get(this,i);
            if(aux_employee->id==id_)
            {
                retorno=i;
                break;
            }
       }
   }
    return retorno;
}
