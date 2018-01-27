#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define pf(n) printf("%d\n",n)
#define pfcs(cs) printf("Case %d:\n",cs);
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;

double a[103];
int dp[103];
int solve(int n)
{
    if(n>8)
    {
        double sum=0.0;
        int intsum = 0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
            intsum+=floor(a[i]);
        }
        return floor(sum)+intsum;
    }
    int ans = 0;
    return ans+solve(n+1);

}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    while(1)
    {
        int n;
        isc(n);
        if(n==0) break;
        loop(i,1,n) scanf("%lf",&a[i]);
        cout<<solve(1)<<endl;
    }

    return 0;
}

