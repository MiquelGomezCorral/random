#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
    int n, cont = 0;
    double res = 0.0, aux; 
    cin >> n;
    double a[n];

    for(int i = 0; i < n; i++){
        cin >> aux;
        if(aux >= 5.00){
            cont++;
            res += 0.0 + aux;
        }
    }
    res = 1.0 * res / cont;
    printf("%.2f\n",res);
    /*res *= 100.0;
    res = round(res);
    res /= 100.0;
    cout << res;*/

    return 0;
}