#include<bits/stdc++.h>
using namespace std;

int cost[200];
vector<int> adj[110];

int lastnode,mx,mxnode;
int dfs(int s)
{
    lastnode = s;
    //cout<<lastnode<<endl;
    if(adj[s].size())
    {
         mx = 0, mxnode = s;
        for(int i=0;i<adj[s].size();i++)
        {
            int v = adj[s][i];
            if(cost[v]>mx)
            {
                mx = cost[v];
                mxnode = v;
            }
        }
        return cost[s] + dfs(mxnode);
    }
    return cost[s];
}
int main()
{
    int t,n,m,u,v,cs=1;
    cin>>t;
    while(t--)
    {
        memset(cost,0,sizeof(cost));
        for(int i=0;i<=105;i++) adj[i].clear();
        char c = getchar();
        cin>>n>>m;

        for(int i=0;i<n;i++)
        {
            cin>>cost[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
       // int mx=INT_MIN;

        int ans = dfs(0);
        cout<<"Case "<<cs++<<": "<<ans<<" "<<mxnode<<endl;
    }
    return 0;
}
