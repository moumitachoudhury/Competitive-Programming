#include<bits/stdc++.h>
using namespace std;
vector<int> adj[500005];
bool vis[1007];
int level[2000];

//s starting node, n no of nodes
void bfs(int s)
{
    int i;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    queue<int> q;

    q.push(s);
    vis[s] = true;
    level[s] = 0;
//    parent[s] = s; //needed for path printing
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(i=0; i<adj[u].size(); i++)
        {
            if(!vis[adj[u][i]])
            {
                int v = adj[u][i];
                vis[v] = true;
                q.push(v);
                level[v] = level[u] + 1;

            }
        }

    }
}

int main()
{
   // freopen("out.txt","w",stdout);
    int t,n,u,v,p;
    char s;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        s = getchar();

        cin>>n>>p;
        for(int i=0;i<=n;i++)
        {
            adj[i].clear();
        }
        while(p--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(0);
        for(int i=1; i<n; i++)
        {
            cout<<level[i]<<endl;
        }
        if(i!=t)
        cout<<endl;
    }
    return 0;
}
