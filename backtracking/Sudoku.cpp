// sudoku 4 x 4 backtrack
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int n = 4;
int sudoku[n][n] = {
    {0,1,0,0},
    {3,0,0,4},
    {0,4,0,0},
    {0,0,0,0}
};

bool esValido(int fila, int col, int num) {
    // Verificar fila
    for (int i = 0; i < n; i++) {
        if (sudoku[fila][i] == num) return false;
    }

    // Verificar columna
    for (int i = 0; i < n; i++) {
        if (sudoku[i][col] == num) return false;
    }

    // Verificar subcuadro de 2 x 2
    int subcuadroFila = fila / 2 * 2;
    int subcuadroCol = col / 2 * 2;
    for (int i = subcuadroFila; i < subcuadroFila + 2; i++) {
        for (int j = subcuadroCol; j < subcuadroCol + 2; j++) {
            if (sudoku[i][j] == num) return false;
        }
    }
    return true;
}

bool tieneSolucion(int fila, int col) {
    if (fila == n)
    {
        return true;
    }
    if (col == n)
    {
        return tieneSolucion(fila + 1, 0);
    }
    if (sudoku[fila][col] != 0) {
        return tieneSolucion(fila, col + 1);
    }
    for (int num = 1; num <= 4; num++)
    {
        if (esValido(fila, col, num))
        {
            sudoku[fila][col] = num;
            if (tieneSolucion(fila, col + 1))
            {
                return true;
            }
            sudoku[fila][col] = 0;
        }
    }
    return false;
}

int main()
{
    bool a = tieneSolucion(0, 0);
    cout << "La solucion es: " << endl;
    if (a) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No hay solucion" << endl;
    }
    return 0;
}
