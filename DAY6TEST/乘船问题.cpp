#include<bits/stdc++.h>
using namespace std;
bool judge(int n)
{
    for(int i=2; i<=sqrt(n); i++)
        if(n%i==0)
            return false;
    return true;
}
int n,k,data[25];
int num[25],tot=0,ans=0;
void dfs(int id,int ret)
{
    if(id==k+1)
    {
        int sum=0;
        for(int i=0; i<tot; i++)
            sum+=num[i];
        if(judge(sum)) ans++;
        return ;
    }
    for(int i=ret+1; i<=n-(k-id); i++)
    {
        num[tot++]=data[i];
        dfs(id+1,i);
        tot--;
    }
}
int main()
{

    while(cin>>n>>k)
    {
        for(int i=1; i<=n; i++)
            cin>>data[i];
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
