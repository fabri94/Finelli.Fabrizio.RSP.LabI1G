#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "post.h"

int parser_postsFromText(FILE* pFile, LinkedList* pListaPosts)
{
    int todoOk = 0;
    int cant;

    char buffer[5][128];
    ePost* auxPost;

    if(pFile!=NULL&&pListaPosts!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
        do
        {
            cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(cant<5)
            {
                break;
            }

            auxPost=post_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(auxPost!=NULL)
            {
                ll_add(pListaPosts,auxPost);
                todoOk=1;
                auxPost=NULL;
            }
        }
        while(!feof(pFile));
    }
    return todoOk;
}


