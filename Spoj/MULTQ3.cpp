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

#define mx 100003
typedef long long i64;
struct info
{
    int prop;
    int mod1, mod2, mod3;
    void Merge(info Left,info Right)
    {
        mod1 = Left.mod1 + Right.mod1;
        mod2 = Left.mod2 + Right.mod2;
        mod3 = Left.mod3 + Right.mod3;
    }
} tree[mx * 3];
void rotate(int node)
{
    int temp=tree[node].mod2;
        tree[node].mod2=tree[node].mod1;
        tree[node].mod1=tree[node].mod3;
        tree[node].mod3=temp;
    /* if (tree[node].prop  == 1)
    {
        int temp=tree[node].mod2;
        tree[node].mod2=tree[node].mod1;
        tree[node].mod1=tree[node].mod3;
        tree[node].mod3=temp;
    }
   else if (tree[node].prop == 2)
    {
        int temp=tree[node].mod2;
        tree[node].mod2=tree[node].mod1;
        tree[node].mod1=tree[node].mod3;
        tree[node].mod3=temp;

    }*/
   // cout<<"dfcd "<<node<<" "<<tree[node].mod3<<endl;
}
void pushdown(int node)
{

    if(tree[node].prop==0) return;
    tree[node].prop %= 3;
    tree[2*node].prop += tree[node].prop;
    tree[2*node + 1].prop += tree[node].prop;
    rept(i,0,tree[node].prop)
    {
        rotate(2*node);
        rotate(2*node+1);

    }
    //
    tree[node].prop = 0;
}
void update(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        rotate(node);
        tree[node].prop ++;
       // tree[node].prop %= 3;

       return;
    }
    pushdown(node);
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j);
    update(Right, mid + 1, e, i, j);
    tree[node].Merge(tree[node * 2], tree[node *2 + 1]);
    //cout<<"mod "<<node<<" "<<tree[node].mod3<<endl;
    //  cout<<"sdfdf "<<tree[node].mod1<<" "<<tree[node].mod2<<" "<<tree[node].mod3<<endl;

}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].mod3;
    pushdown(node);
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);

    return p1 + p2;
}


void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].mod3 = 1;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].Merge(tree[node*2], tree[node*2+1]);
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
#endif
    int n,q;
    isc(n);
    isc(q);
    init(1,1,n);
    loop(i,1,q)
    {
        int t,l,r;
        isc(t);
        isc(l);
        isc(r);

        if(t)
            pf(query(1,1,n,l+1,r+1));
        else update(1,1,n,l+1,r+1);
    }

    return 0;
}

