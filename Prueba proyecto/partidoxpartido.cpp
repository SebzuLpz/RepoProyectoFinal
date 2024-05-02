#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Equipo {
    int id;
    string nombre;
    int defensa;
    int ataque;
};

struct Partido {
    Equipo equipo1;
    Equipo equipo2;
    int goles1;
    int goles2;
};

struct Grupo {
    int id;
    string nombre;
    vector<Equipo> equipos;
    vector<Partido> partidos;
};

struct Arbol {
    Equipo equipo;
    Arbol* izquierda;
    Arbol* derecha;
};

void leerArchivo(string archivo, vector<Grupo>& grupos);
void simularPartido(Partido& partido);
void simularGrupo(Grupo& grupo);
void determinarClasificados(Grupo& grupo, vector<Equipo>& clasificados);
void crearArbol(vector<Equipo>& equipos, Arbol*& arbol);
void jugarPartido(Arbol* arbol);
void eliminacionDirecta(vector<Equipo>& equipos);
void mostrarPartido(Partido& partido);
void mostrarGrupo(Grupo& grupo);
void mostrarClasificados(vector<Equipo>& clasificados);
void mostrarArbol(Arbol* arbol);

// Funciones para leer el archivo de texto
void leerArchivo(string archivo, vector<Grupo>& grupos) {
    ifstream file(archivo);
    string linea;
    Grupo grupo;
    while (getline(file, linea)) {
        if (linea == "*") {
            if (!grupo.equipos.empty()) {
                grupos.push_back(grupo);
                grupo.equipos.clear();
                grupo.partidos.clear();
            }
        } else if (linea.find("Grupo")!= string::npos) {
            grupo.id = stoi(linea.substr(0, linea.find(" ")));
            grupo.nombre = linea.substr(linea.find(" ") + 1);
        } else if (linea.find("-")!= string::npos) {
            // Fecha
        } else if (linea.find("+")!= string::npos) {
            Partido partido;
            getline(file, linea);
            if (linea.empty() || linea.find_first_not_of("0123456789") != string::npos) {
                cerr << "Error: no se pudo convertir la cadena a un entero." << endl;
                continue;
            }
            partido.equipo1.id = stoi(linea.substr(0, linea.find(" ")));
            partido.equipo1.nombre = linea.substr(linea.find(" ") + 1);
            getline(file, linea);
            if (linea.empty() || linea.find_first_not_of("0123456789") != string::npos) {
                cerr << "Error: no se pudo convertir la cadena a un entero." << endl;
                continue;
            }
            partido.equipo1.defensa = stoi(linea.substr(0, linea.find(" ")));
            partido.equipo1.ataque = stoi(linea.substr(linea.find(" ") + 1));
            getline(file, linea);
            if (linea.empty() || linea.find_first_not_of("0123456789") != string::npos) {
                cerr << "Error: no se pudo convertir la cadena a un entero." << endl;
                continue;
            }
            partido.equipo2.id = stoi(linea.substr(0, linea.find(" ")));
            partido.equipo2.nombre = linea.substr(linea.find(" ") + 1);
            getline(file, linea);
            if (linea.empty() || linea.find_first_not_of("0123456789") != string::npos) {
                cerr << "Error: no se pudo convertir la cadena a un entero." << endl;
                continue;
            }
            partido.equipo2.defensa = stoi(linea.substr(0, linea.find(" ")));
            partido.equipo2.ataque = stoi(linea.substr(linea.find(" ") + 1));
            grupo.partidos.push_back(partido);
        }
    }
    if (!grupo.equipos.empty()) {
        grupos.push_back(grupo);
    }
}

// Funciones para simular partidos
void simularPartido(Partido& partido) {
    int goles1 = rand() % (partido.equipo1.ataque + 1) + partido.equipo2.defensa;
    int goles2 = rand() % (partido.equipo2.ataque + 1) + partido.equipo1.defensa;
    partido.goles1 = goles1;
    partido.goles2 = goles2;
}

void simularGrupo(Grupo& grupo) {
    for (Partido& partido : grupo.partidos) {
        simularPartido(partido);
    }
}

