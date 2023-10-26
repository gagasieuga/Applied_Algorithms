#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int n, cur_cost = 0, opt_cost = INT_MAX, cmin = INT_MAX;
int C[MAXN][MAXN]; // Cost matrix
int x[MAXN], x_opt[MAXN];
bool visited[MAXN];

void TRY(int k) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            x[k] = i;
            visited[i] = true;
            cur_cost += C[x[k - 1]][i]; // Add the cost of going from the previous city to the current city

            if (k == n) {
                // If all cities have been visited, check if this is a better tour
                if (cur_cost + C[i][1] < opt_cost) {
                    opt_cost = cur_cost + C[i][1];
                    for (int j = 1; j <= n; j++) {
                        x_opt[j] = x[j];
                    }
                }
            } else {
                // Prune the search if the current partial tour is worse than the best-known solution
                if (cur_cost + (n - k + 1) * cmin < opt_cost) {
                    TRY(k + 1);
                }
            }

            visited[i] = false; // Backtrack
            cur_cost -= C[x[k - 1]][i];
        }
    }
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> C[i][j];
            if (i != j) {
                cmin = min(cmin, C[i][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    x[1] = 1;
    visited[1] = true;
    TRY(2);
    cout << opt_cost << endl;
    return 0;
}
