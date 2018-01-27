#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[4],i,t,caseno=1;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<3;i++){
        scanf("%d",&a[i]);
        }
        sort(a,a+3);
        printf("Case %d: %d\n",caseno++,a[1]);
    }
    return 0;

}
