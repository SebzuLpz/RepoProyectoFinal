#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Estructuras de datos
struct Equipo {
    int id;
    string nombre;
    int defensa;
    int ataque;
    int puntos;
    string jugadores;
};

struct Jugador {
    int id;
    string nombre;
    int agresividad;
};

struct Partido {
    Equipo equipo1;
    Equipo equipo2;
    int golesEquipo1;
    int golesEquipo2;
    vector<Tarjeta> tarjetas;
};

struct Tarjeta {
    int tipo; // 0: amarilla, 1: roja
    Jugador jugador;
};

// Funciones de simulación
Partido simularPartido(Equipo equipo1, Equipo equipo2);
void imprimirResultados(Partido partido);
void actualizarTablaPosiciones(vector<Partido> partidos, vector<Equipo> equipos);
void simularCopa(int tipoSimulacion);

// Funciones de lectura de archivos
vector<Equipo> leerEquipos(string archivo);
vector<Grupo> leerGrupos(string archivo);

// Funciones de menú
void menu();
void opcionEquipos();
void opcionGrupos();
void opcionSimular();

int main() {
    srand(time(NULL)); // Inicializar generador de números aleatorios
    menu();
    return 0;
}

// Implementación de funciones de simulación
Partido simularPartido(Equipo equipo1, Equipo equipo2) {
    Partido partido;
    partido.equipo1 = equipo1;
    partido.equipo2 = equipo2;


    // Simulación del partido
    int golesEquipo1 = rand() % (equipo1.ataque + equipo2.defensa) + 1;
    int golesEquipo2 = rand() % (equipo2.ataque + equipo1.defensa) + 1;

    partido.golesEquipo1 = golesEquipo1;
    partido.golesEquipo2 = golesEquipo2;

    // Simulación de tarjetas
    for (int i = 0; i < 5; i++) {
        int jugadorId = rand() % (equipo1.jugadores.size() + equipo2.jugadores.size());
        Jugador jugador = (jugadorId < equipo1.jugadores.size())? equipo1.jugadores[jugadorId] : equipo2.jugadores[jugadorId - equipo1.jugadores.size()];
        int tipoTarjeta = (rand() % 2 == 0)? 0 : 1; // 0: amarilla, 1: roja
        Tarjeta tarjeta = { tipoTarjeta, jugador };
        partido.tarjetas.push_back(tarjeta);
    }

    return partido;
}

void imprimirResultados(Partido partido) {
    cout << "Partido: " << partido.equipo1.nombre << " vs " << partido.equipo2.nombre << endl;
    cout << "Goles: " << partido.golesEquipo1 << " - " << partido.golesEquipo2 << endl;
    cout << "Tarjetas: ";
    for(const auto& tarjeta : partido.tarjetas) {
        cout << tarjeta.jugador.nombre << " (" << (tarjeta.tipo == 0? "amarilla" : "roja") << ")" << endl;
    }
    cout << endl;
}

void actualizarTablaPosiciones(vector<Partido> partidos, vector<Equipo> equipos) {
    // Actualizar tabla de posiciones de cada grupo
    for (const auto& partido : partidos) {
        int puntosEquipo1 = (partido.golesEquipo1 > partido.golesEquipo2)? 3 : (partido.golesEquipo1 == partido.golesEquipo2)? 1 : 0;
        int puntosEquipo2 = (partido.golesEquipo2 > partido.golesEquipo1)? 3 : (partido.golesEquipo2 == partido.golesEquipo1)? 1 : 0;

        for (auto& equipo : equipos) {
            if (equipo.id == partido.equipo1.id) {
                equipo.puntos += puntosEquipo1;
            } else if (equipo.id == partido.equipo2.id) {
                equipo.puntos += puntosEquipo2;
            }
        }
    }

    // Ordenar tabla de posiciones de cada grupo
    for (auto& grupo : grupos) {
        sort(grupo.begin(), grupo.end(), [](const Equipo& e1, const Equipo& e2) {
            return e1.puntos > e2.puntos;
        });
    }
}

