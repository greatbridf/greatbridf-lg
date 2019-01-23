#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool visited[16] = {false};
int result[16];

bool is_prime(int a, int b) {
  return __gcd(a, b) == 1;
}

void prime(int END, int n) {
  if (n == END + 1) {
    for (int i = 0; i < END; ++i)
      printf("%d ", result[i]);
    cout << endl;
    return;
  }
  for (int i = 0; i < END; ++i) {
    if (!visited[i] && (i == END-1 || is_prime(i, result[i+1]))) {
      visited[i] = true;
      result[i] = i+1;
      prime(END, n+1);
      visited[i] = false;
    }
  }
}

int main() {
  int END;
  cin >> END;
  prime(END, 1);
  return 0;
}

