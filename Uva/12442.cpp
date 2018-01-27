#include<bits/stdc++.h>
using namespace std;
vector<int>adj[50005];
bool vis[50005];
int cost[50005];
int cnt;
int lastnode,mx,mxnode;
int dfs(int s)
{
    vis[s] = 1;

    int ans = 0;
    for(int i=0; i<adj[s].size(); i++)
    {
        if(!vis[adj[s][i]])
        {

            cnt++;
            //cost[adj[s][i]] = cost[s] + 1;
            ans += 1+dfs(adj[s][i]);
        }
    }
    vis[s] = false;
    return cost[s] = ans;
}

int main()
{
    int t,u,v,cs=1;

//    for(int i=1;i<=50001;i++) cost[i] = 1;
    cin>>t;
    while(t--)
    {
        mx = INT_MIN;
        for(int i=0; i<=50005; i++) adj[i].clear();
        memset(cost,-1,sizeof(cost));
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            //  adj[v].push_back(u);
        }
        for(int i=1; i<=n; i++)
        {
            if(cost[i]==-1)
            {
                cnt = dfs(i);
            }
            if(cnt>mx)
            {
                mx = cnt;
                mxnode = i;
            }
            // cout<<"cnt "<<cnt<<endl;
        }
        cout<<"Case "<<cs++<<": "<<mxnode<<endl;

    }

    //   dfs(4);cout<<cnt<<endl;


return 0;
}
