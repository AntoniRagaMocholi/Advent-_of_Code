#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Rango{
    long long ini;
    long long fin;
};

vector<Rango> parsearRangos(string linea){
    vector<Rango> rangos;
    string temp = "";

    for(int i=0; i<linea.size(); i++){

        char c = linea[i];

        if(c == ','){
            int pos = temp.find('-');
            string a = temp.substr(0, pos);
            string b = temp.substr(pos+1);

            long long ini = stoll(a);
            long long fin = stoll(b);

            rangos.push_back({ini, fin});

            temp = "";

        }else{
            temp += c;
        }
    }

    if(temp != ""){
        int pos = temp.find('-');
        string a = temp.substr(0, pos);
        string b = temp.substr(pos+1);

        long long ini = stoll(a);
        long long fin = stoll(b);

        rangos.push_back({ini, fin});
    }

    return rangos;
}

bool esInvalido(long long n){
    string s = to_string(n);
    if(s.length() % 2 != 0){
        return false;

    }else{
        int mitad = s.length() / 2;
        string a = s.substr(0, mitad);
        string b = s.substr(mitad);
        return a == b;
    }
}

int main(){
    ifstream archivo("input.txt");
    if(!archivo.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    string linea;
    long long sumaInvalidos = 0;

    while(getline(archivo, linea)){
        if(linea == "") continue;

        vector<Rango> rangos = parsearRangos(linea);
    
        for(int i=0; i<rangos.size(); i++){
            for(long long n = rangos[i].ini; n<=rangos[i].fin; n++){
                if(esInvalido(n)){
                    sumaInvalidos += n;
                }
            }
        }
    }

    archivo.close();

    cout << "La suma de invalidos es: " << sumaInvalidos << endl;

    return 0;
}