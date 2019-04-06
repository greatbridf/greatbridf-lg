#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
  int id;
  int mark;
} Person;

bool cmp(Person a, Person b) {
  return (a.mark > b.mark or (a.mark == b.mark and a.id < b.id));
}

int main() {
  int n, m;
  cin >> n >> m;
  m *= 1.5;
  Person* arr = new Person[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].id >> arr[i].mark;
  }
  sort(arr, arr+n, cmp);
  int line = arr[m-1].mark, in = 0;
  while (in < m or arr[in].mark == line) {
    ++in;
  }
  cout << line << ' ' << in << endl;
  for (int i = 0; i < in; ++i) {
    cout << arr[i].id << ' ' << arr[i].mark << endl;
  }
  return 0;
}

