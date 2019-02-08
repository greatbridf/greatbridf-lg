#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[200010];
int main() {
    int n,k,ans=1,i,start;
    cin>>n>>k;
    for(i=0; i<n; i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    start=0;
    for(i=1; i<n; i++) {
        if(a[i]-a[start]>k) {
            ans++;
            start=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
