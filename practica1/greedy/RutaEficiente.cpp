#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cantParadas(int C, vector<int> KM);

int main()
{
    int C = 50;
    vector<int> KM = {0, 10, 40, 70, 90, 130, 179, 210, 215, 220, 230, 235, 260};
    // 0 + 40 + 90 + 130 + 179 + 210
    cout << cantParadas(C, KM);
    return 0;
}



int cantParadas(int C, vector<int> KM)
{
    int ultimaParada = 0;
    int res = 1;
    for (int i = 1; i < KM.size(); i++) {
        if ((C + ultimaParada) - KM[i] < 0) {
            ultimaParada = KM[i - 1];
            res++;
        }
    }
    return res;
}

