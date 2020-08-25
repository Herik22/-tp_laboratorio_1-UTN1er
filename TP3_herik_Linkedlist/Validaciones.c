#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "ctype.h"

#include "validaciones.h"



int utn_solonumero ( char* mystr )
{

    int PointCounter = 0;
    int Iterator = 0;
    int retorno = -1;

    if ( * ( mystr + Iterator ) == '-' )
    {

        Iterator++;











    }

    while ( *( mystr + Iterator ) != '\0'  )
    {

        if ( isdigit ( *(mystr + Iterator) ) != 0 )
        {

            Iterator++;

            retorno =0;


        }
        else if ( ( *(mystr + Iterator) ) == '.' && PointCounter < 1 )
        {

            PointCounter++;

            Iterator++;

            retorno = 0;

        }
        else
        {

            retorno = -1;

            break;

        }

    }

    return retorno;

}

int utn_solocaracter ( char* mystr )
{

    int retorno = -1;

    int Iterator = 0;

    while ( *( mystr + Iterator ) != '\0' )
    {

        if ( isalpha ( *( mystr + Iterator ) ) != 0 || *( mystr + Iterator ) == ' ' )
        {

            Iterator++;

            retorno = 0;

        }
        else
        {

            retorno = -1;

            break;

        }

    }

    return retorno;

}

int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int minimo,int maximo)

{

    int todoOk = -1;

    int auxInt;



    if(pEntero!=NULL&& msg !=NULL && msgError!=NULL && minimo<= maximo && reintentos>=0)

    {

        do

        {

            reintentos--;

            printf("%s",msg);

            if(getInt(&auxInt) == 0 && auxInt >= minimo && auxInt<=maximo)

            {

                *pEntero= auxInt;

                todoOk = 0;

                break;

            }

            else

            {

                printf("%s",msgError);

            }

        }

        while(reintentos >= 0);

    }

    return todoOk;

}

int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float minimo,float maximo)

{

    int todoOk = -1;

    float auxFloat;



    if(pFloat!=NULL&& msg !=NULL && msgError!=NULL && minimo<= maximo && reintentos>=0)

    {

        do

        {

            reintentos--;

            printf("%s",msg);

            if(getFloat(&auxFloat) == 0 && auxFloat >= minimo && auxFloat<=maximo)

            {

                *pFloat= auxFloat;

                todoOk = 0;

                break;

            }

            else

            {

                printf("%s",msgError);

            }

        }

        while(reintentos >= 0);

    }

    return todoOk;

}

int getCadena(char* pAux,int limite)

{

    char auxString[2000];

    int todoOk =-1;

    if (pAux != NULL && limite >0)

    {

        fflush(stdin);

        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')

        {

            auxString[strlen(auxString)-1]='\0';

        }

        if(strlen(auxString)<= limite)

        {

            strncpy(pAux,auxString,limite);

            todoOk=0;

        }

    }

    return todoOk;

}

int getInt(int* pAux)

{

    char auxString[200];

    int todoOk =-1;

    if(getCadena(auxString,200)==0 && isInt(auxString)==0)

    {

        *pAux=atoi(auxString);

        todoOk=0;

    }

    return todoOk;

}

int isInt(char *pAux)

{

    int todoOk=-1;

    int i=0;
    do
    {
        if(*(pAux+i)<48||*(pAux+i)>57)
        {
            break;
        }
        i++;

    }while (i<strlen(pAux));

    if(i==strlen(pAux))

    {

        todoOk=0;

    }else
    printf("SOLO NUMEROS CRACK");

    return todoOk;

}

int isFloat(char* pAux)

{

    int todoOk=-1;

    int i=0;

    int contadorDePuntos=0;

    do

    {

        if(*(pAux+i)=='.')

        {

            contadorDePuntos++;

            if(contadorDePuntos==2)

            {

                break;

            }

        }

        else if(*(pAux+i)<48||*(pAux+i)>57)

        {

            break;

        }

        i++;

    }while (i<strlen(pAux));

    if(i==strlen(pAux))

    {

        todoOk=0;

    }

    return todoOk;

}

int getFloat(float*pAux)

{

    char auxString[200];

    int todoOk =-1;

    if(getCadena(auxString,200)==0 && isFloat(auxString)==0)

    {

        *pAux=atof(auxString);

        todoOk=0;

    }

    return todoOk;

}

int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError)

{

    int todoOk=-1;

    char auxString[limite];

    if(pAux!=NULL && limite >0 && reintentos >=0){

        do{

            reintentos--;

            printf("%s",msj);

            if(getCadena(auxString,limite)==0 && isLetras(auxString)==0){

                strncpy(pAux,auxString,limite);

                todoOk=0;

                break;

            }else

                printf("%s",msjError);

        }while(reintentos>=0);

    }

    return todoOk;

}

int isLetras(char*pAux)

{

    int todoOk=-1;

    int i=0;

    if(pAux!=NULL){

        do{

            if((*(pAux+i)<65||*(pAux+i)>90) && (*(pAux+i)<97||*(pAux+i)>122)){

                break;

            }

            i++;

        }while(i<strlen(pAux));

        if(i==strlen(pAux)){

            todoOk=0;

        }else
        printf("LA CAGASTE");

    }

    return todoOk;

}



