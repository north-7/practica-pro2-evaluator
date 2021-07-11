/** @file CJT_Usuarios.hh
    @brief Especificación de la clase CJT_Usuarios
*/

#ifndef _CJT_USUARIOS_HH_
#define _CJT_USUARIOS_HH_


#include "Usuario.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/** @class CJT_Usuarios
    @brief Representa un conjunto de usuarios

    Los usuarios están guardados en un atributo, ordenado crecientemente según ID
*/
class CJT_Usuarios
{

private:
    map<string, Usuario> CUsuarios;

    /*
      Invariante de la representación:
      - tamaño de CUsuarios > 0
    */


public:

    //Constructures

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un conjunto de usuarios
      \pre Cierto
      \post El resultado es un conjunto de usuarios vacio
    */
    CJT_Usuarios();

    //Consultores

    /** @brief Consultora existencia usuario
        \pre Cierto
        \post True si el parametro implicito contiene el usuario con id_usuario, false de lo contrario
    */
    bool existe_usuario(const string& id_usuario) const;

    /** @brief Consulta curso inscrito
        \pre Cierto
        \post Devuelve -1 si no esta inscrito en ningun curso. Si existe, devuelve la id del curso en el que está inscrito
    */
    int curso_usuario(const string& id_usuario) const;

    /** @brief Consulta problemas resueltos
        \pre Cierto
        \post Si el usuario no existe en el conjunto de usuarios, imprimir mensjae de error. si existe, imprime los problemas resueltos por orden creciente de id de problemas y el numero de intentos realizados a cada problema
    */
    void problemas_resueltos(const string& id_usuario);

    /** @brief Consulta problemas enviables
        \pre Cierto
        \post Si el usuario no existe en el conjunto de usuarios, imprimir mensjae de error. si existe, imprime los problemas enviables por orden creciente de id del usuario y el numero de intentos realizados a cada problema
    */
    void problemas_enviables(const string& id_usuario);

    //Modificadores

    /** Lee un conjunto de usuarios
        \pre Cierto
        \post El parametro implicito contiene el conjunto de usuarios leidos
    */
    void leer_conjunto_usuarios();

    /** @brief Añade un usuario al conjunto
      \pre Cierto
      \post Se añade al parametro implicito un usuario con id_usuario. Imprime por el canal estandard de salida numero de usuarios registrados despues de añadirlo
    */
    void anadir_usuario(const string& id_usuario);

    /** @brief Elimina un usuario del conjunto
      \pre Cierto
      \post Se elimina del parametro implicito un usuario identificador id_leida. Imprime numero de usuarios registrados despues de eliminarlo
    */
    void eliminar_usuario(const string& id_usuario);

    /** @brief Inscribir en curso
        \pre Cierto
        \post Inscribe al usuario id_usuario en el curso id_curso. Si cualquiera de los dos no existe, o el usuario
    */
    void inscribir_curso(const string& id_usuario, const int& id_curso, const CJT_Cursos& Cursos, const CJT_Sesiones& Sesiones);

    /** @brief Por Documentar
        \pre
        \post
    */
    void actualizar_estadisticas_fallo(const string& id_usuario, const string& id_problema);

    /** @brief Por Documentar
        \pre
        \post
    */
    void actualizar_estadisticas_acierto(const string& id_usuario, const string& id_problema, CJT_Cursos& Cursos, const CJT_Sesiones& Sesiones);

    //Lectura y escritura

    /** @brief Lista los usuarios
      \pre Cierto
      \post Imprime en el canal estandard de salida, por orden crecientemente segun id los usuarios y para cada cuantos envios  ha hecho en total, cuantos ha problemas ha resuelto, cuantos ha intentado resolver y el id del curso en el que esta (0 si no esta en ninguno)
    */
    void listar_usuarios();

    /** @brief Escribe un usuario
      \pre Cierto
      \post Imprime por el canal estandard de salida para cada cuantos envios  ha hecho en total,cuantos ha problemas ha resuelto, cuantos ha intentado resolver y el id del curso en el que esta (0 si no esta en ninguno)
    */
    void escribir_usuario(const string& id_usuario);
};
#endif // _CJT_USUARIOS_HH_
