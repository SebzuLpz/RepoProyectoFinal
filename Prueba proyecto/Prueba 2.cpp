#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>

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
    vector<Jugador> jugadores;
};

class Partido {
public:
    int idEquipo1;
    int idEquipo2;
    int golesEquipo1;
    int golesEquipo2;
    int tarjetasAmarillasEquipo1;
    int tarjetasAmarillasEquipo2;
    int tarjetasRojasEquipo1;
    int tarjetasRojasEquipo2;
};

class Grupo {
public:
    int id;
    string nombre;
    vector<Equipo> equipos;
    vector<Partido> partidos;
};

void cargarEquipos(vector<Equipo>& equipos) {
    ifstream archivo("Info_Equipos_Jugadores.txt");
    string linea;
    while (getline(archivo, linea)) {
        if (linea == "-") {
            Equipo equipo;
            getline(archivo, linea);
            equipo.id = stoi(linea);
            getline(archivo, linea);
            equipo.nombre = linea;
            getline(archivo, linea);
            equipo.nivelDefensa = stoi(linea);
            getline(archivo, linea);
            equipo.nivelAtaque = stoi(linea);
            while (true) {
                Jugador jugador;
                getline(archivo, linea);
                jugador.id = stoi(linea);
                getline(archivo, linea);
                jugador.nombre = linea;
                getline(archivo, linea);
                jugador.nivelAgresividad = stoi(linea);
                equipo.jugadores.push_back(jugador);
                if (getline(archivo, linea) == "+") break;
            }
            equipos.push_back(equipo);
        }
    }
    archivo.close();
}

int equiposs() {
    int opcionequipos;
    string equipos1;
    string equipos; // Declarar aquí
    while (true) {
        cout << "Seleccione el equipo que desea ver: " << endl;
        equipos1.clear(); // Vaciar la variable
        cout<<endl;
        ifstream archivo("Equipos.txt");
        while (getline(archivo, equipos)) {
            equipos1 = equipos1 + equipos + "\n";
        }
        cout<<endl;
        archivo.close();
        cout << equipos1 << endl;
        cout << "Digite el equipo que desea ver: " << endl;
        cin >> opcionequipos;
        cout<<endl;
        if (opcionequipos == 17) {
            return 0; // Volver al menú principal
        }
        if (opcionequipos == 1) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Argentina.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 2) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Chile.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 3) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Peru.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 4) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Canada.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 5) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Mexico.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 6) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Ecuador.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 7) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Venezuela.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 8) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Jamaica.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;}
        if (opcionequipos == 9) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("EstadosUnidos.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 10) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Uruguay.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 11) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Panama.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 12) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Bolivia.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 13) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Brasil.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 14) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Colombia.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 15) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("Paraguay.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 16) {
            string jugador1, jugador; // Declarar aquí
            ifstream archivo("CostaRica.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos==17){
            cout<<"Volviendo al menu principal..."<<endl;
        }
        if (opcionequipos >= 18) {
            cout << "Opcion no valida, volviendo al menu..." << endl;
        }
    }
    system("pause");
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
                Partido partido;
                getline(archivo, linea);
                partido.idEquipo1 = stoi(linea);
                getline(archivo, linea);
                partido.idEquipo2 = stoi(linea);
                grupo.partidos.push_back(partido);
                if (getline(archivo, linea) == "-") break;
            }
            grupos.push_back(grupo);
        }
    }
    archivo.close();
}

