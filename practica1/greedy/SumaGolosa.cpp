#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
Queremos encontrar la suma de los elementos de un multiconjunto de números naturales.
Cada suma se realiza exactamente entre dos números x e y y tiene costo x + y.
Queremos encontrar la forma de sumar que tenga costo mínimo, por lo que en nuestro ejemplo la mejor forma sería la primera.

Por ejemplo, si queremos encontrar la suma de {1, 2, 5} tenemos 3 opciones:
 * 1 + 2 (con costo 3) y luego 3 + 5 (con costo 8), resultando en un costo total de 11;
 * 1 + 5 (con costo 6) y luego 6 + 2 (con costo 8), resultando en un costo total de 14;
 * 2 + 5 (con costo 7) y luego 7 + 1 (con costo 8), resultando en un costo total de 15.

*/

int SumaGolosa(vector<int> A) {
    sort(A.begin(), A.end());
    vector<int> costos = {};
    int costoActual = A[0];
    int sol = 0;
    
    for (int i = 1; i < A.size(); i++) {
        costoActual += A[i];
        costos.push_back(costoActual);
    }

    for (int e : costos)
    {
        sol += e;
    }
    return sol;
}

int main() {
    vector<int> A = {1,2,5};
    int suma = SumaGolosa(A);
    cout << suma << endl;
}