void simularCopa(int tipoSimulacion) {
    // Leer archivos de texto con información de equipos y grupos
    vector<Equipo> equipos = leerEquipos("equipos.txt");
    vector<Grupo> grupos = leerGrupos("grupos.txt");

    // Simular partidos
    vector<Partido> partidos;
    for (const auto& grupo : grupos) {
        for (const auto& fecha : grupo.fechas) {
            for (const auto& partido : fecha.partidos) {
                Equipo equipo1 = equipos[partido.equipo1 - 1];
                Equipo equipo2 = equipos[partido.equipo2 - 1];
                Partido simulado = simularPartido(equipo1, equipo2);
                partidos.push_back(simulado);
            }
        }
    }

    // Imprimir resultados de cada partido
    for (const auto& partido : partidos) {
        imprimirResultados(partido);
    }

    // Actualizar tabla de posiciones de cada grupo
    actualizarTablaPosiciones(partidos, equipos);

    // Imprimir tabla de posiciones de cada grupo
    for (const auto& grupo : grupos) {
        cout << "Grupo " << grupo.nombre << endl;
        for (const auto& equipo : grupo.equipos) {
            cout << equipo.nombre << " (" << equipo.puntos << " puntos)" << endl;
        }
        cout << endl;
    }
}

// Implementación de funciones de lectura de archivos
vector<Equipo> leerEquipos(string archivo) {
    vector<Equipo> equipos;
    ifstream file(archivo);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Equipo equipo;
            equipo.id = stoi(line.substr(0, line.find(" ")));
            line = line.substr(line.find(" ") + 1);
            equipo.nombre = line.substr(0, line.find(" "));
            line = line.substr(line.find(" ") + 1);
            equipo.defensa = stoi(line.substr(0, line.find(" ")));
            line = line.substr(line.find(" ") + 1);
            equipo.ataque = stoi(line);
            equipos.push_back(equipo);
        }
        file.close();
    }

    return equipos;
}

vector<Grupo> leerGrupos(string archivo) {
    vector<Grupo> grupos;
    ifstream file(archivo);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Grupo grupo;
            grupo.nombre = line.substr(0, line.find(" "));
            line = line.substr(line.find(" ") + 1);
            grupo.fechas = vector<Fecha>();

            while (line != "*") {
                Fecha fecha;
                fecha.partidos = vector<Partido>();

                while (line != "-") {
                    Partido partido;
                    int posicionSlash = line.find("/");
                    partido.equipo1 = equipos[stoi(line.substr(0, posicionSlash)) - 1];
                    partido.equipo2 = equipos[stoi(line.substr(posicionSlash + 1)) - 1];
                    fecha.partidos.push_back(partido);

                    if (line.find("+") != string::npos) {
                        line = line.substr(line.find("+") + 1);
                    } else {
                        break;
                    }
                }

                grupo.fechas.push_back(fecha);

                if (line.find("*") != string::npos) {
                    line = line.substr(line.find("*") + 1);
                } else {
                    break;
                }
            }

            grupos.push_back(grupo);
        }
        file.close();
    }

    return grupos;
}

// Implementación de funciones de menú
void menu() {
    int opcion;

    do {
        cout << "---- COPA AMERICA 2024 ----" << endl;
        cout << "---- (ESTADOS UNIDOS) ---- " << endl;
        cout << "1. Equipos" << endl;
        cout << "2. Grupos" << endl;
        cout << "3. Simular" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                opcionEquipos();
                break;
            case 2:
                opcionGrupos();
                break;
            case 3:
                opcionSimular();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 4);
}

void opcionEquipos() {
    // Implementar opción de menú para ver equipos
}

void opcionGrupos() {
    // Implementar opción de menú para ver grupos
}

void opcionSimular() {
    int tipoSimulacion;

    cout << "1. Por fechas" << endl;
    cout << "2. Por etapas" << endl;
    cout << "3. Copa entera" << endl;
    cout << "Seleccione el tipo de simulación: ";
    cin >> tipoSimulacion;

    simularCopa(tipoSimulacion);
}