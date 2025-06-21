// Importar librería con utilidades
#include <bits/stdc++.h>
// Para especificar por ejemplo que 'cout' pertenece a la librería estandar
using namespace std;
// Las typedef sirven para poder referirse a un tipo de variable con otro nombre (uno más corto por conveniencia)
typedef long long ll;
typedef unsigned long long ull;
// Las macros sirven para referirse a una expresión con un nombre más corto, hay algunos ejemplos más abajo
#define entf cout << endl
#define ent cout << "\n"
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define MOD 1000000007
#define TESTCASES false
// Resolver el caso de prueba 'tt'
void solve(int tt) {
}
int main() {
    // Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    // TESTCASES al ser una macro se sustituye por false al compilarse. Útil cuando el problema nos pide queprocesemos multiples casos de prueba
    if (TESTCASES) {
        int tt; cin >> tt;
    // Esta macro se sustituirá por 'for (int i= 1; i < tt+1; ++i)'
        REP(i, 1, tt+1) {
            solve(i);
        }
    } else solve(1);

    return 0;
}
