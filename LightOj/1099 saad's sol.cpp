#include<bits/stdc++.h>
using namespace std;

struct node
{
    int now, cost,op;
    node (){}
    node(int _now, int _cost,int _op)
    {
        now = _now ;
        cost = _cost ;
        op=_op;
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
    int i,j;
    for(i=0;i<100006;i++)
    {
        sec[i] = INT_MAX;
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    pq.push(node(s,0,0));
    while(!pq.empty())
    {
        node u = pq.top();
        pq.pop();
        if(u.op==0 && u.cost!=dis[u.now]) continue;
        if(u.op==1 && u.cost!=sec[u.now]) continue;
        for(i=0;i<adj[u.now].size();i++)
        {
            edge e = adj[u.now][i];
            if(dis[e.v]> u.cost + e.w)
            {
                sec[e.v] = dis[e.v];
                dis[e.v] = u.cost + e.w;
                pq.push(node(e.v,dis[e.v],0));
                pq.push(node(e.v,sec[e.v],1));
            }
            else if(dis[e.v]< u.cost + e.w && sec[e.v]> u.cost + e.w)
            {
                sec[e.v] = u.cost + e.w;
                pq.push(node(e.v,sec[e.v],1));
            }

        }
    }
}


int main()
{
    int t,cs = 1,n,r,u,v,w;
    cin>>t;
    while(t--)
    {

        cin>>n>>r;
        for(int i=0;i<=n;i++) adj[i].clear();
        for(int i=0;i<r;i++)
        {
            cin>>u>>v>>w;
            adj[u].push_back(edge(v,w));
            adj[v].push_back(edge(u,w));

        }
        dijkstra(1);
        cout<<"Case "<<cs++<<": "<<sec[n]<<endl;
    }
    return 0;
}
