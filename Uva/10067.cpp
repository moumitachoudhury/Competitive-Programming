#include<bits/stdc++.h>
using namespace std;

int fa[]={1,-1,0,0,0,0,0,0};
int fb[]={0,0,1,-1,0,0,0,0};
int fc[]={0,0,0,0,1,-1,0,0};
int fd[]={0,0,0,0,0,0,1,-1};
int dis[10002];
bool vis[10002];
int cell[10002];

#define isvalid(a,b,c,d) a>=0 && a<=9 && b>=0 && b<=9 && c>=0 && c<=9 && d>=0 && d<=9

bool valid(int x)
{
    if(cell[x]!=-1 && vis[x]==false) return true;
    else return false;
}


void bfs(int s)
{
    int i;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    //int s = 1000*a + 100*b + 10*c +d;
    vis[s] = true;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(i=0;i<8;i++)
        {
            int u = temp;
            int ud = u%10;u/=10;
            int uc = u%10; u/=10;
            int ub = u%10; u/=10;
            int ua = u%10;
            //cout<<u<<" : "<<ua<<" "<<ub<<" "<<uc<<" "<<ud<<endl;
            int ta = (ua + fa[i] + 10 )% 10;
            int tb = (ub + fb[i] + 10) % 10;
            int tc = (uc + fc[i] + 10) % 10;
            int td = (ud + fd[i] + 10) % 10;
            int temp2;
            if(isvalid(ta,tb,tc,td))
            temp2 = ta*1000+tb*100+tc*10+td;
            else continue;
            //cout<<temp2<<" :::: "<<ta<<" "<<tb<<" "<<tc<<" "<<td<<endl;
            if(valid(temp2))
            {
                vis[temp2] = true;
                dis[temp2] = dis[temp] + 1;
                q.push(temp2);

            }
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int z=0; z<t; z++)
    {
        if(z) char c = getchar();
        int a,b,c,d,e,f,g,h;
        cin>>a>>b>>c>>d;
        cin>>e>>f>>g>>h;
        int endi = e*1000 + f*100 + g*10 + h;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>e>>f>>g>>h;
            int fbd = e*1000 + f*100 + g*10 + h;
            cell[fbd] = -1;
        }
        int start = a*1000 + b*100 + c*10 + d;
        bfs(start);
        cout<<dis[endi]<<endl;
        memset(cell,0,sizeof(cell));

    }
    return 0;
}
