#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x, y, j;

    /*cout << "Inserte num: ";
    cin >> x;*/
    cout << "Inserte num: ";
    cin >> y;
    
    for(int i = 1; i <= y; i++){
        bool f = true;
        j = 2;
        while(j < i){
            if((i % j) == 0){
                f == false;
                break;
            }
            j++;
        }
        if(f){
            cout << i << ", ";
        }
        
    }

    return 0;
}