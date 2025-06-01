def IndiceEspejo(A, l,r):
    if l > r: return None
    m = (l + r) // 2
    if A[m] == m:
        return m
    elif A[m] > m:
        return IndiceEspejo(A, l, m - 1)
    else:
        return IndiceEspejo(A, m + 1, r)

if __name__ == "__main__":
    A = [-4,-1,2,4,7]
    res = IndiceEspejo(A, 0, len(A) - 1)
    if res == None:
        print("No hay")
    else:
        print("Hay y es", res)