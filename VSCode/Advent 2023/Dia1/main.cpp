// Advent 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
class Main{
    public: int main(){
        string linea, aux;
        int count = 0;
        ifstream archivo("../input.txt");
        // Verifica si el archivo se abrió correctamente
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo." << std::endl;
            return 1; // Salir con código de error
        }
        while (getline(archivo,linea)) {
            //cout << "----------------------------------------------" << endl;
            count += takeNumbers(linea);
        }

        cout << count << endl;

        archivo.close();
        return 0; // Salir con éxito
    }

    int takeNumbers(string linea){
        int posn1 = -1, posn2 = -1,i;
        string n1 = "", n2;
        char c;
        for(i = 0; i < linea.length() && n1.length()==0; i++){
            c = linea[i];
            if(isdigit(c)) {
                n1 += c;
                posn1 = i;
            }
        }
        for(; i < linea.length(); i++){
            c = linea[i];
            if(isdigit(c))  {
                n2=c;
                posn2 = i;
            }
        }
        //________________________________________________________________
        string* textnum = new string[2];
        int* textpos = new int[2];
        textnum[0] = "-1"; textnum[1] = "-1";
        textpos[0] = -1; textpos[1] = -1;
        int* auxpos = new int[2];
        vector<string> nums = {"one","two","three","four","five","six","seven","eight","nine"};

        for (string num : nums){
            //cout << "-----------------: " << num << endl;
            auxpos = firstLast(linea,num);
            if(auxpos[0]!=-1){
                if(textpos[0] == -1 || auxpos[0]<textpos[0]){
                    textpos[0] = auxpos[0];
                    textnum[0] = parseNumber(num);
                }
                if(textpos[1] == -1 || auxpos[0]>textpos[1]){
                    textpos[1] = auxpos[0];
                    textnum[1] = parseNumber(num);
                }
            }
            if(auxpos[1]!=-1){
                if(textpos[0] == -1 || auxpos[1]<textpos[0]){
                    textpos[0] = auxpos[1];
                    textnum[0] = parseNumber(num);
                }
                if(textpos[1] == -1 || auxpos[1]>textpos[1]){
                    textpos[1] = auxpos[1];
                    textnum[1] = parseNumber(num);
                }
            }
            //cout << "   " << "t1 y post1: " << textnum[0] << ", " << textpos[0] << endl;
            //cout << "   " << "t2 y post2: " << textnum[0] << ", " << textpos[0] << endl;
        }
        //________________________________________________________________
        if(posn2 == -1){       posn2 = posn1; n2 = n1;}//Poner a única ocurrencia
        if(textpos[1] == -1){  textpos[1]=textpos[0]; textnum[1]=textnum[0];}
        string res = "";
        if(posn1 == -1){ //NO hay números
            res+= textnum[0]+textnum[1];
        }else{ //Hay números
            if(textpos[0] == -1) { //NO hay texto
                res+=n1+n2;
            }else{ //Hay texto y números
                if(posn1 < textpos[0]) { //Primera occurrencia es de número
                    res+=n1; 
                    if(posn2 > textpos[1]){
                        res+=n2;  //Última occurrencia es de número
                    }else{
                        res+=textnum[1]; //Última occurrencia es de texto
                    }
                }else {  //Primera occurrencia es de texto 
                    res+=textnum[0];
                    if(posn2 > textpos[1]){
                        res+=n2;  //Última occurrencia es de número
                    }else{
                        res+=textnum[1]; //Última occurrencia es de texto
                    }
                }
            }
        }
        /*cout << linea << ":" << res << endl;
        cout << "      " << "n1 y posn1: " << n1 << ", " << posn1 << endl;
        cout << "      " << "n2 y posn2: " << n2 << ", " << posn2 << endl;
        cout << "      " << "text1 y postext1: " << textnum[0] << ", " << textpos[0] << endl;
        cout << "      " << "text2 y postext2: " << textnum[1] << ", " << textpos[1] << endl;*/

        return stoi(res);
    }

    int* firstLast(string line, string num){
        int pos = line.find(num);
        int fristpos = pos;
        int lastpost = -1;
        while (pos != string::npos) {
            cout << "Encontrado '" << num <<"' en la posicion: " << pos << std::endl;
            pos = line.find(num, pos + 1);
            if(pos != string::npos) lastpost = pos;
        }
        int* res = new int[2];
        res[0] = fristpos; res[1] = lastpost;
        //cout << "firstLast: "<< res[0] << " " << res[1] << endl;
        return res;
    } 
    string parseNumber(string num){
        if(num == "one") return "1";
        else if(num == "two") return "2";
        else if(num == "three") return "3";
        else if(num == "four") return "4";
        else if(num == "five") return "5";
        else if(num == "six") return "6";
        else if(num == "seven") return "7";
        else if(num == "eight") return "8";
        else if(num == "nine") return "9";
        else return "-1";
    }
};

int main() {
    Main m = Main();
    m.main();
}