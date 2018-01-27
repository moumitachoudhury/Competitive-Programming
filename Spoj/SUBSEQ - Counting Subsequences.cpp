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
vector<ll>v,sum;
map<ll,int>mp;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int t;
    isc(t);
    while(t--)
    {
        v.clear();
        sum.clear();
        mp.clear();
        int n;
        int cnt=0;
        isc(n);
        rept(i,0,n)
        {
            ll num;
            llsc(num);
           // if(num==47) cnt++;
            v.push_back(num);
        }
        mp[0]++;
        sum.push_back(v[0]);
        cnt+=mp[sum[0]-47];
        mp[sum[0]]++;


        rept(i,1,n)
        {
            sum.push_back(sum[i-1]+v[i]);
            cnt += mp[sum[i]-47];
            //if(sum[i]==47 || mp[sum[i]]>1 ) cnt++;
            mp[sum[i]]++;
        }
        //rept(i,0,n) cout<<sum[i]<<" ";
        //cout<<endl;
        cout<<cnt<<endl;
    }


    return 0;
}

