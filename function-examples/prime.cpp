#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int main() {
  int n;
  cin >> n;
  if (isPrime(n))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

bool isPrime(int n) {
  if (n == 1) return false;
  int s = sqrt(n);
  for (int i = 2; i <= s; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

