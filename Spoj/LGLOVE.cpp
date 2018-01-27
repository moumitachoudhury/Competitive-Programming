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
const int mx=1e5+10;
#define mod 1000000007
int arr[mx];
struct info
{
    ll mini,maxi,lazy;
    info()
    {
        mini=maxi=lazy=0;
    }
    void clear()
    {
        mini=maxi=lazy=0;
    }
    void Merge(info l,info r)
    {
        mini=min(l.mini,r.mini);
        maxi=max(l.maxi,r.maxi);
    }

}tree[mx*4];

void pushdown(int idx)
{
    if(tree[idx].lazy==0)return;
    tree[idx*2].mini+=tree[idx].lazy;
    tree[idx*2+1].maxi+=tree[idx].lazy;
    tree[idx*2].maxi+=tree[idx].lazy;
    tree[idx*2+1].mini+=tree[idx].lazy;
    tree[idx*2].lazy+=tree[idx].lazy;
    tree[idx*2+1].lazy+=tree[idx].lazy;
    tree[idx].lazy=0;
}

void build(int info,int s,int e)
{
    if(s>e)return;
    if(s==e)
    {
        tree[info].mini=arr[s];
        tree[info].maxi=arr[s];
        tree[info].lazy=0;
        return;
    }
    int mid=s+(e-s)/2;
    build(info*2,s,mid);
    build(info*2+1,mid+1,e);
    tree[info].Merge(tree[info*2],tree[info*2+1]);
}

void update(int node,int s,int e,int l,int r,int v)
{
    if(l>r)return;
    if(l<=s && e<=r)
    {
        tree[node].mini+=v;
        tree[node].maxi+=v;
        tree[node].lazy+=v;
        return;
    }
    pushdown(node);
    int mid=s+(e-s)/2;
    if(l<=mid)update(node*2,s,mid,l,min(mid,r),v);
    if(r>mid)update(node*2+1,mid+1,e,max(mid+1,l),r,v);
    tree[node].Merge(tree[node*2],tree[node*2+1]);
}

int querymin(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return INT_MAX;
    if (b >= i && e <= j)
        return tree[node].mini;
    pushdown(node);
    int mid = (b + e) / 2;
    int p1 = querymin(node*2, b, mid, i, j);
    int p2 = querymin(node*2+1, mid + 1, e, i, j);
    return min(p1,p2);
}

int querymax(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return INT_MIN;
    if (b >= i && e <= j)
        return tree[node].maxi;
    pushdown(node);
    int mid = (b + e) / 2;
    int p1 = querymax(node*2, b, mid, i, j);
    int p2 = querymax(node*2+1, mid + 1, e, i, j);
    //cout<<b<<" "<<mid<<" "<<e<<" "<<p1<<" "<<p2<<endl;
    return max(p1,p2);
}
ll lcmarr[mx*4];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    lcmarr[0]=0;
    lcmarr[1]=1;
    for(int i=2; i<3*mx; i++)
    {
        if(!lcmarr[i])
        {
            for(int j=i; j<3*mx; j+=i)lcmarr[j]=i;
            lcmarr[i]=(lcmarr[i-1]*i)%mod;
        }
        else
        {
            ll p=lcmarr[i],j;

            for(j=i; j%p==0; j/=p);
            if(j == 1) lcmarr[i]=(lcmarr[i-1]*p)%mod;
            else lcmarr[i]=lcmarr[i-1];
        }
    }
     /*unsigned long long g = 1,lcm=1;
     lcmarr[0] = 0;
     lcmarr[1] = 1;
    for(unsigned long long i=2;i<=300000;i++)
    {
         g = __gcd(i,lcm);
         lcm = (lcm/g);
         lcm %= mod;
         lcm *= i;
         lcm %= mod;
         lcmarr[i] = lcm;
    }*/
    int n,m;
    isc(n); isc(m);
    rept(i,1,n+1)isc(arr[i]);
    build(1,1,n);
    loop(i,1,m)
    {
        int type, l, r, v;
        isc(type);
        if(type)
        {
            isc(l); isc(r);

            if(type==1)
            {
                ll ans = querymax(1,1,n,l+1,r+1);
     //           cout<<ans<<" ds"<<endl;
                pf(lcmarr[ans]);
            }
            else
            {
                ll ans = querymin(1,1,n,l+1,r+1);
       //         cout<<l+1<<" "<<r+1<<" "<<ans<<" gd"<<endl;

                pf(lcmarr[ans]);
            }

        }
        else
        {
            isc(l); isc(r); isc(v);
            update(1,1,n,l+1,r+1,v);
        }
    }

    return 0;
}


