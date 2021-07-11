/** @file Prob_Ses.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CONEXIONES_HH_
#define _CONEXIONES_HH_

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

using namespace std;

class Conexiones
{
private:

    map <string, int> prob_ses; //señala a que sesion i-essima del curso pertenece cada problema

public:

/** @brief Por Documentar
    \pre
    \post
*/
void anadir_entrada(const string& id_problema, int i);

/** @brief Por Documentar
    \pre
    \post
*/
bool anadir_entrada_nueva(const string& id_problema, int i);

/** @brief Por Documentar
    \pre
    \post
*/
int encontrar_problema(const string& id_problema) const;

};
#endif
