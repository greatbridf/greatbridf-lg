#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int limit, n;
    cin >> limit >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr+i);
    }
    sort(arr, arr+n);
    int* left = arr, *right = arr+n-1;
    // [1, 3, 5]
    //  ↑     ↑
    // left right
    int result = 0;
    while (true) {
        if (left > right) break;
        if (left == right) {
            ++result;
            break;
        }
        if (*left + *right > limit) {
            ++result;
            --right;
        } else {
            ++result;
            ++left;
            --right;
        }
    }
    cout << result;
    return 0;
}
