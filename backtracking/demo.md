# DEMO

```(Python)
def n_reinas(estado: list[list[int]], col: int) -> int:
    if col == N:
        return 1
    total = 0
    for fila in range(N):
        estado[fila][col] = 1
        total += n_reinas(estado, col + 1)
        estado[fila][col] = 0
    return total
```

- Demuestra que la cantidad de estados visitados por `n_reinas` es $Θ(N^N)$.

Cada nivel del arbol crece exponencialmente N veces. Es decir, el primer nivel tiene N^0 estados, el segundo N^1 estados y así crece hasta el último nivel. Donde de cada uno de los N^(N-1) estados se desprenden N^N estados. Esto sucede porque no hay podas, por lo que se explora todo el campo de soluciones, que en este caso, tanto las soluciones parciales como las inválidas y las válidas son estados del árbol de recursión. Luego, lo que representa esto es
 $$ \sum_{i=1}^{N} i^i \in Θ(N^N) $$

```(Python)
def n_reinas_poda(estado: list[list[int]], col: int) -> int:
    if col == N:
        return 1
    total = 0
    for fila in range(N):
        if es_seguro(estado, fila, col):
            estado[fila][col] = 1
            total += n_reinas_poda(estado, col + 1)
            estado[fila][col] = 0
    return total
```

- Demuestra que la cantidad de estados visitados por `n_reinas_poda` es $O(N!)$.

