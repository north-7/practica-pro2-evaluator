/** @file Problema.hh
    @brief Especificación de la clase Problema
*/

#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/** @class Problema
    @brief Representa un problema

    Tiene 3 atributos a modo de estadísticas: envios totales, envios completos y ratio entre estos

*/
class Problema {

private:

    int envios_totales;
    int envios_completados;
    double ratio;

    /*
      Invariante de la representación:
      - envios_totales >= 0
      - envios completados >= 0
      - ratio = (envios_totales+1) / (envios_completados+1)
    */

public:

    //Constructures

    /** @brief Creadora por defecto

        Se ejecutara automáticamente al declarar un problema
        \pre Cierto
        \post Crea un problema con numero de envios totales y numero de envios correctos = 0 y ratio = 1
    */
    Problema();

    /** @brief Por Documentar
        \pre
        \post
    */
    void actualizar_estadisticas_fallo();

    /** @brief Por Documentar
        \pre
        \post
    */
    void actualizar_estadisticas_acierto();

    /** @brief Por Documentar
        \pre
        \post
    */
    double obt_ratio() const;

    /** @brief Operación de escritura
        \pre Cierto
        \post Imprime en el canal estandard de salida el numero de envios totales, el numero de envios con exito,
        el ratio entre ambos
    */
    void escribir();
};
#endif // _PROBLEMA_HH_
