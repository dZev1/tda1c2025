#include <iostream>

using namespace std;

const int N = 3;
const int K = 12;
int Memo[N + 1][K + 1];


bool subsetSumTD(int C[], int i, int j)
{
    if (j < 0) return false;
    if (i < 0) return j == 0;

    if (Memo[i][j] == -1)
    {
        Memo[i][j] = subsetSumTD(C, i - 1, j) || subsetSumTD(C, i - 1, j - C[i]);
    }

    return Memo[i][j];
}

bool subsetSumBU(int C[], int k, bool Memo[N + 1][K + 1])
{
    for (int j = 0; j <= K; j++)
    {
        Memo[0][j] = j == 0;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            Memo[i][j] = Memo[i - 1][j] ||
                         (j - C[i] >= 0 && Memo[i - 1][j - C[i]]);
        }
    }
    return Memo[N][K];
} 


int main()
{
    for (int k = 0; k <= N; k++)
    {
        for (int l = 0; l <= K; l++)
        {
            Memo[k][l] = -1;
        }
    }
    int suma = K;
    int conjunto[N] = { 6, 12, 6 };
    bool M[N+1][K+1];
    bool isSolvable = subsetSumBU(conjunto, suma, M);
    cout << "Hay solucion? " << isSolvable << endl;
}