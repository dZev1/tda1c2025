Memo = {}
def cc(M, i, T):
    if T == 0:
        return True
    if T != 0 and i == len(M):
        return False
    if ((i,T) in Memo.keys()):
        return Memo[(i,T)]
    
    res = cc(M, i + 1, T - M[i]) or cc(M, i + 1, T)
    Memo[(i, T)] = res
    return Memo[(i, T)]

if __name__ == "__main__":
    M = [2,2,6,10,8,7,7]
    T = 7
    print(cc(M,0,T))
    