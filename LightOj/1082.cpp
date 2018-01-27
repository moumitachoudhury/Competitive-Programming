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

#define mx 100004
int arr[mx];
int tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];

        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
   /* cout<<tree[Left]<<" "<<tree[Right]<<endl;
    if(tree[Left]<tree[Right]) tree[node] = tree[Left];
    else tree[node] = tree[Right];
    cout<<tree[node]<<endl;*/
    tree[node] = min(tree[Left], tree[Right]);
 //   tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return INT_MAX; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return min(p1,p2);
    //বাম এবং ডান পাশের যোগফল
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif


    int t,cs=1;
    isc(t);
    while(t--)
    {
        int n,q;
        isc(n);isc(q);

        loop(i,1,n) isc(arr[i]);
        init(1, 1, n);
        int l,r;
        printf("Case %d:\n",cs++);

        rept(j,0,q)
        {
            isc(l);isc(r);

           pf( query(1, 1, n, l, r));
        }


    }

    return 0;
}

