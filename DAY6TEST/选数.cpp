#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,k;
int a[10000];
int sum=0;
int ans=0;
int isPrime(int n)
{
  if(n==1||n==0)
  	return 0;
  int m = (int)sqrt(n);
  for(int i=2 ; i <= m ; i++)
  	if(n%i==0)
  	   return 0;
  return 1;
}
void dfs(int step,int i)
{
	int j;
	if(step>k)
	{
		if(isPrime(sum))
			ans++;
		return ;
	}
	for(j=i;j<=n;j++)
	{
		sum=sum+a[i];
		dfs(step+1,j+1);
		sum=sum-a[i];
	}
}
int main()
{
  int i;
  //freopen("10.in", "r", stdin);
  //freopen("10.out", "w", stdout);
  cin>>n>>k;
  for(i=1;i<=n;i++)
  {
  	cin>>a[i];
   } 
  dfs(1,1);
  cout<<ans<<endl;
  return 0;
}

