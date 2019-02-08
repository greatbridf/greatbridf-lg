/*
乘船问题
有n个人，第i个人重量为w[i]。每艘船的最大载重量均为C，且最多只能乘两个人。请问如何用最少的船装载所有人。

Input
输入有多组数据。每组数据第一行输入两个整数n和C，表示有n个人，每艘船最大载重量为C，第二行输入n个整数w[i]，表示每个人的重量。所有数据均在[1, 400]内，对于所有的w[i]，都有w[i] <= C。

Output
对应每组数据，输出一个整数，表示装载所有人用的最少船数。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, max;
	while (cin >> n >> max) {
		int* arr = new int[n];
		for (int i = 0; i < n; ++i)
			scanf("%d", arr+i);
		sort(arr, arr+n);		// 40 50 90
		int* left = arr, *right = &arr[n-1];
		int count = 0;
		while (left <= right) {
			if (left == right) {
				++count;
				break;
			}
			if (*left + *right > max) {
				--right;
				++count;
			}
			if (*left + *right <= max) {
				++left;
				--right;
				++count;
			}
		}
		cout << count << endl;
		delete [] arr;
	}
	return 0;
}

