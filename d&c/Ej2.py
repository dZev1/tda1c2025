def IndiceEspejo(A, l,r):
    if l > r: return None
    m = (l + r) // 2
    if A[m] == m + 1:
        return m + 1
    elif A[m] > m:
        return IndiceEspejo(A, l, m - 1)
    else:
        return IndiceEspejo(A, m + 1, r)

# T(n) = T(n/2) + O(1)

# k = log_2(1) = 0
# f(n) = O(n^0) = O(1) => T(n) = O(n^0 * log n) = O(log n)
# O == \Theta

if __name__ == "__main__":
    A = [1,2,5,9,7]
    res = IndiceEspejo(A, 0, len(A) - 1)
    if res == None:
        print("No hay")
    else:
        print("Hay y es", res)