#include<bits/stdc++.h>
using namespace std;

struct node
{
    int now, cost;
    node (){}
    node(int _now, int _cost)
    {
        now = _now ;
        cost = _cost ;
    }
};

struct edge
{
    int v, w;
    edge(){}
    edge(long _v, long _w)
    {
        v = _v;
        w = _w;
    }
};

bool operator <(node a, node b)
{
    return a.cost>b.cost;
}
vector<edge>adj[100006];
int dis[100006];
int sec[1000006];
priority_queue<node> pq;
int parent[100006];
int mini;
void dijkstra(int s)
{
    mini = INT_MAX;
    int i,j;
    for(i=0;i<100006;i++)
    {
        sec[i] = INT_MAX;
        dis[i] = INT_MAX;
    }
    dis[s] = 0;

    parent[s] = s;
    pq.push(node(s,0));
    while(!pq.empty())
    {
        node u = pq.top();
        pq.pop();
        if(u.cost!=dis[u.now]) continue;
        for(i=0;i<adj[u.now].size();i++)
        {
            edge e = adj[u.now][i];
            if(dis[e.v]> u.cost + e.w)
            {
                sec[e.v] = dis[e.v];
                dis[e.v] = u.cost + e.w;
                pq.push(node(e.v,dis[e.v]));
                parent[e.v] = u.now;
               // printf("%d %d\n",e.v,dis[e.v]);
            }

        }
    }
}


void pathf(int s)
{
    if(s==parent[s])
    {
        //cout<<s;
        mini = min(mini,adj[s][parent[s]].w  );
        return;
    }
    pathf(parent[s]);
    mini = min(mini,adj[s][parent[s]].w  );
}

int main()
{
    int t,cs = 1,n,r,u,v,w;
    cin>>t;
    while(t--)
    {

        cin>>n>>r;
        //for(int i=0;i<=n;i++) adj[i][i] = 0;
        for(int i=0;i<r;i++)
        {
            cin>>u>>v>>w;
            adj[u].push_back(edge(v,w));
            adj[v].push_back(edge(u,w));

        }
        dijkstra(1);
        pathf(n);
        cout<<dis[n]<<endl;
        if(sec[n]==INT_MAX) cout<<dis[n] + (2*mini)<<endl;

        else  cout<<"Case "<<cs++<<": "<<sec[n]<<endl;
    }
    return 0;
}
