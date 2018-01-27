#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        double ans=0.0;
        for(int j=1;j<=n;j++) ans += (n*1.0/j);
        printf("Case %d: %.10f\n",i,ans);
    }
    return 0;
}
