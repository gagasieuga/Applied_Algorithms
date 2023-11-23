#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int n, test, C;

int merge(int arr[], int l, int m, int r) {
    int subArr1 = m - l + 1;
    int subArr2 = r - m;
    int L[subArr1], R[subArr2];
    for (int i = 0; i < subArr1; i++) {
        L[i] = arr[l+i];
    }
    for (int i = 0; i < subArr2; i++) {
        R[i] = arr[m+1+i];
    }
    int i = 0, j = 0; // index of subArr1 and subArr2
    int k = l; // index of arr
    while (i < subArr1 && j < subArr2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < subArr1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (i < subArr2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void input () {
    cin >> n >> C;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int max_distance_sub_seq() {
    
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    mergeSort(arr, 0, n-1);
    return 0;
}