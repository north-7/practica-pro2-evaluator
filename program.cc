/** @file main.cc
    @brief Especificación del main del programa
*/

#include "CJT_Problemas.hh"
#include "CJT_Sesiones.hh"
#include "CJT_Cursos.hh"
#include "CJT_Usuarios.hh"

using namespace std;

int main() {
    CJT_Problemas Problemas;
    CJT_Sesiones Sesiones;
    CJT_Cursos Cursos;
    CJT_Usuarios Usuarios;

    Problemas.leer_conjunto_problemas();
    Sesiones.leer_conjunto_sesiones();
    Cursos.leer_conjunto_cursos(Sesiones);
    Usuarios.leer_conjunto_usuarios();

    string op, input;
    cin >> op;
    while (op != "fin") {
        cout << "#" << op;

        if (op == "nuevo_problema" or op == "np" ){
            string id_problema;
            cin >> id_problema;
            cout << " " << id_problema << endl;

            Problemas.anadir_problema(id_problema);
        }

        else if (op == "nueva_sesion" or op == "ns") {
            string id_sesion;
            cin >> id_sesion;
            cout << " " << id_sesion << endl;

            Sesiones.anadir_sesion(id_sesion);
        }

        else if (op == "nuevo_curso" or op == "nc") {
            cout << endl;
            Curso c;
            if (c.leer_curso_nuevo(Sesiones)) Cursos.anadir_curso(c);
            else cout << "error: curso mal formado" << endl;
        }

        else if (op == "alta_usuario" or op == "a") {
            string id_usuario;
            cin >> id_usuario;
            cout << " " << id_usuario << endl;

            if (not Usuarios.existe_usuario(id_usuario)) Usuarios.anadir_usuario(id_usuario);
            else cout << "error: el usuario ya existe" << endl;
        }

        else if (op == "baja_usuario" or op == "b") {
            string id_usuario;
            cin >> id_usuario;
            cout << " " << id_usuario << endl;

            if (Usuarios.existe_usuario(id_usuario)) {
                int curso_actual = Usuarios.curso_usuario(id_usuario);
                if (curso_actual != -1) Cursos.eliminar_usuario(curso_actual, id_usuario);
                Usuarios.eliminar_usuario(id_usuario);
                }
            else cout << "error: el usuario no existe" << endl;
        }

        else if (op == "inscribir_curso" or op == "i") {
            int id_curso;
            string id_usuario;
            cin >> id_usuario >> id_curso;
            cout << " " << id_usuario << " " << id_curso << endl;

            if (not Usuarios.existe_usuario(id_usuario)) cout << "error: el usuario no existe" << endl;
            else if (not Cursos.existe_curso(id_curso)) cout << "error: el curso no existe" << endl;
            else if (Usuarios.curso_usuario(id_usuario) != -1) cout << "error: usuario inscrito en otro curso" << endl;
            else {
                Usuarios.inscribir_curso(id_usuario, id_curso, Cursos, Sesiones);
                Cursos.inscribir_usuario(id_curso, id_usuario);
            }
        }

        else if (op == "curso_usuario" or op == "cu") {
            string id_usuario;
            cin >> id_usuario;
            cout << " " << id_usuario << endl;

            if (not Usuarios.existe_usuario(id_usuario)) cout << "error: el usuario no existe" << endl;
            else {
                int x = Usuarios.curso_usuario(id_usuario);
                if (x == -1) cout << "0" << endl;
                else cout << x << endl;
            }
        }

        else if (op == "sesion_problema" or op == "sp"){
            int id_curso;
            string id_problema;
            cin >> id_curso >> id_problema;
            cout << " " << id_curso << " " << id_problema << endl;

            if (not Cursos.existe_curso(id_curso)) cout << "error: el curso no existe" << endl;
            else if (not Problemas.existe_problema(id_problema)) cout << "error: el problema no existe" << endl;
            else {
                op = Cursos.sesion_problema(id_curso, id_problema);
                if (op != "0") cout << op << endl;
                else cout << "error: el problema no pertenece al curso" << endl;
            }
        }

        else if (op == "problemas_resueltos" or op == "pr") {
            string id_usuario;
            cin >> id_usuario;
            cout << " " << id_usuario << endl;

            if (not Usuarios.existe_usuario(id_usuario)) cout << "error: el usuario no existe" << endl;
            else Usuarios.problemas_resueltos(id_usuario);
        }

        else if (op == "problemas_enviables" or op == "pe") {
            string id_usuario;
            cin >> id_usuario;
            cout << " " << id_usuario << endl;

            if (not Usuarios.existe_usuario(id_usuario)) cout << "error: el usuario no existe" << endl;
            else Usuarios.problemas_enviables(id_usuario);
        }

        else if (op == "envio" or op == "e") {
            string id_usuario, id_problema;
            int resultado;
            cin >> id_usuario >> id_problema >> resultado;
            cout << " " << id_usuario << " " << id_problema << " " << resultado << endl;

            if (resultado == 0) {
                Problemas.actualizar_estadisticas_fallo(id_problema);
                Usuarios.actualizar_estadisticas_fallo(id_usuario, id_problema);
            }
            else {
                Problemas.actualizar_estadisticas_acierto(id_problema);
                Usuarios.actualizar_estadisticas_acierto(id_usuario, id_problema, Cursos, Sesiones);
            }
        }

        else if (op == "listar_problemas" or op == "lp") {
            cout << endl;
            Problemas.listar_problemas();
        }

        else if (op == "escribir_problema" or op == "ep"){
            string id_problema;
            cin >> id_problema;
            cout << " " << id_problema << endl;

            Problemas.escribir_problema(id_problema);
        }

        else if (op == "listar_sesiones" or op == "ls") {
            cout << endl;

            Sesiones.listar_sesiones();
        }

        else if (op == "escribir_sesion" or op == "es") {
            string id_sesion;
            cin >> id_sesion;
            cout << " " << id_sesion << endl;

            Sesiones.escribir_sesion(id_sesion);
        }

        else if (op == "listar_cursos" or op == "lc") {
            cout << endl;

            Cursos.listar_cursos();
        }

        else if (op == "escribir_curso" or op == "ec"){
            int id_curso;
            cin >> id_curso;
            cout << " " << id_curso << endl;

            Cursos.escribir_curso(id_curso);
        }

        else if (op == "listar_usuarios" or op == "lu") {
            cout << endl;

            Usuarios.listar_usuarios();
        }

        else if (op == "escribir_usuario" or op == "eu") {
            string id_usuario;
            cin >> id_usuario;
            cout << " " << id_usuario << endl;

            Usuarios.escribir_usuario(id_usuario);
        }
        cin >> op;
    }
}
