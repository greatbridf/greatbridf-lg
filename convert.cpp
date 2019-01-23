#include <iostream>
#include <cstdio>

using namespace std;

const char ks[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
    '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// 3064
void convert(int n, int k) {
  if (n >= k) {
    convert(n/k, k);		// ->	3064 / 16 = 191 / 16 = 11 / 16 = 0
    n %= k;					// ->	3064 % 16 = 8 || 191 % 16 = F || 11 % 16 = B
  }
  printf("%c", ks[n]);
}

int main() {
  int n;
  int k;
  while (cin >> n >> k) {
    if (n < 0) {
      n *= -1;
      cout << "-";
    }
    convert(n, k);
    cout << endl;
  }
  return 0;
}

