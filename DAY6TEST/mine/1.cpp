/*
覆盖点问题
设x1，x2，……，xn 是数轴上的 n (5<=n<=10000)个点。用固定长度 k（1<=k<=1000） 的闭区间覆盖这n个点，求至少需要多少个这样的固定长度闭区间。

Input
第一行两个整数n和k
第二行有n个整数，x1，x2，……，xn，-10000<=xi<=10000

Output
一行一个整数，表示需要区间的个数
*/Input

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int arr[10000] = {};
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr+i);
	}
	sort(arr, arr+n);
	
	int ans = 0;
	int j = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == n || j == n-1) {
			++ans;
			break;
		}
		int tmp = arr[i] - arr[j];
		if (tmp < k) continue;
		if (tmp == k) {
			++ans;
			j = i+1;
			++i;
		}
		if (tmp > k) {
			++ans;
			j = i+1;
		}
	}
	cout << ans;
	return 0;
}
/*
7 3
1 2 3 4 5 -2 6
-2 1 2 3 4 5 6

*/

