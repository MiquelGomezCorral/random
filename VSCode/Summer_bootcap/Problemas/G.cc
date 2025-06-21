#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
    int n, d;
    char o;
    double res = 0.0; 
    bool err = false;
    cin >> n >> o >> d;
    //cout << n << o << d << res << endl;
    switch(o){
        case '+':{
                res = n+d;
            break;
        }
        case '-':{
                res = n-d;
            break;
        }
        case '*':{
                res = n*d;
            break;
        }
        case '/':{
                if(d == 0){err = true; break;}
                res = 1.0*n/d;
            break;
        }
    }
    
    if(err){cout << "ERROR";}
    else{
        if(o == '/'){
            printf("%.2f\n",res);
        }else{
            cout << res;
        }
        
    }
    
    return 0;
}