#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long data[3];
    cin >> data[0];
    cin >> data[1];
    cin >> data[2];

    //cout << data[0] << " " << data[1] << " " << data[2] << " " << endl;

    if(data[2] >= 1){data[2]--;}
    else if(data[1] >= 1){data[1]--;}
    else if(data[0] >= 1){data[0]--;}

    //cout << data[0] << " " << data[1] << " " << data[2] << " " << endl;
    
    long res = data[2]*13 + data[1]*7 + data[0]*5;
    cout << res;
    
    return 0;
}