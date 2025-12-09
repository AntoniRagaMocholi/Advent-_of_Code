#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <utility>

using namespace std;

int encontrarColumnaDeS(const vector<string>& mapa){
    if(mapa.empty() || mapa[0].empty()){
        return -1;
    }
    for(int i=0; i<mapa[0].size(); i++){
        if(mapa[0][i] == 'S'){
            return i;
        }
    }
    return -1;
}

bool enRango(int fila, int columna, int numFilas, int numColumnas){
    if(fila < 0 || fila >= numFilas){
        return false;
    }
    if(columna < 0 || columna >= numColumnas){
        return false;
    }
    return true;
}

vector<string> leer_archivo(const string& nombre_archivo){
    vector<string> mapa;
    ifstream archivo(nombre_archivo);
    if(!archivo.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return mapa;
    }
    
    string linea;

    while(getline(archivo, linea)){
        if(!linea.empty()){
            mapa.push_back(linea);
        }
    }
    archivo.close();
    return mapa;
}

vector<pair<int, int>> vecinos(int fila, int columna, const vector<string>& mapa){
    vector<pair<int, int>> adj;
    int numFilas = (int)mapa.size();
    if(numFilas == 0) {
        return adj;
    }
    int numColumnas = (int)mapa[0].size();
    if(!enRango(fila, columna, numFilas, numColumnas)){
        return adj;
    }

    char ch = mapa[fila][columna];

    if(ch == '.'){
        if(enRango(fila+1, columna, numFilas, numColumnas)){
            adj.emplace_back(fila+1 ,columna);
        }
    }else if(ch == '^'){
        if(enRango(fila, columna-1, numFilas, numColumnas)){
            adj.emplace_back(fila, columna-1);
        }
        
        if (enRango(fila, columna + 1, numFilas, numColumnas)) {
            adj.emplace_back(fila, columna+1);
        }
    }else if(ch == 'S'){
        if (enRango(fila+1, columna, numFilas, numColumnas)) {
            adj.emplace_back(fila+1, columna);
        }
    }else{ 
        if (enRango(fila+1, columna, numFilas, numColumnas)) {
            adj.emplace_back(fila+1, columna);
        }
    }

    return adj;
}

int contarDivisionesGrafo(const vector<string>& mapa, int filaIni, int colIni){
    int numFilas = (int)mapa.size();
    int numColumnas = (int)mapa[0].size();
    if(numFilas == 0 || numColumnas == 0){
        return 0;
    }
    if(!enRango(filaIni, colIni, numFilas, numColumnas)){
        return 0;
    }

    vector<vector<char>> visitado(numFilas, vector<char>(numColumnas, 0));
    queue<pair<int, int>> q;
    q.emplace(filaIni, colIni);
    int divisiones = 0;

    while(!q.empty()){
        auto [fila, columna] = q.front();
        q.pop();

        if(visitado[fila][columna]){
            continue;
        }
        visitado[fila][columna] = 1;

        if(mapa[fila][columna] == '^'){
            divisiones++;
        }

        const auto adj = vecinos(fila, columna, mapa);

        
        for (const auto& [nr, nc] : adj) {
            if (enRango(nr, nc, numFilas, numColumnas)) {
                q.emplace(nr, nc);
            }
        }
    }
    return divisiones;
}

void resolver_problema(const vector<string>& mapa){
    if(mapa.empty()){
        return;
    }

    const int numFilas    = (int)mapa.size();
    const int numColumnas = (int)mapa[0].size();

    int iniColumna = encontrarColumnaDeS(mapa);
    if(iniColumna == -1){
        cout << "Error, no se encontro inicio de S\n";
        return;
    }

    int resultadoTotal = contarDivisionesGrafo(mapa, 1, iniColumna);

    cout << "El numero total de divisiones es = " << resultadoTotal << endl;
}

long long contarTimelines(const vector<string>&mapa, int fila, int columna, vector<vector<long long>>& memoria){
    int numFilas = (int)mapa.size();
    int numColumnas = (int)mapa[0].size();
    if(fila < 0 || fila >= numFilas || columna < 0 || columna >= numColumnas){
        return 1;
    }

    long long &m = memoria[fila][columna];
    if(m != -1){
        return m;
    }

    const char ch = mapa[fila][columna];
    long long res = 0;

    if(ch == '.' || ch == 'S'){
        res = contarTimelines(mapa, fila+1, columna, memoria);
    }else if(ch == '^'){
        res = 0;
        res += contarTimelines(mapa, fila, columna-1, memoria);
        res += contarTimelines(mapa, fila, columna+1, memoria);
    }else{
        res = contarTimelines(mapa, fila+1, columna, memoria);
    }
    m = res;
    return res;

}

void resolver_problema_parte_2(const vector<string>&mapa){
    if(mapa.empty()){
        return;
    }
    
    const int numFilas    = (int)mapa.size();
    const int numColumnas = (int)mapa[0].size();

    int iniColumna = encontrarColumnaDeS(mapa);
    if(iniColumna == -1){
        cout << "Error, no se encontro inicio de S\n";
        return;
    }

    vector<vector<long long>>memoria(numFilas, vector<long long>(numColumnas, -1));
    long long totalTimelines = contarTimelines(mapa, 1, iniColumna, memoria);

    cout << "El numero total de timelines es = " << totalTimelines << endl;

}



int main(){
    vector<string> mapa = leer_archivo("input.txt");
    if(mapa.empty()){
        cerr << "Error en la lectura\n";
        return 1;
    }

    //resolver_problema(mapa);

    resolver_problema_parte_2(mapa);

    return 0;
}