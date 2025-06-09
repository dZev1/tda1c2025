# Demo permutaciones

```(Python)
def permutations(arr, path=[]):
    if len(path) == len(arr):
        print(path)
        return
    for num in arr:
        if num not in path:
            permutations(arr, path + [num])
```

- Demostrar correctitud del algoritmo.

## SOLUCION

Caso base:
    `if len(path) == len(arr): print(path)` lo cual es correcto, pues se llegó a una permutación de `arr` pasando todos los elementos del array `arr` a `path`.

Paso inductivo:
    Nuestra HI es que el algoritmo es correcto hasta un num en `arr < len(arr)`. Es decir, se forma una permutación de arr hasta el i-ésimo numero que contiene
Queremos probar que mantiene su correctitud al avanzar al siguiente numero en `arr`. Es decir, el `i + 1`-ésimo elemento.

El siguiente numero al avanzar de numero en arr, por el for, se evaluará si este pertenece o no a la permutación armada hasta el anterior número.
En caso de que no pertenezca, se agregará el número a la permutación armada hasta el momento, la cual sabemos que es una permutación válida de arr[:i], es decir de los anteriores i elementos de arr, por HI. Entonces agregar este elemento a la permutación armada, sigue manteniendo una permutación válida pero ahora de arr[:i+1].
En caso de que ya pertenezca, la permutación se mantendrá igual a la permutación anterior, la cual sabemos que es válida por HI.
Demostrando así que se mantiene la correctitud del algoritmo en ambos casos posibles.

Por lo tanto, como el caso base, y el paso inductivo son correctos, entonces el algoritmo es correcto.
