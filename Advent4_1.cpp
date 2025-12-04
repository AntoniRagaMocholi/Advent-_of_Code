#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int contarAdyacentes(const vector<vector<char>>& grid, int i, int j, int filas, int columnas) {
    int aux = 0;
    int movs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    for (int k = 0; k < 8; k++) {      
        int ni = i + movs[k][0];
        int nj = j + movs[k][1];
        
        if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
            if (grid[ni][nj] == '@') {
                aux++; 
            }
        }
    }

    return aux;
}

int main() {
    vector<vector<char>> grid;
    string line;

    while (getline(cin, line)) {
        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }

    int filas = grid.size();
    int columnas = filas > 0 ? grid[0].size() : 0;

    int NumX = 0;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (grid[i][j] == '@' && contarAdyacentes(grid, i, j, filas, columnas) < 4) {
                NumX++;
            }
        }
    }

    cout << "Se marcaron " << NumX << " rollos de papel como accesibles." << endl;

    return 0;
}