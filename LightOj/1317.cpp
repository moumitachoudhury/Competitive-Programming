#include<stdio.h>

int main()
{
    int t,n,cs,m,k;
    double p;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%d %d %d %lf",&n,&m,&k,&p);
        printf("Case %d: %.6f\n",cs,n*p*k);
    }
    return 0;
}
