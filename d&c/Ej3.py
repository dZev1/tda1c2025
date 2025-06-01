def PotLog(a: int, b: int) -> int:
    if b == 0:
        return 1
    elif b % 2 == 1:
        return a * PotLog(a * a, b // 2)
    else:
        return PotLog(a * a, b // 2)

if __name__ == "__main__":
    print(PotLog(2,3))
    
# T(b) = 1 * T(b/2) + Theta(1)
# k = log_2(1) = 0
# f(n) = Theta(n^k) = Theta(n^0) = Theta(1)
# f(n) = Theta(n^k) => T(n) = Theta(n^k * log^(k + 1) (n)) = Theta(log n)