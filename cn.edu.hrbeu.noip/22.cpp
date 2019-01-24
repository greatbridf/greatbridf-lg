#include <iostream>

using namespace std;

bool holes[1000];

int main() {
  int nHole, nTimes;
  long long t = 0;
  cin >> nHole >> nTimes;
  for (int i = 0; i < nTimes; ++i) {
    holes[t%nHole==0 ? nHole : t%nHole] = true;
    t += (i+1);
  }
  bool flag = false;
  for (int i = 1; i <= nHole; ++i) {
    if (!holes[i]) {
      flag = true;
      cout << i << " ";
    }
  }
  if (!flag)
    cout << 0;
  cout << endl;
  return 0;
}
