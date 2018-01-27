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
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
////////////////////////////////////////////////////////

//int v[1000006], sum[1000006];
ll sum[1000005];
map<ll,int>mp;
//ll mp[1000005];
int a[1000005];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int t;
    isc(t);
    //string s;
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        mp.clear();
//        memset(mp,0,sizeof(mp));

        int n,k=0;
        ll cnt=0;
        isc(n);
        for(int i=0;i<n;i++) isc(a[i]);
        mp[0]++;
        sum[0] = a[0];
        cnt+=mp[sum[0]];
        mp[sum[0]]++;

        rept(i,1,n)
        {
            sum[i] = sum[i-1]+a[i];
            cnt += mp[sum[i]];
            mp[sum[i]]++;
        }

       cout<<cnt<<endl;
       // printf("%lld\n",cnt);
    }


    return 0;
}


