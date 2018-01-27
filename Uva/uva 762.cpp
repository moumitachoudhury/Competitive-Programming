#include<bits/stdc++.h>
using namespace std;
map<string,vector<string>>adj;
//vector<string> adj[1000];
map<string,bool> vis;
map<string,int> level;
map<string,string> parent;
void pathf(string x)
{
    if(x==parent[x])return;
    pathf(parent[x]);
    cout<<parent[x]<<" "<<x<<endl;
}
 //s starting node, n no of nodes
void bfs(string s)
{
    int i;

    //memset(vis,false,sizeof(vis));
    // memset(level,-1,sizeof(level));
    queue<string> q;

    q.push(s);
    vis[s] = true;
    level[s] = 0;
    parent[s] = s;

    while(!q.empty()){
        string u = q.front();
        q.pop();

    for(i=0;i<adj[u].size();i++)
    {
        if(!vis[adj[u][i]])
        {
            string v = adj[u][i];
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
   // freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);

    int n,i,j,c=0;
    string s1,s2,src,des;
    //map<string,vector<string>>::iterator it;
    while(scanf("%d",&n)==1)
    {
        if(c++) cout<<endl;
        //for(it=adj.begin();it!=adj.end();++it) adj.clear();
        adj.clear();
        vis.clear();
        level.clear();
        for(i=0;i<n;i++)
        {
            cin>>s1>>s2;
            adj[s1].push_back(s2);
            adj[s2].push_back(s1);
           // level[s1] = -1;
           // level[s2] = -1;
        }
        cin>>src>>des;
        //cout<<level[des]<<endl;
        bfs(src);
        if(level[des]==0) printf("No route\n");
        else{
            //if(level[des]==0) cout<<des<<" "<<des<<endl;
           // else{
                pathf(des);
                //cout<<endl;
            }

        }


    return 0;
}

