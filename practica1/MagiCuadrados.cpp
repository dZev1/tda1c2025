#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int RES;
const int n = 3;
int cuadrado[n][n] = {};
vector<int> numDisponibles;

bool esMagico(int cuadrado[n][n])
{
    int sumaDiagonal1 = 0, sumaDiagonal2 = 0;
    for (int i = 0; i < n; ++i)
    {
        sumaDiagonal1 += cuadrado[i][i];
        sumaDiagonal2 += cuadrado[i][n - 1 - i];
    }
    if (sumaDiagonal1 != sumaDiagonal2)
        return false;

    for (int i = 0; i < n; ++i)
    {
        int sumaFila = 0, sumaColumna = 0;
        for (int j = 0; j < n; ++j)
        {
            sumaFila += cuadrado[i][j];
            sumaColumna += cuadrado[j][i];
        }
        if (sumaFila != sumaColumna || sumaFila != sumaDiagonal1)
            return false;
    }
    return true;
}

bool filaValida(int cuadrado[n][n], int i)
{
    vector<bool> numUsados(n + 1, false);
    for (int j = 0; j < n; ++j)
    {
        if (cuadrado[i][j] != 0)
        {
            if (numUsados[cuadrado[i][j]])
                return false;
            numUsados[cuadrado[i][j]] = true;
        }
    }
    return true;
}

bool columnaValida(int cuadrado[n][n], int j)
{
    vector<bool> numUsados(n + 1, false);
    for (int i = 0; i < n; ++i)
    {
        if (cuadrado[i][j] != 0)
        {
            if (numUsados[cuadrado[i][j]])
                return false;
            numUsados[cuadrado[i][j]] = true;
        }
    }
    return true;
}

void MagiCuadrados(int cuadrado[n][n], int i, int j, vector<int> numDisponibles)
{
    if (i == n)
    {
        if (esMagico(cuadrado))
        {
            RES++;
        }
        return;
    }

    for (int k : numDisponibles)
    {
        cuadrado[i][j] = k;
        vector<int> numDisponiblesAux = numDisponibles;
        // Eliminar el número k de la lista de números disponibles
        numDisponiblesAux.erase(remove(numDisponiblesAux.begin(), numDisponiblesAux.end(), k), numDisponiblesAux.end());

        if (filaValida(cuadrado, i) && columnaValida(cuadrado, j))
        {
            if (j == n - 1)
            {
                MagiCuadrados(cuadrado, i + 1, 0, numDisponiblesAux);
            }
            else
            {
                MagiCuadrados(cuadrado, i, j + 1, numDisponiblesAux);
            }
        }
        cuadrado[i][j] = 0;
    }
}

int main()
{
    for (int i = 1; i < (n * n) + 1; ++i)
    {
        numDisponibles.push_back(i);
    }
    for (int elem : numDisponibles)
    {
        cout << elem << " ";
    }
    MagiCuadrados(cuadrado, 0, 0, numDisponibles);
    cout << "Cantidad de cuadrados magicos: " << RES << endl;
    return 0;
}
