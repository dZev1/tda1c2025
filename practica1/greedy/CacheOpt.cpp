#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;
vector<int> R = {1,2,9,4,0,6,6,7,1,0};

int cantMisses(int i, set<int> mem)
{
    if (i == R.size())
    {
        return 0;
    }
    if (mem.find(R[i]) == mem.end())
    {
        return 1 + cantMisses(i + 1, mem);
    }
    return cantMisses(i + 1, mem);
}

int main()
{
    set<int> mem = {1,2,6,9};
    

    cout << cantMisses(0, mem);
    
    return 0;
}


/*
inicio unordered_map<int,fifo<int>> M

for i in range (R.size)
    if C.size < k 
        agrega R[i] a C <- C esta ordenado por proximas apariciones
        M[R[i]] = desencolar()
        continue
    if R[i] in C and M[R[i]].empty()
        C.remove(R[i])
    else
        C.sacarMaximo()
        C.agregar(R[i])
return C

*/ 
