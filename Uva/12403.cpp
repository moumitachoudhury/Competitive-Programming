#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i,c=1;
    long long int ans = 0;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",c++);
        cin>>s;
        if(s=="donate")
        {
            scanf("%d",&n);
            ans += n;
        }
        else printf("%lld\n",ans);
    }
    return 0;
}
