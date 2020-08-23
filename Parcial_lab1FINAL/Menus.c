#include "Menus.h"
#include "Validaciones_.h"
int menuPrincipal()
{
    int decision;
    utn_getEntero(&decision,3,"1. Listar Choferes.\n 2. Listar Camiones con chofer.\n3. Listar Choferes con camion.\n4. Alta camion.\n5. Baja camion.\n6. Modificar camion.\n7. Alta chofer.\n8. Baja chofer.\n9. Ordenar camiones por TIPO.\n10. Editar  Chofer.\n11.listar Chofer con mas de un camion\n12.Listar Camiones con mas de 10 anios \n13.Listar Camion por Marca \n14.Listar y ordenar Choferes por cantidad de Camiones (REVISAR)\n15.Listar  y  ordenar Choferes por cantidad de Camiones y Nombre \n16.Promedio de Edad en Choferes \n17.Promedio Antiguedad Flota de Camiones\n18.Porcentaje de Varones sobre el total de Choferes \n19.Listar Choferes con Camion por marca\n20.Lista de Choferes por Nacionalidad\n21.Ordenar Chofer por Nacionalidad y por Nombre\n22. Salir\n","Error:Ingrese una opcion valida\n",1,22);
    return decision;
}
int menu_tipocamion()
{
    int decision;
    utn_getEntero(&decision,3,"1.Corta Distancia.\n 2.Larga Distancia.\n ","Error: Elija una opcion valida.\n",1,2);
    return decision;
}

int menu_modificar()
{
    int decision;
    utn_getEntero(&decision,3,"1.Modificar Anio. \n2. Modificar Marca.\n3.Modificar Chofer\n","Error: Elija una opcion valida.\n",1,3);
    return decision;
}
int menu_modificarChofer()
{
    int decision;
    utn_getEntero(&decision,3,"1.Editar Nombre: \n2.Editar Apellido: \n3.Editar DNI: \n4.Editar Legajo:  \n5.Editar Nacionalidad:\n6.Editar Telefono: \n7.Editar Edad\n8.Editar Sexo\n9.Salir\n","Error: Ingrese una opcion Valida!!",1,9);
    return decision;
}

