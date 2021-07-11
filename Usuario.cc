#include "Usuario.hh"

Usuario::Usuario() {
    curso = -1;
    envios = 0;
    intentados = 0;
}

void Usuario::actualizar_estadisticas_fallo(const string& id_problema) {
    map<string, int>::iterator it = enviables.find(id_problema);
    it->second++;
    ++envios;
    if (it->second == 1) intentados++;
}

void Usuario::actualizar_estadisticas_acierto(const string& id_problema, CJT_Cursos& Cursos, const CJT_Sesiones& Sesiones, const string& id_usuario) {
    map<string, int>::iterator it = enviables.find(id_problema);
    it->second++;

    if (it->second == 1) ++intentados;
    ++envios;

    resueltos.insert(make_pair(it->first, it->second));
    enviables.erase(it);


    string id_sesion = Cursos.sesion_problema(curso, id_problema);

   actualizar_enviables_recursivo(id_problema, id_sesion, Sesiones);

   if (enviables.empty()) {
    Cursos.usuario_completado(curso, id_usuario);
    curso = -1;
   }
}

void Usuario::actualizar_enviables_recursivo(const string& id_problema, const string& id_sesion, const CJT_Sesiones& Sesiones) {
    map<string, int>::iterator it = resueltos.find(id_problema);
    if (it != resueltos.end()){
    pair<string, string> hijos = Sesiones.obtener_hijos(id_sesion, id_problema);
    actualizar_enviables_recursivo(hijos.first, id_sesion, Sesiones);
    actualizar_enviables_recursivo(hijos.second, id_sesion, Sesiones);
    }
    else if (id_problema != "0") enviables.insert(make_pair(id_problema, 0));
}

void Usuario::inscribir_curso(const int& id_curso, const CJT_Cursos& Cursos, const CJT_Sesiones& Sesiones) {
    this->curso = id_curso;

    int size = Cursos.tamano_curso(id_curso);
    for (int i = 0; i < size; ++i) {
        string id_sesion = Cursos.obtener_sesion_i(id_curso, i);
        string id_problema = Sesiones.obtener_raiz(id_sesion);
        actualizar_enviables_recursivo(id_problema, id_sesion, Sesiones);
    }
}

int Usuario::consultar_curso() const {
    return this->curso;
}

void Usuario::imprimir_resueltos() {
    for (map<string, int>::const_iterator it = resueltos.begin(); it != resueltos.end(); ++it) {
    cout << it->first << "(" << it->second << ")" << endl;
    }
}

void Usuario::imprimir_enviables() {
    if (curso == -1) cout << "error: usuario no inscrito en ningun curso" << endl;
    else {
        for (map<string, int>::const_iterator it = enviables.begin(); it != enviables.end(); ++it) {
        cout << it->first << "(" << it->second << ")" << endl;
        }
    }
}

void Usuario::escribir() {
    cout << "(" << envios << "," << resueltos.size() << "," << intentados << ",";
    if (curso == -1) cout << "0";
    else cout << curso;
    cout << ")" << endl;
}
