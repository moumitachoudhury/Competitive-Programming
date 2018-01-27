#include<bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool vis[105];
int level[1000005];
 //s starting node, n no of nodes
void bfs(int s)
{
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    int i;

    queue<int> q;

    q.push(s);
    vis[s] = true;
    level[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

    for(i=0;i<adj[u].size();i++)
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

    int n=1,e,i,j,x,y,ttl,cnt=0,cas=1;
    while(1){
        int id=0;
    map<int,int>idc;
    scanf("%d",&e);
    if(e==0) break;
    for(i=0;i<40;i++)adj[i].clear();

    for(i=0;i<e;i++)
    {
        scanf("%d %d",&x,&y);
        if(!idc[x]) idc[x] = ++id;
        if(!idc[y]) idc[y] = ++id;
        adj[idc[x]].push_back(idc[y]);
        adj[idc[y]].push_back(idc[x]);

    }
    while(1)
    {
        cnt = 0;
        scanf("%d %d",&x,&ttl);
        if(x==0 && ttl==0) break;
        bfs(idc[x]);
        for(i=1;i<=id;i++)
        {
            if(level[i]==-1 || level[i]>ttl) cnt++;
            //printf("%d %d\n",i,level[i]);
            //if(level[i]>ttl) cnt++;
        }
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cas++,cnt,x,ttl);
    }
    }
//    printf("%d\n",level[]);
    return 0;
}

