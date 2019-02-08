/*
取球问题
有一个袋子里有无数个红球和蓝球，玩家需要选取n个小球，但是不能连续选取两个红球，而且需要考虑选取顺序：红蓝和蓝红是两种不同情况。问：有多少种不同的选取方法？
 

Input
一行，整数n，表示n个小球。

Output
一行，一个整数，表示选取方法的数量。 
*/
#include <iostream>
#include <memory.h>

using namespace std;

int n;
int* ans;
long long count = 0;

void dfs(int a) {
	if (a == n) {
		++count;
		return;
	}
	for (int i = 1; i <= 2; ++i) {		// RED: 1 BLUE: 2
		if (a == 0 || i == 2 || (i == 1 && ans[a-1] != 1)) {
			ans[a] = i;
			dfs(a+1);
		}
	}
	return;
}

int main() {
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	ans = new int[n];
	memset(ans, 0x00, sizeof(int)*n);
	dfs(0);
	cout << count;
	delete [] ans;
	return 0;
}

