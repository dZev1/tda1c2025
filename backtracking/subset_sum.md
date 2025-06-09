# DEMO

```(Python)
def subset_sum(nums: list[int], T: int, index: int = 0) -> bool:
    if T == 0: return True
    if index == len(nums): return False
    return subset_sum(nums, T, index + 1) or subset_sum(nums, T - nums[index], index + 1)
```

- Demostrar que el algoritmo es correcto.

Usamos inducción sobre el indice.

Casos Base:
    1) `if T == 0: return True` -> esto vale pues llegamos a nuestro target con nuestro Array de numeros.
    2) `if index == len(nums): return False` -> como no entró al `if T ==0: return True` y recorrimos completamente nuestro array de números, entonces el mismo no nos permitió llegar al resultado esperado.
Paso Inductivo:
HI) El algoritmo funciona correctamente para todos los `0 < index <= len(nums)`, es decir, devuelve si el array nums alcanza para satisfacer la suma que de T o no.

q.v.q. el algoritmo es correcto si comienza desde index = 0.

El algoritmo entra a `return subset_sum(nums, T, 0 + 1) or subset_sum(nums, T - nums[index], 0 + 1)`, que sabemos que subset_sum(n,T,i) vale para todo i > 0. Por lo tanto, la respuesta que nos dará será si vale `subset_sum(nums, T, 1)`, lo cual sabemos que se calcula correctamente por nuestra HI, o si vale `subset_sum(nums, T - nums[0], 0 + 1)`, que también sabemos que vale o no vale por nuestra HI.
Luego, si alguna de las dos opciones llega a True, subset_sum(nums, T, 0) == True, lo cual es cierto, pues se encontró un subconjunto de elementos de nums tal que sumen T. Si da false, significa que no se encontró ninguna forma de obtener un subconjunto de nums tal que sume T.
Por lo tanto el algoritmo funciona correctamente.