int grupos() {
    int opciongrupos;
    string grupo_1;
    string grupo1; // Declarar aquí
    while (true) {
        cout << "Seleccione el grupo que desea ver: " << endl;
        grupo_1.clear(); // Vaciar la variable
        cout << "1. Grupo A " << endl;
        cout << "2. Grupo B " << endl;
        cout << "3. Grupo C " << endl;
        cout << "4. Grupo D " << endl;
        cout << "5. Volver al menu principal" << endl;
        cin >> opciongrupos;
        cout<<endl; // Agregar esta línea dentro del bucle while (true)
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
            return 0; // Volver al menú principal
        }
        if (opciongrupos >= 6) {
            cout << "Opcion no valida volviendo al menu..." << endl;
        }
    }
}
void simularPartidos(vector<Grupo>& grupos) {
    queue<Partido> colaPartidos;
    stack<Partido> pilaResultados;

    // Cargar cola de partidos
    for (auto& grupo : grupos) {
        for (auto& partido : grupo.partidos) {
            colaPartidos.push(partido);
        }
    }

    // Simular partidos
    while (!colaPartidos.empty()) {
        Partido partido = colaPartidos.front();
        colaPartidos.pop();

        // Simular partido (aquí va la lógica de simulación)
        int golesEquipo1 = rand() % 5; // Simulación de goles
        int golesEquipo2 = rand() % 5; // Simulación de goles
        int tarjetasAmarillasEquipo1 = rand() % 3; // Simulación de tarjetas amarillas
        int tarjetasAmarillasEquipo2 = rand() % 3; // Simulación de tarjetas amarillas
        int tarjetasRojasEquipo1 = rand() % 2; // Simulación de tarjetas rojas
        int tarjetasRojasEquipo2 = rand() % 2; //Simulación de tarjetas rojas

        // Asignar goles y tarjetas a los equipos
        for (auto& grupo : grupos) {
            if (grupo.id == partido.idEquipo1 / 10) {
                for (auto& equipo : grupo.equipos) {
                    if (equipo.id == partido.idEquipo1) {
                        equipo.goles += golesEquipo1;
                        equipo.tarjetasAmarillas += tarjetasAmarillasEquipo1;
                        equipo.tarjetasRojas += tarjetasRojasEquipo1;
                    }
                    if (equipo.id == partido.idEquipo2) {
                        equipo.goles += golesEquipo2;
                        equipo.tarjetasAmarillas += tarjetasAmarillasEquipo2;
                        equipo.tarjetasRojas += tarjetasRojasEquipo2;
                    }
                }
            }
        }

        // Guardar resultado en la pila de resultados
        Partido resultado;
        resultado.idEquipo1 = partido.idEquipo1;
        resultado.idEquipo2 = partido.idEquipo2;
        resultado.golesEquipo1 = golesEquipo1;
        resultado.golesEquipo2 = golesEquipo2;
        resultado.tarjetasAmarillasEquipo1 = tarjetasAmarillasEquipo1;
        resultado.tarjetasAmarillasEquipo2 = tarjetasAmarillasEquipo2;
        resultado.tarjetasRojasEquipo1 = tarjetasRojasEquipo1;
        resultado.tarjetasRojasEquipo2 = tarjetasRojasEquipo2;
        pilaResultados.push(resultado);
    }

    // Mostrar resultados
    while (!pilaResultados.empty()) {
        Partido resultado = pilaResultados.top();
        pilaResultados.pop();

        cout << "Partido: " << resultado.idEquipo1 << " vs " << resultado.idEquipo2 << endl;
        cout << "Goles: " << resultado.golesEquipo1 << " vs " << resultado.golesEquipo2 << endl;
        cout << "Tarjetas amarillas: " << resultado.tarjetasAmarillasEquipo1 << " vs " << resultado.tarjetasAmarillasEquipo2 << endl;
        cout << "Tarjetas rojas: " << resultado.tarjetasRojasEquipo1 << " vs " << resultado.tarjetasRojasEquipo2 << endl;
        cout << endl;
    }
}

void imprimirGrupos(vector<Grupo>& grupos) {
    for (auto& grupo : grupos) {
        cout << "Grupo " << grupo.nombre << ":" << endl;
        cout << "Equipos:" << endl;
        for (auto& equipo : grupo.equipos) {
            cout << equipo.id << " " << equipo.nombre << " " << equipo.goles << " " << equipo.tarjetasAmarillas << " " << equipo.tarjetasRojas << endl;
        }
        cout << endl;
    }
}

int reproduccion() {
    vector<Equipo> equipos;
    cargarEquipos(equipos);

    vector<Grupo> grupos;
    cargarPartidos(grupos);

    simularPartidos(grupos);

    imprimirGrupos(grupos);

    return 0;
}

int simular() {
    int opcionsimular;
    while (true) {
        cout << "1. Simular partido por partido" << endl;
        cout << "2. Simular torneo por fechas" << endl;
        cout << "3. Simular torneo por etapas" << endl;
        cout << "3. Simular copa america" << endl;
        cin >> opcionsimular;
        cout<<endl;
        if (opcionsimular == 1) {
            reproduccion();
        }
        if (opcionsimular == 2) {

        }
        if (opcionsimular == 3) {

        }
        if (opcionsimular == 4){

        }
        else {
            cout << "Opcion no valida volviendo al menu principal..." << endl;
            return 0;
        }
    }
}

int main() {
    while (true) {
        cout << "---- COPA AMERICA 2024 ----" << endl;
        cout << "---- (ESTADOS UNIDOS) ---- " << endl;
        cout << "1. Equipos" << endl;
        cout << "2. Grupos" << endl;
        cout << "3. Simular" << endl;
        cout << "4. Salir" << endl;
        cout<<"Seleccione una opcion: "<<endl;
        int opcionmenu1;
        cin >> opcionmenu1;
        cout<<endl;
        switch (opcionmenu1) {
            case 1:
                equiposs();
                system ("cls");
                break;
            case 2:
                grupos();
                break;
            case 3:
                simular();
                break;
            case 4:
            cout<<"Saliendo del programa..."<<endl;
            cout<<"Nos vemos pronto :)"<<endl;
                return 0; // Salir del programa
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
    return 0;
}