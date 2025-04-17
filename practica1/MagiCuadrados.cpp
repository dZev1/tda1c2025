#include <iostream>
#include <vector>

using namespace std;

int RES;
const int n = 3;
int cuadrado[n][n] = {};
int numDisponibles[n * n] = {};


bool esMagico(const int cuadrado[n][n]) {
    int sumaMagica = n * (n * n + 1) / 2;

    // Verificar filas
    for (int i = 0; i < n; ++i) {
        int sumaFila = 0;
        for (int j = 0; j < n; ++j) {
            sumaFila += cuadrado[i][j];
        }
        if (sumaFila != sumaMagica) return false;
    }

    // Verificar columnas
    for (int j = 0; j < n; ++j) {
        int sumaColumna = 0;
        for (int i = 0; i < n; ++i) {
            sumaColumna += cuadrado[i][j];
        }
        if (sumaColumna != sumaMagica) return false;
    }

    // Verificar diagonales
    int sumaDiagonal1 = 0, sumaDiagonal2 = 0;
    for (int i = 0; i < n; ++i) {
        sumaDiagonal1 += cuadrado[i][i];
        sumaDiagonal2 += cuadrado[i][n - i - 1];
    }
    if (sumaDiagonal1 != sumaMagica || sumaDiagonal2 != sumaMagica) return false;

    return true;
}

void MagiCuadrados(int cuadrado[n][n], int fila, int col, int usados) {
    if (fila == n) {
        if (esMagico(cuadrado)) {
            ++RES;
        }
        return;
    }

    int siguienteFila = (col == n - 1) ? fila + 1 : fila;
    int siguienteCol = (col == n - 1) ? 0 : col + 1;

    for (int i = 0; i < n * n; ++i) {
        if (!(usados & (1 << i))) {
            cuadrado[fila][col] = numDisponibles[i];
            MagiCuadrados(cuadrado, siguienteFila, siguienteCol, usados | (1 << i));
            cuadrado[fila][col] = 0;
        }
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
