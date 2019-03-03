#include <iostream>
#include <cstring>
#include <memory.h>

#define SIZE 1024

using namespace std;

int* num();
void input(int* des, char* src);
void output(int* src);
int* add(int* a, int* b);
int* multiply(int* a, int* b);

int main() {
  int* a = num();
  int* b = num();
  char tmp[SIZE] = "";

  cin >> tmp;
  input(a, tmp);
  cin >> tmp;
  input(b, tmp);

  int* res = add(a, b);
  cout << "Add: ";
  output(res);
  cout << endl;
  delete [] res;

  res = multiply(a, b);
  cout << "Multiply: ";
  output(res);
  cout << endl;
  delete [] res;

  delete [] b;
  delete [] a;
  return 0;
}

int* num() {
  int* arr = new int[SIZE];
  memset(arr, 0x00, sizeof(int) * SIZE);
  return arr;
}

void input(int* des, char* src) {
  des[0] = strlen(src);
  for (int i = des[0]-1; i >= 0; --i)
    des[des[0]-i] = src[i]-'0';
}

void output(int* des) {
  for (int i = des[0]; i > 0; --i)
    cout << des[i];
}

int* add(int* a, int* b) {
  int* r = num();
  r[0] = a[0] > b[0] ? a[0]+1 : b[0]+1;
  for (int i = 1; i <= r[0]; ++i) {
    r[i] += a[i] + b[i];
    r[i+1] += r[i] / 10;
    r[i] %= 10;
  }
  if (r[r[0]] == 0) --r[0];
  return r;
}

int* multiply(int* a, int* b) {
  int* r = num();
  r[0] = a[0] + b[0];
  for (int i = 1; i <= a[0]; ++i) {
    for (int j = 1; j <= b[0]; ++j) {
      r[i+j-1] += a[i]*b[j];
      r[i+j] += r[i+j-1] / 10;
      r[i+j-1] %= 10;
    }
  }
  while (r[r[0]] == 0) --r[0];
  return r;
}

