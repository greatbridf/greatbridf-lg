#include <iostream>
#include <cstdio>
#include <algorithm>

#define __macos

#ifdef __macos
#define __gcd __algo_gcd
#endif

using namespace std;

bool visited[20] = {true, false};
int result[20] = {1};
int END;

bool is_prime(int a) {
  if (a <= 3) return true;
  for (int i = 2; i < a; ++i)
    if (a%i==0)
      return false;
  return true;
}

void prime(int n) {
  if (n == END && is_prime(result[0]+result[n-1])) {
    for (int i = 0; i < END; ++i)
      printf("%d ", result[i]);
    cout << endl;
    return;
  }
  for (int i = 2; i <= END; ++i) {
    if (!visited[i-1] && is_prime(result[n-1]+i)) {
      visited[i-1] = true;
      result[n] = i;
      prime(n+1);
      visited[i-1] = false;
    }
  }
}

int main() {
  while (cin >> END) {
    prime(1);
  }
  return 0;
}

