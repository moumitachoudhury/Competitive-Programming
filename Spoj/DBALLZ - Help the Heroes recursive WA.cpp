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
ll dp[1010][1010];

ll solve(int n, int e)
{
    if(n==0 || e==0) return 0;
    if(dp[n][e]!=-1) return dp[n][e];
    ll ret = INT_MIN;

    if (energy[n]<=e)
    ret = max(timee[n]+ solve(n, e-energy[n]), solve(n-1, e));
    //cout<<n<<" "<<e<<" "<<ret<<endl;
  return dp[n][e] = ret;
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
        memset(dp,-1,sizeof(dp));
        int e;
        isc(e); isc(n);
        loop(i,1,n) isc(energy[i]);
        loop(i,1,n) isc(timee[i]);
        printf("%lld\n", solve(n,e));
    }

    return 0;
}

