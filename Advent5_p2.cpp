#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>



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
    int nrangos = 0;

    
    while (getline(archivo, linea)) {
        if (linea.empty()) {
            break; 
        }

        stringstream ss(linea);
        long long inicio, fin;
        char guion;

        if (ss >> inicio >> guion >> fin) {
            rangos.push_back({inicio, fin});
            nrangos++;
        }
    }
    archivo.close();


    for (int i = 0; i < nrangos - 1; i++) {
        for (int j = 0; j < nrangos - i - 1; j++) {
            
            if (rangos[j].inicio > rangos[j + 1].inicio) {
                Rango temporal = rangos[j];
                rangos[j] = rangos[j + 1];
                rangos[j + 1] = temporal;
            }
        }
    }

    
    vector<Rango> rangosFusionados;
    
    if (nrangos > 0) {
        rangosFusionados.push_back(rangos[0]);

        for (int i = 1; i < nrangos; i++) {
            
            Rango& ultimo = rangosFusionados.back();
            Rango actual = rangos[i];

            if (actual.inicio <= ultimo.fin) {

                if (actual.fin > ultimo.fin) {
                    ultimo.fin = actual.fin;
                }
            } else {
                rangosFusionados.push_back(actual);
            }
        }
    }


    long long totalFrescos = 0;
    
    for (int i = 0; i < rangosFusionados.size(); i++) {
        totalFrescos += (rangosFusionados[i].fin - rangosFusionados[i].inicio + 1);
    }

    cout << "Total de ingredientes frescos (sin repetir): " << totalFrescos << endl;

    return 0;
}
