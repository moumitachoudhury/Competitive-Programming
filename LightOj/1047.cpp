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
int a[21][5];
ll dp[21][5];

ll solve(int i, int prevcolor)
{
    if(i>=n) return 0;
    //cout<<i<<" "<<prevcolor<<endl;
    if(dp[i][prevcolor]!=-1) return dp[i][prevcolor];
    ll mini = INT_MAX;
    if(prevcolor!=0)
    {
        mini = min(mini, a[i][0]+solve(i+1,0));
    }
    if(prevcolor!=1)
    {
        mini = min(mini, a[i][1]+solve(i+1,1));

    }
    if(prevcolor!=2)
    {
        mini = min(mini, a[i][2]+solve(i+1,2));
    }
  //  return mini;
 // cout<<i<<" "<<prevcolor<<" "<<mini<<endl;
    return dp[i][prevcolor] = mini;
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
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                isc(a[i][j]);
            }
        }
        ll mini = INT_MAX;
        for(int i=0;i<3;i++)
        {
            ll ans = a[0][i]+solve(1,i);
            mini = min(mini, ans);
        }
        printf("Case %d: %lld\n",cs++,mini);
    //    cout<<solve(0,-1)<<endl;
    }


    return 0;
}
