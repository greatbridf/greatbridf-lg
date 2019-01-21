#include <iostream>

using namespace std;

const int am[] = {100, 50, 20, 10, 5, 1};

int change(int& n, int i) {
	if (n == 0) return 0;
	if (i == 5) return n;
	int tmp = n / am[i];
	n -= (tmp * am[i]);
	return tmp + change(n, ++i);
}

int main() {
	int n;
	cin >> n;
	cout << change(n, 0);
	return 0;
}
