#include "CJT_Cursos.hh"

CJT_Cursos::CJT_Cursos() {

}


string CJT_Cursos::sesion_problema(const int& id_curso, const string& id_problema) const {
    return VCursos[id_curso-1].buscar_problema(id_problema);
}

void CJT_Cursos::inscribir_usuario(const int& id_curso, const string& id_usuario) {
    VCursos[id_curso-1].inscribir_usuario(id_usuario);
}

void CJT_Cursos::eliminar_usuario(const int& id_curso, const string& id_usuario) {
    VCursos[id_curso-1].borrar_usuario(id_usuario);
}

void CJT_Cursos::usuario_completado(const int& id_curso, const string& id_usuario) {
    VCursos[id_curso-1].curso_completado(id_usuario);
}

bool CJT_Cursos::existe_curso(const unsigned int& id_curso) const {
    return (id_curso >= 1 and id_curso <= VCursos.size());
}

int CJT_Cursos::tamano_curso(const int& id_curso) const {
    return VCursos[id_curso-1].tamano();
}

string CJT_Cursos::obtener_sesion_i(const int& id_curso, const int& i) const {
    return VCursos[id_curso-1].sesion_i(i);
}

void CJT_Cursos::anadir_curso(const Curso& c) {
    VCursos.push_back(c);
    cout << VCursos.size() << endl;
}

void CJT_Cursos::leer_conjunto_cursos(const CJT_Sesiones& Sesiones) {
    int input;
    cin >> input;
    vector<Curso> x(input);
    VCursos = x;
    for (int i = 0; i < input; ++i) {
        VCursos[i].leer_curso();
        VCursos[i].inicializar_problemas(Sesiones);
    }
}

void CJT_Cursos::listar_cursos() {
    int size = VCursos.size();
    for (int i = 0; i < size; ++i) {
        cout << i+1 << " ";
        VCursos[i].escribir();
    }
}

void CJT_Cursos::escribir_curso(const int& id_curso) {
    if (existe_curso((id_curso))) {
        cout << id_curso << " ";
        VCursos[id_curso-1].escribir();
    }
    else cout << "error: el curso no existe" << endl;
}
