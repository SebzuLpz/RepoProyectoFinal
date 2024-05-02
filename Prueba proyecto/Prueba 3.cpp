#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>

using namespace std;

class Jugador {
public:
    int id;
    string nombre;
    int nivelAgresividad;
};

class Equipo {
public:
    int id;
    string nombre;
    int nivelDefensa;
    int nivelAtaque;
    int goles;
    int tarjetasAmarillas;
    int tarjetasRojas;
    vector<Jugador> jugadores;
};

class Partido {
public:
    int idEquipo1;
    string nombreEquipo1;
    int idEquipo2;
    string nombreEquipo2;
    int golesEquipo1;
    int golesEquipo2;
    int tarjetasAmarillasEquipo1;
    int tarjetasAmarillasEquipo2;
    int tarjetasRojasEquipo1;
    int tarjetasRojasEquipo2;
    int golesEquipos[0];
    int tarjetasAmarillasEquipos[0];
    int tarjetasRojasEquipos[0];

};

class Grupo {
public:
    int id;
    string nombre;
    vector<Equipo> equipos;
    vector<Partido> partidos;
};


int equiposs() {
    int opcionequipos = 0;
    string equipos1;
    string equipos;
    while (true) {
        cout << "Seleccione el equipo que desea ver: " << endl;
        equipos1.clear();
        cout << endl;
        ifstream archivo("Equipos.txt");
        while (getline(archivo, equipos)) {
            equipos1 = equipos1 + equipos + "\n";
        }
        cout << endl;
        archivo.close();
        cout << equipos1 << endl;
        cout << "Digite el equipo que desea ver: " << endl;
        cin >> opcionequipos;
        cout << endl;
        if (opcionequipos == 17) {
            return 0;
        }
        if (opcionequipos == 1) {
            string jugador1, jugador;
            ifstream archivo("Argentina.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 2) {
            string jugador1, jugador;
            ifstream archivo("Chile.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 3) {
            string jugador1, jugador;
            ifstream archivo("Peru.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 4) {
            string jugador1, jugador;
            ifstream archivo("Canada.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 5) {
            string jugador1, jugador;
            ifstream archivo("Mexico.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 6) {
            string jugador1, jugador;
            ifstream archivo("Ecuador.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 7) {
            string jugador1, jugador;
            ifstream archivo("Venezuela.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 8) {
            string jugador1, jugador;
            ifstream archivo("Jamaica.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 9) {
            string jugador1, jugador;
            ifstream archivo("EstadosUnidos.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 10) {
            string jugador1, jugador;
            ifstream archivo("Uruguay.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 11) {
            string jugador1, jugador;
            ifstream archivo("Panama.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 12) {
            string jugador1, jugador;
            ifstream archivo("Bolivia.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 13) {
            string jugador1, jugador;
            ifstream archivo("Brasil.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 14) {
            string jugador1, jugador;
            ifstream archivo("Colombia.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 15) {
            string jugador1, jugador;
            ifstream archivo("Paraguay.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 16) {
            string jugador1, jugador;
            ifstream archivo("CostaRica.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 17) {
            cout << "Volviendo al menú principal..." << endl;
            break;
        }
        if (opcionequipos >= 18) {
            cout << "Opción no válida, volviendo al menú..." << endl;
        }
    }
    system("pause");
    return 0;
}

int grupos() {
    int opciongrupos = 0;
    string grupo_1;
    string grupo1;
    while (true) {
        cout << "Seleccione el grupo que desea ver: " << endl;
        grupo_1.clear();
        cout << "1. Grupo A " << endl;
        cout << "2. Grupo B " << endl;
        cout << "3. Grupo C " << endl;
        cout << "4. Grupo D " << endl;
        cout << "5. Volver al menú principal" << endl;
        cin >> opciongrupos;
        cout << endl;
        if (opciongrupos == 1) {
            ifstream archivo("GrupoA.txt");
            while (getline(archivo, grupo1)) {
                grupo_1 = grupo_1 + grupo1 + "\n";
            }
            archivo.close();
            cout << grupo_1 << endl;
        }
        if (opciongrupos == 2) {
            ifstream archivo("GrupoB.txt");
            while (getline(archivo, grupo1)) {
                grupo_1 = grupo_1 + grupo1 + "\n";
            }
            archivo.close();
            cout << grupo_1 << endl;
        }
        if (opciongrupos == 3) {
            ifstream archivo("GrupoC.txt");
            while (getline(archivo, grupo1)) {
                grupo_1 = grupo_1 + grupo1 + "\n";
            }
            archivo.close();
            cout << grupo_1 << endl;
        }
        if (opciongrupos == 4) {
            ifstream archivo("GrupoD.txt");
            while (getline(archivo, grupo1)) {
                grupo_1 = grupo_1 + grupo1 + "\n";
            }
            archivo.close();
            cout << grupo_1 << endl;
        }
        if (opciongrupos == 5) {
            return 0;
        }
        if (opciongrupos >= 6) {
            cout << "Opción no válida, volviendo al menú..." << endl;
        }
    }
}

void cargarPartidos(vector<Grupo>& grupos) {
    ifstream archivo("Partidos.txt");
    string linea;
    while (getline(archivo, linea)) {
        if (linea == "*") {
            Grupo grupo;
            getline(archivo, linea);
            grupo.id = stoi(linea);
            getline(archivo, linea);
            grupo.nombre = linea;
            while (true) {
                getline(archivo, linea);
                if (linea == "-") break; // Fin de la fecha
                Partido partido;
                getline(archivo, linea);
                partido.idEquipo1 = stoi(linea);
                getline(archivo, linea);
                partido.nombreEquipo1 = linea;
                getline(archivo, linea);
                partido.idEquipo2 = stoi(linea);
                getline(archivo, linea);
                partido.nombreEquipo2 = linea;
                grupo.partidos.push_back(partido);
            }
            grupos.push_back(grupo);
        }
    }
    archivo.close();
}
void simularPartidoEspecifico(){

}
void consultarGruposEquipos (){
    int opciongruposequipos;
    cout<<"Seleccione una opcion: "<<endl;
    cout<<"1. Ver equipos"<<endl;
    cout<<"2. Ver grupos"<<endl;
    cin>>opciongruposequipos;
    switch (opciongruposequipos)
    {
    case 1:
        equiposs();
        break;
    case 2:
        grupos();
    break;
    default:
        break;
    }

}


void simularPartidos(Nodo* nodo, stack<Partido>& pilaResultados) {
    if (nodo == nullptr) return;

    // Simular partido
    int golesEquipo1 = rand() % 5;
    int golesEquipo2 = rand() % 5;
    int tarjetasAmarillasEquipo1 = rand() % 3;
    int tarjetasAmarillasEquipo2 = rand() % 3;
    int tarjetasRojasEquipo1 = rand() % 2;
    int tarjetasRojasEquipo2 = rand() % 2;

    // Asignar goles y tarjetas a los equipos
    for (auto& equipo : equiposClasificados) {
        if (equipo.id == nodo->partido.idEquipo1) {
            equipo.goles += golesEquipo1;
            equipo.tarjetasAmarillas += tarjetasAmarillasEquipo1;
            equipo.tarjetasRojas += tarjetasRojasEquipo1;
        }
        if (equipo.id == nodo->partido.idEquipo2) {
            equipo.goles += golesEquipo2;
            equipo.tarjetasAmarillas += tarjetasAmarillasEquipo2;
            equipo.tarjetasRojas += tarjetasRojasEquipo2;
        }
    }

    // Guardar resultado en la pila de resultados
    Partido resultado;
    resultado.idEquipo1 = nodo->partido.idEquipo1;
    resultado.idEquipo2 = nodo->partido.idEquipo2;
    resultado.golesEquipos[0] = nodo->partido.golesEquipo1;
    resultado.golesEquipos[1] = nodo->partido.golesEquipo2;
    resultado.tarjetasAmarillasEquipos[0] = nodo->partido.tarjetasAmarillasEquipo1;
    resultado.tarjetasAmarillasEquipos[1] = nodo->partido.tarjetasAmarillasEquipo2;
    resultado.tarjetasRojasEquipos[0] = nodo->partido.tarjetasRojasEquipo1;
    resultado.tarjetasRojasEquipos[1] = nodo->partido.tarjetasRojasEquipo2;
    pilaResultados.push(resultado);

    // Simular partidos de los hijos
    simularPartidos(nodo->izquierda, pilaResultados);
    simularPartidos(nodo->derecha, pilaResultados);
}


void simularTorneo(vector<Grupo>& grupos) {
    cout << "Simulando partidos..." << endl;
    simularPartidos(grupos);

    // Avanzar de fase (grupos -> cuartos de final)
    vector<Equipo> equiposClasificados;
    for (auto& grupo : grupos) {
        // Ordenar equipos por puntos y goles
        sort(grupo.equipos.begin(), grupo.equipos.end(), [](Equipo a, Equipo b) {
            if (a.goles == b.goles) return a.tarjetasAmarillas < b.tarjetasAmarillas;
            return a.goles > b.goles;
        });

        // Seleccionar los 2 primeros equipos de cada grupo
        equiposClasificados.push_back(grupo.equipos[0]);
        equiposClasificados.push_back(grupo.equipos[1]);
    }

    // Cuartos de final
    Nodo* arbolCuartosDeFinal = nullptr;
    for (int i = 0; i < equiposClasificados.size(); i += 2) {
        Nodo* nodo = new Nodo();
        nodo->partido.idEquipo1 = equiposClasificados[i].id;
        nodo->partido.nombreEquipo1 = equiposClasificados[i].nombre;
        nodo->partido.idEquipo2 = equiposClasificados[i + 1].id;
        nodo->partido.nombreEquipo2 = equiposClasificados[i + 1].nombre;
        nodo->izquierda = nullptr;
        nodo->derecha = nullptr;

        if (arbolCuartosDeFinal == nullptr) {
            arbolCuartosDeFinal = nodo;
        } else {
            Nodo* actual = arbolCuartosDeFinal;
            while (true) {
                if (actual->partido.idEquipo1 == nodo->partido.idEquipo1 || actual->partido.idEquipo1 == nodo->partido.idEquipo2) {
                    // El equipo ya está en el árbol
                    break;
                }
                if (actual->izquierda == nullptr) {
                    actual->izquierda = nodo;
                    break;
                }
                if (actual->derecha == nullptr) {
                    actual->derecha = nodo;
                    break;
                }
                if (actual->izquierda->partido.idEquipo1 < nodo->partido.idEquipo1 && actual->izquierda->partido.idEquipo2 < nodo->partido.idEquipo1) {
                    actual = actual->izquierda;
                } else {
                    actual = actual->derecha;
                }
            }
        }
    }

    // Simular cuartos de final
    stack<Partido> pilaResultados;
    simularPartidos(arbolCuartosDeFinal, pilaResultados);

    // Semifinales
    Nodo* arbolSemifinales = nullptr;
    while (!pilaResultados.empty()) {
        Nodo* nodo = new Nodo();
        Partido partido = pilaResultados.top();
        pilaResultados.pop();

        nodo->partido.idEquipo1 = partido.idEquipo1;
        nodo->partido.nombreEquipo1 = partido.nombreEquipo1;
        nodo->partido.idEquipo2 = partido.idEquipo2;
        nodo->partido.nombreEquipo2 = partido.nombreEquipo2;
        nodo->izquierda = nullptr;
        nodo->derecha = nullptr;

        if (arbolSemifinales == nullptr) {
            arbolSemifinales = nodo;
        } else {
            Nodo* actual = arbolSemifinales;
            while (true) {
                if (actual->partido.idEquipo1 == nodo->partido.idEquipo1 || actual->partido.idEquipo1 == nodo->partido.idEquipo2) {
                    // El equipo ya está en el árbol
                    break;
                }
                if (actual->izquierda == nullptr) {
                    actual->izquierda = nodo;
                    break;
                }
                if (actual->derecha == nullptr) {
                    actual->derecha = nodo;
                    break;
                }
                if (actual->izquierda->partido.idEquipo1 < nodo->partido.idEquipo1 && actual->izquierda->partido.idEquipo2 < nodo->partido.idEquipo1) {
                    actual = actual->izquierda;
                } else {
                    actual = actual->derecha;
                }
            }
        }
    }

    // Simular semifinales
    stack<Partido> pilaResultadosSemifinales;
    simularPartidos(arbolSemifinales, pilaResultadosSemifinales);

    // Final
    Nodo* arbolFinal = nullptr;
    while (!pilaResultadosSemifinales.empty()) {
        Nodo* nodo = new Nodo();
        Partido partido = pilaResultadosSemifinales.top();
        pilaResultadosSemifinales.pop();

        nodo->partido.idEquipo1 = partido.idEquipo1;
        nodo->partido.nombreEquipo1 = partido.nombreEquipo1;
        nodo->partido.idEquipo2 = partido.idEquipo2;
        nodo->partido.nombreEquipo2 = partido.nombreEquipo2;
        nodo->izquierda = nullptr;
        nodo->derecha = nullptr;

        if (arbolFinal == nullptr) {
            arbolFinal = nodo;
        } else {
            Nodo* actual = arbolFinal;
            while (true) {
                if (actual->partido.idEquipo1 == nodo->partido.idEquipo1 || actual->partido.idEquipo1 == nodo->partido.idEquipo2) {
                    // El equipo ya está en el árbol
                    break;
                }
                if (actual->izquierda == nullptr) {
                    actual->izquierda = nodo;
                    break;
                }
                if (actual->derecha == nullptr) {
                    actual->derecha = nodo;
                    break;
                }
                if (actual->izquierda->partido.idEquipo1 < nodo->partido.idEquipo1 && actual->izquierda->partido.idEquipo2 < nodo->partido.idEquipo1) {
                    actual = actual->izquierda;
                } else {
                    actual = actual->derecha;
                }
            }
        }
    }

    // Simular final
    stack<Partido> pilaResultadosFinal;
    simularPartidos(arbolFinal, pilaResultadosFinal);

    // Mostrar resultados de los partidoscout << "------------------------------" << endl;
    cout << "Resumen del torneo:" << endl;
    cout << "------------------------------" << endl;
    while (!pilaResultadosFinal.empty()) {
        Partido resultado = pilaResultadosFinal.top();
        pilaResultadosFinal.pop();

        cout << "Equipo " << resultado.idEquipo1 << ": " << resultado.golesEquipos[0] << " goles, " << resultado.tarjetasAmarillasEquipos[0] << " tarjetas amarillas, " << resultado.tarjetasRojasEquipos[0] << " tarjetas rojas." << endl;
        cout << "Equipo " << resultado.idEquipo2 << ": " << resultado.golesEquipos[1] << " goles, " << resultado.tarjetasAmarillasEquipos[1] << " tarjetas amarillas, " << resultado.tarjetasRojasEquipos[1] << " tarjetas rojas." << endl;
        cout << "------------------------------" << endl;
    }
}


int main() {
    vector<Grupo> grupos;
    bool flagMenu = true;

    while (flagMenu) {
        int opcion;
        cout << "Menú de opciones:" << endl;
        cout << "1. Simular torneo." << endl;
        cout << "2. Simular partidos." << endl;
        cout << "3. Simular partido específico." << endl;
        cout << "4. Consultar grupos y equipos." << endl;
        cout << "5. Salir." << endl;
        cout << "Ingrese la opción deseada: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            simularTorneo(grupos);
            break;
        case 2:
            simularPartidos(grupos);
            break;
        case 3:
            simularPartidoEspecifico();
            break;
        case 4:
            consultarGruposEquipos();
            break;
        case 5:
            flagMenu = false;
            break;
        default:
            cout << "Opción no válida, volviendo al menú..." << endl;
            break;
        }
    }
}