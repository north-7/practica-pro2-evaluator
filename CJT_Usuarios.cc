#include "CJT_Usuarios.hh"

CJT_Usuarios::CJT_Usuarios(){
}

int CJT_Usuarios::curso_usuario(const string& id_usuario) const {
    map<string, Usuario>::const_iterator it = CUsuarios.find(id_usuario);
    return it->second.consultar_curso();
}

bool CJT_Usuarios::existe_usuario(const string& id_usuario) const{
    return CUsuarios.find(id_usuario) != CUsuarios.end();
}

void CJT_Usuarios::inscribir_curso(const string& id_usuario, const int& id_curso, const CJT_Cursos& Cursos, const CJT_Sesiones& Sesiones) {
    map<string, Usuario>::iterator it = CUsuarios.find(id_usuario);
    return it->second.inscribir_curso(id_curso, Cursos, Sesiones);
}

void CJT_Usuarios::problemas_resueltos(const string& id_usuario) {
    map<string, Usuario>::iterator it = CUsuarios.find(id_usuario);
    it->second.imprimir_resueltos();
}

void CJT_Usuarios::problemas_enviables(const string& id_usuario) {
    map<string, Usuario>::iterator it = CUsuarios.find(id_usuario);
    it->second.imprimir_enviables();
}

void CJT_Usuarios::actualizar_estadisticas_fallo(const string& id_usuario, const string& id_problema) {
    map<string, Usuario>::iterator it = CUsuarios.find(id_usuario);
    it->second.actualizar_estadisticas_fallo(id_problema);
}

void CJT_Usuarios::actualizar_estadisticas_acierto(const string& id_usuario, const string& id_problema, CJT_Cursos& Cursos, const CJT_Sesiones& Sesiones) {
    map<string, Usuario>::iterator it = CUsuarios.find(id_usuario);
    it->second.actualizar_estadisticas_acierto(id_problema, Cursos, Sesiones, it->first);
}

void CJT_Usuarios::leer_conjunto_usuarios() {
    int input;
    cin >> input;
    for (int i = 0; i < input; ++i) {
        Usuario u;
        string id_usuario;
        cin >> id_usuario;
        CUsuarios.insert(make_pair(id_usuario, u));
    }
}

void CJT_Usuarios::anadir_usuario(const string& id_usuario) {
    Usuario u;
    CUsuarios.insert(make_pair(id_usuario, u));
    cout << CUsuarios.size() << endl;
}

void CJT_Usuarios::eliminar_usuario(const string& id_usuario) {
     map<string, Usuario>::iterator it = CUsuarios.find(id_usuario);
     CUsuarios.erase(it);
     cout << CUsuarios.size() << endl;
}

void CJT_Usuarios::listar_usuarios() {
    for (map<string, Usuario>::iterator it = CUsuarios.begin(); it != CUsuarios.end(); ++it) {
    cout << it->first;
    it->second.escribir();
    }
}

void CJT_Usuarios::escribir_usuario(const string& id_usuario) {
    if (existe_usuario(id_usuario)) {
        map<string, Usuario>::iterator it = CUsuarios.find(id_usuario);
        cout << it->first;
        it->second.escribir();
    }
    else cout << "error: el usuario no existe" << endl;
}

