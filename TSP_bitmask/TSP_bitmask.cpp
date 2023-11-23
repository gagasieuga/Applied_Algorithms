#include <bits/stdc++.h>
#include <algorithm>
#include <cstring> // memset
using namespace std;

const int N = 20;
const int INF = 100000000;
int n;
int C[N][N];
int iMem [N][1<<N];

//bitmask
int TSP(int i, int S) {
    if (S == (1<<n)-1) return C[i][0]; //S = 2^n - 1 where S is the set of visited cities, if S = 2^n - 1, all cities have been visited, return the cost from i to 0
    if (iMem[i][S] != -1) return iMem[i][S]; //if iMem[i][S] has been calculated, return it
    
    int ans = INF; //initialize ans to be INF
    for (int j = 0; j < n; j++){ 
        if (S & (1<<j)) continue; //if j has been visited, continue

        ans = min(ans, TSP(j, S | (1<<j)) + C[i][j]); //update ans, where S | (1<<j) means add city j to S
        iMem[i][S] = ans; //store ans in iMem[i][S]
    }
    return ans; //return ans
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> C[i][j];
        }
    }
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    memset(iMem, -1, sizeof(iMem));
    cout << TSP(0, 1) << endl;
    return 0;
}