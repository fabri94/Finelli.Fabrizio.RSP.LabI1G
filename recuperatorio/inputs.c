#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

int getEntero(int* pNumero, int lInf, int lSup, int intentos, char msj[], char msjError[])
{
    int todoOk=0;
    int auxNumero;
    if(pNumero!=NULL&&lInf<=lSup&&intentos>0&&msj!=NULL&&msjError!=NULL)
    {
        for(int i=intentos;i>0;i--)
        {
            printf("%s",msj);
            fflush(stdin);
            if((scanf("%d",&auxNumero))
               &&(auxNumero>=lInf)
               &&(auxNumero<=lSup))
                {
                    *pNumero=auxNumero;
                    todoOk=1;
                    break;
                }
            printf("%s",msjError);
        }
    }
    return todoOk;
}

int getFlotante(float* pNumero, float lInf, float lSup, int intentos, char msj[], char msjError[])
{
    int todoOk=0;
    float auxNumero;
    if(pNumero!=NULL&&lInf<=lSup&&intentos>0&&msj!=NULL&&msjError!=NULL)
    {
        for(int i=intentos;i>0;i--)
        {
            printf("%s",msj);
            fflush(stdin);
            if((scanf("%f",&auxNumero))
               &&(auxNumero>=lInf)
               &&(auxNumero<=lSup))
                {
                    *pNumero=auxNumero;
                    todoOk=1;
                    break;
                }
            printf("%s",msjError);
        }
    }
    return todoOk;

}

int getCadena(char cadena[], int largo, int intentos, char msj[], char msjError[])
{
    char auxCadena[100];
    int todoOk=0;
    int flag;
    int i=0;
    if(cadena!=NULL&&intentos>0&&msj!=NULL&&msjError!=NULL)
    {
        do
        {
            printf("%s",msj);
            fflush(stdin);
            gets(auxCadena);
            flag=0;

            while(auxCadena[i]!='\0')
            {
                if((auxCadena[i]!=' ')&&(auxCadena[i]<'a'||auxCadena[i]>'z')&&(auxCadena[i]<'A'||auxCadena[i]>'Z')&&(auxCadena[i]!='.'))
                {
                    flag=1;
                    break;
                }
                else
                {
                    i++;
                }
            }
            if(strlen(auxCadena)<=largo&&!flag)
            {
                strcpy(cadena,auxCadena);
                todoOk=1;
                break;
            }
            printf("%s",msjError);
            intentos--;
        }while(intentos);

    }

    return todoOk;
}

int formatearSustPropio(char cadena[])
{
    int todoOk=0;
    if(cadena!=NULL)
    {
        strlwr(cadena);
        cadena[0]=toupper(cadena[0]);
        for(int i=1;cadena[i]!='\0';i++)
        {
            if(cadena[i]==' ')
            {
                cadena[i+1]=toupper(cadena[i+1]);
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int getLetra(char *letra, int intentos, char msj[], char msjError[])
{
    int todoOk=0;
    if (letra!=NULL&&msj!=NULL&&msjError!=NULL&&intentos>=0)
    {
        do
        {
            printf("%s", msj);
            fflush(stdin);
            scanf("%c", letra);
            if(!isalpha(*letra))
            {
                printf("%s", msjError);
                intentos--;
            }
            else
            {
                break;
            }
        }while(intentos);

        if(intentos>0)
        {
            todoOk=1;
        }
    }
    return todoOk;

}
