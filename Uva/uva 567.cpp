#include<bits/stdc++.h>
using namespace std;

vector<int> adj[40];
bool vis[40];
int level[40];
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
    int n,e,i,j,x,y,src,des,cas=1,que;
    while(scanf("%d",&n)==1)
    {

        for(i=1; i<=n; i++)
        {
            scanf("%d",&x);
            adj[1].push_back(x);
            adj[x].push_back(1);
        }
        for(j=2; j<=19; j++)
        {
            scanf("%d",&n);
            for(i=1; i<=n; i++)
            {
                scanf("%d",&x);
                adj[j].push_back(x);
                adj[x].push_back(j);
            }
        }
        scanf("%d",&que);
        printf("Test Set #%d\n",cas++);


        for(i=1; i<=que; i++)
        {
            scanf("%d %d",&src,&des);
            bfs(src);
            printf("%2d to %2d: %d\n",src,des,level[des]);
        }
        printf("\n");
        for(int i=0; i<21; i++)
        {
            adj[i].clear();
        }
    }

    return 0;
}
