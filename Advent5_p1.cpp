#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream> // <--- 1. NECESARIO PARA LEER ARCHIVOS

using namespace std;

struct Rango {
    long long inicio;
    long long fin;
};

int main() {
    
    ifstream archivo("input.txt");

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo input.txt" << endl;
        return 1;
    }

    vector<Rango> rangos;
    string linea;
    int nrangos;


    while (getline(archivo, linea)) {
        if (linea.empty()) {
            break; 
        }

        stringstream ss(linea);
        long long inicio, fin;
        char guion;

        if (ss >> inicio >> guion >> fin) {
            rangos.push_back({inicio, fin});
        }
        nrangos++;
    }


    long long idActual;
    int contadorFrescos = 0;


    while (archivo >> idActual) {
        bool esFresco = false;
        for (int i =0;i<nrangos;i++) {
            if (idActual >= rangos[i].inicio && idActual <= rangos[i].fin) {
                esFresco = true;
                break;
            }
        }

        if (esFresco==true) {
            contadorFrescos++;
        }
    }


    archivo.close();

    cout << "Total de ingredientes frescos: " << contadorFrescos << endl;

    return 0;
}
