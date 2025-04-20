#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;
map<pair<int, int>,int> memo;

pair<int,int> ccBT(vector<int> B, int c, int i) {
    if (i == B.size()) {
        int res = c >= 0 ? c : INT_MAX;
        return {res, 0};
    }

    pair<int,int> noUsando = ccBT(B, c, i + 1);
    pair<int,int> usando = ccBT(B, c - B[i], i + 1);
    usando.second++;
    
    if (noUsando.first < usando.first) return noUsando;
    else if (usando.first < noUsando.first) return usando;
    else return (noUsando.second < usando.second) ? noUsando : usando;
}

int ccTD(vector<int> B, int c, int i) {
    if (memo.find({c,i}) != memo.end()) {
        return memo[{c, i}];
    }
    if (i >= B.size()) {
        int res = c >= 0 ? c : INT_MAX;
        memo[{c,i}] = res;
        return res;
    }
    memo[{c,i}] = min(ccTD(B, c, i + 1), ccTD(B, c - B[i], i + 1));
    return memo[{c,i}];
}

int main() {
    vector<int> B = { 2, 3, 5, 10, 20, 20 };
    int c = 14;

    pair<int,int> sol = ccBT(B, c, 0);

    cout << "Quedan de excedentes: $" << sol.first << " con cantidad de billetes: " << sol.second << endl;
}

