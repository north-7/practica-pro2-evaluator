#include "CJT_Sesiones.hh"

CJT_Sesiones::CJT_Sesiones() {
    static map<string, Sesion> CSesiones;
}

bool CJT_Sesiones::existe_sesion(const string& id_sesion) const {
    map<string, Sesion>::const_iterator it;
    it = CSesiones.find(id_sesion);
    return it != CSesiones.end();
}

bool CJT_Sesiones::problema_en_sesion(const string& id_sesion, const string& id_problema) const {
    map<string, Sesion>::const_iterator it = CSesiones.find(id_sesion);
    return (it->second.esta_problema(id_problema));
}

void CJT_Sesiones::leer_conjunto_sesiones() {
    int input;
    cin >> input;
    for (int i = 0; i < input; ++i) {
        string id_sesion;
        cin >> id_sesion;
        Sesion s;
        s.leer_sesion();
        CSesiones.insert(make_pair(id_sesion, s));
    }
}

void CJT_Sesiones::anadir_sesion(const string& id_sesion) {
    Sesion s;//
    s.leer_sesion();
    if (existe_sesion(id_sesion)) cout << "error: la sesion ya existe" << endl;
    else {
        CSesiones.insert(make_pair(id_sesion, s));
        cout << CSesiones.size() << endl;
    }
}

string CJT_Sesiones::obtener_raiz(const string& id_sesion) const {
    map<string, Sesion>::const_iterator it = CSesiones.find(id_sesion);
    return it->second.obtener_raiz();
}

pair<string, string> CJT_Sesiones::obtener_hijos(const string& id_sesion, const string id_problema) const {
    map<string, Sesion>::const_iterator it = CSesiones.find(id_sesion);
    return it->second.obtener_hijos(id_problema);
}

void CJT_Sesiones::inicializar_problemas(Conexiones& Conex, const string& id_sesion, int i) const {
    map<string, Sesion>::const_iterator it = CSesiones.find(id_sesion);
    it->second.inicializar_problemas(Conex,i);
}

bool CJT_Sesiones::inicializar_problemas_nuevos(Conexiones& Conex, const string& id_sesion, int i) const {
    map<string, Sesion>::const_iterator it = CSesiones.find(id_sesion);
    return it->second.inicializar_problemas_nuevos(Conex,i);
}

void CJT_Sesiones::listar_sesiones() {
    for (map<string, Sesion>::iterator it = CSesiones.begin(); it != CSesiones.end(); ++it) {
        cout << it->first << " ";
        it->second.escribir();
        cout << endl;
    }
}

void CJT_Sesiones::escribir_sesion(const string& id_sesion) {
    if (existe_sesion((id_sesion))) {
        map<string, Sesion>::iterator it;
        it = CSesiones.find(id_sesion);
        cout << it->first << " ";
        it->second.escribir();
        cout << endl;
    }
    else cout << "error: la sesion no existe" << endl;
}
