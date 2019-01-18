#include <iostream>
#include <stringstream>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	char cx = x+48;
	long result = 0;
	stringstream ss();
	for (int i = 1; i <= n; ++i) {
		ss << i;
	}
	for (char one : ss)
	cout << result;
	return 0;
}
