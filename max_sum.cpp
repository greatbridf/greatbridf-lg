#include <iostream>

using namespace std;

int main() {
	int line, col;
	cin >> line >> col;
	int result = 0;
	while (line--) {
		int max;
		cin >> max;
		for (int i = 0; i < col-1; ++i) {
			int tmp;
			cin >> tmp;
			if (tmp > max) max = tmp;
		}
		result += max;
	}
	cout << result;
	return 0;
}
