#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED
typedef struct
{
    int id;
    char user[128];
    int likes;
    int dislikes;
    int followers;
}ePost;


#endif // POST_H_INCLUDED
ePost* post_new();
ePost* post_newParametros(char* id, char* user, char* likes, char* dislikes, char* followers);

int post_delete(ePost* this);

int post_setId(ePost* this, int id);
int post_setUser(ePost* this, char* user);
int post_setLikes(ePost* this, int likes);
int post_setDislikes(ePost* this, int dislikes);
int post_setFollowers(ePost* this, int followers);


int post_getId(ePost* this, int* id);
int post_getUser(ePost* this, char* user);
int post_getLikes(ePost* this, int* likes);
int post_getDislikes(ePost* this, int* dislikes);
int post_getFollowers(ePost* this, int* followers);


void* post_asignarEstadisticas(void* pPost);

int filterMejoresPosteos(void* pPost);
int filterHaters(void* pPost);

int compararFollowers(void* pPost1, void* pPost2);

void menuOpciones();

