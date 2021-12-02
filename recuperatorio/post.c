#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "post.h"
#include "inputs.h"
#include "LinkedList.h"


ePost* post_new()
{
    ePost* nuevoPost=(ePost*) malloc(sizeof(ePost));
    if(nuevoPost!=NULL)
    {
        nuevoPost->id=0;
        strcpy(nuevoPost->user,"");
        nuevoPost->likes=0;
        nuevoPost->dislikes=0;
        nuevoPost->followers=0;
    }
    return nuevoPost;
}


ePost* post_newParametros(char* id, char* user, char* likes, char* dislikes, char* followers)
{
    ePost* nuevoPost=post_new();
    if(nuevoPost!=NULL)
    {
        if(!(post_setId(nuevoPost,atoi(id)) &&
                post_setUser(nuevoPost,user) &&
                post_setLikes(nuevoPost,atoi(likes)) &&
                post_setDislikes(nuevoPost,atoi(dislikes))&&
                post_setFollowers(nuevoPost,atoi(followers))
               ))
        {
            post_delete(nuevoPost);
            nuevoPost=NULL;
        }
    }
    return nuevoPost;

}

int post_delete(ePost* this)
{
    int todoOk=0;
    if(this!=NULL)
    {
        free(this);
        todoOk=1;
    }
    return todoOk;

}

int post_setId(ePost* this, int id)
{
    int todoOk=0;
    if(this!=NULL&&id>0)
    {
        this->id=id;
        todoOk=1;
    }
    return todoOk;

}


int post_setUser(ePost* this, char* user)
{
    int todoOk = 0;
    if(this!=NULL&&user!=NULL&&strlen(user)>0&&strlen(user)<128)
    {
        strcpy(this->user, user);
        todoOk=1;
    }
    return todoOk;
}


int post_setLikes(ePost* this, int likes)
{
    int todoOk=0;
    if(this!=NULL&&likes>=0)
    {
        this->likes=likes;
        todoOk=1;
    }
    return todoOk;


}

int post_setDislikes(ePost* this, int dislikes)
{
  int todoOk=0;
    if(this!=NULL&&dislikes>=0)
    {
        this->dislikes=dislikes;
        todoOk=1;
    }
    return todoOk;
}

int post_setFollowers(ePost* this, int followers)
{
  int todoOk=0;
    if(this!=NULL&&followers>=0)
    {
        this->followers=followers;
        todoOk=1;
    }
    return todoOk;
}


int post_getId(ePost* this, int* id)
{
    int todoOk;
    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        todoOk=1;
    }
    return todoOk;

}

int post_getUser(ePost* this, char* user)
{
   int todoOk=0;
    if(this!=NULL&&user!=NULL)
    {
        strcpy(user, this->user);
        todoOk=1;
    }
    return todoOk;


}

int post_getLikes(ePost* this, int* likes)
{
    int todoOk=0;
    if(this!=NULL&&likes!=NULL)
    {
        *likes=this->likes;
        todoOk=1;
    }
    return todoOk;


}
int post_getDislikes(ePost* this, int* dislikes)
{
    int todoOk=0;
    if(this!=NULL&&dislikes!=NULL)
    {
        *dislikes=this->dislikes;
        todoOk=1;
    }
    return todoOk;


}

int post_getFollowers(ePost* this, int* followers)
{
    int todoOk=0;
    if(this!=NULL&&followers!=NULL)
    {
        *followers=this->followers;
        todoOk=1;
    }
    return todoOk;


}

void* post_asignarEstadisticas(void* pPost)
{
    int likes;
    int dislikes;
    int followers;
    int maxLikes=5000;
    int minLikes=500;
    int maxDislikes=3500;
    int minDislikes=300;
    int maxFollowers=20000;
    int minFollowers=10000;
    ePost* auxPost=NULL;

    if(pPost!=NULL)
    {
        auxPost=(ePost*)pPost;

        likes=rand()%(maxLikes-minLikes+1)+minLikes;
        dislikes=rand()%(maxDislikes-minDislikes+1)+minDislikes;
        followers=rand()%(maxFollowers-minFollowers+1)+minFollowers;

        post_setLikes(auxPost,likes);
        post_setDislikes(auxPost,dislikes);
        post_setFollowers(auxPost,followers);

    }
    return auxPost;
}

int filterMejoresPosteos(void* pPost)
{
    int returnAux=0;
    ePost* auxPost=NULL;
    if(pPost!=NULL)
    {
        auxPost=(ePost*)pPost;
        if(auxPost->likes>3000)
        {
            returnAux=1;
        }
    }
    return returnAux;
}

int filterHaters(void* pPost)
{
    int returnAux=0;
    ePost* auxPost=NULL;
    if(pPost!=NULL)
    {
        auxPost=(ePost*)pPost;
        if(auxPost->dislikes > auxPost->likes)
        {
            returnAux=1;
        }
    }
    return returnAux;

}


int compararFollowers(void* pPost1, void* pPost2)
{
    int todoOk=0;
    ePost* auxPost1=NULL;
    ePost* auxPost2=NULL;

    if(pPost1!=NULL&&pPost2!=NULL)
    {
        auxPost1=(ePost*)pPost1;
        auxPost2=(ePost*)pPost2;
        if(auxPost1->followers < auxPost2->followers)
            {
                todoOk=1;
            }

        if(auxPost1->followers > auxPost2->followers)
             {
                 todoOk=-1;
             }
    }
    return todoOk;
}

void menuOpciones()
{
    printf("***** Menu de opciones ***** \n\n");
    printf("  1. Cargar archivo.\n");
    printf("  2. Imprimir lista.\n");
    printf("  3. Asignar estadisticas.\n");
    printf("  4. Filtrar por mejores posteos.\n");
    printf("  5. Filtrar por haters.\n");
    printf("  6. Ordenar por cantidad de followers.\n");
    printf("  7. Mostrar mas popular.\n");
    printf("  8. Salir.\n\n");
}
