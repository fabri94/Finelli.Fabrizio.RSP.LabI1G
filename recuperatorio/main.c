#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "post.h"
#include "Controller.h"
#include "inputs.h"
#include "informes.h"


#define INTENTOS 3

int main()
{
    srand(time(NULL));
    int opcion=0;
    int flagSts=0;
    char path[20];
    char salir;
    char seguir='s';
    LinkedList *listaPosts=ll_newLinkedList();


    if(listaPosts==NULL)
    {
        printf("No se pudo crear la linkedList.\n");
        exit(1);
    }

    do
    {
        system("cls");
        menuOpciones();

        if(!getEntero(&opcion,1,8,INTENTOS,"Ingrese opcion: ","Error, opcion invalida\n"))
        {
            printf("Se excedio el limite de intentos, se cerrara el programa\n");
            exit(1);
        }
        switch(opcion)
        {
        case 1:
            system("cls");
            if(getCadena(path,19,INTENTOS,"Ingrese el nombre del archivo a cargar (sugerencia: 'posts.csv'): ","Error, reingrese nombre: \n"))
            {

                if(controller_loadFromText(listaPosts,path))
                {
                    printf("Se cargo el archivo de posts\n");
                }else
                {
                    printf("Hubo un error al querer abrir el archivo\n");
                }
            }else
            {
                printf("Se excedio el limite de intentos\n");
            }

            system("pause");
            break;

        case 2:
            system("cls");
            if(!ll_isEmpty(listaPosts))
            {
                controller_listPosts(listaPosts);
            }else
            {
                printf("No hay posts para mostrar ya que aun no se cargo ningun archivo\n");
            }
            system("pause");
            break;

        case 3:
            system("cls");
            if(!ll_isEmpty(listaPosts))
            {
                if(controller_mapAsignStatistics(listaPosts))
                {
                    printf("\nSe asignaron correctamente las estadisticas\n");
                    flagSts=1;
                }
            }else
            {
                printf("No hay posts para mostrar ni asignarle estadisticas ya que aun no se cargo ningun archivo\n");
            }
            system("pause");
            break;

        case 4:
            system("cls");
            if(!ll_isEmpty(listaPosts)&&flagSts)
            {
                if(controller_filterBestPosts(listaPosts))
                {
                    printf("\nSe filtaron los mejores posteos (>3000 likes) y se guardaron\n");
                }
            }else
            {
                printf("No hay posts para mostrar ni filtrar de acuerdo a la cantidad de likes ya que aun no se cargo ningun archivo o no se asignaron estadisticas aun\n");
            }
            system("pause");
            break;

        case 5:
            system("cls");
            if(!ll_isEmpty(listaPosts)&&flagSts)
            {
                if(controller_filterHaters(listaPosts))
                {
                    printf("\nSe filtaron los haters de acuerdo al numero de dislikes\n");
                }
            }else
            {
                printf("No hay haters para mostrar ni filtrar de acuerdo al numero de dislikes ya que aun no se cargo ningun archivo, o no se asignaron estadisticas aun\n");
            }
            system("pause");
            break;

        case 6:
            system("cls");
            if(!ll_isEmpty(listaPosts)&&flagSts)
            {
                if(controller_sortByFollowers(listaPosts))
                {
                    printf("Se ordenaron los posts de acuerdo a la cantidad de followers (orden descendente), con exito\n");
                }
            }else
            {
                printf("No hay posts para ordenar ya que no se cargo ningun archivo o no se asignaron estadisticas aun.\n");
            }
            system("pause");
            break;

        case 7:
            system("cls");
            if(!ll_isEmpty(listaPosts))
            {
                if(userMasPopular(listaPosts)&&flagSts)
                {
                    printf("Se filtro/aron el/los user/s mas popular/es con exito\n");
                }
            }else
            {
                printf("No hay posts para filtrar ya que no se cargo ningun archivo o no se asignaron estadisticas aun.\n");
            }
            system("pause");
            break;

        case 8:
            system("cls");
            if(!getLetra(&salir,INTENTOS,"¿Esta seguro que desea salir? 's' para si, 'n' para no: ","Error\n"))
            {
                printf("Se excedio el limite de intentos\n");
            }else
            {
                if(salir=='s')
                {
                    printf("\nHa seleccionado salir.\nSe cerrara el programa.\n");
                    seguir='n';
                }
            }
            break;
        }
    }while(seguir=='s');

    ll_deleteLinkedList(listaPosts);
    return 0;
}
