#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>
#include "../functions.cpp"
using namespace std;
class Main{
    public: int awd;
    public: int main(){
        string linea;
        int res = 0;
        ifstream archivo("../input.txt");
        if (!archivo.is_open()) {    // Verifica si el archivo se abrió correctamente
            cerr << "Error al abrir el archivo." << std::endl; return 1; // Salir con código de error
        }
        //____________________________________________________________________________________________________
        while (getline(archivo,linea)) {
            cout << "-------------------" << endl;
            cout << "Res: " << res << endl;
            res += validateLine(linea);
        }
        //____________________________________________________________________________________________________
        cout << "--------------------------------------" << endl;
        cout <<"END RESULT: " << res << endl;
        archivo.close();
        return 0; // Salir con éxito
    }
    int validateLine(string linea){
        vector<string> line; tokenize(linea, ' ', line); //split(linea, ' ');
        for(string s : line) cout << s <<",";
        vector<int> winners, numbers;
        int res = 0;
        for(int i = 2; i <= 11; i++) {
            cout << line[i];
            winners.push_back(stoi(line[i])); //line[i+1] != "|"
        }
        for(int i = 13; i < line.size(); i++) {
            cout << line[i];
            numbers.push_back(stoi(line[i]));
        }

        for(int i : numbers) if(contains(winners,i)) res++;
        
        return (res==0) ? 0 : static_cast<int>(pow(2,res-1)); //Si no ha encontrado nada return 0, sino 2^res-1;
    }
};
int main() {
    Main m = Main();
    m.main();
    m.awd;
}
