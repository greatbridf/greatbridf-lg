#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[30000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d", arr+i);
    sort(arr, arr+n);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
    	int tmp = 0;
    	scanf("%d", &tmp);
    	printf("%d\n", arr[tmp-1]);
    }
    return 0;
}
