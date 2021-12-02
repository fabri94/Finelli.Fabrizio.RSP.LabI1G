#include "post.h"
#include "LinkedList.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(LinkedList* pListaPosts, char* path);

int controller_saveAsText(LinkedList* pListaPosts, char* path);

int controller_listPost(ePost* pPost);

int controller_listPosts(LinkedList* pListaPosts);

int controller_mapAsignStatistics(LinkedList* pListaPosts);

int controller_filterBestPosts(LinkedList* pListaPosts);

int controller_filterHaters(LinkedList* pListaPosts);

int controller_sortByFollowers(LinkedList* pListaPosts);


#endif // CONTROLLER_H_INCLUDED
