#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<int> IActual;
set<int> mejorI;
const int N = 4;
int mejorSuma = 0;
int M[N][N] = { { 0 ,10,10, 1 } ,
                { 10, 0, 5, 2 } ,
                { 10, 5, 0, 1 } ,
                {  1, 2, 1, 0 }  };

void maxiSubconjunto(int M[N][N], int k, int N, set<int>& IActual,
                     int sumaActual,int nextIndex, set<int>& mejorI, int& mejorSuma)
{
    if (IActual.size() == k)
    {
        if (sumaActual > mejorSuma)
        {
            mejorSuma = sumaActual;
            mejorI = IActual;
        }
        return;
    }

    for (int i = nextIndex; i < N; i++)
    {
        int nuevaSuma = sumaActual;
        for (int j : IActual)
        {
            nuevaSuma += M[i][j - 1] + M[j - 1][i];
        }
        IActual.insert(i + 1);
        maxiSubconjunto(M, k, N, IActual, nuevaSuma, i + 1, mejorI, mejorSuma);
        IActual.erase(i + 1);
    }
}

int main()
{
    int k = 3;
    maxiSubconjunto(M, k, N, IActual, 0, 0, mejorI, mejorSuma);
    cout << "El mejor subconjunto es: { ";
    for (int i : mejorI)
    {
        cout << i << " ";
    }
    cout << "}\n";
}