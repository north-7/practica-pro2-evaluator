/** @file CJT_Problemas.hh
    @brief Especificación de la clase CJT_Problemas
*/

#ifndef _CJT_PROBLEMAS_HH_
#define _CJT_PROBLEMAS_HH_


#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class CJT_Problemas
    @brief Representa un conjunto ordenado de problemas

    Los problemas están guardados en un atributo, en formato diccionario e identifibales por su id
    Estan ordenados segun su ratio entre envios totales / envios correctos
*/
class CJT_Problemas {

private:



    map<string, Problema> CProblemas;

    /*
      Invariante de la representación:
      - Tamaño de CProblemas > 0
      - CProblemas ordenado crecientemente segun ratio de los problemas y por id en caso de empate
    */


public:

    //Constructores

    /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un conjunto de problemas
      \pre Cierto
      \post El resultado es un conjunto de problemas vacio
  */
    CJT_Problemas();

    //Consultores

    /** @brief Consultora de la existencia de un problema
      \pre Cierto
      \post El resultado indica si el problema está en el parametro implicito
    */
    bool existe_problema(const string& id_problema) const;

    //Modificadores

    /** @brief Por Documentar
        \pre
        \post
    */
    void actualizar_estadisticas_fallo(const string& id_problema);

    /** @brief Por Documentar
        \pre
        \post
    */
    void actualizar_estadisticas_acierto(const string& id_problema);

    /** Lee un conjunto de problemas
        \pre Cierto
        \post El parametro implicito contiene el conjunto de problemas leidos
    */
    void leer_conjunto_problemas();

    /** @brief Añade un problema al conjunto
      \pre Cierto
      \post El parámetro implícito contiene sus problemas originales mas el identificado por id_problema. En caso de ya existir, imprime en el canal estandard de salida un mensaje de error
    */
    void anadir_problema(const string& id_problema);

    //Lectura y escritura

    /** @brief Lista los problemas
      \pre Cierto
      \post Imprime en el canal estandard de salida,por orden creciente, segun ratio, y en caso de empate por id, los ids de cada problema, el numero de intentos totales, el numero de intentos con exito y el ratio entre ambos
    */
    void listar_problemas();

    /** @brief Escribe un problema
      \pre Cierto
      \post Imprime en el canal estandard de salida el id del problema, el numero de envios totales, el numero de envios con exito, el ratio de completados. Si no existe, enviar mensaje de error
    */
    void escribir_problema(const string& id_problema);
};
#endif // _CJT_PROBLEMAS_HH_
