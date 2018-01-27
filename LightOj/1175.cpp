#include<bits/stdc++.h>
using namespace std;


int row,col;
string maze[205];
#define pii pair<int,int>

int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int cell[205][205];
int d[205][205],vis[205][205];
int fire[205][205];

void update_fire()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(maze[i][j]=='F')
            {

                if((i+1)>=0 && (i+1)<row && cell[i+1][j]!=-1) fire[i+1][j]=1;
                if((j+1)>=0 && (j+1)<col && cell[i][j+1]!=-1) fire[i][j+1]=1;
                if((i-1)>=0 && (i-1)<row && cell[i-1][j]!=-1) fire[i-1][j]=1;
                if((j-1)>=0 && (j-1)<col && cell[i][j-1]!=-1) fire[i][j-1]=1;
            }
        }
    }


    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(fire[i][j]==1) maze[i][j] = 'F';
        }
    }

}
void print_fire()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++) cout<<fire[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void bfs(int sx,int sy)
{
    memset(vis,0,sizeof vis);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            d[i][j] = INT_MAX;
    }
    vis[sx][sy]=1;
    d[sx][sy] = 0;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        update_fire();
        for(int k=0; k<4; k++)
        {
            int tx=top.first+fx[k];
            int ty=top.second+fy[k];
           // cout<<tx<<" "<<ty<<endl;
            //cout<<cell[tx][ty]<<" "<<vis[tx][ty]<<" "<<fire[tx][ty]<<endl;
            print_fire();
            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && vis[tx][ty]==0 && fire[tx][ty]!=1) //Check if the neighbor is valid and not visited before.
            {
                //cout<<tx<<" "<<ty<<endl;
                vis[tx][ty]=1;

                d[tx][ty]=d[top.first][top.second]+1;
                q.push(pii(tx,ty)); //Pushing a new pair in the queue
            }
        }
    }
}


int main()
{
    //freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>row>>col;
        int sx,sy;
        memset(fire,0,sizeof(fire));
        memset(cell,0,sizeof(cell));
        for(int i=0; i<row; i++) cin>>maze[i];
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(maze[i][j]=='#') cell[i][j] = -1;
                else if(maze[i][j]=='F') fire[i][j] = 1;
                else if(maze[i][j]=='J')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        bfs(sx,sy);
        int mini = INT_MAX;
        for(int i=0;i<row;i++) mini = min(d[i][0],mini);
        for(int i=0;i<row;i++) mini = min(d[i][col-1],mini);
        for(int i=0;i<col;i++) mini = min(d[0][i],mini);
        for(int i=0;i<col;i++) mini = min(d[row-1][i],mini);
        if(mini==INT_MAX) cout<<"Case "<<cs++<<": "<<"IMPOSSIBLE"<<endl;
        else cout<<"Case "<<cs++<<": "<<mini + 1<<endl;
    }
    return 0;
}
