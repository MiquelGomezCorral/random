#include <iostream>
#include <cmath>
using namespace std;
 
int main(){ //Número triangular
    int n, t;
    cin >> n >> t;
    if(n%t == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
   

    return 0;
}