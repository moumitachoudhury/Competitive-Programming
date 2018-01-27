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

#define mx 100005
int arr[mx];
ll tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = 0;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
ll query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int t,cs=1;
    isc(t);
    vector<PI>v;
    while(t--)
    {
        memset(tree,0,sizeof(tree));

        int n;
        isc(n);
        v.clear();
        init(1,1,n);
        loop(i,1,n)
        {
            isc(arr[i]);
            v.push_back(make_pair(arr[i],i));
        }
        ll mod = 1000000007;
        ll res=INT_MAX,res2=0;
        sort(v.begin(),v.end());
        int cnt=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[v[i].first]==0)
            {
                mp[v[i].first]=++cnt;
            }
        }
        cout<<cnt<<" "<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            res = query(1,1,cnt,mp[arr[i]]-1,mp[arr[i]]-1)+1;
            cout<<i<<" "<<v[i-1].second<<" "<<" "<<mp[arr[i]]<<" "<<res<<endl;
            res2+=res;
            res2%=mod;
            update(1,1,cnt,mp[arr[i]],res);
        }
        printf("Case %d: %lld\n",cs++,res2);
    }

    return 0;
}
