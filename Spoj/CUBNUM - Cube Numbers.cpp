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

ll dp[100005];
ll solve()
{
    for(int i=0;i<=100001;i++) dp[i]=INT_MAX;
    for(int i=1; i*i*i<=100001; i++)
    {
        int num = i*i*i;
        dp[num] = 1;
      //  cout<<i<<endl;

    }

    for(int i=1; i<=100001; i++)
    {
        for(int j=1;j<=46;j++){
            int numm = j*j*j;
            if(i>numm)
            dp[i] = min(dp[i],dp[numm]+dp[i-numm]);
        }

    }


}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    //cout<<(int)cbrt(35)<<endl;
    int n;

    int cs = 1;
    solve();
    //cout<<dp[35]<<" "<<dp[87072]<<endl;
    while(scanf("%d",&n)!=EOF)
    {
        printf("Case #%d: %lld\n",cs++,dp[n]);
    }
    //int ans = (int)cbrt(3375);
    //cout<<ans<<" "<<ans*ans*ans<<endl;
    //printf("%lld\n", solve(87072));

    return 0;
}

