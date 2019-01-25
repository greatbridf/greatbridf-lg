#include <iostream>
#include <string>
#include <memory.h>

#define SIZE 1000

using namespace std;

struct big_decimal {
  int* num;
  big_decimal() {
    this->num = new int[SIZE];
    memset(this->num, 0x00, sizeof(int)*SIZE);
    this->num[0] = 0;
  }
  // ~big_decimal() {
  //   delete [] this->num;
  // }

  big_decimal operator= (const int a) {
    int tmp = a;
    while (tmp) {
      this->num[++this->num[0]] = tmp % 10;
      tmp /= 10;
    }
    return *this;
  }

  big_decimal operator= (int* a) {
    delete [] this->num;
    this->num = a;
    return *this;
  }

  int& operator[] (const int i) {
    return this->num[i];
  }
};

big_decimal multiply(big_decimal a, big_decimal b) {
  big_decimal ans;
  ans[0] = a[0] + b[0];
  for (int i = 1; i <= a[0]; ++i) {
    for (int j = 1; j <= b[0]; ++j) {
      ans[1+i-1+j-1] += a[i]*b[j];
      ans[1+i-1+j-1+1] += ans[1+i-1+j-1]/10;
      ans[1+i-1+j-1] %= 10;
    }
  }
  while (!ans[ans[0]]) --ans[0];
  return ans;
}

int main() {
  big_decimal result;
  result = 1;
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    big_decimal tmp;
    tmp = i;
    result = multiply(result, tmp);
  }
  for (int i = result[0]; i >= 1; --i) {
    cout << result[i];
  }
  cout << endl;
  return 0;
}
