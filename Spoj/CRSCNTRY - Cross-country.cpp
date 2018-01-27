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

//bitmask//
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
////////////////////////////////////////////////////////

vector<int>a,b;
int way[10000][10000];

int lcs(int m, int n)
{
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) way[i][j] = 0;
            else if(a[i-1]==b[j-1]) way[i][j] = 1 + way[i-1][j-1];
            else
            {
                way[i][j] = max(way[i-1][j],way[i][j-1]);
            }
        }
    }
    return way[m][n];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    isc(t);
    int cnt=0;
    while(t--)
    {
        a.clear();
        b.clear();
        int mx=0;
        while(true)
        {
            int temp;
            scanf("%d",&temp);
            if(temp==0)break;
            a.push_back(temp);
        }
        while(true)
        {
            b.clear();
            int temp;
            scanf("%d",&temp);
            if(temp==0)break;
            b.push_back(temp);
            while(true)
            {
                scanf("%d",&temp);
                if(temp==0)break;
                b.push_back(temp);
            }
            mx=max(mx,lcs(a.size(),b.size()));
        }
        printf("%d\n",mx);
    }


    return 0;
}

