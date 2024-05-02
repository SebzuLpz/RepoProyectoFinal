
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <random>
#include <iomanip>

using namespace std; 

class Jugador {
public:
    int id;
    string nombre;
    int agresividad;

    Jugador(int id, string nombre, int agresividad)
        : id(id), nombre(nombre), agresividad(agresividad) {}
};

class Equipo {
public:
    int id;
    string nombre;
    int defensa;
    int ataque;
    int grupo;
    string grupoNombre;
    vector<Jugador> jugadores;
    unsigned int partidosJugados;
    int puntos;

    Equipo(int id, string nombre, int defensa, int ataque, int grupo, string grupoNombre)
        : id(id), nombre(nombre), defensa(defensa), ataque(ataque), grupo(grupo), grupoNombre(grupoNombre), puntos(0) {}
};

vector<Equipo> equipos;

void cargarEquipos() {
    ifstream archivo("InfoEquiJug.txt");
    if (!archivo) {
        cerr << "No se ha podido abrir el archivo..." << endl;
        exit(1);
    }

    string linea;
    while (getline(archivo, linea, '+')) {
        int id;
        string nombre;
        int defensa;
        int ataque;
        int grupo;
        string grupoNombre;

        istringstream iss(linea);
        iss >> id >> nombre >> defensa >> ataque >> grupo >> grupoNombre;

        Equipo equipo(id, nombre, defensa, ataque, grupo, grupoNombre);

        while (getline(archivo, linea) && linea!= "-") {
            int idJugador;
            string nombreJugador;
            int agresividad;

            istringstream issJugador(linea);
            issJugador >> idJugador >> nombreJugador >> agresividad;

            Jugador jugador(idJugador, nombreJugador, agresividad);
            equipo.jugadores.push_back(jugador);
        }

        equipos.push_back(equipo);
    }
}

random_device rd;
mt19937 gen(rd());

