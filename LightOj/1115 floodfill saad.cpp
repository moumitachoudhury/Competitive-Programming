#include<iostream>
using namespace std;
char ori[50][50],temp[50][50];
int n,m;
void ff(int x, int y, char prevV, char newV)
{
    if (x < 0 || x >= n || y < 0 || y >= m)return;
    if (temp[x][y] != prevV)return;
    temp[x][y] = newV;
    ff(x+1, y, prevV, newV);
    ff(x-1, y, prevV, newV);
    ff(x, y+1, prevV, newV);
    ff(x, y-1, prevV, newV);
}
void rs(char c)
{
   for (int i=0; i<n; i++)for (int j=0; j<m; j++)if (temp[i][j] != c)temp[i][j] = '-';//everything that is not c is replaced with '-'
   //in next four line i traversed the boundary and replaced '-' back to '.'
   for (int i=0; i<n; i++)if(temp[i][0] == '-')ff(i, 0, '-', '.');
   for (int i=0; i<n; i++)if(temp[i][m-1] == '-')ff(i, m-1, '-', '.');
   for (int i=0; i<m; i++)if(temp[0][i] == '-')ff(0, i, '-', '.');
   for (int i=0; i<m; i++)if(temp[n-1][i] == '-')ff(n-1, i, '-', '.');
   //so every thing that is still '-' is replaced with c
   for (int i=0; i<n; i++)for (int j=0; j<m; j++)if(temp[i][j] == '-')temp[i][j] =c;
   //updated original map only for c. do not update for other character. also made a copy in temp;
   for (int i=0; i<n; i++)for (int j=0; j<m; j++){if(temp[i][j] ==c)ori[i][j] =c;else temp[i][j]=ori[i][j];}
}
int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        cas++;
        cin>>n>>m;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin>>ori[i][j];temp[i][j]=ori[i][j];}//takes input map and makes a copy
        for(char c='A';c<='Z';c++)rs(c);//do this for A to Z
        cout<<"Case "<<cas<<":"<<endl;
        for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<ori[i][j];cout<<endl;}//outputs map
    }
    return 0;
}

