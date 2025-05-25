#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;
const int N = 20;

unordered_map<int, int[N]> dp;

int MGN(int p[N],int c, int j)
{
    if (j == N) return (c == 0) ? 0 : -1e9;
    if (dp[j][c]) return dp[j][c];
    
    int sinComprar = MGN(p, c, j + 1);
    int comprar = (c < N) ? MGN(p, c + 1, j + 1) - p[j] : -1e9;
    int vender = (c > 0) ? MGN(p, c - 1, j + 1) + p[j] : -1e9;

    dp[j][c]= max({sinComprar, comprar, vender}); 
    return dp[j][c];
}

int main()
{
    int p[N] = {3,2,5,6,12,39,1,6,3,3,5,2,5,6,12,39,1,6,3,3};

    cout << "ganancia maxima: " << MGN(p, 0, 0) << endl;
}






















// Sea p ∈ N^n tal que p[i] es el precio de un asteroide el i-ésimo día en una secuencia de n días.

// Quiere comprar y vender asteroides durante esos n dias tal que obtenga el mayor beneficio posible.

// Solo puede:
//  - comprar a lo sumo un asteroide cada día,
//  - puede vender a lo sumo un asteroide cada dia y
//  - comienza sin asteroides. (ganancia 0)

// elecciones: compro, vendo o no hago nada en ese día
// solo puedo comprar si tengo #asteroides >= 1

// PROBLEMA DE OPTIMIZACION => Al final debería no tener ningun asteroide

// por ejemplo si tengo p = [3, 2, 5, 6]
// la mayor ganancia es 6
//  1. compro a 3 -- dia 1
//  2. compro a 2 -- dia 2
//  3. vendo a 5 el asteroide del dia 1 -- dia 3 --> 5 - 3 = 2
//  4. vendo a 6  el asteroide del dia 2 -- dia 4 --> 6 - 2 = 4 

// por ejemplo si tengo p = [3,6,10]
// la mayor ganancia es 7
//  1. compro a 3 dia 1 // comprados = [0]
//  2. no hago nada dia 2
//  3. vendo a 10 el asteroide del dia 1 - dia 3 --> 10 - 3 = 7