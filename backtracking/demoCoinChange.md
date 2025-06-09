# Demo Coin Change

```(Python)
def cambio(monedas: list[int], C: int) -> int:
    if C == 0: return 0
    if C < 0: return inf
    min_monedas = inf
    for m in monedas:
        res = cambio(monedas, C - m)
        if res + 1 < min_monedas:
            min_monedas = res + 1
    return min_monedas
```

- Demuestra por inducción que el  algoritmo `cambio` encuentra correctamente el número mínimo de monedas necesarias para dar un cambio C.

CASOS BASE:
    `if C == 0: return 0`. Tiene sentido, pues no hace falta agregar más monedas. Llegamos al cambio que queríamos.
    `C < 0: return inf`. Tiene sentido, pues la combinación de monedas elegidas nunca podrá dar el cambio justo, sino que se pasa.

PASO INDUCTIVO:
Nuestra hipotesis inductiva es que el algoritmo es correcto para todos los 0 <= k < |monedas|, tal que:
    - retorna 0 si se pudo llegar al cambio justo usando las monedas de 0 a k.
    - retorna infinito si nos pasamos usando ese mismo conjunto de monedas.

Quiero ver si el algoritmo es correcto usando k + 1 monedas.

```
min_monedas = inf
for m in monedas:
    res = cambio(monedas, C - m)
    if res + 1 < min_monedas:
        min_monedas = res + 1
return min_monedas
```

Sabemos que en las primeras k iteraciones del for, el algoritmo funcionará correctamente. Pues por HI es correcto y `min_monedas = M`, M = minimo de monedas necesarias para llegar al cambio C entre las k monedas.
En la iteración k + 1, se evaluará si se puede llegar al cambio C - (k + 1) lo cual se divide en dos casos:
    1. Si C - (k + 1) es exactamente 0, entonces se evaluará si obtener el cambio con k + 1 monedas se puede hacer con menos monedas que antes. En caso de que esto suceda, este será el resultado.
    2. Si C - (k + 1) < 0, entonces no se puede obtener el cambio usando (k + 1) monedas, por lo tanto la forma de llegar al cambio será la misma que M. Lo cual es correcto por HI.
De ambas maneras, llegaremos al minimo de monedas necesarias para dar un cambio C con k+1 monedas.
Por lo tanto, como valen tanto casos base, como el paso inductivo, entonces el algoritmo es correcto.
