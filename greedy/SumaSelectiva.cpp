#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 10;


int solve(int X[N], int k) {
    sort(X, X + N);
    int sol = {};
    for (int i = N - 1; i >= N - k; i--) {
        sol += X[i];
    } // O(n log n + n = n log n)
    return sol;
}

int main() {
    int X[10] = {1,20,-3,4,5,6,7,-8,9,10};
    int sol = solve(X, 2);
    cout << sol;
    return 0;
}

/*
Sean O y G dos soluciones, donde G es una solución dada por el algoritmo greedy, y O una solución óptima al problema.
Quiero demostrar que O y G son ambas soluciones óptimas al problema.

Veamos la estructura de cada solución:
    G es la suma de los elementos {a0,a1,...,ak} de el conjunto X
    O es la suma de los elementos {b0,b1,...,bk} de el conjunto X.

Alcanza con probar que Σ ai == Σ bi.
Para probarlo, asumiremos que Σ ai < Σ bi, es decir, que la solución G no es óptima.

Buscamos una solución O', también óptima, t.q. O' tenga elementos de G. Sabemos que G tiene los K elementos más grandes de X y, que cualquier elemento que pertenece a O pero no pertenece a G, es menor que cualquier aj que pertenece a G.

Entonces reeemplazo en O (formando O') cualquier elemento bj que no pertenezca a G, por un aj cualquiera que pertenezca a G \ O, y esto va a mantener la suma, o aumentarla.
Repetimos esto hasta ver que O' solo contenga elementos de G, O' == G, que mantiene o aumenta la suma total. Luego, se tiene que cumplir que Σ oi = Σ bi. 


*/