#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"
#include "post.h"

int controller_loadFromText(LinkedList* pListaPosts, char* path)//cambiar esto hacer que reciba char* path
{
    int todoOk=0;
    FILE* pFile=NULL;

    if(path!=NULL&&pListaPosts!=NULL)
    {
            pFile=fopen(path,"r");
            if(pFile==NULL)
            {
                printf("No se pudo abrir el archivo.\n");
            }
            else
            {
                if(parser_postsFromText(pFile,pListaPosts))
                {
                    printf("Carga de archivo de texto exitosa.\n");
                    todoOk=1;
                }
            }
            fclose(pFile);
    }
    return todoOk;
}


int controller_saveAsText(LinkedList* pListaPosts, char* path) //cambiar esto hacer que reciba char* path
{
    int todoOk=0;
    int id;
    char user[128];
    int likes;
    int dislikes;
    int followers;
    ePost* pPost;
    FILE* pFile=NULL;

    if(path!=NULL&&pListaPosts!=NULL)
    {

            pFile=fopen(path, "w");
            if(pFile==NULL)
            {
                printf("No se pudo abrir el archivo.\n");
            }
            else
            {
                fprintf(pFile,"id,user,likes,dislikes,followers\n");
                for(int i=0;i<ll_len(pListaPosts);i++)
                {
                    pPost=(ePost*) ll_get(pListaPosts,i);
                    if(pPost!=NULL)
                    {
                        if(post_getId(pPost,&id) &&
                                post_getUser(pPost,user) &&
                                post_getLikes(pPost,&likes) &&
                                post_getDislikes(pPost,&dislikes) &&
                                post_getFollowers(pPost,&followers))
                        {
                            fprintf(pFile, "%d,%s,%d,%d,%d\n", id, user, likes, dislikes, followers);
                            todoOk=1;
                        }
                    }
                }
            }

        fclose(pFile);
    }
    return todoOk;
}

int controller_listPost(ePost* pPost)
{
    int todoOk=0;
    int id;
    char user[128];
    int likes;
    int dislikes;
    int followers;

    if(pPost!=NULL)
    {
        if( post_getId(pPost,&id) &&
                                post_getUser(pPost,user) &&
                                post_getLikes(pPost,&likes) &&
                                post_getDislikes(pPost,&dislikes) &&
                                post_getFollowers(pPost,&followers))
        {
            printf (" %3d   %-20s  %4d        %4d           %5d\n", id, user, likes, dislikes, followers);
            todoOk=1;
        }
    }
    return todoOk;
}

int controller_listPosts(LinkedList* pListaPosts)
{
    int todoOk=0;
    int tam;
    ePost* auxPost=NULL;
    if(pListaPosts!=NULL)
    {
        tam=ll_len(pListaPosts);
        system("cls");
        printf("    ******    Lista de posts   *****\n\n");
        printf("---------------------------------------------------------------------\n");
        printf(" ID    USER                 LIKES      DISLIKES      FOLLOWERS\n");
        printf("---------------------------------------------------------------------\n");
        for(int i=0;i<tam;i++)
        {
            auxPost=(ePost*) ll_get(pListaPosts,i);
            //mostrarPelicula(auxMovie);
            controller_listPost(auxPost);
            todoOk=1;
        }

    }
    return todoOk;


}

int controller_mapAsignStatistics(LinkedList* pListaPosts)
{
    int todoOk=0;
    pListaPosts=ll_map(pListaPosts,post_asignarEstadisticas);
    if(pListaPosts!=NULL)
    {
        controller_listPosts(pListaPosts);
        todoOk=1;
    }
    return todoOk;

}


int controller_filterBestPosts(LinkedList* pListaPosts)
{
    int todoOk=0;
    char nombreArchivo[20];


    pListaPosts=ll_filter(pListaPosts,filterMejoresPosteos);

    if(pListaPosts!=NULL)
    {
            controller_listPosts(pListaPosts);
            system("pause");
            if(!getCadena(nombreArchivo,19,3,"\nIngrese nombre del archivo a guardar sin la extension '.csv' : ","Error, reingrese nombre: \n"))
            {
                printf("Se excedio el limite de intentos y no se pudo guardar el archivo\n");
            }else
            {
                strcat(nombreArchivo,".csv");
                controller_saveAsText(pListaPosts,nombreArchivo);
            }
            todoOk=1;
    }
    return todoOk;

}

int controller_filterHaters(LinkedList* pListaPosts)
{
    int todoOk=0;
    char nombreArchivo[20];


    pListaPosts=ll_filter(pListaPosts,filterHaters);

    if(pListaPosts!=NULL)
    {
            controller_listPosts(pListaPosts);
            system("pause");
            if(!getCadena(nombreArchivo,19,3,"\nIngrese nombre del archivo a guardar sin la extension '.csv' : ","Error, reingrese nombre: \n"))
            {
                printf("Se excedio el limite de intentos y no se pudo guardar el archivo\n");
            }else
            {
                strcat(nombreArchivo,".csv");
                controller_saveAsText(pListaPosts,nombreArchivo);
            }
            todoOk=1;
    }
    return todoOk;

}

int controller_sortByFollowers(LinkedList* pListaPosts)
{
    int todoOk=0;
    if(pListaPosts!=NULL)
    {
        ll_sort(pListaPosts,compararFollowers,1);
        controller_listPosts(pListaPosts);
        todoOk=1;
    }

    return todoOk;
}


