/** @file CJT_Sesiones.hh
    @brief Especificación de la clase CJT_Sesiones
*/

#ifndef _CJT_SESIONES_HH_
#define _CJT_SESIONES_HH_

#include "Sesion.hh"
#include "Conexiones.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

/** @class CJT_Sesiones
    @brief Representa un conjunto ordenado de sesiones

    Las sesiones están guardados en un atributo, en formato diccionario e identifibales por su id
*/
class CJT_Sesiones
{
private:

    map<string, Sesion> CSesiones;

    /*
      Invariante de la representación:
      - Tamaño de CSesiones > 0
      - CSesiones esta ordenado crecientemente segun id de las Sesiones
    */

public:

    //Constructures

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un conjunto de sesiones
      \pre Cierto
      \post El resultado es un conjunto de sesiones vacio
    */
    CJT_Sesiones();

    //Consultores

    /** @brief Por Documentar
        \pre
        \post
    */
    //void inicializar_problemas_curso(Curso& curso, const string& id_sesion, int i);

    /** @brief Consultora de existencia de sesion
        \pre Cierto
        \post True si en el parametro implicito existe una sesion con el id dado
    */
    bool existe_sesion(const string& id_sesion) const;

    /** @brief Buscadora de problema en sesion
        \pre Cierto
        \post Devuelve true si el problema está en alguna sesión, false de lo contrario
    */
    bool problema_en_sesion(const string& id_sesion, const string& id_problema) const;

    /** @brief Consultora del primer problema de la sesion
        \pre Cierto
        \post Devuelve el problema inicial de la sesion
    */
    string obtener_raiz(const string& id_sesion) const;

    /** @brief Por Documentar
        \pre
        \post
    */
    pair<string, string> obtener_hijos(const string& id_sesion, const string id_problema) const;

    //Modificadores

    /** Lee un conjunto de sesiones
        \pre Cierto
        \post El parametro implicito contiene el conjunto de sesiones que se han leido
    */
    void leer_conjunto_sesiones();

    /** @brief Añade una sesion al conjunto
      \pre Cierto
      \post Se añade al parametro implicito una sesion con id_sesion y se le añade una serie de problemas leidos en formato preorden
    */
    void anadir_sesion(const string& id_sesion);

    /** @brief Por Documentar
        \pre
        \post
    */
    void inicializar_problemas(Conexiones& Conex, const string& id_sesion, int i) const;

    /** @brief Por Documentar
        \pre
        \post
    */
    bool inicializar_problemas_nuevos(Conexiones& Conex, const string& id_sesion, int i) const;


    //Lectura y escritura

    /** @brief Lista las sesiones
      \pre Cierto
      \post Imprime en el canal estandard de salida las sesiones del parametro implicito en orden creciente segun id
    */
    void listar_sesiones();

    /** @brief Escribe una sesion
      \pre Cierto
      \post Imprime en el canal estandard de salida el id de la sesion, el numero de problemas que contiene y su estructura de problemas
        en formato postorden. Si no existe ninguna sesion con el id en el parametro implcito, imprimir mensaje de error
    */
    void escribir_sesion(const string& id_sesion);
};
#endif // _CJT_SESIONES_HH_
