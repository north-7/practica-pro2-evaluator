/** @file CJT_Cursos.hh
    @brief Especificación de la clase CJT_Cursos
*/

#ifndef _CJT_CURSOS_HH_
#define _CJT_CURSOS_HH_


#include "Curso.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

/** @class CJT_Cursos
    @brief Representa un conjunto ordenado de cursos

    Los cursos están guardados en un atributo, ordenado crecientemente según ID
*/
class CJT_Cursos
{
private:
    vector<Curso> VCursos;

    /*
      Invariante de la representación:
      - Tamaño de VCursos > 0
      - Los elementos de VCursos designan elementos con una id de 1 mas que si indice; el elemento V[0] representa el de id 1.
    */

public:

    //Constructures

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un conjunto de cursos
      \pre Cierto
      \post El resultado es un conjunto de cursos vacio
    */
    CJT_Cursos();

    //Consultores

    /** @brief Consultora de sesion del curso en posicion i
        \pre Cierto
        \post Devuelve la id de la sesion del curso id_curso leida la i-essima
    */
    string obtener_sesion_i(const int& id_curso, const int& i) const;

    /** @brief Buscadora de sesion problema
        \pre Cierto
        \post Devuelve el id de la sesion en la que se encuentra el problema o i0 si no está en el curso
    */
    string sesion_problema(const int& id_curso, const string& id_problema) const;

    /** @brief Consultora existencia curso
      \pre Cierto
        \post Devuelve true si existe un curso con la id en el conjunto de cursos del parametro implicito. false de lo contrario
    */
    bool existe_curso(const unsigned int& id_curso) const;

    /** @brief Consultora tamaño de un curso
        \pre Cierto
        \post Devuelve la cantidad de sesiones que tiene el curso
    */
    int tamano_curso(const int& id_curso) const;


    //Modificadores

    /** @brief Elimina usuario del curso
        \pre Cierto
        \post El curso id_curso deja de tener guardada id_usuario
    */
    void eliminar_usuario(const int& id_curso, const string& id_usuario);

    /** @brief Por Documentar
        \pre
        \post
    */
    void usuario_completado(const int& id_curso, const string& id_usuario);

    /** Lee un conjunto de cursos
        \pre Cierto
        \post El parametro implicito contiene el conjunto de cursos leidos
    */
    void leer_conjunto_cursos(const CJT_Sesiones& Sesiones);

    /** @brief Añade un curso al conjunto
      \pre Cierto
      \post Se añade al parametro implícito el curso c
    */
    void anadir_curso(const Curso& c);

    /** @brief Añade un usuario a un curso
        \pre Cierto
        \post El curso referenciado por id_curso tiene guardado el usuario id_usuario como inscrito
    */
    void inscribir_usuario(const int& id_curso, const string& id_usuario);

    //Lectura y escritura

    /** @brief Lista los cursos
      \pre Cierto
      \post Imprime en el canal estandard de salida,por orden creciente de id, la id de cada curso, el numero de usuarios que lo han completado, el numero de usuarios inscritos, el numero de sesiones que lo forman y los identificadores de dichas sesiones, en el orden que se leyo al crear el curso
    */
    void listar_cursos();

    /** @brief Escribe un curso
      \pre Cierto
      \post Imprime en el canal estandard de salida la id del curso, el numero de usuarios que lo han completado, el numero de usuarios actuales, el numero de sesiones que lo forman y los ids de dichas sesiones, en el orden que se leyo al crear el curso
    */
    void escribir_curso(const int& id_curso);

};
#endif // _CJT_CURSOS_HH_
