/*
���ǵ�����
��x1��x2��������xn �������ϵ� n (5<=n<=10000)���㡣�ù̶����� k��1<=k<=1000�� �ı����串����n���㣬��������Ҫ���ٸ������Ĺ̶����ȱ����䡣

Input
��һ����������n��k
�ڶ�����n��������x1��x2��������xn��-10000<=xi<=10000

Output
һ��һ����������ʾ��Ҫ����ĸ���
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

