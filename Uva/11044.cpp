#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,m,i,j,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        long long int ans = (n/3) * (m/3);
        printf("%lld\n",ans);
     //   else printf("%lld\n",(ans/9)-1);
    }
    return 0;
}