int generarNumero(int min, int max) {
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

bool partidoJugado(int equipo1, int equipo2) {
    if (equipo1 < equipo2) {
        for (int i = 0; i < equipos.size(); i++) {
            if (equipos[i].id == equipo1 && equipos[i].partidosJugados & (1 << equipo2)) {
                return true;
            }
        }
    } else {
        for (int i = 0; i < equipos.size(); i++) {
            if (equipos[i].id == equipo2 && equipos[i].partidosJugados & (1 << equipo1)) {
                return true;
            }
        }
    }
    return false;
}

void simularPartido(Equipo& equipo1, Equipo& equipo2) {
    int golesEquipo1 = 0;
    int golesEquipo2 = 0;
    //Simulacion de goles
    int ultimoGol = -1;
    for (int i = 0; i < 10; i++) { 
        // Aumentar el número de iteraciones a 16
        int probabilidadGol= generarNumero(1, 10);
        if (probabilidadGol <= equipo1.ataque && probabilidadGol > equipo2.defensa) {
            golesEquipo1++;
            ultimoGol = 1;
        }
        if (probabilidadGol <= equipo2.ataque && probabilidadGol > equipo1.defensa) {
            golesEquipo2++;
            ultimoGol = 2;
        }
    }
    // Simulación de tarjetas
    vector<int> tarjetasAmarillasEquipo1;
    vector<int> tarjetasRojasEquipo1;
    vector<int> tarjetasAmarillasEquipo2;
    vector<int> tarjetasRojasEquipo2;

    for (const auto& jugador : equipo1.jugadores) {
        int probabilidadTarjeta = generarNumero(1, 10);
        if (probabilidadTarjeta >= jugador.agresividad) {
            if (probabilidadTarjeta >= 7) {
                tarjetasRojasEquipo1.push_back(jugador.id);
            } else {
                tarjetasAmarillasEquipo1.push_back(jugador.id);
            }
        }
    }

    for (const auto& jugador : equipo2.jugadores) {
        int probabilidadTarjeta = generarNumero(1, 10);
        if (probabilidadTarjeta >= jugador.agresividad) {
            if (probabilidadTarjeta >= 7) {
                tarjetasRojasEquipo2.push_back(jugador.id);
            } else {
                tarjetasAmarillasEquipo2.push_back(jugador.id);
            }
        }
    }

    // Imprimir resultado
    cout << "-------------------------------------------------------------------" << endl;
    cout << equipo1.grupoNombre << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << equipo1.nombre << "[" << golesEquipo1 << "]-[" << golesEquipo2 << "]" << equipo2.nombre << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Tarjetas en el partido:" << endl;
    cout << "--------------------------" << endl;
    cout << "Tarjetas amarillas:" << endl;
    cout << "     " << equipo1.nombre << endl;
    for (int id : tarjetasAmarillasEquipo1) {
        for (const auto& jugador : equipo1.jugadores) {
            if (jugador.id == id) {
                cout << "          " << jugador.nombre << " (" << equipo1.nombre << ")" << endl;
                break;
            }
        }
    }
    cout << "     " << equipo2.nombre << endl;
    for (int id : tarjetasAmarillasEquipo2) {
        for (const auto& jugador : equipo2.jugadores) {
            if (jugador.id == id) {
                cout << "          " << jugador.nombre << " (" << equipo2.nombre << ")" << endl;
                break;
            }
        }
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "Tarjetas rojas:" << endl;
    cout << "     " << equipo1.nombre << endl;
    for (int id : tarjetasRojasEquipo1) {
        for (const auto& jugador : equipo1.jugadores) {
            if (jugador.id == id) {
                cout << "          " << jugador.nombre << " (" << equipo1.nombre << ")" << endl;
                break;
            }
        }
    }
    cout << "     " << equipo2.nombre << endl;
    for (int id : tarjetasRojasEquipo2) {
        for (const auto& jugador : equipo2.jugadores) {
            if (jugador.id == id) {
                cout << "          " << jugador.nombre << " (" << equipo2.nombre << ")" << endl;
                break;
            }
        }
    }
    cout << "------------------------------------------------------------------" << endl;
    system("pause");
    system ("cls");
    // Actualizar el número de partidos jugados
    if (ultimoGol == 1){
        equipo1.partidosJugados++;
    } else if (ultimoGol == 2) {
        equipo2.partidosJugados++;
    } else {
        equipo1.partidosJugados++;
        equipo2.partidosJugados++;
    }
    // Actualizar puntos del equipo 1
    if (golesEquipo1 > golesEquipo2) {
        equipo1.puntos += 3;
    } else if (golesEquipo1 == golesEquipo2) {
        equipo1.puntos++;
        equipo2.puntos++;
    }

    // Actualizar puntos del equipo 2
    if (golesEquipo2 > golesEquipo1) {
        equipo2.puntos += 3;
    } else if (golesEquipo2 == golesEquipo1) {
        equipo1.puntos++;
        equipo2.puntos++;
    }

}

void mostrarTablaPosiciones(vector<Equipo>& equipos,  const string& grupoNombre) {
    sort(equipos.begin(), equipos.end(), [](const Equipo& e1, const Equipo& e2 ) {
        return e1.puntos > e2.puntos;
    });
    
    cout << "+--------------------------------------+" << endl;
    cout << "|               " << setw(20) << left << grupoNombre << "   |" << endl;
    //cout << "|                 GRUPO                |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "|      EQUIPOS       |       PUNTOS    |" << endl;
    cout << "+--------------------------------------+" << endl;

    int grupo = equipos[0].grupo;
    int contador = 1;

    for (const auto& equipo : equipos) {
        if (equipo.grupo != grupo) {
            grupo = equipo.grupo;
            contador = 1;
        }

        cout << "|  " << setw(15) << left << equipo.nombre << "   |    " << setw(6) << right << equipo.puntos << "       |" << endl;
        contador++;
    }

    cout << "+--------------------------------------+" << endl;
}

void simularFaseGrupos() {
    for (int grupo = 1; grupo <= 4; grupo++) { 
        // Asumo que hay 4 grupos
        vector<Equipo*> equiposGrupo;
        for (auto& equipo : equipos) {
            if (equipo.grupo == grupo) {
                equiposGrupo.push_back(&equipo);
            }
        }

        // Generar combinaciones de partidos
        vector<pair<int, int>> partidos;
        for (int i = 0; i < equiposGrupo.size(); i++) {
            for (int j = i + 1; j < equiposGrupo.size(); j++) {
                partidos.push_back({equiposGrupo[i]->id, equiposGrupo[j]->id});
            }
        }

        // Simular partidos
        for (auto& partido : partidos) {
            int idEquipo1 = partido.first;
            int idEquipo2 = partido.second;
            Equipo* equipo1 = nullptr;
            Equipo* equipo2 = nullptr;
            for (auto& equipo : equipos) {
                if (equipo.id == idEquipo1) {
                    equipo1 = &equipo;
                } else if (equipo.id == idEquipo2) {
                    equipo2 = &equipo;
                }
                if (equipo1 && equipo2) {
                    break;
                }
            }
            simularPartido(*equipo1, *equipo2);

            // Actualizar el número de partidos jugados
            equipo1->partidosJugados++;
            equipo2->partidosJugados++;
        }
    }

    // Mostrar tabla de posiciones de cada grupo
for (int grupo = 1; grupo <= 4; grupo++) {
        vector<Equipo> equiposGrupo;
        for (auto& equipo : equipos) {
            if (equipo.grupo == grupo) {
                equiposGrupo.push_back(equipo);
            }
        }
        string grupoNombre = to_string(grupo);
        if (grupoNombre=="1"){
            grupoNombre="GRUPO A";
        }
        if (grupoNombre=="2"){
            grupoNombre="GRUPO B";
        }
        if (grupoNombre=="3"){
            grupoNombre="GRUPO C";
        }
        if (grupoNombre=="4"){
            grupoNombre="GRUPO D";
        }


        mostrarTablaPosiciones(equiposGrupo, grupoNombre);
    }
}

    int main() {
    cargarEquipos();

    // Simular partidos por grupo
    //for (const auto& equipo : equipos) {
    //    for (const auto& otroEquipo : equipos) {
    //        if (equipo.grupo == otroEquipo.grupo && equipo.id!= otroEquipo.id) {
    //            simularPartido(const_cast<Equipo&>(equipo), const_cast<Equipo&>(otroEquipo));
    //        }
    //    }
    //}
    simularFaseGrupos();


return 0;
}
