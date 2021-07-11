#include "Sesion.hh"

Sesion::Sesion() {
    tamano = 0;
}

bool Sesion::esta_problema(const string& id_problema) const {
    return (Probs.find(id_problema) != Probs.end());
}

string Sesion::obtener_raiz() const {
    return Ses.value();
}

pair<string, string> Sesion::obtener_hijos(const string& id_problema) const{
    pair<string, string> hijos;
    obtener_hijos_recursivo(Ses, id_problema, hijos);
    return hijos;
}

bool Sesion::obtener_hijos_recursivo(const BinTree<string>& a, const string& id_problema, pair<string, string>& hijos) const {

    if (a.value() == id_problema) {
        if (a.left().empty()) hijos.first = "0";
        else hijos.first = a.left().value();

        if (a.right().empty()) hijos.second = "0";
        else hijos.second = a.right().value();

        return true;
    }
    else {
        if (a.left().empty() and a.right().empty()) return false;
        if (a.left().empty()) return obtener_hijos_recursivo(a.right(), id_problema, hijos);
        if (a.right().empty()) return obtener_hijos_recursivo(a.left(), id_problema, hijos);
        return obtener_hijos_recursivo(a.left(), id_problema, hijos) or obtener_hijos_recursivo(a.right(), id_problema, hijos);
    }
}


void Sesion::leer_sesion() {
    leer_arbol_binario(Ses);
}

void Sesion::leer_arbol_binario(BinTree<string>& a) {
    string s;
    cin >> s;
    if (s != "0") {
        this->tamano++;
        Probs.insert(s);

        BinTree<string> iz;
        leer_arbol_binario(iz);

        BinTree<string> de;
        leer_arbol_binario(de);

        a = BinTree<string>(s, iz, de);
    }
}

void Sesion::inicializar_problemas(Conexiones& Conex, int i) const {
    ini_problemas_recursivo(Ses, Conex, i);
}

bool Sesion::inicializar_problemas_nuevos(Conexiones& Conex, int i) const {
    return ini_problemas_nuevos_recursivo(Ses, Conex, i);
}


void Sesion::ini_problemas_recursivo(const BinTree<string>& a, Conexiones& Conex, int i) const {
    if (not a.empty()){
        ini_problemas_recursivo(a.left(), Conex, i);
        ini_problemas_recursivo(a.right(), Conex, i);
        Conex.anadir_entrada(a.value(), i);
    }
}

bool Sesion::ini_problemas_nuevos_recursivo(const BinTree<string>& a, Conexiones& Conex, int i) const {
    if (not a.empty()){
        if (not ini_problemas_nuevos_recursivo(a.left(), Conex, i)) return false;
        if (not ini_problemas_nuevos_recursivo(a.right(), Conex, i)) return false;
        return Conex.anadir_entrada_nueva(a.value(), i);
    }
    return true;
}


void Sesion::escribir() {
    cout << this->tamano << " ";
    escribir_arbol_binario(Ses);
}

void Sesion::escribir_arbol_binario(const BinTree<string>& a) {
    if (not a.empty()) {
        cout << "(";
        escribir_arbol_binario(a.left());
        escribir_arbol_binario(a.right());
        cout << a.value() << ")";
    }
}
