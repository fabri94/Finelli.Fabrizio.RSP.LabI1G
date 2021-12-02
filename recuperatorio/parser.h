#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
/** \brief Parsea los datos los datos de los empleados desde el archivo posts.csv (modo texto).
 *
 * \param pFile FILE* archivo de donde se obtienen los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \return int devuelve 1 si esta todo bien o 0 si hubo algun problema
 *
 */
int parser_postsFromText(FILE* pFile , LinkedList* pListaPosts);


#endif // PARSER_H_INCLUDED
