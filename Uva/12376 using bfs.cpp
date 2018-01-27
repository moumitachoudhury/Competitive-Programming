//AC hoynai
#include<bits/stdc++.h>
using namespace std;

int cost[200];
vector<int> adj[110];

bool vis[110];
bool flag = 0;
int temp = 0,mx,mxnode;
void bfs(int s)
{
    int i;
    memset(vis,false,sizeof(vis));
//    memset(level,-1,sizeof(level));
    queue<int> q;
    q.push(s);
    vis[s] = true;


    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        mx = temp;
        flag = 0;
        for(i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!vis[v])
            {

                if(cost[v] + temp>mx)
                {
                    mx = cost[v] + temp;
                    mxnode = v;
                    flag = true;
                }
            }
        }
            if(flag)
            {
                vis[mxnode] = 1;
                q.push(mxnode);
                temp = mx;
            }
        }
    }




int main()
{
    int t,n,m,u,v,cs=1;
    cin>>t;
    while(t--)
    {
        memset(cost,0,sizeof(cost));
        for(int i=0; i<=105; i++) adj[i].clear();
        char c = getchar();
        cin>>n>>m;

        for(int i=0; i<n; i++)
        {
            cin>>cost[i];
        }
        for(int i=0; i<m; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
        // int mx=INT_MIN;

        bfs(0);
        cout<<"Case "<<cs++<<": "<<mx<<" "<<mxnode<<endl;
    }
    return 0;
}

