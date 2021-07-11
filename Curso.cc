#include "Curso.hh"

Curso::Curso() {
}

int Curso::tamano() const {
    return Cur.size();
}
void Curso::inscribir_usuario(const string& id_usuario) {
    UIns.insert(id_usuario);
    cout << UIns.size() << endl;
}

void Curso::borrar_usuario(const string& id_usuario) {
    UIns.erase(id_usuario);
}

void Curso::curso_completado(const string& id_usuario) {
    UIns.erase(id_usuario);
    UCom.insert(id_usuario);
}

string Curso::buscar_problema(const string& id_problema) const {
    int aux = Conex.encontrar_problema(id_problema);
    if (aux == -1) return "0";
    else return Cur[aux];
}

string Curso::sesion_i(const int& i) const {
    return Cur[i];
}

void Curso::inicializar_problemas(const CJT_Sesiones& Sesiones) {
    int size = Cur.size();
    for (int i = 0; i < size; ++i) {
        Sesiones.inicializar_problemas(Conex, Cur[i], i);
    }
}

void Curso::leer_curso() {
    int input;
    cin >> input;
    vector<string> x(input);
    this->Cur = x;
    for (int i = 0; i < input; ++i) {
        string id_sesion;
        cin >> id_sesion;
        Cur[i] = id_sesion;
    }
}

bool Curso::leer_curso_nuevo(const CJT_Sesiones& Sesiones) {
    int input;
    cin >> input;
    vector<string> x(input);
    this->Cur = x;

    bool valido = true;
    int i = 0;

   while (valido and i < input) {
        string id_sesion;
        cin >> id_sesion;
        Cur[i] = id_sesion;
        if (not Sesiones.inicializar_problemas_nuevos(Conex, Cur[i], i)) valido = false;
        ++i;
    }
    while (i < input) {
        string descarte;
        cin >> descarte;
        i++;
    }

    return valido;
}

void Curso::escribir() {
    int size = Cur.size();
    cout << UCom.size() << " " << UIns.size() << " " << size << " (";
    for (int i = 0; i < size; ++i) {
        if (i != 0) cout << " ";
        cout << Cur[i];
    }
    cout << ")" <<  endl;
}
