/*
��kС����
����n����������n��10000��Ҫ�����n���������еĵ�k����С��������ͬ��С������ֻ����һ�Σ���k��1000����������С��30000��

Input
��һ��Ϊn��k; �ڶ��п�ʼΪn����������ֵ���������ÿո������


Output
��k����С������ֵ�����޽⣬�������NO RESULT����

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

