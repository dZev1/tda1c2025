# Demo LCS

```(Python)
def lcs(X: str, Y: str, m: int, n: int) -> int:
    if m == 0 or n == 0: return 0
    if X[m-1] == Y[n-1]:
        return 1 + lcs(X, Y, m-1, n-1)
    else:
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n))
```

- Demuestra por inducción que el siguiente algoritmo recursivo encuentra correctamente la longitud de la subsecuencia común más larga entre dos cadenas:

CASOS BASE:
`if m == 0 or n == 0: return 0`
Si m == 0 O n == 0, devuelve 0 pues llegamos al final de la cadena m o de la cadena n, y por lo tanto no podemos comparar más sus elementos.
PASO INDUCTIVO:
Nuestra Hipótesis inductiva es que el algoritmo funciona correctamente para los k o h elementos correspondientes a X e Y con $0 < k \leq m$ y $0 < h \leq n$, es decir, devuelve la longitud de la subcadena común más larga entre ambas cadenas.

q.p.q el algoritmo es correcto para k - 1 o h - 1.

```(Python)
    if X[m-1] == Y[n-1]:
        return 1 + lcs(X, Y, m-1, n-1)
    else:
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n))
```

Si k - 1 o h - 1 son iguales a 0, entonces se llega al caso base `if m == 0 or n == 0: return 0` y el resultado será el obtenido hasta el paso anterior el cual será correcto por HI.

Si k - 1 y h - 1 son distintos a 0, pero se cumple `X[m-1] == Y[n - 1]`, entonces se suma 1 al resultado de obtener la longitud de la cadena más larga hasta k y h, lo cual es correcto por HI.

Por último si son distinto `X[m - 1] y Y[n - 1]`, entonces buscaremos la próxima cadena en común más larga, ya sea decrementado el indice de Y o el indice de X, hasta encontrarla, y luego calcularemos sus lcs para luego retornar de ellas cuál es la mayor cadena, lo cual es correcto por HI ya que el algoritmo calcula correctamente para situaciones donde k == m o h == n.
Si no tienen ninguna en común, se devolverá 0. Lo cual es correcto, pues la longitud de la cadena más comun es igual a la longitud de una cadena vacía, la cual es 0.

Por lo tanto, como el algoritmo es correcto para los casos base, y también lo es para el paso inductivo, entonces el algoritmo es correcto y devuelve la longitud de la cadena en común más larga entre dos cadenas.
