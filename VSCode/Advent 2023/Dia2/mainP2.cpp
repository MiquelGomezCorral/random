#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
vector<int> MinPerColor = {0,0,0}; 
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
        int amount; string color;
        vector<string> line = split(linea, ' ');
        int gameNumber = stoi(line[1].substr(0,line[1].length()-1));

        //cout << " GameNum: " << gameNumber << endl; 
        //cout << "------------" << endl;
        MinPerColor[RED] = 0; MinPerColor[GREEN] = 0; MinPerColor[BLUE] = 0;

        for(size_t i = 2; i < line.size(); i+=2){
            amount = stoi(line[i]);
            //cout << "   Amount: " << amount << endl;

            color = line[i+1];
            if(color[color.length()-1] == ';' || color[color.length()-1] == ','){
                color = color.substr(0,color.length()-1);
            }
            //cout << "   Color: " << color << endl;

            setMinAmount(amount,color);
            //cout << "   MInPerColor: " << MinPerColor[RED]<<", "<<MinPerColor[GREEN]<<", "<<MinPerColor[BLUE] << endl;
        }
        return MinPerColor[RED]*MinPerColor[GREEN]*MinPerColor[BLUE]; 
    }
    int setMinAmount(int amout, string color){
        if(color == "red"){
            if(amout>=MinPerColor[RED]){
                MinPerColor[RED] = amout;
            }
        }
        else if(color == "green"){
            if(amout>=MinPerColor[GREEN]){
                MinPerColor[GREEN] = amout;
            }
        }   
        else if(color == "blue"){
            if(amout>=MinPerColor[BLUE]){
                MinPerColor[BLUE] = amout;
            }
        }
        return 0;
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