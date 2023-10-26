#include <bits/stdc++.h> 
using namespace std;

int cnt = 0;
int n, M;
int a[1000];

int solution(int ptr, int M){
    if (M == 0 && ptr < n-1){
        return 0;
    }
    if (ptr == n-1) {
        if (M%a[ptr] == 0 && M != 0) {
            cnt++;
        }
        return 0;
    }
    else {
        // chay gia tri cho bien a[ptr] la Xptr
        for(int i = 1; i <= M/a[ptr]; i++){
            solution(ptr+1, M - i*a[ptr]);
        }
    }
}

int main() 
{ 
    cin >> n >> M;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solution(0, M);
    cout << cnt << endl;
}
