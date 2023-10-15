#include  <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int arr[MAXN];
int M[30][MAXN];
int m, n;

void precompute() {
    //initialize array data
    for(int i = 0; i < n; i++){
        M[0][i] = arr[i];
    }

    for (int j = 1; (1<<j) <= n; j++){
        for (int i = 0; i + (1 << j) - 1 <=  n; i++){
            M[j][i] = min(M[j-1][i], 
                          M[j-1][i + (1 << (j - 1) )]); //min of M[j][i] and M[j][i+(2^(j-1))]
        }
    }

}

int rmq(int i, int j){
    int k = log2(j - i + 1); //VD từ i -> j có 9 phần tử thì log2(9) sẽ ra 3
    return min(M[k][i], M[k][j - (1 << k) + 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 0;
    int startIndex, endIndex;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    precompute();
    cout << "Nhap so cap phan tu can tinh tong:" << endl;
    cin >> m;
    for (int i = 0; i < m; i++){
        cout << "Nhap cap phan tu thu " << i+1 << endl;
        cin >> startIndex >> endIndex;

        if (startIndex > endIndex || startIndex < 0 || endIndex >= n){
            cout << "Khong hop le" << endl;
            return 0;
        } 
        
        sum += rmq(startIndex, endIndex);
        cout << sum << endl;
    }
    cout << "Tong la " << sum << endl;
}