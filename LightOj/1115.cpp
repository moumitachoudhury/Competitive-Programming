#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define pb push_back

vector<int>adj[100005];
ll v[100005];
int vis[100005];

int dfs(int u)
{
    int sum = v[u];
    vis[u] = 1;
    int i;
    for(i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!vis[v])
        {
            dbg(v);
            sum += dfs(v);
        }
    }
    return sum;
    }

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,i;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            vis[i] = 1;
            adj[i].clear();
        }
        while(m--)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&v[i]);

        }
        int ans = 0;
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                ans = max(ans,dfs(i));
                dbg(ans);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
