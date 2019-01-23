/*
元素之和
已知n个整数，又已知一整数m。如能使n个整数中任意几个元素之和等于m，则输出YES，否则输出NO。
Input:
三行
第一行，一个整数，表示n。(1<n≤30)
第二行，输入n个整数，用空隔分开。
第三行，一个整数，表示 m。
Output:
E.g.
6
1 3 9 23 16 7
25
YES
*/
#include <iostream>
#include <cstdio>

using namespace std;
int arr[30];

bool sum(int i, int limit) {
  if (arr[i] == limit) return true;
  if (i == 0) return false;
  return sum(i - 1, limit - arr[i]) || sum(i - 1, limit);
}

int main() {
  int n, m;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      scanf("%d", arr+i);
    cin >> m;
    if (sum(n-1, m))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

