/*
取书问题

KiKi喜欢看书，书架上有n本书，KiKi任意取m本书（不放回），求有多少种取法？

Input
多组输入，每行输入n和m，n表示书架上的n本书，m表示任意取的书本数量，用空格分隔。

Output
针对每组输入，输出一个整数，表示取法数量。


*/
#include <iostream>
#include <memory.h>

using namespace std;

bool* vis;
int n, m, count = 0;

void dfs(int s) {
	if (s == m+1) {
		++count;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(s+1);
			vis[i] = false;
		}
	}
	return;
}

int main() {
	while (cin >> n >> m) {
		count = 0;
		vis = new bool[n];
		memset(vis, 0x00, sizeof(bool)*n);
		dfs(1);
		cout << count << endl;
		delete [] vis;
	}
	return 0;
}

