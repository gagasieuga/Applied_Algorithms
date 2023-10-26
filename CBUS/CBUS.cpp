#include <bits/stdc++.h>
using namespace std;

int cost[1000][1000];
int n, max_load; //n vua la so khach, 2n vua la size matrix, omg
int load = 0;
int x[1000];
bool visited[1000];
int cur_cost = 0, opt_cost = INT_MAX, cmin = INT_MAX;

bool is_cand(int i){
    if (visited[i]) return false;
    if (i > n) return visited[i-n];
    return (load < max_load);
}

void TRY(int c){
    for(int i = 1; i <= 2*n; i++){
        if (is_cand(i)){
            x[c] = i;
            visited[i] = true;
            if (i <= n){
                load += 1;
            }
            else {
                load -= 1;
            }
            cur_cost += cost[x[c-1]][i]; //cost of going from previous city to current city
            
            //if all cities have been visited, check if this is a better tour
            if (c == 2*n){
                if (cur_cost + cost[i][0] < opt_cost){
                    opt_cost = cur_cost + cost[i][0];
                }
            }
            else {
                if (cur_cost + (2*n - c + 1) * cmin < opt_cost && load <= max_load) {
                    TRY(c+1);
                }
            }
            //backtrack 
            if (i <= n){
                load -= 1;
            }
            else {
                load += 1;
            }
            visited[i] = false;
            cur_cost -= cost[x[c-1]][i];
        }
    }
}

int main (){
    cin >> n >> max_load;
    for (int i = 0; i <= 2*n; i++){
        for (int j = 0; j <= 2*n; j++){
            cin >> cost[i][j];
            if (i != j) {
                cmin = min(cmin, cost[i][j]);
            }
        }
    }
    x[1] = 0;
    visited[0] = true;
    TRY(1);
    cout << opt_cost << endl;
    return 0;
}
