def IosifStalin(A):
    if len(A) == 1:
        return True
    
    half = len(A) // 2
    
    lSum = sum(A[:half])
    rSum = sum(A[half:])
    
    if lSum <= rSum:
        return False
    
    return IosifStalin(A[:half]) and IosifStalin(A[half:])

if __name__ == "__main__":
    A = [1, 2, 3, 4, 8, 6, 7, 5]
    print(IosifStalin(A))