#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	vector<string> solutions;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 9; ++j) {
			for (int k = 1; k <= 9; ++k) {
				int num = 100*i+10*j+k;
				int two_times = 2 * num;
				int three_times = 3 * num;
				string arr = to_string(num).append(to_string(two_times).append(to_string(three_times)));
				sort(arr.begin(), arr.end());
				if (arr.size() != 9) goto END;
				for (int a = 1; a < arr.size(); ++a) {
					if (arr[a-1] != a+48)
						goto END;
				}
				solutions.push_back(to_string(num) + " " + to_string(two_times) + " " + to_string(three_times));
				END:
					;
			}
		}
	}
	for (auto solution : solutions) {
		cout << solution << endl;
	}
	return 0;
}
