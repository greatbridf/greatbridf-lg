// http://www.cnblogs.com/antineutrino/p/3334540.html
/*
1. 移动n-1个盘子 A -> C -> B
2. 移动n个盘子 A -> C
3. 移动n-1个盘子 B -> A -> C
*/
#include <iostream>
#include <cstdio>

using namespace std;

long long step = 1;

// n: 第n个盘子（从上至下） a: 原柱子 b: 过程柱子 c: 目标柱子
void hanoi(int n, char a, char b, char c) {
  if (n == 0) return;
  hanoi(n-1, a, c, b);		// 直到最顶端柱子
  printf("STEP%lld-%d:%c-->%c\n", step++, n, a, c);	// A ---C--->B
  hanoi(n-1, b, a, c);		// B ---A--->C
}

int main() {
  int n;
  cin >> n;
  hanoi(n, 'A', 'B', 'C');
  return 0;
}

