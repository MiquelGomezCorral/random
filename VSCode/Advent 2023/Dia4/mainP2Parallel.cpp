//PARA COMPILAR USAR ctr + shift + b
//PARA EJECUTAR USAR .\mainP2Parallel.exe OMP_NUM_THREADS=14

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
        ifstream archivo("input.txt");
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
        int lineId, wins, i; vector<string> line; string toTokenice; bool exit = false;
        #pragma omp parallel private(line,lineId,wins, toTokenice,i) reduction(+:res)
        {
            while(!lineQ.empty()){
                res++;
                line.clear();
                #pragma omp critical//(pop)
                {
                    if(!lineQ.empty()){ 
                        toTokenice = lineQ.front();
                        lineQ.pop();
                    }else exit = true;
                }
                if(exit)break;

                tokenize(toTokenice, ' ', line); 
                line[1].pop_back();
                lineId = stoi(line[1]);
                wins = validateLine(line);

                for(i = 1; i <= wins; i++){
                    #pragma omp critical//(push)
                    lineQ.push(lines[lineId+i]);
                }
                if(res % 10000 == 0 && omp_get_thread_num() == 0) cout << "Cards left: "<< lineQ.size() <<", res: " << res << endl;
            }
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
    //omp_set_num_threads(10);
    auto inicio = high_resolution_clock::now();
    Main m = Main();
    m.main();
    auto fin = high_resolution_clock::now();

    auto duracion = duration_cast<microseconds>(fin - inicio);
    cout << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "TIEMPO DE EJECUCION: " << duracion.count()/1000 << " MiliSegundos"<<endl;
}