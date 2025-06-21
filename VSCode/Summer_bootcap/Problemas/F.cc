#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long min = 0;
    cin >> min;

    //cout << min << endl;
    min += 12*60; //Sumamos a las 12
    min = min % (60*24); //Hacemos que se quede todo en un día

    long hour = min/60;
    min = min % 60;

    if(min > 10){
        if(hour > 10){
            cout << hour << ":" << min;
        }else{
            cout << "0" << hour << ":" << min;
        }
    }else{
        if(hour > 10){
            cout << hour << ":" << "0" << min;
        }else{
            cout << "0" << hour << ":" << "0" << min;
        }
    }
    
    return 0;
}