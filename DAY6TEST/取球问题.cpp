#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int getBall(int n){
	if( n == 1) {
		return 2;
	}
	if( n == 2) {
		return 3;
	}
	return getBall(n-1) + getBall(n-2);
}
int main()
{
  
  freopen("10.in", "r", stdin);
  freopen("10.out", "w", stdout);
  int n;
  while(cin >> n)
  {
  	cout << getBall(n) << endl;
  }
  return 0;
}

