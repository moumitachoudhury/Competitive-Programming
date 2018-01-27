#include<bits/stdc++.h>
using namespace std;

bool vis[230];
vector<int> adj[100000];
int color[10000];
int cnt,n;
int bfs(int s)
{
    int i;
    queue<int> q;
    q.push(s);
    int id1 = 1,id2=0;
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
                if(color[v]==color[u]) return 0;
            }
            else
            {
                if(color[u]=='r')
                {
                    color[v] = 'b';
                    id2++;
                }
                else if(color[u]=='b')
                {
                    color[v] = 'r';
                    id1++;
                }
                //cnt++;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return max(1,min(id1,id2));
}

int main()
{
    //freopen("out.txt","w", stdout);
    int t,u,v,p;
    cin>>t;
    while(t--){
        memset(vis,false,sizeof(vis));
        memset(color,0,sizeof(color));
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
        int a = bfs(0);
        for(int i=1;i<n;i++)
        {
            if(vis[i]==false && a>0)
            {
                int x = bfs(i);
                if(x>0) a += x;
                else
                {
                    a = 0;
                    break;
                }
            }
        }
        if(a==0) cout<<-1<<endl;
        else cout<<a<<endl;

    }
    return 0;
}
