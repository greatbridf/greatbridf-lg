// http://noip.hrbeu.edu.cn/problem/15
// Hi-accurate sum
#include <iostream>

using namespace std;

typedef unsigned char byte;

class Decimal {
  private:
    int* num;
  public:
    ~Decimal() {
      delete [] num;
    }

    friend istream& operator>> (istream& is, Decimal& me) {
      string tmp;
      is >> tmp;
      me.num = new int[tmp.length()+1];
      me.num[0] = tmp.length();
      for (int i = 0; i < me.num[0]; ++i) {
        me.num[i+1] = tmp.at(i);
      }
      return is;
    }

    friend ostream& operator<< (ostream& os, const Decimal& me) {
      os << me.num;
      return os;
    }

    Decimal operator+ (const Decimal& uke) {
      Decimal arata;
      return arata;
    }
};

int main() {
  Decimal a, b;
  cout << a << " " << b;
  cin >> a >> b;
  cout << a << " " << b;
  return 0;
}
