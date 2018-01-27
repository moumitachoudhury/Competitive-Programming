#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,m,i,j,t,a[150],sum;
    scanf("%d",&t);
    while(t--)
    {

        int ans = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

        }
        sort(a,a+n);
        ans = a[n-1] - a[0];
        printf("%d\n",ans*2);

    }
    return 0;
}

