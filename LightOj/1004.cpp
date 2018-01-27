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
    ll a[500][500];
    ll dp[500][500];
    int n;
    ll solve(int i, int j)
    {
        if(a[i][j]==0) return a[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        else
        {
            ll ret = a[i][j];
            if(i<=n && j!=0 && j!=i) ret += max(solve(i-1,j),solve(i-1,j-1));
            else if( i <= n && i == 0)
            ret +=solve(i-1 , j);
            else if(i <= n &&j == i)
            ret += solve(i-1 , j-1);
            else ret += max(solve(i-1,j),solve(i-1,j+1));
            return dp[i][j] = ret;
        }
    }

    int main()
    {
        #ifndef ONLINE_JUDGE
       // freopen("input.txt", "r", stdin);
       // freopen("out2.txt", "w", stdout);
        #endif
        int t,cs=1;
        isc(t);
        while(t--)
        {
            memset(dp,-1,sizeof(dp));
            isc(n);
             for(int j=1;j<n;j++)
               for(int k=1;k<=j;k++)
                 llsc(a[j][k]);
              for(int j=n;j<2*n;j++)
               for(int k=1;k<=2*n-j;k++)
                 llsc(a[j][k]);
            ll ans = a[2*n-1][1];
            ans +=max( solve(2*n-2,1), solve(2*n-2,2));
            printf("Case %d: %lld\n",cs++,ans);
        }

        return 0;
    }
