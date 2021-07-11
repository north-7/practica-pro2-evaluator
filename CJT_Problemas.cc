#include "CJT_Problemas.hh"
#include <map>
using namespace std;

CJT_Problemas::CJT_Problemas() {
    map<string, Problema> CProblemas;
}

void CJT_Problemas::actualizar_estadisticas_fallo(const string& id_problema) {
    map<string, Problema>::iterator it = CProblemas.find(id_problema);
    it->second.actualizar_estadisticas_fallo();
}

void CJT_Problemas::actualizar_estadisticas_acierto(const string& id_problema) {
    map<string, Problema>::iterator it = CProblemas.find(id_problema);
    it->second.actualizar_estadisticas_acierto();
}

bool CJT_Problemas::existe_problema(const string& id_problema) const {
    map<string, Problema>::const_iterator it;
    it = CProblemas.find(id_problema);
    return it != CProblemas.end();
}

void CJT_Problemas::leer_conjunto_problemas() {
    int input;
    cin >> input;
    for (int i = 0; i < input; ++i) {
        string id_problema;
        cin >> id_problema;
        Problema p;
        CProblemas.insert(make_pair(id_problema, p));
    }
}

void CJT_Problemas::anadir_problema(const string& id_problema) {
    if (existe_problema(id_problema)) cout << "error: el problema ya existe" << endl;
    else {
        Problema p;
        CProblemas.insert(make_pair(id_problema, p));
        cout << CProblemas.size() << endl;
    }
}

void CJT_Problemas::listar_problemas() {
    map< pair<double, string>, Problema> lprob;
    for (map<string, Problema>::iterator it = CProblemas.begin(); it != CProblemas.end(); ++it) lprob.insert( make_pair(make_pair(it->second.obt_ratio(), it->first), it->second));
    for (map< pair<double, string>, Problema>::iterator it = lprob.begin(); it != lprob.end(); ++it) {
        cout << it->first.second;
        it->second.escribir();
    }
}

void CJT_Problemas::escribir_problema(const string& id_problema) {
    if (existe_problema((id_problema))) {
        cout << id_problema;
        map<string, Problema>::iterator it;
        it = CProblemas.find(id_problema);
        it->second.escribir();
    }
    else cout << "error: el problema no existe" << endl;
}


