import numpy as np

def potencia(A, n):
    result = np.eye(4, dtype=A.dtype)
    while k > 0:
        if k % 2 == 1:
            result = result @ A
        A = A @ A
        k = k // 2
    return result
    
    return result

def PotenciaSum(A, n):
    if n == 1:
        return A.copy()
    else:
        m = n // 2
        S_m = PotenciaSum(A, m) 
        A_m = potencia(A, m)
        return S_m + np.dot(A_m, S_m)