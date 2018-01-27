#include<bits/stdc++.h>
using namespace std;

int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,i,n,x,y,a[1005],c=1;
while(1)    {
        x = 0, y= 0;
        scanf("%d",&n);
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>0) x++;
            else if(a[i]==0)y++;
        }
        printf("Case %d: %d\n",c++,x-y);

    }

    return 0;
}
