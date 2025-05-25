#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<pair<int, int>, int> memo;

int numeroCombinatorio(int n, int k)
{
    if (k == 0 || k == n)
    {
        if (memo.find({n,k}) == memo.end())
        {
            memo[{n,k}] = 1;
            return 1;
        }
    }
    if (k > 0 && k < n)
    {
        memo[{n,k}] = numeroCombinatorio(n - 1, n - k) + numeroCombinatorio(n - 1, k);
    }
    return memo[{n,k}];
}

int nCrBU(int n, int k)
{
    vector<vector<int>> A(n+1, vector<int>(k+1, 0));
    for (int i = 1; i <= n; ++i)
    {
        A[i][0] = 1;
    }
    for (int j = 0; j <= k; ++j)
    {
        A[j][j] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
        }
    }
    return A[n][k];
}

int main()
{
    int n, k;
    cout << "Ingrese n: ";
    cin >> n;
    cout << "Ingrese k: ";
    cin >> k;
    cout << "El numero combinatorio de " << n << " sobre " << k << " es: " << nCrBU(n, k) << endl;
    return 0;
}
