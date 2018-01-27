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


#define mx 100001
int arr[mx];
struct info
{
    int maxi1, maxi2;
} tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].maxi1 = arr[b];
        tree[node].maxi2 = INT_MIN;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].maxi1 = max(tree[Left].maxi1, tree[Right].maxi1);
    tree[node].maxi2 = min(max(tree[Left].maxi1, tree[Right].maxi2),
                           max(tree[Left].maxi2, tree[Right].maxi1));
}
info query(int node, int b, int e, int i, int j)
{
    info res;
    res.maxi1 = INT_MIN;
    res.maxi2 = INT_MIN;
    if (i > e || j < b)
        return res;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    info p1 = query(Left, b, mid, i, j);
    info p2 = query(Right, mid + 1, e, i, j);

    res.maxi1 =  max(p1.maxi1, p2.maxi1);
    res.maxi2 = min(max(p1.maxi1, p2.maxi2),
                    max(p1.maxi2, p2.maxi1));
    return res;
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i)
    {
        tree[node].maxi1 = newvalue;
        tree[node].maxi2 = INT_MIN;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node].maxi1 = max(tree[Left].maxi1, tree[Right].maxi1);
    tree[node].maxi2 = min(max(tree[Left].maxi1, tree[Right].maxi2),
                           max(tree[Left].maxi2, tree[Right].maxi1));
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n,q;
    isc(n);
    loop(i,1,n) isc(arr[i]);
    isc(q);
    init(1,1,n);
    loop(i,1,q)
    {

        char c;
        int x,y;
        //cin>>c>>x>>y;
        scanf(" %c %d %d",&c,&x,&y);
        if(c=='Q')
        {
          //  cout<<"sdfs"<<endl;
            info ans = query(1,1,n,x,y);
            pf(ans.maxi1+ans.maxi2);
        }
        else
        {
            update(1,1,n,x,y);
        }
    }
    return 0;
}

