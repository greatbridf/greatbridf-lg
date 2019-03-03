#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int arr[20] = {};

int result = 0, k = 0;

bool isPrime(int n) {
  if (n < 2) return false;
  int s = sqrt(n);
  for (int i = 2; i <= s; ++i)
    if (n % i == 0) return false;
  return true;
}

void sel(int index, int sum) {
  if (k == 0) {
    if (isPrime(sum)) ++result;
    return;
  }
  if (index == -1) return;
  --k;
  sel(index-1, sum+arr[index]);
  ++k;
  sel(index-1, sum);
}

int main() {
  int a;
  cin >> a >> k;
  for (int i = 0; i < a; ++i) {
    scanf("%d", arr+i);
  }
  sel(a-1, 0);
  cout << result;
  return 0;
}
