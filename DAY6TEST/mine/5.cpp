/*
ȡ������

KiKiϲ�����飬�������n���飬KiKi����ȡm���飨���Żأ������ж�����ȡ����

Input
�������룬ÿ������n��m��n��ʾ����ϵ�n���飬m��ʾ����ȡ���鱾�������ÿո�ָ���

Output
���ÿ�����룬���һ����������ʾȡ��������


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

