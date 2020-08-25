#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();
// recibe y posiciona un campo de la estructura 0=OK -1=FAIL.
int employee_setId(Employee* this,int id_);
//devuelve un campo de la estructura 0=OK -1=FAIL.
int employee_getId(Employee* this,int* id_);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int obtener_ID(int* id_);
int actualizar_ID(int id_);

int employee_CompareById(void* e1, void* e2);
int employee_CompareByName(void* e1, void* e2);
int employee_CompareByHorasTrabajadas(void* e1, void* e2);
int employee_CompareBySueldo(void* e1, void* e2);

void employee_show_employee(Employee* Pemployee);
int employee_buscarpor_ID(LinkedList* this,int id_ );
#endif // employee_H_INCLUDED
