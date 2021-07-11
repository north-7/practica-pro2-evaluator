#include "Problema.hh"

using namespace std;

Problema::Problema() {
    envios_totales = 0;
    envios_completados = 0;
    ratio = 1;
}

void Problema::actualizar_estadisticas_fallo() {
    envios_totales++;
    ratio = (double(envios_totales + 1) / (envios_completados + 1));
}

void Problema::actualizar_estadisticas_acierto() {
    envios_totales++;
    envios_completados++;
    ratio = (double(envios_totales + 1) / (envios_completados + 1));
}

double Problema::obt_ratio() const {
    return ratio;
}

void Problema::escribir() {
    cout << '(' << envios_totales << ',' << envios_completados << ',' << ratio << ')' << endl;
}
