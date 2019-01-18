#include <iostream>
#include <memory.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool* arr = new bool[n];
	memset(arr, 0x00, sizeof(bool));
	int cur = 0, count = 0, out = 0;
	do {
		if (!arr[cur]) ++count;
		if (count == m) {
			arr[cur] = true;
			cout << cur+1 << " ";
			count = 0;
			++out;
			continue;
		}
		++cur;
		if (cur == n) cur = 0;
	} while (out != n);
	return 0;
}
