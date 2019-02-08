/*
ȡ������

��֪n��1<=n<=20��������x1,x2,��,xn��1<=xi<=500�����Լ�һ������k��k<n������n����������ѡk��������ӣ��ɷֱ�õ�һϵ�еĺ͡����ڣ�Ҫ����������Ϊ�������ж����֡����統 n=3��k��2
3�������ֱ�Ϊ 1��2��3ʱ���ɵ�ȫ������������ǵĺ�Ϊ��1+2=3,1+3=4,2+3=5
���ڣ�Ҫ����������Ϊ�������ж����֡�
������������2�ֵĺ�Ϊ������1+2=3,2+3=5

Input
�����У�
��һ�У�n��k ��1<=n<=20��k��n�����ÿո�ָ���
�ڶ��У�x1,x2����,xn ��1<=xi<=500��

Output
һ�������������������������� 

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;

int n, k;
long long ans = 0;

int arr[20];
bool vis[20];
int tmp[20];

bool is_prime(int a) {
	if (a == 1) return false;
	for (int i = 2; i <= sqrt(a); ++i) {
		if (a%i == 0) return false;
	}
	return true;
}

void dfs(int s) {
	if (s == k) {
		int sum = tmp[0], min = tmp[0];
		for (int i = 1; i < k; ++i) {
			if (min > tmp[i]) return;
			min = tmp[i];
			sum += tmp[i];
		}
		if (is_prime(sum))
			++ans;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i] /*&& (s == 0 || (s != 0 && (tmp[s] < arr[i])))*/) {
			tmp[s] = arr[i];
			vis[i] = true;
			dfs(s+1);
			vis[i] = false;
			tmp[s] = 0;
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		scanf("%d", arr+i);
	dfs(0);
	cout << ans << endl;
	return 0;
}

