#include <iostream>

using namespace std;

bool holes[1000];

int main() {
  int nHole, nTimes;
  long long t = 0;
  cin >> nHole >> nTimes;
  for (int i = 0; i < nTimes; ++i) {
    if (t%nHole == 0) holes[nHole] = true;
    else holes[t%nHole] = true;
    t += (i+1);
  }
  int flag = 0;
  for (int i = 1; i <= nHole; ++i) {
    if (!holes[i]) {
      ++flag;
      cout << i << " ";
    }
  }
  if (flag == 0)
    cout << 0;
  cout << endl;
  return 0;
}
