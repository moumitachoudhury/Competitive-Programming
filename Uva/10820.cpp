#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int phi[500005];
int mark2[500005];
int n = 500005;
void seivephi()
{
    int i,j;
    for(i=1;i<=n;i++) phi[i] = i;
    phi[1] = 1;
    mark2[1] = 1;
    for(i=2;i<=n;i++)
    {
        if(mark2[i]==0)
        {
            for(j=i;j<=n;j+=i){
                mark2[j] =1;
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
    /*for(i=1;i<=n;i++)
    printf("%d %d\n",i,phi[i]);*/
}
int main()
{
    int i,j,x;
    long long int cnt;
    seivephi();
    while(scanf("%d",&x)==1)
    {
        if(x==0) break;
        cnt = phi[x];
        cnt = cnt*(cnt-1)/2;
        long long int ans = (x*x) - cnt;
        printf("%lld\n",ans);


       /* for(i=1;i<=n;i++)
        {
            if(phi[i]!=1) cnt++;
        }*/
    }
    return 0;
}
