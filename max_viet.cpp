#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;

int T,A[MAX],N,C;


void solve(){
    cin >> T;
    while(T--){
        cin >> N >> C;

        for(int i=0;i<N;i++) cin >> A[i];
        sort(A,A+N);
        int min_ = 1,max_ = A[N-1]-A[0],res;


        while(min_ <= max_){
            bool d = false;
            int mid =(min_+max_)/2;
            int cnt = 1,tmp = A[0];
            for(int i=1;i<N;i++){
                if(A[i] - tmp >= mid){
                    cnt++;
                    tmp = A[i];
                }
                if(cnt >= C){
                    d = true;
                    break;
                }
            }
            if(d){
                min_ = mid+1;
                res = mid;
            }
            else max_ = mid-1;
        }
        cout << res << endl;
    }
}

int main(){

    solve();
}