// Funciones para determinar clasificados
void determinarClasificados(Grupo& grupo, vector<Equipo>& clasificados) {
    map<int, int> puntos;
    map<int, int> diferenciaGoles;
    for (Partido& partido : grupo.partidos) {
        int puntos1 = partido.goles1 > partido.goles2? 3 : partido.goles1 == partido.goles2? 1 : 0;
        int puntos2 = partido.goles2 > partido.goles1? 3 : partido.goles2 == partido.goles1? 1 : 0;
        puntos[partido.equipo1.id] += puntos1;
        puntos[partido.equipo2.id] += puntos2;
        diferenciaGoles[partido.equipo1.id] += partido.goles1 - partido.goles2;
        diferenciaGoles[partido.equipo2.id] += partido.goles2 - partido.goles1;
    }
    vector<pair<int, int>> ranking;
    for (auto& punto : puntos) {
        ranking.push_back({punto.second, diferenciaGoles[punto.first]});
    }
    sort(ranking.begin(), ranking.end(), greater<pair<int, int>>());
    for (size_t i = 0; i < 2 && i < ranking.size(); i++) {
        for (Equipo& equipo : grupo.equipos) {
            if (equipo.id == ranking[i].first) {
                clasificados.push_back(equipo);
                break;
            }
        }
    }
}
void crearArbol(vector<Equipo>& equipos, Arbol*& arbol) {
    if (equipos.empty()) {
        arbol = nullptr;
        return;
    }
    arbol = new Arbol();
    arbol->equipo = equipos[0];
    vector<Equipo> izquierda(equipos.begin() + 1, equipos.end());
    crearArbol(izquierda, arbol->izquierda);
    vector<Equipo> derecha; // crea un objeto vector vacío
    crearArbol(derecha, arbol->derecha);
}
// Funciones para eliminación directa
Arbol* crearArbol(vector<Equipo>& equipos) {
    if (equipos.size() == 1) {
        Arbol* arbol = new Arbol();
        arbol->equipo = equipos[0];
        arbol->izquierda = nullptr;
        arbol->derecha = nullptr;
        return arbol;
    }
    int mitad = equipos.size() / 2;
    vector<Equipo> izquierda(equipos.begin(), equipos.begin() + mitad);
    vector<Equipo> derecha(equipos.begin() + mitad, equipos.end());
    Arbol* arbol = new Arbol();
    arbol->equipo = izquierda[izquierda.size() - 1];
    arbol->izquierda = crearArbol(izquierda);
    arbol->derecha = crearArbol(derecha);
    return arbol;
}

void jugarPartido(Arbol* arbol) {
    if (arbol == nullptr) {
        return;
    }
    Partido partido;
    partido.equipo1 = arbol->equipo;
    partido.equipo2 = arbol->equipo;
    partido.goles1 = rand() % (arbol->equipo.ataque + 1) + arbol->equipo.defensa;
    partido.goles2 = rand() % (arbol->equipo.ataque + 1) + arbol->equipo.defensa;
    simularPartido(partido);
    if (arbol->izquierda != nullptr) {
        jugarPartido(arbol->izquierda);
    }
    if (arbol->derecha != nullptr) {
        jugarPartido(arbol->derecha);
    }
}

void eliminacionDirecta(vector<Equipo>& equipos) {
    Arbol* arbol = nullptr;
    crearArbol(equipos, arbol);
    jugarPartido(arbol);
    // Mostrar resultados
    cout << "Eliminación directa:" << endl;
    mostrarArbol(arbol);
    delete arbol;
}

// Funciones para mostrar resultados
void mostrarPartido(Partido& partido) {
    cout << partido.equipo1.nombre << " (" << partido.goles1 << "-" << partido.goles2 << ") vs " << partido.equipo2.nombre << " (" << partido.goles2 << "-" << partido.goles1 << ")" << endl;
}

void mostrarGrupo(Grupo& grupo) {
    cout << "Grupo " << grupo.nombre << ":" << endl;
    for (Equipo& equipo : grupo.equipos) {
        cout << equipo.id << ". " << equipo.nombre << " (" << equipo.defensa << "/" << equipo.ataque << ")" << endl;
    }
    for (Partido& partido : grupo.partidos) {
        mostrarPartido(partido);
    }
}

void mostrarClasificados(vector<Equipo>& clasificados) {
    cout << "Clasificados:" << endl;
    for (Equipo& equipo : clasificados) {
        cout << equipo.id << ". " << equipo.nombre << " (" << equipo.defensa << "/" << equipo.ataque << ")" << endl;
    }
}

void mostrarArbol(Arbol* arbol) {
    if (arbol == nullptr) {
        return;
    }
    mostrarArbol(arbol->izquierda);
    cout << arbol->equipo.nombre << endl;
    mostrarArbol(arbol->derecha);
}
int main() {
    vector<Grupo> grupos;
    leerArchivo("Partidos.txt", grupos);
    for (Grupo& grupo : grupos) {
        simularGrupo(grupo);
        for (Equipo& equipo : grupo.equipos) {
            cout << equipo.id << ". " << equipo.nombre << " (" << equipo.defensa << "/" << equipo.ataque << ")" << endl;
        }
        cout << endl;
        for (Partido& partido : grupo.partidos) {
            mostrarPartido(partido);
        }
        cout << endl;
    }
    vector<Equipo> clasificados;
    for (Grupo& grupo : grupos) {
        determinarClasificados(grupo, clasificados);
    }
    mostrarClasificados(clasificados);
    eliminacionDirecta(clasificados);
    return 0;
}