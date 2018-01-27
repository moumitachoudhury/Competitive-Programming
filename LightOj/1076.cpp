#include<bits/stdc++.h>
using namespace std;

int m,n,v[1009];

bool can(int);
int bs(int,int);

int main()
{
    int i,j,t,c=1,total,low;
    scanf("%d",&t);
    while(t--)
    {
        total = 0;
        low = 0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&v[i]);

            total += v[i];
            if(v[i]>low) low = v[i];
        }

        int ans = bs(low,total);
    printf("Case %d: %d\n",c++,ans);
    }


    return 0;
}


bool can(int capacity)
{
    int cnt = 1, sum = 0,i;
    for(i=0;i<n;i++)
    {
//        printf("sum = %d\n",sum + v[i]);
        if(sum+v[i]<=capacity)
        {
            sum += v[i];
        }
        else
        {
            sum = v[i];
            cnt++;
        }
    }
   // printf("cnt = %d\n",cnt);
    if(cnt>m) return false;
    else return true;

}


int bs(int low, int high)
{
    int lo = low, hi = high,ans;
    int mid;
    while(lo<=hi)
    {
        mid = (lo + hi) / 2;
      //  printf("mid = %d\n",mid);
        if(can(mid))
        {
            ans = mid;
            hi = mid - 1;
           // printf("%d\n",ans);
        }
        else
        {
         //   printf("m = %d\n",mid);
            lo = mid + 1;
        }
    }
    return ans;
}
