#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[20000];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int nCow, nShelfHeight;
    cin >> nCow >> nShelfHeight;
    for (int i = 0; i < nCow; ++i) {
        scanf("%d", arr+i);
    }
    sort(arr, arr+nCow, cmp);
    int nHeight = 0, result = 0;
    for (int i = 0; nHeight < nShelfHeight; ++i, ++result) {
        nHeight += arr[i];
    }
    cout << result;
    return 0;
}
