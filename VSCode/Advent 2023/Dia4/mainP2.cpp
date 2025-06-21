#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <queue>
#include <chrono>
#include <omp.h>
#include "../functions.cpp"
using namespace std;
using namespace chrono;
class Main{
    public: int main(){
        string linea;
        int res = 0;
        ifstream archivo("../input.txt");
        if (!archivo.is_open()) {    // Verifica si el archivo se abrió correctamente
            cerr << "Error al abrir el archivo." << std::endl; return 1; // Salir con código de error
        }
        //____________________________________________________________________________________________________
        queue<string> lineQ;
        vector<string> lines; lines.push_back("");
        cout << "-------------------" << endl;
        cout << "Queueing... " << endl;
        while (getline(archivo,linea)) {
            
            lines.push_back(linea);
            lineQ.push(linea);
        }
        cout << "-------------------" << endl;
        cout << "Counting... " << endl;
        int lineId, wins; vector<string> line; 
        while(!lineQ.empty()){
            res++;
            //cout << "-----" << endl;
            //cout << lineQ.front() << endl;
            line.clear();
            tokenize(lineQ.front(), ' ', line); lineQ.pop();
            //for(string s : line) cout << s <<", "; cout  << endl;
            line[1].pop_back();
            //cout << "Line pos: " <<line[1] ;
            lineId = stoi(line[1]);
            wins = validateLine(line);

            for(int i = 1; i <= wins; i++){
                lineQ.push(lines[lineId+i]);
            }
            if(res % 100000 == 0)cout << "Cards left: "<<lineQ.size()<<", res: " << res << endl;
        }

        //____________________________________________________________________________________________________
        cout << "--------------------------------------" << endl;
        cout <<"END RESULT: " << res << endl;
        archivo.close();
        return 0; // Salir con éxito
    }
    int validateLine(vector<string> line){
        vector<int> winners, numbers;
        int res = 0;

        for(int i = 2; i <= 11; i++) winners.push_back(stoi(line[i])); //line[i+1] != "|"
        for(int i = 13; i < line.size(); i++) numbers.push_back(stoi(line[i]));
        //for(int i = 2; i <= 6; i++) winners.push_back(stoi(line[i])); //line[i+1] != "|"
        //for(int i = 8; i < line.size(); i++) numbers.push_back(stoi(line[i]));

        for(int i : numbers) if(contains(winners,i)) res++;
        
        return res;
    }
};
int main() {
    auto inicio = high_resolution_clock::now();
    Main m = Main();
    m.main();
    auto fin = high_resolution_clock::now();

    auto duracion = duration_cast<microseconds>(fin - inicio);
    cout << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "TIEMPO DE EJECUCION: " << duracion.count()/1000000 << " segundos"<<endl;
}