/*
第k小整数
现有n个正整数，n≤10000，要求出这n个正整数中的第k个最小整数（相同大小的整数只计算一次），k≤1000，正整数均小于30000。

Input
第一行为n和k; 第二行开始为n个正整数的值，整数间用空格隔开。


Output
第k个最小整数的值；若无解，则输出“NO RESULT”。

*/
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int arr[10001] = {};
	int srt[30001] = {};
	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		scanf("%d", &tmp);
		srt[tmp] = 1;
	}
	int j = 0;
	for (int i = 1; i <= 30000; ++i) {
		if (srt[i] == 1) {
			arr[j] = i;
			++j;
		}
	}
	if (arr[k-1] == 0) cout << "NO RESULT";
	else cout << arr[k-1];
	return 0;
}

