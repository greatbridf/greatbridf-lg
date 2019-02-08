/*
取数问题

已知n（1<=n<=20）个整数x1,x2,…,xn（1<=xi<=500），以及一个整数k（k<n）。从n个整数中任选k个整数相加，可分别得到一系列的和。现在，要求你计算出和为素数共有多少种。例如当 n=3，k＝2
3个整数分别为 1，2，3时，可得全部的组合与它们的和为：1+2=3,1+3=4,2+3=5
现在，要求你计算出和为素数共有多少种。
例如上例，有2种的和为素数：1+2=3,2+3=5

Input
分两行，
第一行，n和k （1<=n<=20，k＜n），用空格分隔。
第二行，x1,x2，…,xn （1<=xi<=500）

Output
一个整数（满足条件的种数）。 

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

