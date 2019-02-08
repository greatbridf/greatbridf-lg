/*
ȡ������
��һ������������������������������Ҫѡȡn��С�򣬵��ǲ�������ѡȡ�������򣬶�����Ҫ����ѡȡ˳�򣺺��������������ֲ�ͬ������ʣ��ж����ֲ�ͬ��ѡȡ������
 

Input
һ�У�����n����ʾn��С��

Output
һ�У�һ����������ʾѡȡ������������ 
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

