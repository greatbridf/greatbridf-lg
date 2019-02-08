#include <iostream>
#include <cstdio>
using namespace std;
int getBook(int n, int m)
{
	if(n < m){
		return 0;
	}
	if( n == m){
		return 1;
	}
	if( m == 0 ){
		return 1;
	}
	return getBook(n-1, m-1) + getBook(n-1, m);
}
int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		cout << getBook(n, m) << endl;
	}
	return 0;
}
