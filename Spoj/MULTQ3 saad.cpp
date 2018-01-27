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

struct node{
    int mod3[3],lazy;
    node()
    {
        mod3[0]=mod3[1]=mod3[2]=lazy=0;
    }
    void clear()
    {
        mod3[0]=mod3[1]=mod3[2]=lazy=0;
    }
    void Merge(node l,node r)
    {
        rept(i,0,3)mod3[i]=l.mod3[i]+r.mod3[i];
    }
    void Rotate()
    {
        int temp=mod3[2];
        mod3[2]=mod3[1];
        mod3[1]=mod3[0];
        mod3[0]=temp;
    }
};
const int mx=1e5+10;
int n,q;
node tree[4*mx];

void pushdown(int idx)
{
    if(tree[idx].lazy==0)return;
    tree[idx].lazy%=3;
    tree[idx*2].lazy+=tree[idx].lazy;
    tree[idx*2+1].lazy+=tree[idx].lazy;
    rept(i,0,tree[idx].lazy)
    {
        tree[idx*2].Rotate();
        tree[idx*2+1].Rotate();
    }
    tree[idx].lazy=0;
}

void build(int node,int s,int e)
{
    if(s>e)return;
    tree[node].clear();
    if(s==e)
    {
       tree[node].mod3[0]=1;
       return;
    }
    int mid=s+(e-s)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    tree[node].Merge(tree[node*2],tree[node*2+1]);
}

void update(int node,int s,int e,int l,int r)
{
    if(l>r)return;
    if(l<=s && e<=r)
    {
        tree[node].Rotate();
        tree[node].lazy++;
        return;
    }
    pushdown(node);
    int mid=s+(e-s)/2;
    if(l<=mid)update(node*2,s,mid,l,min(mid,r));
    if(r>mid)update(node*2+1,mid+1,e,max(mid+1,l),r);
    tree[node].Merge(tree[node*2],tree[node*2+1]);

    cout<<"mod "<<node<<" "<<tree[node].mod3[0]<<" ";
    cout<<endl;
}

int query(int node,int s,int e,int l,int r)
{
    if(l>r)return 0;
    if(l<=s && e<=r)
    {
        return tree[node].mod3[0];
    }
    pushdown(node);
    int mid=s+(e-s)/2;
    int ans=0;
    if(l<=mid)ans+=query(node*2,s,mid,l,min(mid,r));
    if(r>mid)ans+=query(node*2+1,mid+1,e,max(mid+1,l),r);
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cas=0;
    isc(t);
    while(t--)
    {
        int u,v,w;
        isc(n);isc(q);
        build(1,1,n);
        printf("Case %d:\n",++cas);
        //cout<<tree[1].mod3[0]<<endl;
        rept(i,0,q)
        {
            isc(u);isc(v);isc(w);
            v++;w++;
            if(!u)update(1,1,n,v,w);
            else
            {
                //cout<<v<<" "<<w<<endl;
                printf("%d\n",query(1,1,n,v,w));
            }
        }
    }
    return 0;
}
