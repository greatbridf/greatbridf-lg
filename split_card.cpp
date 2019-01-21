#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	int sum = 0, avg;
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr+i);
		sum += arr[i];
	}
	avg = sum / n;
	int result = 0;
	for (int i = 0; i < n; ++i)
		arr[i] -= avg;
	for (int i = 0; i < n-1; ++i) {
		if (arr[i] == 0) continue;
		arr[i+1] += arr[i];
		arr[i] -= arr[i];
		++result;
	}
	cout << result;
	return 0;
}
