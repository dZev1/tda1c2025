#include <iostream>
#include <vector>

using namespace std;

int RES;
const int n = 3;
int cuadrado[n][n] = {};
int numDisponibles[n * n] = {};




void MagiCuadrados(int cuadrado[n][n], int i, int j, int numMagico)
{
    int sumaFParcial = 0;
    for (int k = i; k < n; k++)
    {
        int sumaFila = 0;
        for (int l = 0; l < n; l++) {
            sumaFila += cuadrado[k][l];
        }
        if (numMagico == -1)
        {
            numMagico = sumaFila;
        }
        if (sumaFila != numMagico)
        {
            return;
        }
        cout << "la suma es " << numMagico << endl;
    }

}

int main()
{
    for (int i = 1; i < (n * n) + 1; ++i)
    {
        numDisponibles[i - 1] = i;
    }
    for (int elem : numDisponibles)
    {
        cout << elem << " ";
    }
    MagiCuadrados(cuadrado, 0, 0, -1);
    return 0;
}
