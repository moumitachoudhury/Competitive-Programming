#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;
#define mx 100005
#define inf INT_MIN
int n;
ll a[mx];
ll dp[mx];

ll solve()
{
    dp[n-1] = a[n-1];
    dp[n-2] = dp[n-1] + a[n-2];
    dp[n-3] = dp[n-2] + a[n-3];

    for(int i=n-4; i>=0; i--)
    {

        dp[i] = max(dp[i], a[i]+dp[i+2]);
        //cout<<"1 "<<dp[i]<<endl;
        if(i+1<n)
            dp[i] = max(dp[i], a[i]+a[i+1]+dp[i+4]);
        //cout<<"2 "<<dp[i]<<endl;

        if(i+2<n)
            dp[i] = max(dp[i], a[i]+a[i+1]+a[i+2]+dp[i+6]);
        //cout<<"3 "<<dp[i]<<endl;
    }
    return dp[0];



}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    isc(t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));

        isc(n);
        rept(i,0,n)
        {

            llsc(a[i]); //cout<<a[i]<<endl;
        }
//cout<<"ok";
        printf("%lld\n", solve());
    }

    return 0;
}

