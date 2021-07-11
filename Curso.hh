/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#include "CJT_Sesiones.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <set>
#endif

/** @class Curso
    @brief Representa una lista de sesiones ordenado

    Guarda las sesiones segun el orden de entrada

*/
class Curso
{
private:
    vector<string> Cur;
    set<string> UIns;
    set<string> UCom;

    Conexiones Conex;

    /*
      Invariante de la representación:
      - Tamaño de Cur > 0
      - Cur ordenado crecientemente segun el orden de entrada
      - UIns contiene solo usuarios activos
      - UCom contiene usuarios activos y pasados
    */

public:

    //Constructures

    /** @brief Creadora por defecto

        Se ejecutara automáticamente al declarar un curso
        \pre Cierto
        \post El resultado es un curso con conjuntos vacios de sesiones, usuarios inscritos y usuarios completados
    */
    Curso();

    //Modificadores

    /** @brief Inscribe un usuario al curso
        \pre Cierto
        \post Se añade al conjunto de usuarios inscritos el id
    */
    void inscribir_usuario(const string& id_usuario);

    /** @brief Elimina un usuario del curso
        \pre Cierto
        \post Se elimina del conjunto de usuarios inscritos el id
    */
    void borrar_usuario(const string& id_usuario);


    /** @brief Acciones al completar curso
        \pre Cierto
        \post Se elimina la id del conjunto de usuarios inscritos y se añade al conjunto de usuarios completados
    */
    void curso_completado(const string& id_usuario);

    //Consultores

    /** @brief Consultora sesion leida la í-essima
        \pre Cierto
        \post Devuelve la id de la sesion leida la i-essima
    */
    string sesion_i(const int& i) const;

    /** @brief Tamaño curso
        \pre Cierto
        \post Devuelve la cantidad de sesiones que tiene el curso
    */
    int tamano() const;

    /** @brief Buscar problema
        \pre Cierto
        \post Devuelve el id de la sesion en la que se encuentra id_problema, o 0 si el problema no esta en el curso
    */
    string buscar_problema(const string& id_problema) const;

    /** @brief Por Documentar
        \pre
        \post
    */
    void inicializar_problemas(const CJT_Sesiones& Sesiones);


    //Lectura y escritura

    /** @brief Operacion de lectura
        \pre Está preparado por el canal estandard un entero S que representa el numero de sesiones seguido de S sesiones
        \post Si hay problemas repetidos entre las sesiones, devuelve false. Si no, el parámetro implícito es un conjunto de sesiones, y devuelve true.
    */
    bool leer_curso_nuevo(const CJT_Sesiones& Sesiones);

    /** @brief Por Documentar
        \pre
        \post
    */
    void leer_curso();

    /** @brief Operación de escritura
        \pre Cierto
        \post Imprime por el canal estandard de salida el numero de usuarios que lo han completado, el numero de usuarios actuales, el numero de sesiones que lo forman y los ids de dichas sesiones, en el orden que se leyo al crear el curso
    */
    void escribir();

};
#endif // _CURSO_HH_
