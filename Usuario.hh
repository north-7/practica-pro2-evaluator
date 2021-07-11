/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include "CJT_Cursos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/** @class Usuario
    @brief Representa un usuario

    Tiene 3 atributos a modo de estadísticas: problemas intentados, resueltos y enviados
*/
class Usuario
{

private:
    map<string, int> resueltos;     //id_problema, intentos
    map<string, int> enviables;     //id_problema, intentos
    int curso;
    int envios;
    int intentados;

    /*
      Invariante de la representación:
      - si el tamaño de enviables = 0 --> usuario no está inscrito en ningun curso
      - curso identifica la id del curso al que está inscrito actualmente; -1 indica que no está inscrito en ningun curso.
      - enviables nunca contendrá un problema que se encuentra en resueltos
      - en intentados, intentos >= 1
      - en resueltos, intentos >= 1
      - en enviables, intentos >= 0
    */


    /** @brief Por Documentar
        \pre
        \post
    */
    void actualizar_enviables_recursivo(const string& id_problema, const string& id_sesion, const CJT_Sesiones& Sesiones);

public:

    //Constructures

    /** @brief Creadora por defecto

        Se ejecutara automáticamente al declarar un usuario
        \pre Cierto
        \post El resultado es un usuario con un conjunto de intentados vacio, un conjunto de resueltos vacio y un conjunto de enviables vacio
    */
    Usuario();

    //Modificadores

    /** @brief Inscribe el usuario en un curso
        \pre Cierto
        \post Se guarda la id del curso y se añaden todos los problemas iniciales de sus sesiones al conjunto de enviables
    */
    void inscribir_curso(const int& id_curso, const CJT_Cursos& Cursos, const CJT_Sesiones& Sesiones);

    /** @brief Por Documentar
        \pre
        \post
    */
    void actualizar_estadisticas_fallo(const string& id_problema);

    /** @brief Por Documentar
        \pre
        \post
    */
    void actualizar_estadisticas_acierto(const string& id_problema, CJT_Cursos& Cursos, const CJT_Sesiones& Sesiones, const string& id_usuario);

    //Consultores

    /** @brief Consultora de curso inscrito
        \pre Cierto
        \post Devuelve la id del curso en el que esta inscrito el parametro implicito, o -1 si no está en ninguno
    */
    int consultar_curso() const;

    //Lectura y escritura

    /** @brief Imprime resueltos
        \pre Cierto
        \post Imprime en el canal estandard de salida los id de problemas resueltos y el numero de intentos a cada uno; Si no tiene ningun resuelto, salto de linea.
    */
    void imprimir_resueltos();

    /** @brief Imprime enviables
        \pre Cierto
        \post Imprime en el canal estandard de salida los id de problemas enviables y el numero de intentos a cada uno. Si el parametro implicito no esta inscrito en ningun curso, imprimir mensaje de error
    */
    void imprimir_enviables();

    /** @brief Escribe el usuario
        \pre Cierto
        \post Imprime en el canal estandard de salida cuantos envios en total ha realizado, cuantos problemas ha resuelto bien, cuantos ha intentado y el id del curso en el que está inscrito (0 si ninguno)
    */
    void escribir();

};
#endif // _USUARIO_HH_
