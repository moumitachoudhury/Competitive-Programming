#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,q,i,j,low,up;
    scanf("%d",&n);
    int g[n+5];
    for(i=0;i<n;i++) scanf("%d",&g[i]);
    scanf("%d",&q);
    int c[q+5];
    for(i=0;i<q;i++)
    {
        scanf("%d",&c[i]);
        low = lower_bound(g,g+n,c[i]) - g;
        up = upper_bound(g,g+n,c[i]) - g;
        if(low) printf("%d ",g[low-1]);
        else printf("X ");
        if(up==n && g[up]!= g[n-1]) printf("X");
        else printf("%d",g[up]);
        printf("\n");
    }


    return 0;
}







