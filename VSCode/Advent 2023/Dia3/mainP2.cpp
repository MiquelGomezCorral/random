#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
class Main{
    public: int main(){
        string lineaAnt, lineaMid, lineaPost, aux;
        int res = 0;
        ifstream archivo("../input.txt");
        if (!archivo.is_open()) {    // Verifica si el archivo se abrió correctamente
            cerr << "Error al abrir el archivo." << std::endl;
            return 1; // Salir con código de error
        }
        //____________________________________________________________________________________________________
        getline(archivo,lineaAnt);
        getline(archivo,lineaMid);
        while (getline(archivo,lineaPost)) {
            cout << "-------------------" << endl;
            cout << "Res: " << res << endl;
            res += validateLine(lineaAnt,lineaMid,lineaPost);

            lineaAnt = lineaMid;
            lineaMid = lineaPost;
        }
        //____________________________________________________________________________________________________
        cout << "--------------------------------------" << endl;
        cout <<"END RESULT: " << res << endl;
        archivo.close();
        return 0; // Salir con éxito
    }
    int validateLine(string lineaAnt,string lineaMid,string lineaPost){
        int res = 0, j, MaxSize = lineaMid.length();
        char aux;
        string n1 = "", n2 = "";
        for(int i = 0; i < lineaMid.length();i++){
            aux = lineaMid[i];
            //cout << aux[0];
            if(aux == '*'){
                n1 = "", n2 = "";
                //----LINEA ANT----
                if(isdigit(lineaAnt[i])){
                    j = i-1;
                    while(isdigit(lineaAnt[j]) && j >= 0) j--;
                    j++;
                    while(isdigit(lineaAnt[j])) n1+=lineaAnt[j++];
                }else{
                    if(isdigit(lineaAnt[i-1])){
                        j = i-1;
                        while(isdigit(lineaAnt[j]) && j >= 0) j--;
                        j++;
                        while(isdigit(lineaAnt[j])) n1+=lineaAnt[j++];
                    }
                    if(isdigit(lineaAnt[i+1])){
                        j = i+1;
                        while(isdigit(lineaAnt[j]) && j < MaxSize) n2+=lineaAnt[j++];
                    }
                }

                //----LINEA MID----
                if(isdigit(lineaMid[i-1])){
                    j = i-1;
                    while(isdigit(lineaMid[j]) && j >= 0) j--;
                    j++;

                    if(n1 == "")    while(isdigit(lineaMid[j])) n1 += lineaMid[j++];  
                    else if(n2=="") while(isdigit(lineaMid[j])) n2 += lineaMid[j++];  
                }
                if(isdigit(lineaMid[i+1])){
                    j = i+1;

                    if(n1 == "")    while(isdigit(lineaMid[j]) && j < MaxSize) n1 += lineaMid[j++];  
                    else if(n2=="") while(isdigit(lineaMid[j]) && j < MaxSize) n2 += lineaMid[j++]; 
                }

                //----LINEA POS----
                if(isdigit(lineaPost[i])){
                    j = i-1;
                    while(isdigit(lineaPost[j]) && j >= 0) j--;
                    j++;
                    if(n1 == "")    while(isdigit(lineaPost[j])) n1 += lineaPost[j++];  
                    else if(n2=="") while(isdigit(lineaPost[j])) n2 += lineaPost[j++]; 
                }else{
                    if(isdigit(lineaPost[i-1])){
                        j = i-1;
                        while(isdigit(lineaPost[j]) && j >= 0) j--;
                        j++;
                        if(n1 == "")    while(isdigit(lineaPost[j])) n1 += lineaPost[j++];  
                        else if(n2=="") while(isdigit(lineaPost[j])) n2 += lineaPost[j++]; 
                    }
                    if(isdigit(lineaPost[i+1])){
                        j = i+1;
                        if(n1 == "")    while(isdigit(lineaPost[j]) && j < MaxSize) n1 += lineaPost[j++];  
                        else if(n2=="") while(isdigit(lineaPost[j]) && j < MaxSize) n2 += lineaPost[j++]; 
                    }
                }
                cout << aux << ": "<< n1 << ":" << n2 << ". ";
                if(n1 != "" && n2 != ""){
                    res+=stoi(n1)*stoi(n2);
                    cout << "Res+= " << (stoi(n1)*stoi(n2));
                }
                cout << endl;
            }
        }
        cout << endl;
        return res;
    }
};
int main() {
    Main m = Main();
    m.main();
}