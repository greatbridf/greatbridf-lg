#include <iostream>
#include <string>

using namespace std;

void add(int* a, int* b) {
  int len = a[0]>b[0] ? a[0] : b[0];
  for (int i = 1; i <= len; ++i) {
    int sum = a[i] + b[i];
    a[i+1] += sum/10;
    a[i] = sum%10;
  }
  if (a[len+1] > 0) ++a[0];         // 更新数字长度
  else a[0] = len;
  return;
}

void output(int* a) {
  for (int i = a[0]; i >= 1; --i) {
    cout << a[i];
  }
  return;
}

int main() {
  string sa, sb;
  cin >> sa >> sb;
  int a[501] = {};
  int b[501] = {};
  a[0] = sa.length();
  b[0] = sb.length();
  for (int i = 1; i <= a[0]; ++i) {     // 倒序存储
    a[i] = sa[a[0]-i]-'0';
  }
  for (int i = 1; i <= b[0]; ++i) {
    b[i] = sb[b[0]-i]-'0';
  }
  add(a, a);
  add(a, b);
  output(a);
  return 0;
}

/*
e.g:


#include<bits/stdc++.h>
#define MAIN 410
using namespace std;
int tmp[MAIN],tmp2[MAIN];
void addition(int a[],int b[])
{
  int len=a[0]>b[0]?a[0]:b[0];
  for(int i=1; i<=len; i++)
  {
    a[i+1]+=(a[i]+b[i])/10;
    a[i]=(a[i]+b[i])%10;
  }
  if(a[len+1]>0)
    a[0]=len+1;
  else
    a[0]=len;
  for(int i=a[0]; i>=0; i--)
    tmp[i]=a[i];
  return ;
}
void output(int a[])
{
  for(int i=a[0]; i>0; i--)
    cout<<a[i];
  cout<<endl;
  return ;
}
int main()
{
  //freopen("add.in","r",stdin);
  //freopen("add.out","w",stdout);
  int a[MAIN]= {},b[MAIN]= {},c[MAIN]= {};
  string s1,s2;
  cin>>s1>>s2;
  a[0]=s1.length();
  for(int i=1; i<=a[0]; i++)
    a[i]=s1[a[0]-i]-'0';
  b[0]=s2.length();
  for(int i=1; i<=b[0]; i++)
    b[i]=s2[b[0]-i]-'0';
  addition(a,a);
  addition(tmp,b);
  output(tmp);
  return 0;
}
*/
