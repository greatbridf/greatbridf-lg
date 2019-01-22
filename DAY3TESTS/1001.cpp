#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    if (a%2==1 && b%2==0) return true;
    if (a%2==1 && b%2==1) return a > b;
    if (a%2==0 && b%2==0) return a < b;
    return false;
}

int main() {
    int arr[10];
    for (int i = 0; i < 10; ++i) cin >> arr[i];
    sort(arr, arr+10, cmp);
    for (int i = 0; i < 10; ++i) cout << arr[i] << " ";
    return 0;
}
