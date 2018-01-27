#include<bits/stdc++.h>
using namespace std;

int mark[1000002];
int prime[300000];
int k;

void seive(int n)
{
    int i,j=0;
    mark[0]=1;
    mark[1] = 1;
    for(i=4;i<=n;i+=2) mark[i] = 1;
    int limit = sqrt(n*1.)+2;
    prime[k++]=2;
    for(i=3;i<=n;i+=2)
    {
        if(mark[i]==0)
        {
            prime[k++] = i;
            if(i<=limit){
            for(j=i*i;j<=n;j+=2*i)
                mark[j] = 1;
        }
        }
    }

}


int main()
{
    int n ,i;
    while(scanf("%d",&n)==1){
    seive(1000002);
    for(i=0;i<=k;i++) {
        while(n%prime[i]==0)
        {
            n /= prime[i];
            printf("%d\n",prime[i]);
        }
        if(n==1) break;
    }
    if(n!=1) printf("prime\n");
    }



}
