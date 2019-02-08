/*
�˴�����
��n���ˣ���i��������Ϊw[i]��ÿ�Ҵ��������������ΪC�������ֻ�ܳ������ˡ�������������ٵĴ�װ�������ˡ�

Input
�����ж������ݡ�ÿ�����ݵ�һ��������������n��C����ʾ��n���ˣ�ÿ�Ҵ����������ΪC���ڶ�������n������w[i]����ʾÿ���˵��������������ݾ���[1, 400]�ڣ��������е�w[i]������w[i] <= C��

Output
��Ӧÿ�����ݣ����һ����������ʾװ���������õ����ٴ�����
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

