#include "Conexiones.hh"

void Conexiones::anadir_entrada(const string& id_problema, int i) {
    prob_ses.insert(make_pair(id_problema, i));
}

bool Conexiones::anadir_entrada_nueva(const string& id_problema, int i) {
    pair< map<string,int>::iterator, bool> ret = prob_ses.insert(make_pair(id_problema, i));
    return ret.second;
}

int Conexiones::encontrar_problema(const string& id_problema) const {
    map<string, int>::const_iterator it = prob_ses.find(id_problema);
    if (it == prob_ses.end()) return -1;
    else return it->second;
}
