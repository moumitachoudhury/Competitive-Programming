#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,j;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        double ans=1.0;
        for( j=1;j<=n;j++)
        {
            ans *= ((n-j+1)*1.0)/n;
            //cout<<ans<<endl;
            double tmp = 1-ans;
            if(tmp>=0.5) break;
        }


        printf("Case %d: %d\n",i,j-1);
    }
    return 0;
}

