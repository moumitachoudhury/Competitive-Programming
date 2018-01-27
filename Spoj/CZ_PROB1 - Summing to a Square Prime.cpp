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


long long int prime[100000], nprime=1;
int mark[100000];
void seive(long long int n)
{
    long long int i,j,limit = sqrt(n*1.)+2;
    mark[1] = 1;
    for(i=4;i<=n;i+=2) mark[i] = 1;
    prime[nprime++] = 2;
    for(i=3;i<=n;i+=2){
        if(!mark[i])

            if(i%4==1)
            prime[nprime++] = i;
            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j] = i;
                }
            }

    }
}

int n;
ll way[100006];
ll solve(int a,int b)
{
    way[0] = 1;

    for(int j=1;j<=b;j++)
    {
        for(int i=1; i<=a; i++)
        {
            if(i>=j)
                way[i] += way[i-j];
    //        cout<<i<<" "<<" "<<j<<" "<<i-j<<" "<<way[i]<<" "<<way[i-j]<<endl;
        }
    }
    return way[a];
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    seive(100006);
    int t;
    isc(t);
    //cout<<prime[501]<<endl;
    while(t--)
    {
        memset(way,0,sizeof (way));
        isc(n); int k; isc(k);
        int a = prime[n];
        printf("%lld\n", solve(a,k));
    }

    //cout<<solve(5,2)<<endl;
    //for(int i=0;i<=5;i++) cout<<prime[i]<<endl;

    return 0;
}

