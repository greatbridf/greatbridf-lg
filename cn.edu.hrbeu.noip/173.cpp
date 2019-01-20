#include <iostream>

using namespace std;

typedef struct Student {
  int id;
  int cn;
  int ma;
  int en;
  int to;
} Student;

void calc_total(Student& s) {
  s.to = s.cn + s.ma + s.en;
}

bool cmp(Student a, Student b) {
  return ((a.to > b.to)||(a.to == b.to && a.cn > b.cn)||(a.to == b.to && a.cn == b.cn && a.id < b.id));
}

int main() {
  int n;
  cin >> n;
  Student* students = new Student[n];
  for (int i = 0; i < n; ++i) {
    cin >> students[i].cn >> students[i].ma >> students[i].en;
    students[i].id = i+1;
    calc_total(students[i]);
  }
  sort(students, students+n, cmp);
  for (int i = 0; i < 5; ++i) {
    cout << students[i].id << " " << students[i].to << endl;
  }
  return 0;
}
