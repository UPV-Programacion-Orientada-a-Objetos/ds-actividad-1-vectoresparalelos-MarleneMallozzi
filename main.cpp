#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "¿Cuantos atletas deseas registrar? ";
    cin >> n;
    cin.ignore();

    vector<string> nombres(n);
    vector<string> paises(n);
    vector<string> disciplinas(n);
    vector<char> generos(n);
    vector<int> oros(n);

    for (int i = 0; i < n; i++) {
        cout << "\nAtleta " << i+1 << ":\n";
        cout << "Nombre: ";
        getline(cin, nombres[i]);
        cout << "Pais: ";
        getline(cin, paises[i]);
        cout << "Disciplina: ";
        getline(cin, disciplinas[i]);
        cout << "Genero (M/F): ";
        cin >> generos[i];
        cout << "Medallas de oro: ";
        cin >> oros[i];
        cin.ignore();
    }

    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Buscar atleta\n";
        cout << "2. Total de medallas por pais\n";
        cout << "3. Atleta con mas medallas\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre;
            cout << "Nombre del atleta: ";
            getline(cin, nombre);
            bool encontrado = false;
            for (int i = 0; i < n; i++) {
                if (nombres[i] == nombre) {
                    cout << "Pais: " << paises[i]
                         << ", Oros: " << oros[i] << "\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "Atleta no encontrado.\n";
        }

        else if (opcion == 2) {
            unordered_map<string,int> totales;
            for (int i = 0; i < n; i++) {
                totales[paises[i]] += oros[i];
            }
            for (auto &p : totales) {
                cout << p.first << ": " << p.second << " oros\n";
            }
        }

        else if (opcion == 3) {
            int idx = 0;
            for (int i = 1; i < n; i++) {
                if (oros[i] > oros[idx]) idx = i;
            }
            cout << "Atleta con mas oros: " << nombres[idx]
                 << " (" << paises[idx] << ") - " << oros[idx] << "\n";
        }

    } while (opcion != 0);

    return 0;
}

