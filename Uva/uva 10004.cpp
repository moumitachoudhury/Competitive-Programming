#include<bits/stdc++.h>
using namespace std;

bool vis[230];
vector<int> adj[100000];
int color[10000];

bool bfs(int s)
{
    int i;
    memset(vis,false,sizeof(vis));
    memset(color,'z',sizeof(color));
    queue<int> q;
    q.push(s);
    color[s] = 'r';
    vis[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //color[u] = 'r';
        for(int i = 0; i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(vis[adj[u][i]])
            {
                if(color[v]==color[u]) return false;
            }
            if(!vis[adj[u][i]])
            {
                if(color[u]=='r')color[v] = 'b';
                else color[v] = 'r';
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return true;
}

int main()
{
    int n,i,j,l,x,y;

    while(1)
    {

        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&l);
        for(i=0;i<1000;i++) adj[i].clear();

        for(i=0;i<l;i++)
        {
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int a = bfs(x);
        if(!a) printf("NOT BICOLORABLE.\n");
        else printf("BICOLORABLE.\n");

    }
    return 0;
}
