#include<bits/stdc++.h>
using namespace std;


int r,c,l;
#define pii pair<int,int>
#define valid(nx,ny,nz) nx>=0 && nx<r && ny>=0 && ny<c && nz>=0 && nz<l
int fx[]={1,-1,0,0,0,0};
int fy[]={0,0,1,-1,0,0};
int fz[]={0,0,0,0,1,-1};
int d[35][35][35];
bool vis[35][35][35];
int cell[35][35][35];

//pii parent[1005][1005];

void bfs(int sz,int sx,int sy)
{
    int i;
    memset(vis,false,sizeof(vis));
    memset(d,-1,sizeof(d));
    vis[sz][sx][sy] = true;
    d[sz][sx][sy] = 0;
    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(sz,pii(sx,sy)));
    while(!q.empty())
    {
        pair<int,pair<int,int>> u = q.front();
        q.pop();
        for(i=0;i<6;i++)
        {
            int tz = u.first + fz[i];
            int tx = u.second.first + fx[i];
            int ty = u.second.second + fy[i];
            if(valid(tx,ty,tz) && !vis[tz][tx][ty] && cell[tz][tx][ty]!=-1)
            {
                //cout<<tz<<" "<<tx<<" "<<ty<<endl;
                vis[tz][tx][ty] = true;
               // printf("cell %c %d\n",tx,ty);
                d[tz][tx][ty] = d[u.first][u.second.first][u.second.second] + 1;
                q.push(make_pair(tz,pii(tx,ty)));
                //parent[tx][ty] = u;
            }
        }
    }
}

int main()
{
    int sz,sx,sy,ex,ez,ey;
    while(1)
    {
        cin>>l>>r>>c;
        if(l==0 && r==0 && c==0) break;
        string s[35][35];
        for(int i=0;i<l;i++)
        {
            //cout<<i<<endl;
            for(int j=0;j<r;j++)
            cin>>s[i][j];
            char c = getchar();
        }
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<r;j++)
            {
                for(int k=0;k<c;k++)
                {
                    if(s[i][j][k]=='S')
                    {
                        sz = i;
                        sx = j;
                        sy = k;

                    }
                    else if(s[i][j][k]=='E')
                    {
                        ez = i;
                        ex = j;
                        ey = k;
                    }
                    if(s[i][j][k]=='#') cell[i][j][k] = -1;
                }
            }
        }
       // cout<<sz<<" "<<sx<<" "<<sy<<endl;
       // cout<<ez<<" "<<ex<<" "<<ey<<endl;
       bfs(sz,sx,sy);
       if(d[ez][ex][ey]==-1) cout<<"Trapped!"<<endl;
       else cout<<"Escaped in "<<d[ez][ex][ey]<<" minute(s)."<<endl;
        memset(cell,0,sizeof(cell));


    }
    return 0;
}
