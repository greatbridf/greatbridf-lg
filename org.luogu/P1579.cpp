#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

short primes[20000] = {-1};

bool isPrime(int n) {
  if (primes[n] == -1) {
    int s = sqrt(n);
    for (int i = 2; i <= s; ++i)
      if (n % i == 0) {
        primes[n] = 0;
        return false;
      }
    primes[n] = 1;
    return true;
  } else {
    return primes[n];
  }
}

int main() {
  memset(primes, -1, sizeof(primes));
  int n;
  cin >> n;
  for (int i = 2; i <= n-4; ++i) {
    for (int j = 2; j <= n-4; ++j) {
      int k = n - i - j;
      if (isPrime(i) and isPrime(j) and isPrime(k)) {
        cout << i << ' ' << j << ' ' << k;
        return 0;
      }
    }
  }
  return 0;
}
