// http://www.cnblogs.com/antineutrino/p/3334540.html
/*
1. �ƶ�n-1������ A -> C -> B
2. �ƶ�n������ A -> C
3. �ƶ�n-1������ B -> A -> C
*/
#include <iostream>
#include <cstdio>

using namespace std;

long long step = 1;

// n: ��n�����ӣ��������£� a: ԭ���� b: �������� c: Ŀ������ 
void hanoi(int n, char a, char b, char c) {
	if (n == 0) return;
	hanoi(n-1, a, c, b);		// ֱ��������� 
	printf("STEP%lld-%d:%c-->%c\n", step++, n, a, c);	// A ---C--->B
	hanoi(n-1, b, a, c);		// B ---A--->C
}

int main() {
	int n;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	return 0; 
} 
 
