/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#include "Conexiones.hh"


#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
#include "BinTree.hh"
#endif

/** @class Sesion
    @brief Representa una sesion de problemas ordenada

    Guarda los id de problemas segun una relación de prerequisitos

*/
class Sesion
{

private:

    BinTree<string> Ses;
    int tamano;
    set<string> Probs;

    /*
      Invariante de la representación:
      - Tamaño de Ses > 0
      - Los problemas de Ses están ordenados en Preorden, representando un sistema de prerequisitos
      - Probs contiene los problemas de la sesion, con tal de agilizar otros calculos
    */

    /**@brief Lee el arbol binario que forma una sesion, en formato preorden
        \pre Cierto
        \post El parametro implicito contiene el arbol binario leido y un conjunto con los problemas
    */
    void leer_arbol_binario(BinTree<string>& a);

    /**@brief Escribe el arbol binario de la sesión, en formato postorden
    \pre Cierto
    \post Se imprime por el canal estandard de salida el arbol
    */
    static void escribir_arbol_binario(const BinTree<string>& a);

    /** @brief Por Documentar
        \pre
        \post
    */
    void ini_problemas_recursivo(const BinTree<string>& a, Conexiones& Conex, int i) const;

    /** @brief Por Documentar
        \pre
        \post
    */
    bool ini_problemas_nuevos_recursivo(const BinTree<string>& a, Conexiones& Conex, int i) const;

    /** @brief Por Documentar
        \pre
        \post
    */
    bool obtener_hijos_recursivo(const BinTree<string>& a, const string& id_problema, pair<string, string>& hijos) const;

public:

    //Constructures

    /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar una sesion.
      \pre Cierto
      \post El resultado es una sesion conteniendo un arbol de problemas y un conjunto de problemas vacio
    */
    Sesion();

    // Consultores

    /** @brief Consultora de si está el problema en la sesion
        \pre Cierto
        \post Devuelve true si el problema está en la sesion
    */
    bool esta_problema(const string& id_problema) const;

    /** @brief Consultora requisito inicial sesion
        \pre Cierto
        \post Devuelve el primer problema a resolver de la sesion
    */
    string obtener_raiz() const;

    /** @brief Por Documentar
        \pre
        \post
    */
    pair<string, string> obtener_hijos(const string& id_problema) const;

    /** @brief Por Documentar
        \pre
        \post
    */
    void inicializar_problemas(Conexiones& Conex, int i) const;

    /** @brief Por Documentar
        \pre
        \post
    */
    bool inicializar_problemas_nuevos(Conexiones& Conex, int i) const;

    //Lectura y escriptura

    /** @brief Operacion de lectura
        \pre Está preparado por el canal estandard un listado de problemas en formato preorden
        \post El parámetro implícito conteniendo los problemas entrados siguiento las relaciones de requisito y un conjunto con los problemas
    */
    void leer_sesion();

    /** @brief Operacion de escritura
        \pre Cierto
        \post Imprime en el canal estandard de salida el numero de problemas que contiene y su estructura de problemas en formato postorden
    */
    void escribir();

};
#endif // _SESION_HH_
