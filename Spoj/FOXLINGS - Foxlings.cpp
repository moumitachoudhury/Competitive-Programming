#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define pf(n) printf("%d\n",n)
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;

map<int, int>id,sz;

int root(int i)
{
    while (i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

bool connected(int p, int q)
{
    return root(p) == root(q);
}

int cnt = 0;
void unionn(int p, int q)
{
    int i = root(p);
    int j = root(q);
    if(i==j) return;
    cnt++;
    if (sz[i] < sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif


    int n,m,a,b;
    isc(n);
    isc(m);


    rept(i,0,m)
    {
        isc(a);
        isc(b);
        if(!id[a])
        {
            id[a] = a;
            sz[a] = 1;
        }
        if(!id[b])
        {
            id[b] = b;
            sz[b] = 1;
        }
        unionn(a,b);

    }

    pf(n-cnt);

    return 0;
}

