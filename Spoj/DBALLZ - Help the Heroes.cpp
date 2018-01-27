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
int n, timee[1005], energy[1005];
ll dp[1000003];

ll solve(int n, int e)
{

    ll ans = INT_MIN;

    for (int i=0; i<=e; i++)
      for (int j=0; j<n; j++)
         if (energy[j] <= i)
            dp[i] = max(dp[i], dp[i-energy[j]]+timee[j]);

    //for(int i=0;i<=e;i++) cout<<i<<" "<<dp[i]<<endl;// ans =  max(ans, dp[i]);
    return dp[e];
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
        int e;
        isc(e); isc(n);
        loop(i,1,n) isc(energy[i]);
        loop(i,1,n) isc(timee[i]);
        printf("%lld\n", solve(n,e));
    }

    return 0;
}

