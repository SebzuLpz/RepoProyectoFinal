#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>

using namespace std;

struct Equipo {
    int id;
    string nombre;
    int defensa;
    int ataque;
    int puntos;
    int golesFavor;
    int golesContra;
};

int main() {
    srand(time(NULL));
    ifstream archivo("Partidos.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    list<vector<Equipo>> grupos;
    vector<Equipo> grupo;
    string linea;

    while (getline(archivo, linea)) {
        if (linea == "*") {
            if (!grupo.empty()) {
                grupos.push_back(grupo);
                grupo.clear();
            }
        } else if (linea.find("Grupo")!= string::npos) {
            // Ignorar
        } else if (linea.find("-")!= string::npos) {
            // Ignorar
        } else if (linea.find("+")!= string::npos) {
            // Leer partido
            Equipo equipo1, equipo2;
            getline(archivo, linea);
            stringstream ss(linea);
            ss >> equipo1.id;
            getline(ss, equipo1.nombre, ' ');
            ss >> equipo1.defensa >> equipo1.ataque;

            getline(archivo, linea);
            ss.str(linea);
            ss.clear();
            ss >> equipo2.id;
            getline(ss, equipo2.nombre, ' ');
            ss >> equipo2.defensa >> equipo2.ataque;

            grupo.push_back(equipo1);
            grupo.push_back(equipo2);
        }
    }

    if (!grupo.empty()) {
        grupos.push_back(grupo);
    }

    archivo.close();

    // Mostrar menú para elegir grupo
    cout << "Elija un grupo para simular:" << endl;
    for (int i = 0; i < grupos.size(); i++) {
        cout << ++i << ". Grupo " << i + 1 << endl;
    }
    int grupoElegido;
    cin >> grupoElegido;

    vector<Equipo> grupoElegidoList = grupos[grupoElegido - 1];

    // Simular partidos del grupo elegido
    for (int i = 0; i < grupoElegidoList.size(); i += 2) {
        Equipo equipo1 = grupoElegidoList[i];
        Equipo equipo2 = grupoElegidoList[i + 1];

        // Simular partido
        int golesEquipo1 = rand() % (equipo1.ataque + equipo2.defensa) + 1;
        int golesEquipo2 = rand() % (equipo2.ataque + equipo1.defensa) + 1;

        cout << "Partido: " << equipo1.nombre << " vs " << equipo2.nombre << endl;
        cout << "Resultado: " << golesEquipo1 << " - " << golesEquipo2 << endl;

        if (golesEquipo1 > golesEquipo2) {
            equipo1.puntos += 3;
            equipo1.golesFavor += golesEquipo1;
            equipo1.golesContra += golesEquipo2;
            equipo2.golesFavor += golesEquipo2;
            equipo2.golesContra += golesEquipo1;
        } else if (golesEquipo1 < golesEquipo2) {
            equipo2.puntos += 3;
            equipo2.golesFavor += golesEquipo2;
            equipo2.golesContra += golesEquipo1;
            equipo1.golesFavor += golesEquipo1;
            equipo1.golesContra += golesEquipo2;
        } else {
            equipo1.puntos += 1;
            equipo2.puntos += 1;
            equipo1.golesFavor += golesEquipo1;
            equipo1.golesContra += golesEquipo2;
            equipo2.golesFavor += golesEquipo2;
            equipo2.golesContra += golesEquipo1;
        }
    }

    // Mostrar tabla del grupo
    cout << "Tabla del grupo:" << endl;
    for (Equipo equipo : grupoElegidoList) {
        cout << equipo.id << ". " << equipo.nombre << " - Puntos: " << equipo.puntos << ", GF: " << equipo.golesFavor << ", GC: " << equipo.golesContra << endl;
    }

    return 0;
}