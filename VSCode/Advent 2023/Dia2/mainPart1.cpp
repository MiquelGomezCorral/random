#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
vector<int> MinPerColor = {12,13,14}; 
enum colors{RED,GREEN,BLUE};
class Main{
    public: int main(){
        string linea, aux;
        int res = 0;
        ifstream archivo("../input.txt");
        if (!archivo.is_open()) {    // Verifica si el archivo se abrió correctamente
            cerr << "Error al abrir el archivo." << std::endl;
            return 1; // Salir con código de error
        }
        //____________________________________________________________________________________________________

        while (getline(archivo,linea)) {
            cout << "-------------------" << endl;
            cout << "Res: " << res << endl;
            res += validateGame(linea);
        }

        //____________________________________________________________________________________________________
        cout << res << endl;
        archivo.close();
        return 0; // Salir con éxito
    }
    int validateGame(string linea){
        int amount; string color; bool valid = true;
        vector<string> line = split(linea, ' ');
        int gameNumber = stoi(line[1].substr(0,line[1].length()-1));

        cout << " GameNum: " << gameNumber << endl; 
        cout << "------------" << endl;

        for(size_t i = 2; i < line.size() && valid; i+=2){
            amount = stoi(line[i]);
            cout << "   Amount: " << amount << endl;

            color = line[i+1];
            if(color[color.length()-1] == ';' || color[color.length()-1] == ','){
                color = color.substr(0,color.length()-1);
            }
            cout << "   Color: " << color << endl;
            valid = validAmount(amount,color);

            cout << "   Valid: " << valid << endl;
        }
        return valid ? gameNumber : 0; 
    }
    bool validAmount(int amout, string color){
        if(color == "red")          return amout<=MinPerColor[RED];
        else if(color == "green")   return amout<=MinPerColor[GREEN];
        else if(color == "blue")    return amout<=MinPerColor[BLUE];
        else return false;
    }

    vector<string> split(string str, char pattern) {
        int posInit = 0;
        int posFound = 0;
        string splitted;
        vector<string> results;
        
        while(posFound >= 0){
            posFound = str.find(pattern, posInit);
            splitted = str.substr(posInit, posFound - posInit);
            posInit = posFound + 1;
            results.push_back(splitted);
        }
        return results;
    }
};
int main() {
    Main m = Main();
    m.main();
    
}