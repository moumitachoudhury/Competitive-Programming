#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define valid(nx,ny) nx>='a' && nx<='h' && ny>=1 && ny<=8
int fx[]={-2,-2,-1,1,2,2,1,-1};
int fy[]={-1,1,2,2,-1,1,-2,-2};
int d[300][300];
bool vis[300][300];


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
        for(i=0;i<8;i++)
        {
            int tx = u.first + fx[i];
            int ty = u.second + fy[i];
            if(valid(tx,ty) && !vis[tx][ty])
            {
                vis[tx][ty] = true;
               // printf("cell %c %d\n",tx,ty);
                d[tx][ty] = d[u.first][u.second] + 1;
                q.push(pii(tx,ty));

            }
        }
    }
}
int main()
{
    int x1,x2,y1,y2,i,j;
    //char x1,x2,pl[8];
    string s1,s2;
   while(cin>>s1>>s2)
    {
       // sscanf(pl,"%c%d %c%d",&x1,&y1,&x2,&y2);
        //scanf("%c%d %c%d",&x1,&y1,&x2,&y2);
        x1 = s1[0] - 96;
        y1 = s1[1] - '0';
        x2 = s2[0] - 96;
        y2 = s2[1] - '0';

        bfs(x1,y1);
        cout<<"To get from "<<s1<<" to "<<s2<<"takes "<<d[x2][y2]<<" knight moves."<<endl;
        //printf("To get from %s to %s takes %d knight moves.\n",s1,s2,d[x2][y2]);
        //getchar();
    }

        return 0;
}
