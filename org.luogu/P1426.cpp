#include <iostream>

using namespace std;

int main() {
  double dist, range, traveled = 0, velocity = 7;
  cin >> dist >> range;
  while (traveled < dist-range) {
    traveled += velocity;
    velocity *= 0.98;
  }
  if (traveled + velocity > dist + range) {
    cout << 'n';
    return 0;
  }
  if (traveled - velocity > dist - range)
    cout << 'n';
  else
    cout << 'y';
  return 0;
}
