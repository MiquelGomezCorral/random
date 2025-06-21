#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x = 0, y;
    cout << "Inserte num: ";
    cin >> x;
    char a[x];
    
    cout << "Inserte text: ";
    //cin >> a;
    cin.getline(a,10);
    cout << "Texto escrito: " << a;

    
   

    return 0;
}