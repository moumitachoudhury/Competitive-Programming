#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define valid(nx,ny) nx>=0 && nx<=row && ny>=0 && ny<=col
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int d[1005][1005];
bool vis[1005][1005];
int cell[1005][1005];
int row,col;
//pii parent[1005][1005];

void bfs(int sx,int sy)
{
    int i;
    memset(vis,false,sizeof(vis));
    memset(d,-1,sizeof(d));
    vis[sx][sy] = true;
    d[sx][sy] = 0;
    queue<pii> q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            int tx = u.first + fx[i];
            int ty = u.second + fy[i];
            if(valid(tx,ty) && !vis[tx][ty] && cell[tx][ty]!=-1)
            {
                vis[tx][ty] = true;
               // printf("cell %c %d\n",tx,ty);
                d[tx][ty] = d[u.first][u.second] + 1;
                q.push(pii(tx,ty));
                //parent[tx][ty] = u;
            }
        }
    }
}
int main()
{
    int r,c,i,j,n,num,x1,y1,x2,y2;
    while(1)
    {
        scanf("%d %d",&row,&col);
        //cout<<"p1"<<endl;
        if(row==0 && col==0) break;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&r,&num);

            for(j=0;j<num;j++)
            {
                scanf("%d",&c);
                cell[r][c] = -1;
            }
        }
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        bfs(x1,y1);
        printf("%d\n",d[x2][y2]);
        memset(cell,0,sizeof(cell));
    }

    return 0;
}

