#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Jugador {
    int id;
    string nombre;
    int agresividad;
};

struct Equipo {
    int id;
    string nombre;
    int defensa;
    int ataque;
    vector<Jugador> jugadores;
};

int main() {
    ifstream archivo("Info_Equipos_Jugadores.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    vector<Equipo> equipos;
    Equipo equipoActual;
    string linea;

    while (getline(archivo, linea)) {
        if (linea[0] == '-') {
            // Nuevo equipo
            istringstream iss(linea.substr(1));
            iss >> equipoActual.id;
            getline(iss, equipoActual.nombre, ':');
        } else if (linea[0] == '+') {
            // Nuevo jugador
            Jugador jugador;
            istringstream iss(linea.substr(1));
            iss >> jugador.id;
            getline(iss, jugador.nombre, ':');
            getline(archivo, linea);
            iss.clear();
            iss.str(linea);
            iss >> jugador.agresividad;
            equipoActual.jugadores.push_back(jugador);
        } else {
            // Ignorar línea vacía
            continue;
        }
    }

    archivo.close();


    return 0;
}