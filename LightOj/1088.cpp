#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,q,i,x,y,cnt,low,up,a[100009];
    scanf("%d",&t);

    for(int j=1;j<=t;j++){
        scanf("%d %d",&n,&q);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        printf ("Case %d:\n",j) ;
        for(int k=1;k<=q;k++){
                scanf("%d %d",&x,&y);

            low=lower_bound(a, a+n ,x)-a ;
            up=upper_bound(a, a+n ,y)-a ;
            int ans=up-low ;
           printf ("%d\n",ans) ;
            }
    }
    return 0;
}

                    /*for(i=0;i<n;i++){
                if(a[i]>=x && a[i]<=y) {
                    cnt++;
                }
            }*/
