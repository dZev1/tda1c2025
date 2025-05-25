#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int N = 10;

vector<int> C = {2,4,7};

vector<vector<int>> dp;

int minCosto(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    int costo = j - i;
    int minimo = 1e9;
    bool hayCorte = false;
    for (int c : C)
    {
        if (i < c && c < j)
        {
            hayCorte = true;
            minimo = min(minimo, minCosto(i, c) + minCosto(c,j));
        }
    }

    if (!hayCorte)
    {
        dp[i][j] = 0;
        return 0;
    }
    dp[i][j] = costo + minimo;
    return dp[i][j];
}

int main(int argc, char const *argv[])
{
    dp = vector<vector<int>> (N + 1, vector<int> (N + 1, -1));
    cout << "minimo costo de vara de 10 con cortes en 2, 4, 7 es: " << minCosto(0,10) << endl;
    return 0;
}



















/*
cortar una vara de madera en varios lugares predeterminados.

costo de realizar un corte en una madera de longitud ℓ es ℓ (luego de realizar ese corte quedarán 2 varas de longitudes que sumarán ℓ)

Ejemplo:
    vara de longitud 10
    debe ser cortada a los 2, 4, 7 metros desde un extremo

    se pueden realizar de las siguientes formas:
    
    (1)
        1. cortar en la pos 2 => costo 10 | trozos [1,2] (<- DONE) [3,4,5,6,7,8,9,10]
        2. cortar en la pos 4 => costo 8  | trozos [1,2] (<- DONE) [3,4] (<- DONE) [5,6,7,8,9,10]
        3. cortar en la pos 7 => costo 6  | trozos [1,2] (<- DONE) [3,4] (<- DONE) [5,6,7] (<- DONE) [8,9,10] (<- DONE)
        Costo total = 10 + 8 + 6 = 24
    
    (2)
        1. cortar en la pos 4 => costo 10 | trozos [1,2,3,4] [5,6,7,8,9,10]
        2. cortar en la pos 2 => costo 4  | trozos [1,2] (<- DONE) [3,4] (<- DONE) [5,6,7,8,9,10]
        3. cortar en la pos 7 => costo 6  | trozos [1,2] (<- DONE) [3,4] (<- DONE) [5,6,7] (<- DONE) [8,9,10] (<- DONE)
        Costo total = 10 + 4 + 6

Quiero encontrar el minimo costo posible de cortar una vara de longitud ℓ
=> PROBLEMA DE OPTIMIZACIÓN

Veo con ejemplo:
    vara de longitud 5 -> 1, 3, 4
    [1,2,3,4,5] 3    ct = 5
    [1,2,3] [4,5] 4  ct = 5 + 2
    [1,2,3] [4,5] 1  ct = 5 + 2 + 3
    [1] [2,3] [4,5]  ct = 5 + 2 + 3

    (i == 1 - 1) => Quiero cortar? Si => costoTotal += l y longitud = l - i + 1
                                   No => costoTotal = costoTotal y longitud = longitud
                                   i++

min => +inf
*/
