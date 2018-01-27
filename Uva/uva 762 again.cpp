#include<bits/stdc++.h>
using namespace std;
//map<string,vector<string>>adj;
map<string,int>idc;
map<string,int>::iterator it;
vector<int> adj[1000];
bool vis[1000];
int level[1000];
map<int,int> parent;
void pathf(int x)
{
    if(x==parent[x])return;
    pathf(parent[x]);
    for(it=idc.begin(); it!=idc.end(); ++it)
    {
        if(it->second==parent[x])cout<<it->first<<" ";
    }
    for(it=idc.begin(); it!=idc.end(); ++it)
    {
        if(it->second==x)cout<<it->first<<endl;
    }
}
//s starting node, n no of nodes
void bfs(int s)
{
    int i;

    memset(vis,false,sizeof(vis));
    memset(level,0,sizeof(level));
    queue<int> q;

    q.push(s);
    vis[s] = true;
    level[s] = 0;
    parent[s] = s;

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
                parent[v] = u;
            }
        }

    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,i,j,c=0;
    string s1,s2,src,des;
    //map<string,vector<string>>::iterator it;
    while(scanf("%d",&n)==1)
    {
        if(c++) cout<<endl;
        idc.clear();
        memset(adj,0,sizeof(adj));

        int id = 0;
        for(i=0; i<n; i++)
        {
            cin>>s1>>s2;
            if(!idc[s1]) idc[s1] = ++id;
            if(!idc[s2]) idc[s2] = ++id;
            adj[idc[s1]].push_back(idc[s2]);
            adj[idc[s2]].push_back(idc[s1]);

        }
        cin>>src>>des;

        bfs(idc[src]);
        if(level[idc[des]]==0) printf("No route\n");
        else
        {

            pathf(idc[des]);

        }

    }


    return 0;
}


