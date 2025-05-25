#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Tenemos dos conjuntos de personas y para cada persona sabemos su habilidad de baile. Queremos
armar la máxima cantidad de parejas de baile, sabiendo que para cada pareja debemos elegir
exactamente una persona de cada conjunto de modo que la diferencia de habilidad sea menor o
igual a 1 (en módulo). Además, cada persona puede pertenecer a lo sumo a una pareja de baile.
Por ejemplo, si tenemos un multiconjunto con habilidades {1, 2, 4, 6} y otro con {1, 5, 5, 7, 9}, la
máxima cantidad de parejas es 3. Si los multiconjuntos de habilidades son {1, 1, 1, 1, 1} y {1, 2, 3},
la máxima cantidad es 2.
*/
int cantParejas(vector<int>& A, vector<int>& B);

int main()
{
    vector<int> A = {1, 1, 1, 1, 1};
    vector<int> B = {1, 2, 3};
    cout << "Hay " << cantParejas(A,B) << " soluciones" << endl;
}

int cantParejas(vector<int>& A, vector<int>& B) {
    int sol = 0;
    int i = 0, j = 0;
    int n = A.size(), m = B.size();

    while (i < n && j < m) {
        if (abs(A[i] - B[j]) <= 1) {
            sol++;
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    } // O(max (n, m))

    return sol;
}

/*
Para demostrar que este algoritmo es correcto...
Sean G y O dos soluciones al problema, siendo O una solución óptima al problema y G la solución del algoritmo greedy.
Entonces lo que quiero demostrar es que G es igual a O o A es mejor que O. Lo que llevaría a un absurdo.

Veamos las estructuras de cada una de las soluciones

  * G toma parejas (A_i, B_j) con 0 <= i <= N, 0 <= j <= M, |G| = K
  * O toma parejas (A_n, B_m) con 0 <= n <= N, 0 <= m <= M, |O| = L

q.p.q K = L

Para ello suponemos que K < L, es decir, existen soluciones mejores que G.
Construimos una solución óptima O', modificando O para que coincida al menos con el primer par de G, sin reducir su calidad.

Sea (A_i, B_j) la primera pareja que el algoritmo greedy selecciona. Porque A y B están ordenados, el algoritmo selecciona el primer par válido
(por menor valor posible).

Como O es una solución óptima != G, es posible que (A_i, B_j) \notIn O.

Como O tiene más parejas que G pero no usa (a_i, b_j) entonces podemos modificar O.
Si a_i y b_j no están emparejados en O, pero están disponibles, reemplazamos una pareja de O que usa a a_i o a b_j, o ninguna y mantener la cantidad de parejas o
mejorar el orden de emparejamiento.
Como |a_i - b_j| <= 1, emparejarlos no empeora la solucion.

Con esto, construimos O' t.q O' Contiene (a_i, b_j), |O'| == |O|
O' == G en al menos una pareja más.
Repetimos para cada pareja de G, mostrando que se puede modificar O para parecerse a G sin perder optimalidad.

Por inducción, podemos transformar O en G sin reducir la cantidad de parejas (K == L), por lo tanto, llegamos a que G es óptima. ¡ABSURDO!

El absurdo vino de suponer que G no era solución óptima. Por lo tanto el algoritmo greedy siempre da una solución óptima. 
*/