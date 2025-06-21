#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
class Main{
    public: int count;
    public: int main(){
        string lineaAnt, lineaMid, lineaPost, aux;
        int res = 0;
        ifstream archivo("../inputDaniel.txt");
        if (!archivo.is_open()) {    // Verifica si el archivo se abrió correctamente
            cerr << "Error al abrir el archivo." << std::endl;
            return 1; // Salir con código de error
        }
        //____________________________________________________________________________________________________
        getline(archivo,lineaAnt);
        getline(archivo,lineaMid);
        res += validateLine("",lineaAnt,lineaMid); //Primera linea
        while (getline(archivo,lineaPost)) {
            cout << "-------------------" << endl;
            cout << "Res: " << res << endl;
            res += validateLine(lineaAnt,lineaMid,lineaPost);

            lineaAnt = lineaMid;
            lineaMid = lineaPost;
        }
        cout << "-------------------" << endl;
        cout << "Res: " << res << endl;
        res += validateLine(lineaAnt,lineaMid,""); //Última linea
        //____________________________________________________________________________________________________
        cout << "--------------------------------------" << endl;
        cout <<"END RESULT: " << res << endl;
        archivo.close();
        return 0; // Salir con éxito
    }
    int validateLine(string lineaAnt,string lineaMid,string lineaPost){
        int res = 0; string aux = ""; bool valid = false;
        vector<int> digitPos;
        for(int i = 0; i < lineaMid.length();i++){
            aux = lineaMid[i];
            //cout << aux[0];
            if(isdigit(aux[0])){
                //--------Digitos seguidos y donde buscar-------------
                
                if(i>0) digitPos.push_back(i-1);
                digitPos.push_back(i);
                i++;
                while(isdigit(lineaMid[i])){
                    aux += lineaMid[i];
                    digitPos.push_back(i++);   
                }
                if(i<lineaMid.length()) digitPos.push_back(i);
                //--------Empieza busqueda-------------
                valid = false;
                for(int j : digitPos){
                    if(lineaAnt == "") break;
                    valid = (!isdigit(lineaAnt[j]) && lineaAnt[j] != '.');
                    if(valid) break;
                }
                if(!valid){
                    valid = (!isdigit(lineaMid[digitPos[0]]) && lineaMid[digitPos[0]] != '.')
                        ||  (!isdigit(lineaMid[digitPos[digitPos.size()-1]]) && lineaMid[digitPos[digitPos.size()-1]] != '.');
                }
                for(int j : digitPos){
                    if(lineaPost == "") break;
                    if(valid) break;
                    valid = (!isdigit(lineaPost[j]) && lineaPost[j] != '.');
                }
                //--------Fin busqueda-------------

                if(valid){
                    res+=stoi(aux);
                }   
                cout << aux << ": " << valid << ". ";
                for(int j : digitPos){ cout << j << "-";}
                cout << ".  ";
                digitPos.clear();
            }
        }
        cout << endl;
        return res;
    }
};
int main() {
    Main m = Main();
    m.main();
    m.count;
}