#include <stdlib.h>
#include <stdio.h>
#include "post.h"
#include "informes.h"

int userMasPopular(LinkedList* pListaPosts)
{
    int todoOk=0;
    int tam;
    int masLikes;
    ePost* auxPost=NULL;
    if(pListaPosts!=NULL)
    {
        tam=ll_len(pListaPosts);
        for(int i=0;i<tam;i++)
        {
            auxPost=(ePost*)ll_get(pListaPosts,i);
            if(auxPost!=NULL)
            {
                if(i==0||masLikes<auxPost->likes)
                {
                    masLikes=auxPost->likes;
                }
            }
        }
    }
    printf("\nMayor cantidad de likes: %d\n\nUser/s\n",masLikes);
    printf("----------\n");
    for(int i=0; i<tam;i++)
    {
        auxPost=(ePost*)ll_get(pListaPosts,i);
        if(auxPost!=NULL)
        {
            if(masLikes==auxPost->likes)
            {
                printf("%s\n",auxPost->user);
                todoOk=1;
            }
        }

    }
    printf("\n\n");

    return todoOk;
}
