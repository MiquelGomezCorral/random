#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>
#include "../functions.cpp"
using namespace std;
enum values{out, in, range};
class Main{
    public: int main(){
        string linea;
        int aux;
        int res = numeric_limits<int>::max();
        ifstream archivo("../input.txt");
        if (!archivo.is_open()) {    // Verifica si el archivo se abrió correctamente
            cerr << "Error al abrir el archivo." << std::endl;
            return 1; // Salir con código de error
        }
        //____________________________________________________________________________________________________
        vector<string> seedsLine, valuesLine;vector<long long> seedsNum, valuesNum; bool* seedsChanged;
        getline(archivo,linea);
        tokenize(linea, ' ', seedsLine); 
        seedsLine.erase(seedsLine.begin());
        for (string s : seedsLine) {cout << s << " "; seedsNum.push_back(stoll(s));} //Hacer seeds valores números
        seedsChanged = new bool[seedsNum.size()];
        int size = sizeof(seedsChanged);
        //for(long long i : seedsNum) cout << i << ", " << endl;
        getline(archivo, linea); 
        cout << linea << endl;
        getline(archivo, linea); 
        cout << linea << endl;
        
        while (getline(archivo, linea)) { //Quitar primera linea
            cout << linea << endl;
            for(int i = 0; i < size; i++) seedsChanged[i] = false;

            while (linea != "") { //Hasta que no llegue al final
                valuesLine.clear(); valuesNum.clear(); //Limpiar vectoes
                tokenize(linea, ' ', valuesLine); //Separar valores
                for (string s : valuesLine) valuesNum.push_back(stoll(s)); //Hacer esos valores números

                for (int i = 0; i < seedsNum.size(); i++) {
                    aux = seedsNum[i];
                    if(aux >= valuesNum[in] && aux <= valuesNum[in]+valuesNum[out] && !seedsChanged[i]){
                        seedsNum[i] = aux-valuesNum[in]+valuesNum[out];
                        seedsChanged[i] = true;
                    }
                }
                cout << "   INTER SEEDS VALUES: ";
                for(long long i : seedsNum) cout << i << " ";
                cout << endl << endl;
                if(!getline(archivo, linea)) break;
                cout << linea << endl;
            }
            cout << "END LINE VALUES: ";
            for(long long i : seedsNum) cout << i << " ";
            cout << endl << endl;
            getline(archivo, linea); 
            cout << linea << endl;
        }

        for(long long i : seedsNum){
            if(i < res) res = i;
        }
        
        //____________________________________________________________________________________________________
        cout << "--------------------------------------" << endl;
        cout <<"END RESULT: " << res << endl;
        archivo.close();
        return 0; // Salir con éxito
    }
};
int main() {
    Main m = Main();
    m.main();
    /*vector<long long> valuesNum;
    valuesNum.push_back(970637455);
    valuesNum.push_back(0);
    valuesNum.push_back(188112122);
    long long aux = 144218002;
    if(aux >= valuesNum[1] && aux <= valuesNum[1]+valuesNum[2]){
        aux = aux-valuesNum[1]+valuesNum[0];
    }
    cout << aux;*/
}