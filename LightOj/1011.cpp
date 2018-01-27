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
#define check(n, pos) (n & (1<<pos))
#define set(n, pos) (n | (1<<pos))
int n;
int a[20][20];
ll dp[17][1<<17];
bool mark[20][20];
ll solve(int i, ll vis)
{

    if(i == n)
    {
        return 0;
    }

    if(dp[i][vis]!=-1) return dp[i][vis];

    long long sum;
    sum = -1;
    for (int j = 0; j < n; j++)
    {
        if(check(vis, j) == 0)
        {
            sum = max(sum, a[i][j] + solve(i+1, set(vis, j)));
        }

    }

    dp[i][vis] = sum;
    return dp[i][vis];

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t,cs=1;
    isc(t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        isc(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                isc(a[i][j]);
        }

        printf("Case %d: %lld\n",cs++,solve(0,0));
    }


    return 0;
}

