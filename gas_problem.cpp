#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int* station_distance = new int[k+1];
  for (int i = 0; i < k+1; ++i) {
    cin >> station_distance[i];
    if (station_distance[i] > n) {
      cout << "No Solution!";
      return 0;
    }
  }
  int result = 0, gas_life = n;
  for (int i = 0; i < k+1; ++i) {
    gas_life -= station_distance[i];
    if (gas_life < 0) {
      ++result;
      gas_life = n - station_distance[i];
    }
  }
  cout << result;
  delete [] station_distance;
  return 0;
}
