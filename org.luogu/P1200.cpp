#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char comet[7], team[7];
  scanf("%s%s", comet, team);
  int nC = 1, nT = 1;
  int lC = strlen(comet), lT = strlen(team);
  for (int i = 0; i < lC; ++i)
    nC *= (comet[i] - 'A' + 1);
  for (int i = 0; i < lT; ++i)
    nT *= (team[i] - 'A' + 1);
  if (nC%47 == nT%47)
    cout << "GO";
  else 
    cout << "STAY";
  return 0;
}
